#ifndef PDFREADERLOGIC_H
#define PDFREADERLOGIC_H

#include "types.h"
#include <QString>
#include "documentpdf.h"


class QApplication;
class MainWindow;
class QImage;
class QTextCodec;


class PDFReaderLogic
{

public:
    explicit PDFReaderLogic();
    virtual ~PDFReaderLogic();

    bool_t              openDocument(const QString&);
    bool_t              closeDocument(const int index);

    ThumbonailsListPtr_t getThumbonailsFromDocument(const int index);
    QImage*             getPage(const int index, int_t number);
    int_t               getNumberOfPages(const int index) const;
    int_t               getPageNumber(const int index) const;
    void                setPageNumber(const int index, int_t number);
    double_t            getPageZoom(const int index) const;
    void                setPageZoom(const int index, double_t);

    bool_t isInRangeOfNumbers(const int index, int_t);
    bool_t isLastPage(const int index);
    bool_t isFirstPage(const int index);

private:

    DocumentsPtr_t          m_documents;

};

#endif // PDFREADERLOGIC_H
