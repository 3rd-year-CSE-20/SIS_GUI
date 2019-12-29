#include "login.h"
Login::Login(QWidget *parent):QWidget(parent){

    usrEdit = new QLineEdit("");
    passEdit = new QLineEdit("");
    _mainLayout = new QHBoxLayout();
    _leftLayout = new QVBoxLayout();
    _leftWidget = new QWidget();
    _rightWidget = new QWidget();
    _rightLayout = new QVBoxLayout();
    container = new QWidget();
    mainLayout = new QHBoxLayout();
    img = new QLabel();
    login = new QLabel("       Login");
    loginBtn = new QPushButton("Login");
    img->setPixmap(QPixmap("login.png"));
    forgetLbl = new ClickableLabel();
    regBtn = new QPushButton("Create Account");
//    emit test();


    this->setLayout(_mainLayout);
    this->setStyleSheet("background-color:white; border-radius : 10px;");

    _mainLayout->addWidget(container);
    container->setLayout(mainLayout);
    mainLayout->addWidget(_leftWidget);
    mainLayout->addWidget(_rightWidget);
    mainLayout->setSpacing(0);

    QWidget *t = new QWidget();
    QHBoxLayout *tLay = new QHBoxLayout();
    t->setLayout(tLay);
    tLay->addWidget(new QWidget);
    tLay->addWidget(regBtn);
    tLay->addWidget(new QWidget);

    _leftWidget->setLayout(_leftLayout);
    _leftLayout->addWidget(new QWidget);
    _leftLayout->addWidget(img);
    _leftLayout->addWidget(t);
    _leftLayout->addWidget(new QWidget);

    QWidget *s0 = new QWidget;
    s0->setMinimumHeight(170);
    QWidget *s1 = new QWidget;
    s1->setMaximumHeight(20);
    QWidget *s2 = new QWidget;
    s2->setMaximumHeight(20);
    QWidget *s3 = new QWidget;
    s3->setMaximumHeight(5);

    _rightWidget->setLayout(_rightLayout);
    login->setMaximumHeight(50);
    _rightLayout->addWidget(s0);
    _rightLayout->addWidget(login);
    _rightLayout->addWidget(s1);
    _rightLayout->addWidget(usrEdit);
    _rightLayout->addWidget(passEdit);
    _rightLayout->addWidget(s2);
    _rightLayout->addWidget(loginBtn);
    _rightLayout->addWidget(s3);
    _rightLayout->addWidget(forgetLbl);
    _rightLayout->addWidget(new QWidget);
//    _rightLayout->setSpacing(20);

    forgetLbl->setText("\t\t\tForget Password");
    forgetLbl->setAlignment(Qt::AlignTop);
    QFont f("Arial",30,10);
    login->setFont(f);
    usrEdit->setMinimumHeight(40);
    usrEdit->setMaximumWidth(260);
    usrEdit->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    usrEdit->setPlaceholderText("           ID");

    passEdit->setMinimumHeight(40);
    passEdit->setMaximumWidth(260);
    passEdit->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    passEdit->setPlaceholderText("           Password");
    passEdit->setEchoMode(QLineEdit::Password);

    loginBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : #00c941;}"+
                                    "QPushButton:hover#login{ background : #333333;}");
    loginBtn->setMinimumHeight(40);
    loginBtn->setMaximumWidth(260);
    loginBtn->setObjectName("login");
    regBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : red;}"+
                                    "QPushButton:hover#login{ background : #333333;}");
    regBtn->setMinimumHeight(40);
    regBtn->setMaximumWidth(260);
    regBtn->setObjectName("login");

    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    connect(regBtn,SIGNAL(clicked()),this,SLOT(onRegisterClicked()));
    connect(loginBtn, SIGNAL(clicked()),this,SLOT(onLoginClicked()));

}

void Login::onLoginClicked(){
    emit LoginAcc(usrEdit->text(),passEdit->text());
}

void Login::onRegisterClicked(){
    emit Register();
}
