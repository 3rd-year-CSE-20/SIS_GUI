#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    main = new QWidget();
    _main = new QWidget();
    mainLayout = new QVBoxLayout();
    _mainLayout = new QHBoxLayout();
    loginWidget = new Login(this);

    mainLayout->addWidget(new QWidget);
    mainLayout->addWidget(_main);
    mainLayout->addWidget(new QWidget);
    main->setLayout(mainLayout);

    setWidget(loginWidget);

    this->setCentralWidget(main);
    this->loadStyles();

    connect(loginWidget, &Login::Register,this,&MainWindow::setSignupWidget);
    connect(loginWidget, &Login::LoginAcc, this, &MainWindow::login);
}

void MainWindow::loadStyles(){
    QFile css("../MainWindow/theme.css");
    css.open(QFile::ReadOnly);
    QString Styles = css.readAll();
    this->setStyleSheet(Styles);
}

void MainWindow::setWidget(QWidget *w){
    delete _mainLayout;
    _mainLayout = new QHBoxLayout();
    _mainLayout->addWidget(new QWidget);
    _mainLayout->addWidget(w);
    _mainLayout->addWidget(new QWidget);
    _main->setLayout(_mainLayout);
}

void MainWindow::setSignupWidget(){
    regWidget = new Register();
    delete loginWidget;
    setWidget(regWidget);
    connect(regWidget,&Register::back,this,&MainWindow::setLoginWidget);
}

void MainWindow::setLoginWidget(){
    loginWidget = new Login();
    delete regWidget;
    setWidget(loginWidget);
    connect(loginWidget, &Login::Register,this,&MainWindow::setSignupWidget);
    connect(loginWidget, &Login::LoginAcc, this, &MainWindow::login);
}

void MainWindow::login(QString usr, QString pass){
    if(usr.toStdString()[0] == 'A'){
         long long id = usr.mid(4,3).toLongLong();
         qDebug() << id;
         if(Admin::isInDatabase(id)){
             qDebug() << "here";
             Admin a = Admin::find(id);
             qDebug() << a.getPassword();
             if(!a.getPassword().compare(pass)){
                 delete loginWidget;
                 adminDashboard = new AdminDashboard();
                 setWidget(adminDashboard);
                 connect(adminDashboard, &AdminDashboard::Signout, this, &MainWindow::adminSignout);
                 connect(adminDashboard, &AdminDashboard::addStudent, this, &MainWindow::adminAddStudent);
                 connect(adminDashboard, &AdminDashboard::addAcademic, this, &MainWindow::adminAddAcademic);
                 connect(adminDashboard, &AdminDashboard::studentSelected, this, &MainWindow::studentSelected);
                 connect(adminDashboard, &AdminDashboard::academicSelected,this, &MainWindow::staffSelected);
             }
         }
    }else if(usr.toStdString()[0] == 'S'){
        long long id = usr.mid(4,3).toLongLong();
        qDebug() << id;
        if(StaffMember::isInDatabase(id)){
            qDebug() << "here";
            StaffMember a = StaffMember::find(id);
            qDebug() << a.getPassword();
            if(!a.getPassword().compare(pass)){
                delete loginWidget;
                staffDashboard = new StaffDashboard(&a);
                setWidget(staffDashboard);
                connect(staffDashboard, &StaffDashboard::Signout, this, &MainWindow::academicSignout);
                }
            else{
               loginWidget->errLbl->setVisible(true);
            }
        }
    }
    else{
        long long id = usr.mid(2,4).toLongLong();
        if(Student::isInDatabase(id)){
            Student a = Student::find(id);
            if(!a.getPassword().compare(pass)){
                delete loginWidget;
                studentDashboard = new Dashboard(&a);
                setWidget(studentDashboard);
                connect(studentDashboard, &Dashboard::Signout, this, &MainWindow::Signout);
            }
        }
    }
}

void MainWindow::adminAddStudent(){
    regWidget = new Register(nullptr,true);
    delete adminDashboard;
    setWidget(regWidget);
    connect(regWidget,&Register::back,this,&MainWindow::adminDash);
}

