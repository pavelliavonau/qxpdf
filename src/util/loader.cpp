#include "loader.h"
#include <QPixmap>
#include "GString.h"
#include "PDFDoc.h"
#include "SplashOutputDev.h"
#include "SplashBitmap.h"
#include "types.h"
#include <QImage>

Loader::Loader(const_c_str_t _name)
{

    GString* filename = new GString( _name );

    mp_doc = new PDFDoc(filename, NULL, NULL);

    mp_thumbonails = NULL;
    mp_page = NULL;
}

Loader::~Loader()
{
    delete mp_doc;
}

ThumbonailsListPtr_t Loader::getThumbonails()
{
    if (mp_doc->isOk())
    {
        int_t numPages = mp_doc->getNumPages();

        SplashColor paperColor;
        paperColor[0] = paperColor[1] = paperColor[2] = 0xff;

        SplashOutputDev out(splashModeRGB8, 1, gFalse, paperColor);

        out.startDoc(mp_doc->getXRef());

        mp_thumbonails = new QList<QImage*>();

        for(int_t i = 1; i <= numPages; ++i)
        {
            mp_doc->displayPage(&out, i, THUMBONAIL_RESOLUTION, THUMBONAIL_RESOLUTION, 0,
                         gFalse, gTrue, gFalse);

            SplashBitmap* map = out.takeBitmap();

            QImage* p_image = new QImage(map->takeData(),
                                         map->getWidth(),
                                         map->getHeight(),
                                         map->getWidth() * 3 ,
                                         QImage::Format_RGB888);

            mp_thumbonails->push_back(p_image);

            delete map;
        }
    }
    return mp_thumbonails;
}

QImage *Loader::getPage(int_t number)
{
    if (mp_doc->isOk())
    {
        SplashColor paperColor;
        paperColor[0] = paperColor[1] = paperColor[2] = 0xff;

        SplashOutputDev out(splashModeRGB8, 1, gFalse, paperColor);

        out.startDoc(mp_doc->getXRef());

            mp_doc->displayPage(&out, number, PAGE_RESOLUTION, PAGE_RESOLUTION, 0,
                         gFalse, gTrue, gFalse);

            SplashBitmap* map = out.takeBitmap();

            mp_page = new QImage(map->takeData(),
                                         map->getWidth(),
                                         map->getHeight(),
                                         map->getWidth() * 3 ,
                                         QImage::Format_RGB888);
            delete map;
    }

    return mp_page;
}
