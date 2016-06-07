#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setStyleSheet("background:white;");
    QAction *qu = new QAction("&Qu",this);
    setFixedSize(510,900);
    setWindowTitle(tr("Context Menu Show 1"));
     //add QActions
    addAction(new QAction(tr("&Open"), this));
    addAction(new QAction(QIcon(":/images/mark.png"), tr("&Mark"), this));
    addAction(new QAction(tr("&Quit"), this));
    addAction(qu);
    //設定 contextMenuPolicy属性值为 '以Actions为弹出菜单的菜单项组成菜单'
    setContextMenuPolicy(Qt::ActionsContextMenu);
    connect(qu,SIGNAL(triggered()),qApp,SLOT(quit()));

    koe = new QMediaPlayer();
    koe->setMedia(QUrl("qrc:/sounds/kc50v4.mp3"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


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