void MainWindow::adminAddAcademic(){
    regWidget = new Register(nullptr,true,true);
    delete adminDashboard;
    setWidget(regWidget);
    connect(regWidget,&Register::back,this, &MainWindow::adminDash);
}

void MainWindow::adminDash(){
    adminDashboard = new AdminDashboard();
    delete regWidget;
//    setWidget(studentDashboard);
    setWidget(adminDashboard);
    connect(adminDashboard, &AdminDashboard::Signout, this, &MainWindow::adminSignout);
    connect(adminDashboard, &AdminDashboard::addStudent, this, &MainWindow::adminAddStudent);
    connect(adminDashboard, &AdminDashboard::addAcademic, this, &MainWindow::adminAddAcademic);
    connect(adminDashboard, &AdminDashboard::studentSelected, this, &MainWindow::studentSelected);
    connect(adminDashboard, &AdminDashboard::academicSelected,this, &MainWindow::staffSelected);
}

void MainWindow::studentSelected(Student s){
    studentDashboard = new Dashboard(&s,nullptr,true);
    disconnect(adminDashboard, &AdminDashboard::studentSelected, this, &MainWindow::studentSelected);
    adminDashboard->setVisible(false);
    setWidget(studentDashboard);
    connect(studentDashboard, &Dashboard::Back, this, &MainWindow::studentDashBack);
    connect(studentDashboard, &Dashboard::Delete, this, &MainWindow::studentDashBack);
}
void MainWindow::staffSelected(StaffMember s){
    staffDashboard = new StaffDashboard(&s,nullptr,true);
    disconnect(adminDashboard, &AdminDashboard::academicSelected, this, &MainWindow::staffSelected);
    adminDashboard->setVisible(false);
    setWidget(staffDashboard);
    connect(staffDashboard, &StaffDashboard::Back, this, &MainWindow::staffDashBack);
    connect(staffDashboard, &StaffDashboard::Delete, this, &MainWindow::staffDashBack);

}
void MainWindow::studentDashBack(){
    delete studentDashboard;
    adminDashboard = new AdminDashboard();
    setWidget(adminDashboard);
    connect(adminDashboard, &AdminDashboard::Signout, this, &MainWindow::adminSignout);
    connect(adminDashboard, &AdminDashboard::addStudent, this, &MainWindow::adminAddStudent);
    connect(adminDashboard, &AdminDashboard::addAcademic, this, &MainWindow::adminAddAcademic);
    connect(adminDashboard, &AdminDashboard::studentSelected, this, &MainWindow::studentSelected);
}
void MainWindow::staffDashBack(){
    delete staffDashboard;
    adminDashboard = new AdminDashboard();
    setWidget(adminDashboard);
    connect(adminDashboard, &AdminDashboard::Signout, this, &MainWindow::adminSignout);
    connect(adminDashboard, &AdminDashboard::addStudent, this, &MainWindow::adminAddStudent);
    connect(adminDashboard, &AdminDashboard::addAcademic, this, &MainWindow::adminAddAcademic);
    connect(adminDashboard, &AdminDashboard::academicSelected, this, &MainWindow::staffSelected);
}

void MainWindow::Signout(){
    loginWidget = new Login();
    delete studentDashboard;
    setWidget(loginWidget);
    connect(loginWidget, &Login::Register,this,&MainWindow::setSignupWidget);
    connect(loginWidget, &Login::LoginAcc, this, &MainWindow::login);
}

void MainWindow::adminSignout(){
    loginWidget = new Login();
    delete adminDashboard;
    setWidget(loginWidget);
    connect(loginWidget, &Login::Register,this,&MainWindow::setSignupWidget);
    connect(loginWidget, &Login::LoginAcc, this, &MainWindow::login);
}

void MainWindow::academicSignout(){
    loginWidget = new Login();
    delete staffDashboard;
    setWidget(loginWidget);
    connect(loginWidget, &Login::Register,this,&MainWindow::setSignupWidget);
    connect(loginWidget, &Login::LoginAcc, this, &MainWindow::login);
}

MainWindow::~MainWindow(){
}

