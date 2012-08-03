#include "pdfreaderlogic.h"
#include "mainwindow.h"
#include "loader.h"
#include "GlobalParams.h"
#include <QTextCodec>

PDFReaderLogic::PDFReaderLogic()
{
    globalParams = new GlobalParams(NULL);
    globalParams->setupBaseFonts(NULL);
    mp_codec = QTextCodec::codecForName(SYSTEM_ENCODING);
}

PDFReaderLogic::~PDFReaderLogic()
{   
    delete globalParams;
}

bool_t PDFReaderLogic::loadThumbonailsFromFile(QString filename)
{    
    mp_filename = new QString(filename);

//    wchar_t* wStr;
//    mp_filename->toWCharArray(wStr);

    QByteArray array = mp_codec->fromUnicode(*mp_filename);

    c_str_t c_filename = array.data();

    Loader loader(c_filename);
    if ((mp_thumbonails = loader.getThumbonails()) != NULL)
    {
        m_numberOfPages = mp_thumbonails->size();
        m_pageNumber = 1;
        m_pageZoom = 1;
        mp_currentPage = NULL;
        return true;
    }
    return false;
}

ThumbonailsListPtr_t PDFReaderLogic::getThumbonails() const
{
    return mp_thumbonails;
}

QImage *PDFReaderLogic::getPage(int_t number)
{
    if (mp_currentPage != NULL)
    {
        uchar* bits = mp_currentPage->bits();
        delete[] bits;
        delete mp_currentPage;        
        mp_currentPage = NULL;
    }

    QByteArray array = mp_codec->fromUnicode(*mp_filename);

    c_str_t c_filename = array.data();
    Loader loader(c_filename);

    mp_currentPage = loader.getPage(number);
    return mp_currentPage;
}

int_t PDFReaderLogic::getNumberOfPages() const
{
    return m_numberOfPages;
}

int_t PDFReaderLogic::getPageNumber() const
{
    return m_pageNumber;
}

void PDFReaderLogic::setPageNumber(int_t number)
{
    m_pageNumber = number;
}

double_t PDFReaderLogic::getPageZoom() const
{
    return m_pageZoom;
}

void PDFReaderLogic::setPageZoom(double_t _pageZoom)
{
    m_pageZoom = _pageZoom;
}


bool_t PDFReaderLogic::isInRangeOfNumbers(int_t _number)
{
    if (_number < m_numberOfPages && _number >= 0)
    {
        return true;
    }
    return false;
}

bool_t PDFReaderLogic::isLastPage()
{
    if (m_pageNumber == m_numberOfPages - 1)
    {
        return true;
    }
    return false;
}

bool_t PDFReaderLogic::isFirstPage()
{
    if (m_pageNumber == 0)
    {
        return true;
    }
    return false;
}

bool_t PDFReaderLogic::clean()
{
    foreach (QImage* p_image, *mp_thumbonails)
    {
        uchar* p_bits = p_image->bits();        
        delete[] p_bits;
        delete p_image;

    }

    delete mp_thumbonails;
    delete mp_filename;
    return true;
}

