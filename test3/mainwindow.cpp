#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *smallWindow = new QAction("&Show Window",this);
    QAction *qu = new QAction("&Quit",this);
    setFixedSize(510,900);
    setWindowTitle(tr("Context Menu Show 1"));
     //add QActions
    /*addAction(new QAction(tr("&Open"), this));
    addAction(new QAction(QIcon(":/images/mark.png"), tr("&Mark"), this));
    addAction(smallWindow);
    addAction(qu);
    //設定 contextMenuPolicy屬性值 以Actions為context menu
    setContextMenuPolicy(Qt::ActionsContextMenu);
    connect(smallWindow,SIGNAL(triggered()),qApp,SLOT(OpenNewWindow()));
    connect(qu,SIGNAL(triggered()),qApp,SLOT(quit()));*/
    createActions();
    setWindowFlags(Qt::WindowStaysOnTopHint);

    koe = new QMediaPlayer();
    koe->setMedia(QUrl("qrc:/sounds/kc50v4.mp3"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::OpenNewWindow()
{
    /*CLISupport clisupport;
    clisupport.setWindowModality(Qt::ApplicationModal);
    clisupport.show();*/
    /*Dialog dialog;
    dialog.setModal(true);
    dialog.show();
    dialog.exec();

}*/

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos ;


    //play background music

    if(koe->state() == QMediaPlayer::PlayingState)
    {
          koe->setPosition(0);
    }
    else if (koe->state()==QMediaPlayer::StoppedState)
    {
         QString url= "qrc:/sounds/kc50v" + QString::number(qrand() % ((28 + 1) - 2) + 2) + ".mp3"; //kv50v2~28.mp3
         koe->setMedia(QUrl(url));
         koe->play();
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    this->move(event->globalPos() - this->dPos);

}

void MainWindow::createActions()
{
    openSecWindowAct = new QAction(tr("&Support Start"),this);
    openSecWindowAct->setStatusTip(tr("Open the support window,"
                                      "and begin to support when you type comments on terminal"));
    connect(openSecWindowAct,SIGNAL(triggered()),this,SLOT(openSecWindow()));

    exitAct = new QAction(tr("&Exit"),this);
    exitAct->setStatusTip(tr("Exit this program"));
    connect(exitAct,SIGNAL(triggered()),this,SLOT(exit_()));
}

void MainWindow::openSecWindow()
{
    /*Dialog dialog;
    dialog.setModal(true);
    dialog.show();
    dialog.exec();*/
    /*CLISupport clisupport;
    clisupport.setWindowModality(Qt::ApplicationModal);
    clisupport.show();*/
    if(!clisupport->isVisible()){
    clisupport = new CLISupport();
    //clisupport->setWindowFlags(Qt::WindowStaysOnTopHint);
    clisupport->show();
    }



}

void MainWindow::exit_()
{
    if(clisupport->isVisible())
    {
        clisupport->close();
    }
    close();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(openSecWindowAct);
    menu.addAction(exitAct);
    menu.exec(event->globalPos());

}

