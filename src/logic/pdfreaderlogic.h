#ifndef PDFREADERLOGIC_H
#define PDFREADERLOGIC_H

#include "types.h"


class QApplication;
class MainWindow;
class QImage;
class QTextCodec;


class PDFReaderLogic
{

public:
    explicit PDFReaderLogic();
    virtual ~PDFReaderLogic();

    bool_t              loadThumbonailsFromFile(QString);
    bool_t              loadPageFromFile(const_c_str_t, int_t);
    ThumbonailsListPtr_t getThumbonails() const;
    QImage*             getPage(int_t number);
    int_t               getNumberOfPages() const;
    int_t               getPageNumber() const;
    void                setPageNumber(int_t number);
    double_t            getPageZoom() const;
    void                setPageZoom(double_t);

    bool_t isInRangeOfNumbers(int_t);
    bool_t isLastPage();
    bool_t isFirstPage();
    bool_t clean();

private:

    ThumbonailsListPtr_t    mp_thumbonails;
    QImage*                 mp_currentPage;
    QString*                mp_filename;
    QTextCodec *            mp_codec;

    int_t       m_numberOfPages;
    int_t       m_pageNumber;
    double_t    m_pageZoom;
    
};

#endif // PDFREADERLOGIC_H
