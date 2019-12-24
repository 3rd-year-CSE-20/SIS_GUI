#include "login.h"
Login::Login(QWidget *parent):QWidget(parent){

    usrEdit = new QLineEdit();
    passEdit = new QLineEdit();
    _mainLayout = new QHBoxLayout();
    _leftLayout = new QVBoxLayout();
    _leftWidget = new QWidget();
    _rightWidget = new QWidget();
    _rightLayout = new QVBoxLayout();
    img = new QLabel();

    img->setPixmap(QPixmap("login.png"));

//    emit test();


//    this->setLayout(_mainLayout);
    this->setStyleSheet("background-color:white; border-radius : 10px;");

//    _mainLayout->addWidget(_leftWidget);
//    _mainLayout->addWidget(_rightWidget);
////    _mainLayout->setSpacing(0);

//    _leftWidget->setLayout(_leftLayout);
//    _leftLayout->addWidget(new QWidget);
//    _leftLayout->addWidget(img);
//    _leftLayout->addWidget(new QWidget);

//    _rightWidget->setLayout(_rightLayout);
//    _rightLayout->addWidget(new QWidget);
//    _rightLayout->addWidget(usrEdit);
//    _rightLayout->addWidget(passEdit);
//    _rightLayout->addWidget(new QWidget);

//    passEdit->setEchoMode(QLineEdit::Password);

    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);




}
