#include "dashboard.h"

Dashboard::Dashboard(Student *s,QWidget *parent):QWidget(parent){

    this->s = s;
    mainLayout = new QVBoxLayout();
    _mainLayout = new QHBoxLayout();
    container = new QWidget();
    tabWidget = new QTabWidget();
    backBtn = new QPushButton("Signout");
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


    fnameDBlbl->setText(s->getFirstName());
    lnameDBlbl->setText(s->getLastName());
    birthDBlbl->setText(s->getBirthDate());
    pic->setPixmap(QPixmap(s->getPicture()));
    pic2->setPixmap(QPixmap(s->getPicture()));
    addrDBlbl->setText(s->getAddress());
    idDBlbl->setText(s->getCollegeId());
    currentYDBlbl->setText(s->getAcademicYear());
    departDBlbl->setText(s->getDepartment());

    QWidget *b = new QWidget;
    QHBoxLayout *blay = new QHBoxLayout;
    blay->addWidget(new QWidget);
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
    t2lay->addWidget(fnameDBlbl);

    QWidget *t3 = new QWidget;
    QHBoxLayout *t3lay = new QHBoxLayout;
    t3->setLayout(t3lay);
    t3lay->addWidget(lnamelbl);
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
    tabWidget->addTab(academicInfo," Academic Info ");
    tabWidget->addTab(new QWidget()," Services ");



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

//    fnameDBlbl->setText(s->getFirstName());
//    fnameDBlbl->setText(s->getFirstName());

    this->setStyleSheet("background-color:white; border-radius : 10px;");
    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    connect(backBtn,&QPushButton::clicked,this,&Dashboard::onSignoutClicked);

}

void Dashboard::onSignoutClicked(){
    emit Signout();
}

Dashboard::~Dashboard(){
}
