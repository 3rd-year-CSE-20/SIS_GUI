#include "register.h"

Register:: Register(QWidget *parent) :
    QWidget(parent){
    mainHlayout = new QHBoxLayout(this);
    mainVlayout = new QVBoxLayout(this);
    subMain_L_FLayout = new QFormLayout(this);
    subMain_R_FLayout = new QFormLayout(this);
    firstNameTxt = new QLineEdit();
    lastNameTxt = new QLineEdit();
    birthDateTxt = new QLineEdit();
    addressTxt = new QLineEdit();
    mobileTxt = new QLineEdit();
    birthDate = new QCalendarWidget();
    genderGBox = new QWidget();
    genderLayout = new QHBoxLayout();
    maleRB = new QRadioButton("male");
    femaleRB = new QRadioButton("female");
    browsePic = new QPushButton("Browse");

    subMain_L_FLayout->setVerticalSpacing(20);
    subMain_R_FLayout->setVerticalSpacing(20);

        this->setLayout(mainVlayout);

    mainVlayout->addWidget(new QPushButton);
    mainVlayout->addLayout(mainHlayout);
    mainVlayout->addWidget(new QPushButton);

    mainHlayout->addLayout(subMain_L_FLayout);
    mainHlayout->addLayout(subMain_R_FLayout);

    subMain_L_FLayout->addRow("First Name", firstNameTxt);
    subMain_L_FLayout->addRow("Birth Date", birthDate);
    subMain_L_FLayout->addRow("Gender", genderGBox);
    subMain_L_FLayout->addRow("Address", addressTxt);
//    subMain_L_FLayout->setFormAlignment(Qt::AlignCenter);
//    subMain_L_FLayout->setAlignment(Qt::AlignCenter);
    subMain_R_FLayout->addRow("Last Name", lastNameTxt);
    subMain_R_FLayout->addRow("Add Picture", browsePic);
    subMain_R_FLayout->addRow("Phone", mobileTxt);
//    subMain_R_FLayout->setFormAlignment(Qt::AlignCenter);
//    subMain_R_FLayout->setAlignment(Qt::AlignCenter);
    genderGBox->setLayout(genderLayout);
    genderLayout->addWidget(maleRB);
    genderLayout->addWidget(femaleRB);

}
Register::~Register(){}
