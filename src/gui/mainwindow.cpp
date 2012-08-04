#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pdfreaderlogic.h"
#include <QFileDialog>
#include <QImage>
#include <QGraphicsScene>
#include <QDockWidget>
#include <QMouseEvent>
#include <pagegraphicsitem.h>
#include "pagegraphicsitemevent.h"
#include <QMessageBox>


bool_t g_isFileLoaded;   // BAD, but not works as a member of class (


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);

    createDock();

    QGraphicsScene* pageScene = new QGraphicsScene(ui->pageView);
    ui->pageView->setScene(pageScene);    
    ui->pageView->setDragMode(QGraphicsView::ScrollHandDrag);

    QGraphicsScene* thumbonailsScene = new QGraphicsScene(this);
    ui->thumbonailsView->setScene(thumbonailsScene);
    ui->thumbonailsView->setDragMode(QGraphicsView::ScrollHandDrag);    

    g_isFileLoaded = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *event)
{
    int_t type = event->type();

    switch (type) {
        case (QEvent::User + 1) : {

            PageGraphicsItemEvent* pageGraphicsItemEventPtr = dynamic_cast<PageGraphicsItemEvent*>(event);
            PageGraphicsItem::PageItemType type =  pageGraphicsItemEventPtr->getSenderType();
            switch  (type)
            {
                case PageGraphicsItem::THUMBONAILS_VIEW:
                {
                    int_t number = pageGraphicsItemEventPtr->getThumbonailNumber();
                    showPage(number);
                    event->accept();
                    break;
                }
                case PageGraphicsItem::PAGE_VIEW:
                {
                    double_t scaleFactor = pageGraphicsItemEventPtr->getScaleFactor();
                    applyPageZoom(scaleFactor);
                    event->accept();
                }
                default: break;     // do not care
            }
            break;
        }
        default: break;     // do not care
    }

    return QMainWindow::event(event);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("open file.."), tr(""), tr("PDF Files (*.pdf)"));

    if (filename.isEmpty())
    {
        return;
    }
    /*  busy message  */
    ui->statusBar->showMessage(QString(tr("loading")));    
    this->repaint();

    if (g_isFileLoaded)
    {
        resetStateBeforeLoading();        
    }

    if (!m_readerLogic.openDocument(filename))
    {        
        QMessageBox::information(this, QString(tr("Error")), QString(tr("Error occured while opening file. Sorry.")));
        return;
    }


    setWindowTitle(filename);
    ui->pageNumberEdit->setText( QString::number(m_readerLogic.getPageNumber(0)) );
    createThumbonails();
    showPage(1);

    ui->zoomEdit->setText(QString::number(ZOOM_EDIT_INIT));    
    setEnableControlsState(true);
    ui->statusBar->showMessage(QString(tr("ready")));
    g_isFileLoaded = true;

}

void MainWindow::createThumbonails()
{
    ThumbonailsListPtr_t pages = m_readerLogic.getThumbonailsFromDocument(0);

    ThumbonailsIterator iter = pages->begin();      // :) I know about foreach but iterators I like more

    QGraphicsScene* thumbonailsScene = ui->thumbonailsView->scene();

    double_t    ypos = 0;

    int_t pageNumber = 1;
    while(iter != pages->end())
    {
        PageGraphicsItem* pageItem = new PageGraphicsItem(*iter, PageGraphicsItem::THUMBONAILS_VIEW, this, pageNumber);
        pageItem->setPos(0, ypos);
        thumbonailsScene->addItem(pageItem);
        ypos += pageItem->getHeight() + SPACES_BETWEEN_THUMBONAILS;
        iter++;
        pageNumber++;
    }    
    ui->thumbonailsView->scale(THUMBONAIL_VIEW_LOADING_SCALE, THUMBONAIL_VIEW_LOADING_SCALE);
}

