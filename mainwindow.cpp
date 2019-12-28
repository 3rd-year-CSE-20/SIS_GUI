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
    QFile css("../SIS_GUI/theme.css");
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

void MainWindow::adminSignout(){
    loginWidget = new Login();
//    delete studentDashboard;
    delete adminDashboard;
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
             }
         }
    }else if(usr.toStdString()[0] == 'S'){

    }else{
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

void MainWindow::adminDash(){
    adminDashboard = new AdminDashboard();
    delete regWidget;
//    setWidget(studentDashboard);
    setWidget(adminDashboard);
    connect(adminDashboard, &AdminDashboard::Signout, this, &MainWindow::adminSignout);
    connect(adminDashboard, &AdminDashboard::addStudent, this, &MainWindow::adminAddStudent);
//    connect(studentDashboard,&Dashboard::Signout,this,&MainWindow::Signout);
}

void MainWindow::checkStudentAvailability(){
//    qDebug()<<"Student is received";
//    if(usrEdit->text()[0]!='A'&&usrEdit->text()[0]!='S'){
//        long long id = usrEdit->text().mid(2, 4).toLongLong();
//        Student user = Student::find(id);
//        qDebug()<<"Student is received2";
//        if(user.isInDatabase(id) && passEdit->text()==user.getPassword()){
//            qDebug()<<"Student is received3";
//              this->setCentralWidget(dash); //student dashboard
//         }else{
//            errLbl->setText("Try again username or password is incorrect");
//            formlayout->insertRow(0,"       ",errLbl); //may increase the tab spacing
//            errLbl->show();
//            regLbl->setText("Regeister New User?");
//            regLbl->show();
//          }
//    }
}

void MainWindow::Signout(){
    loginWidget = new Login();
    delete studentDashboard;
//    delete adminDashboard;
    setWidget(loginWidget);
    connect(loginWidget, &Login::Register,this,&MainWindow::setSignupWidget);
    connect(loginWidget, &Login::LoginAcc, this, &MainWindow::login);
}

MainWindow::~MainWindow(){
}

