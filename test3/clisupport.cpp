#include "clisupport.h"
#include "ui_clisupport.h"
#include <QLabel>
#include <QTextBrowser>
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include <QTime>
#include <QDateTime>



CLISupport::CLISupport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CLISupport)
{
    ui->setupUi(this);
    //myTextOutput = new QTextBrowser;
    //ui->textBrowser->setText("You Didn't Pressed / Released any Key");
    ui->myLabel->setText("You Didn't Pressed / Released any Key");
    //setFocusPolicy(Qt::NoFocus);
    //QWidget::clearFocus();
    //QMainWindow::clearFocus();
    QTime myTimer ;
    myTimer.start();
    //while(true)
    //{
       //QThread::sleep(2);
       int countTime = myTimer.elapsed();
       // if ((countTime % 10) == 0)
            //ui->textBrowser->append(countTime.toString());
        qDebug() << countTime ;
    //}


            ui->textBrowser->append("HI");
            //QThread::sleep(2);

}

CLISupport::~CLISupport()
{
    delete ui;
}

bool CLISupport::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this && event->type()== QEvent::KeyPress){

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_W){
            return true ;
        } else {
            return false ;
        }
    }
    return false ;
}

void CLISupport::keyPressEvent(QKeyEvent *event)
{
  // ui->textBrowser->setText("You Pressed Key" + event->text());
   //ui->textBrowser->append(event->text());
   if (event->key() == Qt::Key_Space) {
      ui->textBrowser->insertPlainText(" ");
      qDebug("Space event");
   } else {
      ui->textBrowser->insertPlainText(event->text());
   }
   ui->myLabel->setText("You Pressed Key" + event->text());
   qDebug("At least came here");
   QString text = event->text();
   qDebug() << text ;

}

void CLISupport::keyReleaseEvent(QKeyEvent *event)
{

   //ui->textBrowser->setText("You Release Key" + event->text());
   ui->myLabel->setText("You Release Key" + event->text());
}

void CLISupport::on_pushButton_clicked()
{

}
