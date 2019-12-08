#include "dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QWidget(parent)

{

 mainLayout=new QHBoxLayout();
 academicLayout=new QVBoxLayout();
 personalLayout=new QVBoxLayout();
 personalinfoLabel=new QLabel("personalinfoLabel:",this);
 firstLabel = new QLabel("First Name: ",this);
 lastLabel = new QLabel("Last Name:",this);
 idLabel = new QLabel("ID: ",this);
 birthLabel = new QLabel("Birth Date: ",this);
 phoneLabel = new QLabel("Phone Number: ",this);
 gendreLabel = new QLabel("Gendre: ",this);
 addressLabel = new QLabel("Address: ",this);
 picLabel = new QLabel(" ",this);
 picPath = "anime.png";
 pic = new QPixmap(picPath);
 picLabel->setPixmap(picPath);
 picLabel->setGeometry(200,100,50,100);

 this->setLayout(mainLayout);
 mainLayout->addLayout(personalLayout);
 mainLayout->addLayout(academicLayout);

 personalLayout->addWidget(personalinfoLabel);
 personalLayout->addWidget(firstLabel);
 personalLayout->addWidget(lastLabel);
 personalLayout->addWidget(idLabel);
 personalLayout->addWidget(gendreLabel);
 personalLayout->addWidget(birthLabel);
 personalLayout->addWidget(phoneLabel);
 personalLayout->addWidget(addressLabel);
 personalLayout->addWidget(picLabel);
// font1 = new QFont();
// pal = new QPalette();
// pal->setColor(QPalette::WindowText,Qt::white);
 firstLabel->setStyleSheet("color:white; ");
 lastLabel->setStyleSheet("color:white;  ");
 gendreLabel->setStyleSheet("color:white;");
 birthLabel->setStyleSheet("color:white; ");
 phoneLabel->setStyleSheet("color:white; ");
 picLabel->setStyleSheet("color:white; ");
addressLabel->setStyleSheet("color:white; ");


firstLabel->setFont(QFont("Magma",15));
lastLabel->setFont(QFont("Magma",15));
birthLabel->setFont(QFont("Magma",15));
addressLabel->setFont(QFont("Magma",15));
gendreLabel->setFont(QFont("Magma",15));
phoneLabel->setFont(QFont("Magma",15));




}

Dashboard::~Dashboard()
{
}
