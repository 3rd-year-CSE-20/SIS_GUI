#include "staffdashboard.h"

StaffDashboard::StaffDashboard(StaffMember *s,QWidget *parent):QWidget(parent){
    this->s = s;
    container = new QWidget();
    mainLayout = new QVBoxLayout();
    _mainLayout = new QHBoxLayout();
    academicLayout=new QVBoxLayout();
    personalLayout=new QVBoxLayout();
    personalWidget = new QWidget();
    academicWidget = new QWidget();
    t1 = new QHBoxLayout();
    t2 = new QHBoxLayout();
    tabWidget = new QTabWidget();
    firstLabel = new QLabel("First Name: ",this);
    lastLabel = new QLabel("Last Name:",this);
    idLabel = new QLabel("ID: ",this);
    birthLabel = new QLabel("Birth Date: ",this);
    gendreLabel = new QLabel("Gendre: ",this);
    piclbl1 = new QLabel(" ",this);
    piclbl2 = new QLabel(" ", this);
    graduationyearLabel = new QLabel("Graduation year: ",this);
    teachingcoursesLabel = new QLabel("Courses: ",this);
    departmentLabel = new QLabel("Department: ",this);
    degreeLabel = new QLabel("Degree: ",this);

    fnameDBlbl = new QLabel(" ",this);
    lnameDBlbl = new QLabel(" ",this);
    departDBlbl = new QLabel(" ",this);
    degreeDBlbl = new QLabel(" ",this);
    gendreDBlbl = new QLabel(" ",this);
    birthDBlbl = new QLabel(" ",this);
    idDBlbl = new QLabel(" ",this);
    graduationyearLabelfromDatabase = new QLabel(" ",this);
    teachingcoursesLabelfromDatabase = new QLabel(" ",this);
    signout = new QPushButton("Signout");



    fnameDBlbl->setFont(QFont("Cambria",12));
    lnameDBlbl->setFont(QFont("Cambria",12));
    birthDBlbl->setFont(QFont("Cambria",12));
    gendreDBlbl->setFont(QFont("Cambria",12));
    idDBlbl->setFont(QFont("Cambria",12));
    departDBlbl->setFont(QFont("Cambria",12));
    degreeDBlbl->setFont(QFont("Cambria",12));

    formlayout1 = new QFormLayout();
    formlayout1->setVerticalSpacing(50);
    formlayout1->setHorizontalSpacing(100);
    formlayout1->setFormAlignment(Qt::AlignCenter);

    formlayout2 = new QFormLayout();
    formlayout2->setVerticalSpacing(50);
    formlayout2->setHorizontalSpacing(100);
    formlayout2->setFormAlignment(Qt::AlignCenter);


    firstLabel->setFont(QFont("Times New Roman",17));
    lastLabel->setFont(QFont("Times New Roman",17));
    birthLabel->setFont(QFont("Times New Roman",17));
    gendreLabel->setFont(QFont("Times New Roman",17));
    idLabel->setFont(QFont("Times New Roman",17));

    degreeLabel->setFont(QFont("Times New Roman",17));
    graduationyearLabel->setFont(QFont("Times New Roman",17));
    departmentLabel->setFont(QFont("Times New Roman",17));
    teachingcoursesLabel->setFont(QFont("Times New Roman",17));




    formlayout1->addRow(firstLabel,fnameDBlbl);
    formlayout1->addRow(lastLabel,lnameDBlbl);
    formlayout1->addRow(gendreLabel,gendreDBlbl);
    formlayout1->addRow(birthLabel,birthDBlbl);

    formlayout2->addRow(idLabel,idDBlbl);
    formlayout2->addRow(graduationyearLabel,graduationyearLabelfromDatabase);
    formlayout2->addRow(degreeLabel,degreeDBlbl);
    formlayout2->addRow(departmentLabel,departDBlbl);
    formlayout2->addRow(teachingcoursesLabel,teachingcoursesLabelfromDatabase);

    signout->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : blue;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    signout->setMinimumHeight(40);
    signout->setMaximumWidth(260);
    signout->setObjectName("login");

    fnameDBlbl->setText(s->getFirstName());
    lnameDBlbl->setText(s->getLastName());
    birthDBlbl->setText(s->getBirthDate());
    gendreDBlbl->setText(s->getGendre());
    piclbl1->setPixmap(QPixmap(s->getPicture()));
    piclbl2->setPixmap(QPixmap(s->getPicture()));
    idDBlbl->setText("S"+s->getCollegeId());
    departDBlbl->setText(s->getDepartment());
    degreeDBlbl->setText(s->getDegree());
    graduationyearLabelfromDatabase->setText(s->getBirthDate());

    piclbl1->setMaximumWidth(int(piclbl1->width()*200/piclbl1->width()));
    piclbl1->setMaximumHeight(int(piclbl1->height()*200/piclbl1->height()));
    piclbl1->setScaledContents(true);
    piclbl2->setMaximumWidth(int(piclbl2->width()*200/piclbl2->width()));
    piclbl2->setMaximumHeight(int(piclbl2->height()*200/piclbl2->height()));
    piclbl2->setScaledContents(true);

    QHBoxLayout *t0lay = new QHBoxLayout;
    t0lay->addWidget(new QWidget);
    t0lay->addWidget(signout,Qt::AlignRight);

    this->setLayout(_mainLayout);
    _mainLayout->addWidget(container);
    container->setLayout(mainLayout);
    mainLayout->addWidget(tabWidget);
    mainLayout->addLayout(t0lay);

    personalLayout->setAlignment(Qt::AlignLeft);
    personalWidget->setLayout(t1); //personal layout
    t1->addWidget(piclbl1);
    t1->addLayout(personalLayout);
    personalLayout->addLayout(formlayout1);

    t1->setSpacing(30);

    piclbl1->setStyleSheet("background : red");

    //personalLayout->setSpacing(50);

    //academicLayout->setAlignment(Qt::AlignCenter);
    academicWidget->setLayout(t2); //academic layout
    t2->addWidget(piclbl2);
    t2->addLayout(academicLayout);
    academicLayout->addLayout(formlayout2);


    t2->setSpacing(30);

    tabWidget->addTab(personalWidget, " Personal ");
    tabWidget->addTab(academicWidget, " Academic ");
    tabWidget->setObjectName("login");
    tabWidget->setStyleSheet(QString("QTabWidget::pane#login{border: 1px solid gray;}")+
                                     "QTabBar::tab{padding : 8px;color : white;background : #666666; font-weight: bold;}"+
                                     "QTabBar::tab:selected{background : white; color : black}");


    this->setStyleSheet("background-color:white; border-radius : 10px;");
    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    connect(signout,&QPushButton::clicked,this,&StaffDashboard::onSignoutClicked);

     //connect(backBtn,&QPushButton::clicked,this,&StaffDashboard::onSignoutClicked);
    //connect(studentSearchtxt, &QLineEdit::textEdited, this, &StaffDashboard::onSearchTextChanged);






}
void StaffDashboard::onSignoutClicked(){
    emit Signout();
}
StaffDashboard::~StaffDashboard(){

}
