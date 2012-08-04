#include "documentpdf.h"
#include <QTextCodec>
#include <QByteArray>
#include "GString.h"
#include "PDFDoc.h"
#include <QImage>
#include "SplashOutputDev.h"
#include "SplashBitmap.h"

DocumentPDF::DocumentPDF(const QString& _name)
{
#ifdef WIN32
    wchar_t* array;
    _name.toWCharArray(array);
    mp_doc = new PDFDoc(array, NULL);
#elif defined __unix__

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");

    QByteArray array = codec->fromUnicode(_name);

    const_c_str_t name = array.data();
    GString* filename = new GString( name );
    m_xpdfDoc = new PDFDoc(filename);
    m_valid = m_xpdfDoc->isOk();
#endif
    if (m_valid)
    {
        this->__initOutputDevice();
        this->__getThumbonails();        
        m_numberOfPages = mp_thumbonails->size();
        m_pageNumber = 1;
        m_pageZoom = 1;
        mp_currentPage = NULL;
    }
}

DocumentPDF::~DocumentPDF()
{
    foreach (QImage* p_image, *mp_thumbonails)
    {
        uchar* p_bits = p_image->bits();
        delete[] p_bits;
        delete p_image;

    }

    delete mp_thumbonails;
    delete m_xpdfDoc;
    delete mp_out;
}

bool_t DocumentPDF::isValid()
{
    return m_valid;
}

ThumbonailsListPtr_t DocumentPDF::getThumbonailsFromDocument() const
{
    return mp_thumbonails;
}

QImage *DocumentPDF::getPage(int_t number)
{
    if (mp_currentPage != NULL)
    {
        uchar* bits = mp_currentPage->bits();
        delete[] bits;
        delete mp_currentPage;
        mp_currentPage = NULL;
    }

    this->__getPage(number);
    return mp_currentPage;
}

int_t DocumentPDF::getNumberOfPages() const
{
    return m_numberOfPages;
}

int_t DocumentPDF::getPageNumber() const
{
    return m_pageNumber;
}

void DocumentPDF::setPageNumber(int_t number)
{
    m_pageNumber = number;
}

double_t DocumentPDF::getPageZoom() const
{
    return m_pageZoom;
}

void DocumentPDF::setPageZoom(double_t _pageZoom)
{
    m_pageZoom = _pageZoom;
}

void DocumentPDF::__getThumbonails()
{
    int_t numPages = m_xpdfDoc->getNumPages();

    mp_thumbonails = new QList<QImage*>();

    for(int_t i = 1; i <= numPages; ++i)
    {
        m_xpdfDoc->displayPage(mp_out, i, THUMBONAIL_RESOLUTION, THUMBONAIL_RESOLUTION, 0,
                     gFalse, gTrue, gFalse);

        SplashBitmap* map = mp_out->takeBitmap();

        QImage* p_image = new QImage(map->takeData(),
                                     map->getWidth(),
                                     map->getHeight(),
                                     map->getWidth() * 3 ,
                                     QImage::Format_RGB888);

        mp_thumbonails->push_back(p_image);

        delete map;
    }

}

void DocumentPDF::__getPage(int_t number)
{

    m_xpdfDoc->displayPage(mp_out, number, PAGE_RESOLUTION, PAGE_RESOLUTION, 0,
                 gFalse, gTrue, gFalse);

    SplashBitmap* map = mp_out->takeBitmap();

    mp_currentPage = new QImage(map->takeData(),
                         map->getWidth(),
                         map->getHeight(),
                         map->getWidth() * 3 ,
                         QImage::Format_RGB888);
    delete map;

}

void DocumentPDF::__initOutputDevice()
{
    SplashColor paperColor;
    paperColor[0] = paperColor[1] = paperColor[2] = 0xff;

    mp_out = new SplashOutputDev(splashModeRGB8, 1, gFalse, paperColor);

    mp_out->startDoc(m_xpdfDoc->getXRef());
}
