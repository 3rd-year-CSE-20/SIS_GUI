#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    main = new QWidget();
    _main = new QWidget();
    mainLayout = new QVBoxLayout();
    _mainLayout = new QHBoxLayout();
    loginWidget = new Login(this);

    mainLayout->addWidget(new QWidget);
    mainLayout->addWidget(_main);
    mainLayout->addWidget(new QWidget);
    main->setLayout(mainLayout);
    _main->setLayout(_mainLayout);
    _mainLayout->addWidget(new QWidget);
    _mainLayout->addWidget(loginWidget);
    _mainLayout->addWidget(new QWidget);

    this->setCentralWidget(main);
    this->loadStyles();
}

void MainWindow::loadStyles(){
    QFile css("../SIS_GUI/theme.css");
    css.open(QFile::ReadOnly);
    QString Styles = css.readAll();
    this->setStyleSheet(Styles);
}

MainWindow::~MainWindow(){
}

