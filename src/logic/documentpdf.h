#ifndef DOCUMENTPDF_H
#define DOCUMENTPDF_H

#include <QString>
#include "types.h"

class PDFDoc;
class SplashOutputDev;

class DocumentPDF
{
public:
    DocumentPDF(const QString& filepath);
    virtual ~DocumentPDF();
    bool_t isValid();
    ThumbonailsListPtr_t getThumbonailsFromDocument() const;
    QImage*             getPage(int_t number);
    int_t               getNumberOfPages() const;
    int_t               getPageNumber() const;
    void                setPageNumber(int_t number);
    double_t            getPageZoom() const;
    void                setPageZoom(double_t);


private:
    bool_t      m_valid;
    int_t       m_numberOfPages;
    int_t       m_pageNumber;
    double_t    m_pageZoom;
    PDFDoc*     m_xpdfDoc;
    ThumbonailsListPtr_t    mp_thumbonails;
    QImage*                 mp_currentPage;
    SplashOutputDev*        mp_out;


    void        __getThumbonails();
    void        __getPage(int_t number);
    void        __initOutputDevice();

};

#endif // DOCUMENTPDF_H
