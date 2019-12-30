#include "dashboard.h"
#include <QDebug>

Dashboard::Dashboard(Student *s,QWidget *parent, bool fromAdmin):QWidget(parent){
    this->s = *s;
    mainLayout = new QVBoxLayout();
    _mainLayout = new QHBoxLayout();
    container = new QWidget();
    tabWidget = new QTabWidget();
    backBtn = new QPushButton("Signout");
    deleteBtn = new QPushButton("Delete");
    personalInfo = new QWidget();
    personalInfoLayout = new QVBoxLayout();
    pic = new QLabel();
    fnamelbl = new QLabel("First Name : ");
    fnameDBlbl = new QLabel("Mohamed");
    lnamelbl = new QLabel("Last Name : ");
    lnameDBlbl = new QLabel("Adel");
    addrlbl = new QLabel("Address : ");
    addrDBlbl = new QLabel("90 el na7o 4akloo");
    phonelbl = new QLabel("Phone Number : ");
    phoneDBlbl = new QLabel("0100100100");
    gendlbl = new QLabel("Gender : ");
    gendDBlbl = new QLabel("Male");
    birthlbl = new QLabel("Birthday");
    birthDBlbl = new QLabel("5 / 3 / 2002");
    gpalbl = new QLabel("GPA : ");
    gpaDBlbl = new QLabel("$GPA");
    departlbl = new QLabel("Department : ");
    departDBlbl = new QLabel("$DEP");
    idlbl = new QLabel("ID : ");
    idDBlbl = new QLabel("$ID");
    currentYlbl = new QLabel("Current Academic Year : ");
    currentYDBlbl = new QLabel("$CAY");
    pic2 = new QLabel();
    academicInfo = new QWidget();
    academicInfoLayout = new QVBoxLayout();
    courseslbl = new QLabel("Courses : ");
    coursesDBlbl = new QLabel("$COURSES");
    firstNameEdit = new QLineEdit();
    lastNameEdit = new QLineEdit();
    addressNameEdit = new QLineEdit();
    BirthDayNameEdit = new QLineEdit();
    saveBtn = new QPushButton("Save");
    backkBtn = new QPushButton("Back");

    fnameDBlbl->setText(s->getFirstName());
    lnameDBlbl->setText(s->getLastName());
    birthDBlbl->setText(s->getBirthDate());
    pic->setPixmap(QPixmap(s->getPicture()));
    pic2->setPixmap(QPixmap(s->getPicture()));
    addrDBlbl->setText(s->getAddress());
    idDBlbl->setText(s->getCollegeId());
    currentYDBlbl->setText(s->getAcademicYear());
    departDBlbl->setText(s->getDepartment());

    fnamelbl->setFont(QFont("Times New Roman",17));
    lnamelbl->setFont(QFont("Times New Roman",17));
    birthlbl->setFont(QFont("Times New Roman",17));
    addrlbl->setFont(QFont("Times New Roman",17));
    idlbl->setFont(QFont("Times New Roman",17));
    currentYlbl->setFont(QFont("Times New Roman",17));
    departlbl->setFont(QFont("Times New Roman",17));
    gendlbl->setFont(QFont("Times New Roman",17));

    fnameDBlbl->setFont(QFont("Cambria",12));
    lnameDBlbl->setFont(QFont("Cambria",12));
    birthDBlbl->setFont(QFont("Cambria",12));
    addrDBlbl->setFont(QFont("Cambria",12));
    idDBlbl->setFont(QFont("Cambria",12));
    currentYDBlbl->setFont(QFont("Cambria",12));
    departDBlbl->setFont(QFont("Cambria",12));
    gendDBlbl->setFont(QFont("Cambria",12));

    QWidget *b = new QWidget;
    QHBoxLayout *blay = new QHBoxLayout;
    blay->addWidget(new QWidget);
    if(fromAdmin){
        blay->addWidget(saveBtn,Qt::AlignRight);
        blay->addWidget(backkBtn, Qt::AlignRight);
        blay->addWidget(deleteBtn, Qt::AlignRight);
    }else
        blay->addWidget(backBtn,Qt::AlignRight);
    b->setLayout(blay);

    this->setLayout(_mainLayout);
    _mainLayout->addWidget(container);
    container->setLayout(mainLayout);
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(b);

    QWidget* t1 = new QWidget;
    QHBoxLayout *t1lay = new QHBoxLayout;
    t1->setLayout(t1lay);
    t1lay->addWidget(new QWidget);
    t1lay->addWidget(pic);
    pic->setMaximumWidth(int(pic->width()*200/pic->height()));
    pic->setMaximumHeight(int(pic->height()*200/pic->height()));
    pic->setScaledContents(true);
    t1lay->addWidget(new QWidget);

    QWidget *t11 = new QWidget;
    QHBoxLayout *t11lay = new QHBoxLayout;
    t11->setLayout(t11lay);
    t11lay->addWidget(new QWidget);
    t11lay->addWidget(pic2);
    pic2->setMaximumWidth(int(pic2->width()*200/pic2->height()));
    pic2->setMaximumHeight(int(pic2->height()*200/pic2->height()));
    pic2->setScaledContents(true);
    t11lay->addWidget(new QWidget);

    QWidget *t2 = new QWidget;
    QHBoxLayout *t2lay = new QHBoxLayout;
    t2->setLayout(t2lay);
    t2lay->addWidget(fnamelbl);
    if(fromAdmin){
        t2lay->addWidget(firstNameEdit);
        t2lay->addWidget(new QWidget);
    }else
        t2lay->addWidget(fnameDBlbl);

    QWidget *t3 = new QWidget;
    QHBoxLayout *t3lay = new QHBoxLayout;
    t3->setLayout(t3lay);
    t3lay->addWidget(lnamelbl);
    if(fromAdmin){
        t3lay->addWidget(lastNameEdit);
        t3lay->addWidget(new QWidget);
    }else
        t3lay->addWidget(lnameDBlbl);

    QWidget *t4 = new QWidget;
    QHBoxLayout *t4lay = new QHBoxLayout;
    t4->setLayout(t4lay);
    t4lay->addWidget(gendlbl);
    t4lay->addWidget(gendDBlbl);

    QWidget *t5 = new QWidget;
    QHBoxLayout *t5lay = new QHBoxLayout;
    t5->setLayout(t5lay);
    t5lay->addWidget(addrlbl);
    if(fromAdmin){
        t5lay->addWidget(addressNameEdit);
        t5lay->addWidget(new QWidget);
    }else
        t5lay->addWidget(addrDBlbl);

    QWidget *t6 = new QWidget;
    QHBoxLayout *t6lay = new QHBoxLayout;
    t6->setLayout(t6lay);
    t6lay->addWidget(phonelbl);
    t6lay->addWidget(phoneDBlbl);

    QWidget *t7 = new QWidget;
    QHBoxLayout *t7lay = new QHBoxLayout;
    t7->setLayout(t7lay);
    t7lay->addWidget(birthlbl);
    if(fromAdmin){
        t7lay->addWidget(BirthDayNameEdit,Qt::AlignLeft);
        t7lay->addWidget(new QWidget);
    }else
        t7lay->addWidget(birthDBlbl);


    QWidget *t8 = new QWidget;
    QHBoxLayout *t8lay = new QHBoxLayout;
    t8->setLayout(t8lay);
    t8lay->addWidget(idlbl);
    t8lay->addWidget(idDBlbl);

    QWidget *t9 = new QWidget;
    QHBoxLayout *t9lay = new QHBoxLayout;
    t9->setLayout(t9lay);
    t9lay->addWidget(gpalbl);
    t9lay->addWidget(gpaDBlbl);

    QWidget *t10 = new QWidget;
    QHBoxLayout *t10lay = new QHBoxLayout;
    t10->setLayout(t10lay);
    t10lay->addWidget(currentYlbl);
    t10lay->addWidget(currentYDBlbl);

    QWidget *t12 = new QWidget;
    QHBoxLayout *t12lay = new QHBoxLayout;
    t12->setLayout(t12lay);
    t12lay->addWidget(departlbl);
    t12lay->addWidget(departDBlbl);

    QWidget *t13 = new QWidget;
    QHBoxLayout *t13lay = new QHBoxLayout;
    t13->setLayout(t13lay);
    t13lay->addWidget(courseslbl);
    t13lay->addWidget(coursesDBlbl);

    personalInfo->setLayout(personalInfoLayout);
    personalInfoLayout->addWidget(t1);
    personalInfoLayout->addWidget(t2);
    personalInfoLayout->addWidget(t3);
    personalInfoLayout->addWidget(t4);
    personalInfoLayout->addWidget(t5);
//    personalInfoLayout->addWidget(t6);
    personalInfoLayout->addWidget(t7);

    academicInfo->setLayout(academicInfoLayout);
    academicInfoLayout->addWidget(t11);
    academicInfoLayout->addWidget(t8);
    academicInfoLayout->addWidget(t9);
    academicInfoLayout->addWidget(t10);
    academicInfoLayout->addWidget(t12);
    academicInfoLayout->addWidget(t13);

    tabWidget->addTab(personalInfo," Personal Info ");
    if(!fromAdmin){
        tabWidget->addTab(academicInfo," Academic Info ");
        tabWidget->addTab(new QWidget()," Services ");
    }



    firstNameEdit->setMinimumHeight(40);
    firstNameEdit->setMaximumWidth(260);
    firstNameEdit->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    firstNameEdit->setPlaceholderText("           First Name");
    firstNameEdit->setText(s->getFirstName());
    firstNameEdit->setAlignment(Qt::AlignCenter);

    lastNameEdit->setMinimumHeight(40);
    lastNameEdit->setMaximumWidth(260);
    lastNameEdit->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    lastNameEdit->setPlaceholderText("           Last Name");
    lastNameEdit->setText(s->getLastName());
    lastNameEdit->setAlignment(Qt::AlignCenter);

    addressNameEdit->setMinimumHeight(40);
    addressNameEdit->setMaximumWidth(260);
    addressNameEdit->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    addressNameEdit->setPlaceholderText("           Address");
    addressNameEdit->setText(s->getAddress());
    addressNameEdit->setAlignment(Qt::AlignCenter);

    BirthDayNameEdit->setMinimumHeight(40);
    BirthDayNameEdit->setMaximumWidth(260);
    BirthDayNameEdit->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    BirthDayNameEdit->setPlaceholderText("           Birthdate");
    BirthDayNameEdit->setText(s->getBirthDate());
    BirthDayNameEdit->setAlignment(Qt::AlignCenter);

    tabWidget->setObjectName("login");
    tabWidget->setStyleSheet(QString("QTabWidget::pane#login{border: 1px solid gray;}")+
                                     "QTabBar::tab{padding : 8px;color : white;background : #666666; font-weight: bold;}"+
                                     "QTabBar::tab:selected{background : white; color : black}");

    backBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : blue;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    backBtn->setMinimumHeight(40);
    backBtn->setMaximumWidth(260);
    backBtn->setObjectName("login");

    saveBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : #00c941;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    saveBtn->setMinimumHeight(40);
    saveBtn->setMaximumWidth(260);
    saveBtn->setObjectName("login");

    backkBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : blue;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    backkBtn->setMinimumHeight(40);
    backkBtn->setMaximumWidth(260);
    backkBtn->setObjectName("login");

    deleteBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : red;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    deleteBtn->setMinimumHeight(40);
    deleteBtn->setMaximumWidth(260);
    deleteBtn->setObjectName("login");




//    fnameDBlbl->setText(s->getFirstName());
//    fnameDBlbl->setText(s->getFirstName());

    this->setStyleSheet("background-color:white; border-radius : 10px;");
    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    connect(backBtn,&QPushButton::clicked,this,&Dashboard::onSignoutClicked);
    connect(saveBtn, &QPushButton::clicked, this, &Dashboard::onSaveClicked);
    connect(backkBtn, &QPushButton::clicked, this, &Dashboard::onBackClicked);
    connect(deleteBtn, &QPushButton::clicked, this, &Dashboard::onDeleteClicked);
}

void Dashboard::onSaveClicked(){
    s.setFirstName(firstNameEdit->text());
    s.setLastName(lastNameEdit->text());
    s.setAddress(addressNameEdit->text());
    s.setBirthDate(BirthDayNameEdit->text());
    s.save();
    saveBtn->setEnabled(false);
    saveBtn->setText("Data is Saved");
}

void Dashboard::onSignoutClicked(){
    emit Signout();
}

void Dashboard::onBackClicked(){
    qDebug() << "back";
    emit Back();
}
void Dashboard::onDeleteClicked(){
    qDebug() << "delete";
    s.delete1();
    emit Delete();
}
Dashboard::~Dashboard(){
}
