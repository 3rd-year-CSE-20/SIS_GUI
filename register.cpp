#include "register.h"

Register:: Register(QWidget *parent, bool fromAdmin):QWidget(parent){

    this->fromAdmin = fromAdmin;
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
    generateID = new QPushButton("Generate Student ID");
    generatedID = new QLabel();
    password  = new QLineEdit();
    rewritePassword = new QLineEdit();
    studentID = new QLineEdit();
    wrongPassword = new QLabel("");


    saveBtn->setEnabled(false);

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

    generatedID->setAlignment(Qt::AlignCenter);

    QWidget *t0 = new QWidget();
    QHBoxLayout *t0lay = new QHBoxLayout();
    t0->setLayout(t0lay);
    t0lay->addWidget(generateID);
    t0lay->addWidget(generatedID);

    QWidget *t1 = new QWidget;
    QHBoxLayout *t1lay = new QHBoxLayout;
    t1->setLayout(t1lay);
    t1lay->addWidget(rewritePassword);
    t1lay->addWidget(wrongPassword);

    _leftLayout->setSpacing(10);
    if(fromAdmin)   _leftLayout->addWidget(t0);
    else            _leftLayout->addWidget(new QWidget);
    _leftLayout->addWidget(firstNameTxt);
    _leftLayout->addWidget(lastNameTxt);
    _leftLayout->addWidget(genderGBox);
    _leftLayout->addWidget(mobileTxt);
    _leftLayout->addWidget(addressTxt);
    if(!fromAdmin)
        _leftLayout->addWidget(studentID);
    _leftLayout->addWidget(password);
    _leftLayout->addWidget(t1);
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
    firstNameTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    firstNameTxt->setPlaceholderText(" First Name");

    lastNameTxt->setMinimumHeight(40);
    lastNameTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    lastNameTxt->setPlaceholderText(" Last Name");

    addressTxt->setMinimumHeight(40);
    addressTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    addressTxt->setPlaceholderText(" Adress");

    mobileTxt->setMinimumHeight(40);
    mobileTxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    mobileTxt->setPlaceholderText(" Phone");

    password->setMinimumHeight(40);
    password->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    password->setPlaceholderText(" Password");

    rewritePassword->setMinimumHeight(40);
    rewritePassword->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    rewritePassword->setPlaceholderText(" Rewrite Password");

    wrongPassword->setMaximumHeight(40);
    t1lay->setMargin(0);
    t1lay->setSpacing(0);
    t1->setMaximumHeight(40);

    studentID->setMinimumHeight(40);
    studentID->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    studentID->setPlaceholderText(" Student ID");

    wrongPassword->setStyleSheet("color : red");

    browsePic->setMinimumHeight(40);
    browsePic->setMaximumWidth(260);
    browsePic->setObjectName("login");
    browsePic->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : blue;}"+
                                    "QPushButton:hover#login{ background : #333333;}");

    saveBtn->setMinimumHeight(40);
    saveBtn->setObjectName("login");
    saveBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : #00c941;}"+
                                    "QPushButton:hover#login{ background : #333333;}");

    generateID->setMinimumHeight(40);
    generateID->setObjectName("login");
    generateID->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : #00c941;}"+
                                    "QPushButton:hover#login{ background : #333333;}");

    backBtn->setMinimumHeight(40);
    backBtn->setObjectName("login");
    backBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : red;}"+
                                    "QPushButton:hover#login{ background : #333333;}");


    birthDate->setStyleSheet("background : #aaaaaa");

    genderGBox->setMaximumHeight(40);
    genderGBox->setMaximumWidth(360);

    birthDate->setMaximumHeight(280);

    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    connect(backBtn,&QPushButton::clicked,this,&Register::onBackClicked);
    connect(saveBtn,&QPushButton::clicked,this,&Register::onSaveClicked);
    connect(browsePic,&QPushButton::clicked,this,&Register::onBrowseClicked);
    connect(generateID,&QPushButton::clicked,this,&Register::ongenerateClicked);
    connect(rewritePassword, &QLineEdit::textEdited, this, &Register::onWritePassword);
    connect(password, &QLineEdit::textEdited, this, &Register::onPassword);
}

void Register::onBackClicked(){
    emit back();
}

#include <QDebug>

void Register::onSaveClicked(){
    Student s;
    long long id = studentID->text().mid(2,4).toLongLong();
    s = Student::find(id);
    if(!s.getFirstName().compare("")){
        qDebug() << id;
        s = Student::find(id);
        s.setFirstName(firstNameTxt->text());
        s.setLastName(lastNameTxt->text());
        if(maleRB->isChecked()){
            s.setGendre("male");
        }else{
            s.setGendre("female");
        }
        s.setDepartment("Preparatory");
        s.setAddress(addressTxt->text());
        s.setPicture(path);
        s.setPassword(rewritePassword->text());
        s.setCollegeId(studentID->text());
        s.setBirthDate(birthDate->selectedDate().toString("dd-MM-yyyy"));
        s.save();
    }
    emit save();
}

void Register::onWritePassword(QString newpass){
    if(!newpass.compare(password->text())){
        wrongPassword->setText("Password Matched");
        wrongPassword->setStyleSheet("color : green");
        saveBtn->setEnabled(true);
    }else{
        wrongPassword->setText("Password dosn't Match");
        wrongPassword->setStyleSheet("color : red");
        saveBtn->setEnabled(false);
    }
}

void Register::onPassword(QString newpass){
    if(!newpass.compare(rewritePassword->text())){
        wrongPassword->setText("Password Matched");
        wrongPassword->setStyleSheet("color : green");
        saveBtn->setEnabled(true);
    }else{
        wrongPassword->setText("Password dosn't Match");
        wrongPassword->setStyleSheet("color : red");
        saveBtn->setEnabled(false);
    }
}

void Register::onBrowseClicked(){
    path = QFileDialog::getOpenFileName(this,tr("Browse Picture"), "/home/", tr("Image Files (*)"));
    pic->setPixmap(QPixmap(path));
    pic->setMaximumWidth(int(pic->width()*200/pic->height()));
    pic->setMaximumHeight(int(pic->height()*200/pic->height()));
    pic->setScaledContents(true);
}

void Register::ongenerateClicked(){
    Student s;
    s.save();
    s.getCollegeId();
    QString id = "21";
    int lastId = Student::getLastId();
    if(lastId>9){
        id += "000"+QString::number(lastId);
    }else if(lastId > 99){
        id += "00"+QString::number(lastId);
    }
    else if(lastId > 999){
        id += "0"+QString::number(lastId);
    }else{
        id += QString::number(lastId);
    }
    generatedID->setText(id);
}

Register::~Register(){

}
