#include "pdfreaderlogic.h"
#include "mainwindow.h"
#include "GlobalParams.h"
#include "documentpdf.h"

PDFReaderLogic::PDFReaderLogic()
{
    globalParams = new GlobalParams(NULL);
    globalParams->setupBaseFonts(NULL);
    m_documents = new QList<DocumentPDF*>();
}

PDFReaderLogic::~PDFReaderLogic()
{   
    delete globalParams;
}

bool_t PDFReaderLogic::openDocument(const QString & _name)
{
    DocumentPDF* document = new DocumentPDF(_name);
    m_documents->push_back(document);
    return document->isValid();
}

bool_t PDFReaderLogic::closeDocument(const int index)
{
    DocumentPDF* document = m_documents->takeAt(index);
    delete document;
    return true;
}

ThumbonailsListPtr_t PDFReaderLogic::getThumbonailsFromDocument(const int index)
{
    DocumentPDF* document = m_documents->at(index);
    return document->getThumbonailsFromDocument();
}

QImage *PDFReaderLogic::getPage(const int index, int_t number)
{
    DocumentPDF* document = m_documents->at(index);
    return document->getPage(number);
}

int_t PDFReaderLogic::getNumberOfPages(const int index) const
{
    DocumentPDF* document = m_documents->at(index);
    return document->getNumberOfPages();
}

int_t PDFReaderLogic::getPageNumber(const int index) const
{
    DocumentPDF* document = m_documents->at(index);
    return document->getPageNumber();
}

void PDFReaderLogic::setPageNumber(const int index, int_t number)
{
    DocumentPDF* document = m_documents->at(index);
    document->setPageNumber(number);
}

double_t PDFReaderLogic::getPageZoom(const int index) const
{
    DocumentPDF* document = m_documents->at(index);
    return document->getPageZoom();
}

void PDFReaderLogic::setPageZoom(const int index, double_t _pageZoom)
{
    DocumentPDF* document = m_documents->at(index);
    document->setPageZoom(_pageZoom);
}


bool_t PDFReaderLogic::isInRangeOfNumbers(const int index, int_t _number)
{
    DocumentPDF* document = m_documents->at(index);
    if (_number < document->getNumberOfPages() && _number >= 0)
    {
        return true;
    }
    return false;
}

bool_t PDFReaderLogic::isLastPage(const int index)
{
    DocumentPDF* document = m_documents->at(index);
    if (document->getPageNumber() == document->getNumberOfPages() - 1)
    {
        return true;
    }
    return false;
}

bool_t PDFReaderLogic::isFirstPage(const int index)
{
    DocumentPDF* document = m_documents->at(index);
    if (document->getPageNumber() == 0)
    {
        return true;
    }
    return false;
}
