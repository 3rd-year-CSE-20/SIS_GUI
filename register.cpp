#include "register.h"

Register:: Register(QWidget *parent):QWidget(parent){

    container = new QWidget(this);
    _mainLayout = new QHBoxLayout();
    mainLayout = new QHBoxLayout();
    _leftWidget = new QWidget();
    _rightWidget = new QWidget();
    _leftLayout = new QVBoxLayout();
    _rightLayout = new QVBoxLayout();
    firstNameTxt = new QLineEdit();
    lastNameTxt = new QLineEdit();
    birthDate = new QCalendarWidget();
    addressTxt = new QLineEdit();
    mobileTxt = new QLineEdit();
    genderGBox = new QWidget();
    genderLayout = new QHBoxLayout();
    maleRB = new QRadioButton("male");
    femaleRB = new QRadioButton("female");
    addressTxt = new QLineEdit();
    mobileTxt = new QLineEdit();
    browsePic = new QPushButton("Browse");
    pic = new QLabel("No pic is selected");
    saveBtn = new QPushButton("Save");
    backBtn = new QPushButton("Back");


    pic->setAlignment(Qt::AlignCenter);

    this->setLayout(_mainLayout);
    _mainLayout->addWidget(container);
    container->setLayout(mainLayout);
    mainLayout->addWidget(_leftWidget);
    mainLayout->addWidget(_rightWidget);
    _leftWidget->setLayout(_leftLayout);
    _rightWidget->setLayout(_rightLayout);

    QWidget *b = new QWidget;
    QHBoxLayout *blay = new QHBoxLayout;
    blay->addWidget(saveBtn);
    blay->addWidget(backBtn);
    b->setLayout(blay);

    _leftLayout->setSpacing(10);
    _leftLayout->addWidget(new QWidget);
    _leftLayout->addWidget(firstNameTxt);
    _leftLayout->addWidget(lastNameTxt);
    _leftLayout->addWidget(genderGBox);
    _leftLayout->addWidget(mobileTxt);
    _leftLayout->addWidget(addressTxt);
    _leftLayout->addWidget(b);

    QWidget *t = new QWidget();
    QHBoxLayout *tlay = new QHBoxLayout();
    t->setLayout(tlay);
    t->setMaximumHeight(50);
    tlay->addWidget(new QWidget);
    tlay->addWidget(browsePic);
    tlay->addWidget(new QWidget);
    QLabel *bdLbl = new QLabel("Birthdate : ");
    bdLbl->setMaximumHeight(40);

    _rightLayout->addWidget(bdLbl);
    _rightLayout->addWidget(birthDate);
    _rightLayout->addWidget(pic);
    _rightLayout->addWidget(t);


    genderGBox->setLayout(genderLayout);
    genderLayout->addWidget(maleRB);
    genderLayout->addWidget(femaleRB);


    this->setStyleSheet("background-color:white; border-radius : 10px;");

    firstNameTxt->setMinimumHeight(40);
//    firstNameTxt->setMaximumWidth(360);
    firstNameTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    firstNameTxt->setPlaceholderText(" First Name");

    lastNameTxt->setMinimumHeight(40);
//    lastNameTxt->setMaximumWidth(360);
    lastNameTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    lastNameTxt->setPlaceholderText(" Last Name");

    addressTxt->setMinimumHeight(40);
//    addressTxt->setMaximumWidth(360);
    addressTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    addressTxt->setPlaceholderText(" Adress");

    mobileTxt->setMinimumHeight(40);
//    mobileTxt->setMaximumWidth(360);
    mobileTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    mobileTxt->setPlaceholderText(" Phone");

    browsePic->setMinimumHeight(40);
    browsePic->setMaximumWidth(260);
    browsePic->setObjectName("login");
    browsePic->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : blue;}"+
                                    "QPushButton:hover#login{ background : #333333;}");

    saveBtn->setMinimumHeight(40);
//    saveBtn->setMaximumWidth(200);
    saveBtn->setObjectName("login");
    saveBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : #00c941;}"+
                                    "QPushButton:hover#login{ background : #333333;}");

    backBtn->setMinimumHeight(40);
//    backBtn->setMaximumWidth(200);
    backBtn->setObjectName("login");
    backBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : red;}"+
                                    "QPushButton:hover#login{ background : #333333;}");


    genderGBox->setMaximumHeight(40);
    genderGBox->setMaximumWidth(360);

    birthDate->setMaximumHeight(280);

    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    connect(backBtn,&QPushButton::clicked,this,&Register::onBackClicked);
    connect(saveBtn,&QPushButton::clicked,this,&Register::onSaveClicked);
    connect(browsePic,&QPushButton::clicked,this,&Register::onBrowseClicked);
}

void Register::onBackClicked(){
    emit back();
}

void Register::onSaveClicked(){
    emit save();
}

void Register::onBrowseClicked(){

}
Register::~Register(){}
