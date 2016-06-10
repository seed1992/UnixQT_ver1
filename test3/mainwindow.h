#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QMenu>
#include <QAction>
#include"clisupport.h"
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
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void contextMenuEvent(QContextMenuEvent *event);

private:
    Ui::MainWindow *ui;
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    QMediaPlayer * koe;
    void createActions();

    QAction *openSecWindowAct;
    QAction *exitAct;
    CLISupport *clisupport;
private slots:
    void openSecWindow();
    void exit_();


};



#endif // MAINWINDOW_H