void MainWindow::applyPageZoom(double_t scaleFactor)
{

    double_t newZoomValue = m_readerLogic.getPageZoom(0) * scaleFactor;

    if (newZoomValue > MAXIMUM_PAGE_ZOOM)
    {
        newZoomValue = MAXIMUM_PAGE_ZOOM;
        scaleFactor = MAXIMUM_PAGE_ZOOM / m_readerLogic.getPageZoom(0);
    }

    if (newZoomValue < MINIMUM_PAGE_ZOOM)
    {
        newZoomValue = MINIMUM_PAGE_ZOOM;
        scaleFactor = MINIMUM_PAGE_ZOOM / m_readerLogic.getPageZoom(0);
    }

    m_readerLogic.setPageZoom(0, newZoomValue);
    ui->zoomEdit->setText(QString::number(static_cast<int>(newZoomValue * 100)));
    ui->pageView->scale(scaleFactor, scaleFactor);
}

void MainWindow::showPage(int_t number)
{

    QGraphicsScene* pageScene = ui->pageView->scene();
    pageScene->clear();

    QImage* pImage = m_readerLogic.getPage(0, number);

    PageGraphicsItem* pageItem = new PageGraphicsItem(pImage, PageGraphicsItem::PAGE_VIEW, this, number);

    pageScene->addItem(pageItem);
    m_readerLogic.setPageNumber(0, number - 1);
    ui->pageNumberEdit->setText(QString::number(number));
}

void MainWindow::setEnableControlsState(bool_t _state)
{
    ui->previousButton->setEnabled(_state);
    ui->pageNumberEdit->setEnabled(_state);
    ui->nextButton->setEnabled(_state);
    ui->decZoomButon->setEnabled(_state);
    ui->zoomEdit->setEnabled(_state);
    ui->incZoomButton->setEnabled(_state);
}

void MainWindow::resetStateBeforeLoading()
{
    ui->pageView->scene()->clear();            
    ui->thumbonailsView->scene()->clear();
    ui->thumbonailsView->scale(THUMBONAIL_VIEW_CLOSING_SCALE, THUMBONAIL_VIEW_CLOSING_SCALE);

    /* replacing previous thumbonails */
    QGraphicsScene* thumbonailsScene = ui->thumbonailsView->scene();
    delete thumbonailsScene;
    thumbonailsScene = new QGraphicsScene(this);
    ui->thumbonailsView->setScene(thumbonailsScene);
    /* ------------------------------- */

    applyPageZoom(1 / m_readerLogic.getPageZoom(0));
    ui->thumbonailsView->setDragMode(QGraphicsView::ScrollHandDrag);    

    m_readerLogic.closeDocument(0);
}

void MainWindow::createDock()
{
    mp_dock = new QDockWidget(this);

    mp_dock->setFeatures(mp_dock->features() &~ (QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable));
    mp_dock->setWidget(ui->thumbonailsView);

    addDockWidget(Qt::LeftDockWidgetArea, mp_dock, Qt::Vertical);
}

void MainWindow::on_previousButton_clicked()
{
    int_t pageNumber = m_readerLogic.getPageNumber(0);

    if (!m_readerLogic.isFirstPage(0))
    {
        showPage(pageNumber);
    }
}

void MainWindow::on_nextButton_clicked()
{
    int_t pageNumber = m_readerLogic.getPageNumber(0);

    if (!m_readerLogic.isLastPage(0))
    {
        showPage(pageNumber + 2);
    }
}

void MainWindow::on_pageNumberEdit_returnPressed()
{
    int_t pageNumber = ui->pageNumberEdit->text().toInt();    

    if (!m_readerLogic.isInRangeOfNumbers(0, pageNumber - 1))
    {
        int numberOfPages = m_readerLogic.getNumberOfPages(0);

        if (pageNumber > numberOfPages)
        {
            pageNumber = numberOfPages;
        }
        else
        {
            pageNumber = 1;
        }
    }

    showPage(pageNumber);
}

void MainWindow::on_decZoomButon_clicked()
{
    applyPageZoom(1 + (-1 * ZOOM_STEP));
}

void MainWindow::on_incZoomButton_clicked()
{
    applyPageZoom(1 + ZOOM_STEP);
}

void MainWindow::on_actionShow_thumbonails_triggered(bool checked)
{
    if (checked)
    {
        this->restoreDockWidget(mp_dock);
    }
    else
    {
        this->removeDockWidget(mp_dock);
    }
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}
