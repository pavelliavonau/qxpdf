#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "types.h"
#include "pdfreaderlogic.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
    bool event(QEvent *event);

private slots:
    void on_actionOpen_triggered();

    void on_previousButton_clicked();

    void on_nextButton_clicked();

    void on_pageNumberEdit_returnPressed();

    void on_decZoomButon_clicked();

    void on_incZoomButton_clicked();

    void on_actionShow_thumbonails_triggered(bool checked);

    void on_actionQuit_triggered();

private:

    Ui::MainWindow*     ui;
    QDockWidget*        mp_dock;
    PDFReaderLogic      m_readerLogic;


    void createThumbonails();
    void applyPageZoom(double_t scaleFactor);
    void showPage(int_t number);
    void setEnableControlsState(bool_t _state);
    void resetStateBeforeLoading();
    void createDock();    

};

#endif // MAINWINDOW_H
