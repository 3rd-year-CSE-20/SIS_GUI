#include "staffdashboard.h"

StaffDashboard::StaffDashboard(QWidget *parent) : QWidget(parent){

    mainLayout=new QHBoxLayout();
    academicLayout=new QVBoxLayout();
    personalLayout=new QVBoxLayout();
    personalinfoLabel=new QLabel("Personal information",this);
    academicinfoLabel=new QLabel("Academic information",this);
    firstLabel = new QLabel("First Name: ",this);
    lastLabel = new QLabel("Last Name:",this);
    idLabel = new QLabel("ID: ",this);
    birthLabel = new QLabel("Birth Date: ",this);
    gendreLabel = new QLabel("Gendre: ",this);
    picLabel = new QLabel(" ",this);
    picPath = "anime.png";
    pic = new QPixmap(picPath);
    picLabel->setPixmap(picPath);
    picLabel->setGeometry(200,100,50,100);
    degreeLabel = new QLabel("Degree: ",this);
    graduationyearLabel = new QLabel("Graduation year: ",this);
    teachingcoursesLabel = new QLabel("Courses: ",this);
    departmentLabel = new QLabel("Department: ",this);


    this->setLayout(mainLayout);
    mainLayout->addLayout(academicLayout);
    mainLayout->addLayout(personalLayout);

    personalLayout->addWidget(personalinfoLabel);
    personalLayout->addWidget(firstLabel);
    personalLayout->addWidget(lastLabel);
    personalLayout->addWidget(gendreLabel);
    personalLayout->addWidget(birthLabel);
    personalLayout->addWidget(idLabel);
    personalLayout->addWidget(picLabel);

    academicLayout->addWidget(academicinfoLabel);
    academicLayout->addWidget(degreeLabel);
    academicLayout->addWidget(graduationyearLabel);
    academicLayout->addWidget(departmentLabel);
    academicLayout->addWidget(teachingcoursesLabel);

    personalinfoLabel->setStyleSheet("color:white; ");
    firstLabel->setStyleSheet("color:white; ");
    lastLabel->setStyleSheet("color:white;  ");
    gendreLabel->setStyleSheet("color:white;");
    birthLabel->setStyleSheet("color:white; ");
    picLabel->setStyleSheet("color:white; ");
    idLabel->setStyleSheet("color:white; ");

    academicinfoLabel->setStyleSheet("color:white; ");
    degreeLabel->setStyleSheet("color:white; ");
    graduationyearLabel->setStyleSheet("color:white; ");
    departmentLabel->setStyleSheet("color:white; ");
    teachingcoursesLabel->setStyleSheet("color:white; ");


    personalinfoLabel->setFont(QFont("Magma",15,QFont::Bold));
    firstLabel->setFont(QFont("Magma",15));
    lastLabel->setFont(QFont("Magma",15));
    birthLabel->setFont(QFont("Magma",15));
    gendreLabel->setFont(QFont("Magma",15));
    idLabel->setFont(QFont("Magma",15));

    academicinfoLabel->setFont(QFont("Magma",15,QFont::Bold));
    degreeLabel->setFont(QFont("Magma",15));
    graduationyearLabel->setFont(QFont("Magma",15));
    departmentLabel->setFont(QFont("Magma",15));
    teachingcoursesLabel->setFont(QFont("Magma",15));

    formlayout = new QFormLayout();

    formlayout->addRow(firstLabel,firstLabelfromDatabase);
    formlayout->addRow(lastLabel,lastLabelfromDatabase);
    formlayout->addRow(gendreLabel,gendreLabelfromDatabase);
    formlayout->addRow(birthLabel,birthLabelfromDatabase);
    formlayout->addRow(idLabel,idLabelfromDatabase);
    formlayout->addRow(picLabel,picLabelfromDatabase);

    formlayout->addRow(degreeLabel,degreeLabelfromDatabase);
    formlayout->addRow(graduationyearLabel,graduationyearLabelfromDatabase);
    formlayout->addRow(departmentLabel,departmentfromDatabase);
    formlayout->addRow(teachingcoursesLabel,teachingcoursesLabelfromDatabase);







}

StaffDashboard::~StaffDashboard(){

}
