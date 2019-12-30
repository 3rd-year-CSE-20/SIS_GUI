#include "admindashboard.h"
#include <QtDebug>

AdminDashboard::AdminDashboard(QWidget *parent):QWidget(parent){
    container = new QWidget();
    mainLayout = new QVBoxLayout();
    _mainLayout = new QVBoxLayout();
    tabWidget = new QTabWidget();
    studentWidget = new QWidget();
    studentSearchtxt = new QLineEdit();
    addStudentBtn = new QPushButton("Add Student");
    studentLay = new QVBoxLayout();
    StudentTable = new QTableWidget();
    studentSearchByName = new QRadioButton("Search By Name");
    studentSearchByID = new QRadioButton("Serach By ID");
    academicSearchtxt = new QLineEdit();
    addAcademicBtn = new QPushButton("Add Academic");
    academicTable = new QTableWidget();
    academicWidget = new QWidget();
    academicLay = new QVBoxLayout();
    signout = new QPushButton("Signout");
    deleteBtn = new QPushButton("Delete");

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
    t1lay->addWidget(addStudentBtn);

    QWidget *t2 = new QWidget;
    QHBoxLayout *t2lay = new QHBoxLayout;
    t2->setLayout(t2lay);
    t2lay->addWidget(academicSearchtxt);
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
    studentSearchtxt->setPlaceholderText(" Search Students");

    academicSearchtxt->setMinimumHeight(40);
    academicSearchtxt->setStyleSheet("background : #E6E6E6; border-radius : 20px; padding : 7px");
    academicSearchtxt->setPlaceholderText(" Search By Name ");


    tabWidget->setObjectName("login");
    tabWidget->setStyleSheet(QString("QTabWidget::pane#login{border: 1px solid gray;}")+
                                     "QTabBar::tab{padding : 8px;color : white;background : #666666; font-weight: bold;}"+
                                     "QTabBar::tab:selected{background : white; color : black}");


    addStudentBtn->setStyleSheet(QString("QPushButton#login{border-radius : 20px; padding : 7px; color : white; font-weight: bold;}")+
                                    "QPushButton#login{ background : red;}"+
                                    "QPushButton:hover#login{ background : #333333;}");
    addStudentBtn->setMinimumHeight(40);
    addStudentBtn->setMaximumWidth(260);
    addStudentBtn->setObjectName("login");


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

    this->studentSearchByID->setChecked(true);

    connect(signout,&QPushButton::clicked,this,&AdminDashboard::onSignoutClicked);
    connect(addStudentBtn, &QPushButton::clicked, this, &AdminDashboard::onaddStudentClicked);
    connect(studentSearchtxt, &QLineEdit::textEdited, this, &AdminDashboard::onSearchTextChanged);
    connect(academicSearchtxt, &QLineEdit::textEdited, this, &AdminDashboard::onSearchTextAcademicChanged);
    connect(addAcademicBtn, &QPushButton::clicked, this, &AdminDashboard::onaddAcademicClicked);
    connect(StudentTable, &QTableWidget::cellDoubleClicked, this, &AdminDashboard::onStudentTableClicked);
    connect(academicTable,&QTableWidget::cellDoubleClicked, this, &AdminDashboard::onAcademicTableClicked);
}

void AdminDashboard::onSignoutClicked(){
    emit Signout();
}

void AdminDashboard::initStudentTable(){
    StudentTable->setRowCount(20);
    StudentTable->setColumnCount(4);
    StudentTable->setHorizontalHeaderLabels(QStringList({"ID","Name","Student ID","Department"}));
    StudentTable->setStyleSheet("QTableView {selection-background-color: grey;alternate-background-color: rgb(218, 220, 224);}");
    StudentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    StudentTable->setAlternatingRowColors(true);
    StudentTable->setColumnWidth(0,100);
    StudentTable->setColumnWidth(1,400);
    StudentTable->setColumnWidth(2,100);
    StudentTable->setColumnWidth(3,200);
}

void AdminDashboard::initAcademicTable(){
    academicTable->setRowCount(20);
    academicTable->setColumnCount(3);
    academicTable->setHorizontalHeaderLabels(QStringList({"ID","Name","Department"}));
    academicTable->setStyleSheet("QTableView {selection-background-color: grey;alternate-background-color: rgb(218, 220, 224);}");
    academicTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    academicTable->setAlternatingRowColors(true);
    academicTable->setColumnWidth(0,100);
    academicTable->setColumnWidth(1,500);
    academicTable->setColumnWidth(2,200);
}

void AdminDashboard::onSearchTextChanged(QString text){
    QVector<Student> students ;
    if(studentSearchByID->isChecked()){
        students = Student::where("college_id",text);

    }else{
        students = Student::where("first_name",text);

    }
    int a = 0;
    StudentTable->setRowCount(students.length());
    for(Student s : students){
        StudentTable->setItem(a,0,new QTableWidgetItem(QString::number(a+1)));
        StudentTable->setItem(a,1,new QTableWidgetItem(s.getFirstName()+" "+s.getLastName()));
        StudentTable->setItem(a,2,new QTableWidgetItem(s.getCollegeId()));
        StudentTable->setItem(a,3,new QTableWidgetItem(s.getDepartment()));
        a++;
    }

}

void AdminDashboard::onSearchTextAcademicChanged(QString text){
    QVector<StaffMember> staff ;
    staff = StaffMember::where("first_name",text);
    int a = 0;
    academicTable->setRowCount(staff.length());
    for(StaffMember s : staff){
        academicTable->setItem(a,0,new QTableWidgetItem(QString::number(a+1)));
        academicTable->setItem(a,1,new QTableWidgetItem(s.getFirstName()+" "+s.getLastName()));
        academicTable->setItem(a,2,new QTableWidgetItem(s.getDepartment()));
        a++;
    }

}

void AdminDashboard::onStudentTableClicked(int row, int col){
//    disconnect(StudentTable, &QTableWidget::cellDoubleClicked, this, &AdminDashboard::onStudentTableClicked);
    Student s = Student::where("college_id",StudentTable->item(row,2)->text())[0];
    emit studentSelected(s);
}
void AdminDashboard::onAcademicTableClicked(int row, int col){
    StaffMember s = StaffMember::where("college_id",academicTable->item(row,2)->text())[0];
    emit academicSelected(s);
}

void AdminDashboard::onaddStudentClicked(){
    emit addStudent();
}
void AdminDashboard::onaddAcademicClicked(){
    emit addAcademic();
}


AdminDashboard::~AdminDashboard(){

}
