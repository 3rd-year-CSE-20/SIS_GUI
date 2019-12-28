#include "admindashboard.h"

AdminDashboard::AdminDashboard(QWidget *parent):QWidget(parent){
    container = new QWidget();
    mainLayout = new QVBoxLayout();
    _mainLayout = new QVBoxLayout();
    tabWidget = new QTabWidget();
    studentWidget = new QWidget();
    studentSearchtxt = new QLineEdit();
    addStudentBtn = new QPushButton("Add Student");
    searchStudentBtn = new QPushButton("Search");
    studentLay = new QVBoxLayout();
    StudentTable = new QTableWidget();
    studentSearchByName = new QRadioButton("Search By Name");
    studentSearchByID = new QRadioButton("Serach By ID");
    academicSearchtxt = new QLineEdit();
    searchAcademicBtn = new QPushButton("Search");
    addAcademicBtn = new QPushButton("Add Academic");
    academicTable = new QTableWidget();
    academicWidget = new QWidget();
    academicLay = new QVBoxLayout();
    signout = new QPushButton("Signout");

    QWidget *t1 = new QWidget;
    QHBoxLayout *t1lay = new QHBoxLayout;
    QWidget *t11 = new QWidget();
    QVBoxLayout *t11lay = new QVBoxLayout();
    t11->setLayout(t11lay);
    t1->setLayout(t1lay);
    t11lay->addWidget(studentSearchByName);
    t11lay->addWidget(studentSearchByID);
    t1lay->addWidget(t11);
    t1lay->addWidget(studentSearchtxt);
    t1lay->addWidget(searchStudentBtn);
    t1lay->addWidget(addStudentBtn);

    QWidget *t2 = new QWidget;
    QHBoxLayout *t2lay = new QHBoxLayout;
    t2->setLayout(t2lay);
    t2lay->addWidget(academicSearchtxt);
    t2lay->addWidget(searchAcademicBtn);
    t2lay->addWidget(addAcademicBtn);

    QWidget *t3 = new QWidget;
    QHBoxLayout *t3lay = new QHBoxLayout;
    t3->setLayout(t3lay);
    t3lay->addWidget(new QWidget);
    t3lay->addWidget(signout);

    this->setLayout(_mainLayout);
    _mainLayout->addWidget(container);
    container->setLayout(mainLayout);
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(t3);

    studentWidget->setLayout(studentLay);
    studentLay->addWidget(t1);
    studentLay->addWidget(StudentTable);

    academicWidget->setLayout(academicLay);
    academicLay->addWidget(t2);
    academicLay->addWidget(academicTable);

    tabWidget->addTab(studentWidget, " Students ");
    tabWidget->addTab(academicWidget, " Academic ");

    studentSearchtxt->setMinimumHeight(40);
    studentSearchtxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    studentSearchtxt->setPlaceholderText(" Search By ID");

    academicSearchtxt->setMinimumHeight(40);
    academicSearchtxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    academicSearchtxt->setPlaceholderText(" Search By Name ");


    tabWidget->setObjectName("login");
    tabWidget->setStyleSheet(QString("QTabWidget::pane#login{border: 1px solid gray;}")+
                                     "QTabBar::tab{padding : 8px;color : white;background : #666666; font-weight: bold;}"+
                                     "QTabBar::tab:selected{background : white; color : black}");

    searchStudentBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : #00c941;}"+
                                    "QPushButton:hover#login{ background : #333333;}");
    searchStudentBtn->setMinimumHeight(40);
    searchStudentBtn->setMaximumWidth(260);
    searchStudentBtn->setObjectName("login");

    addStudentBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : red;}"+
                                    "QPushButton:hover#login{ background : #333333;}");
    addStudentBtn->setMinimumHeight(40);
    addStudentBtn->setMaximumWidth(260);
    addStudentBtn->setObjectName("login");

    searchAcademicBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : #00c941;}"+
                                    "QPushButton:hover#login{ background : #333333;}");
    searchAcademicBtn->setMinimumHeight(40);
    searchAcademicBtn->setMaximumWidth(260);
    searchAcademicBtn->setObjectName("login");

    addAcademicBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : red;}"+
                                    "QPushButton:hover#login{ background : #333333;}");
    addAcademicBtn->setMinimumHeight(40);
    addAcademicBtn->setMaximumWidth(260);
    addAcademicBtn->setObjectName("login");

    signout->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                   "QPushButton#login{ background : blue;}"+
                                   "QPushButton:hover#login{ background : #333333;}");
    signout->setMinimumHeight(40);
    signout->setMaximumWidth(260);
    signout->setObjectName("login");

    this->setStyleSheet("background-color:white; border-radius : 10px;");
    this->setMinimumHeight(650);
    this->setMinimumWidth(900);
    this->setMaximumWidth(900);

    this->initStudentTable();
    this->initAcademicTable();

    connect(signout,&QPushButton::clicked,this,&AdminDashboard::onSignoutClicked);
    connect(addStudentBtn, &QPushButton::clicked, this, &AdminDashboard::onaddStudentClicked);
}

void AdminDashboard::onSignoutClicked(){
    emit Signout();
}

void AdminDashboard::initStudentTable(){
    StudentTable->setRowCount(5000);
    StudentTable->setColumnCount(4);
    StudentTable->setHorizontalHeaderLabels(QStringList({"ID","Name","Student ID","Department"}));
    StudentTable->setStyleSheet("QTableView {selection-background-color: grey;alternate-background-color: rgb(218, 220, 224);}");
    StudentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    StudentTable->setAlternatingRowColors(true);
    StudentTable->setColumnWidth(0,100);
    StudentTable->setColumnWidth(1,400);
    StudentTable->setColumnWidth(2,100);
    StudentTable->setColumnWidth(3,200);
//                for (int i = 0; i < 8192; i++) {
//                    dataMemInfo->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
//                    dataMemInfo->setItem(i, 1,  new QTableWidgetItem("00000000000000000000000000000000"));
//                }
}

void AdminDashboard::initAcademicTable(){
    academicTable->setRowCount(5000);
    academicTable->setColumnCount(3);
    academicTable->setHorizontalHeaderLabels(QStringList({"ID","Name","Department"}));
    academicTable->setStyleSheet("QTableView {selection-background-color: grey;alternate-background-color: rgb(218, 220, 224);}");
    academicTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    academicTable->setAlternatingRowColors(true);
    academicTable->setColumnWidth(0,100);
    academicTable->setColumnWidth(1,500);
    academicTable->setColumnWidth(2,200);
//                for (int i = 0; i < 8192; i++) {
//                    dataMemInfo->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
//                    dataMemInfo->setItem(i, 1,  new QTableWidgetItem("00000000000000000000000000000000"));
//                }
}

void AdminDashboard::onaddStudentClicked(){
    emit addStudent();
}

AdminDashboard::~AdminDashboard(){

}
