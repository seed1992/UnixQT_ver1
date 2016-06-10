#ifndef CLISUPPORT_H
#define CLISUPPORT_H

#include <QMainWindow>
#include <QtGui>
#include <QTextBrowser>
#include <QLabel>
#include <QKeyEvent>
#include <QWidget>



namespace Ui {
class CLISupport;
}

class CLISupport : public QMainWindow
{
    Q_OBJECT

public:
    explicit CLISupport(QWidget *parent = 0);
    ~CLISupport();
    bool eventFilter(QObject *watched, QEvent *event);
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CLISupport *ui;
    QTextBrowser *myTextOutput;
    QLabel *myLabel;

};

#endif // CLISUPPORT_H
