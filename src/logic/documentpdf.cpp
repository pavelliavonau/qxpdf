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
    int size = _name.size();
    wchar_t* buffer = new wchar_t[size];
    _name.toWCharArray(buffer);
    m_xpdfDoc = new PDFDoc(buffer, size);
    delete [] buffer;
#elif defined __unix__

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");

    QByteArray array = codec->fromUnicode(_name);

    const_c_str_t name = array.data();
    GString* filename = new GString( name );
    m_xpdfDoc = new PDFDoc(filename);    
#endif
    m_valid = m_xpdfDoc->isOk();
    if (m_valid)
    {
        m_numberOfPages = m_xpdfDoc->getNumPages();
        mp_thumbonails = new QList<QImage*>();
        m_pageNumber = 1;
        m_pageZoom = 1;
        mp_currentPage = NULL;
    }
}

DocumentPDF::~DocumentPDF()
{    
    delete m_xpdfDoc;    
    deleteThumbonails();
    deleteCurrentPage();
}

bool_t DocumentPDF::isValid()
{
    return m_valid;
}

ThumbonailsListPtr_t DocumentPDF::getThumbonailsFromDocument()
{
    this->getThumbonails();
    return mp_thumbonails;
}

QImage *DocumentPDF::getPage(int_t number)
{
    this->deleteCurrentPage();
    this->readPage(number);
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

void DocumentPDF::deleteCurrentPage()
{
    if (mp_currentPage != NULL)
    {
        uchar* bits = mp_currentPage->bits();
        delete[] bits;
        delete mp_currentPage;
        mp_currentPage = NULL;
    }
}

void DocumentPDF::deleteThumbonails()
{
    foreach (QImage* p_image, *mp_thumbonails)
    {
        uchar* p_bits = p_image->bits();
        delete[] p_bits;
        delete p_image;
    }
    delete mp_thumbonails;
}

void DocumentPDF::getThumbonails()
{
    int_t numPages = m_xpdfDoc->getNumPages();

    SplashColor paperColor;
    paperColor[0] = paperColor[1] = paperColor[2] = 0xff;

    SplashOutputDev out(splashModeRGB8, 1, gFalse, paperColor);

    out.startDoc(m_xpdfDoc->getXRef());

    for(int_t i = 1; i <= numPages; ++i)
    {
        m_xpdfDoc->displayPage(&out, i, THUMBONAIL_RESOLUTION, THUMBONAIL_RESOLUTION, 0,
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

void DocumentPDF::readPage(int_t number)
{

    SplashColor paperColor;
    paperColor[0] = paperColor[1] = paperColor[2] = 0xff;

    SplashOutputDev out(splashModeRGB8, 1, gFalse, paperColor);

    out.startDoc(m_xpdfDoc->getXRef());

    m_xpdfDoc->displayPage(&out, number, PAGE_RESOLUTION, PAGE_RESOLUTION, 0,
                 gFalse, gTrue, gFalse);

    SplashBitmap* map = out.takeBitmap();

    mp_currentPage = new QImage(map->takeData(),
                         map->getWidth(),
                         map->getHeight(),
                         map->getWidth() * 3 ,
                         QImage::Format_RGB888);
    delete map;

}
