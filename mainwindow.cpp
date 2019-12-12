#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
        container = new QWidget(this);
        dash = new Dashboard(this);
        reg = new Register(this);
        regLbl = new ClickableLabel(this);
        regLbl->setStyleSheet("color:white");
        regLbl->setFont(QFont("Magma",11));
        QFont f = regLbl->font();
         f.setUnderline(true);
         regLbl->setFont(f);
         errLbl = new QLabel();
         errLbl->setFont(QFont("Magma",11));
         errLbl->setStyleSheet("color:red");

        container->setAutoFillBackground(0);
        this->setAutoFillBackground(0);

//        QPixmap bkgnd("E:\Projects\SIS_GUI\build-SIS_gui-Desktop_Qt_5_12_3_MinGW_64_bit-Debug\debug\wallpaper.png");
//        //bkgnd = bkgnd.scaledToHeight(this->height());
//        QPalette palette;
//        palette.setBrush(QPalette::Background, bkgnd);
//        this->setPalette(palette);
        userLayout = new QHBoxLayout();
        userWidget = new QGroupBox();
        adminRB = new QRadioButton("Admin");
        staffMemberRB = new QRadioButton("Staff Member");
        studentRB = new QRadioButton("Student");
        userLayout->addWidget(adminRB);
        userLayout->addWidget(staffMemberRB);
        userLayout->addWidget(studentRB);
        userWidget->setLayout(userLayout);

        button1 = new QPushButton("Login", this);
        button1->setFont(QFont("Magma",15,QFont::Bold));
        button1->setStyleSheet("background-color:white; border-radius: 15px;color:black "); //background-image: url( MIPS_Architecture_(Pipelined).svg.png)
        formlayout = new QFormLayout();
        usrLbl = new QLabel("Username",this);
        //usrLbl->setStyleSheet("color:white");
        usrLbl->setFont(QFont("Magma",15));

        passLbl = new QLabel("Password",this);
        passLbl->setFont(QFont("Magma",15));

        usrEdit = new QLineEdit();
        usrEdit->setMinimumSize(100,30);
        usrEdit->setFont(QFont("Magma",15,Qt::white));
        usrEdit->setStyleSheet("color:black;background:white");

        passEdit = new QLineEdit();
        passEdit->setMinimumSize(100,30);
        passEdit->setFont(QFont("Magma",15,Qt::white));
        passEdit->setEchoMode(QLineEdit::Password);
        passEdit->setStyleSheet("color:black; background-color:white; ");



        formlayout->addRow(usrLbl, usrEdit);
        formlayout->addRow(passLbl, passEdit);


        container->setLayout(formlayout);
        formlayout->setFormAlignment(Qt::AlignCenter);
        formlayout->setAlignment(Qt::AlignCenter);
        formlayout->setVerticalSpacing(30);
        formlayout->addWidget(userWidget);
        formlayout->addWidget(button1);
        formlayout->addWidget(regLbl);
        container->setStyleSheet("background-color:lightblue");
        this->setStyleSheet("background-position: center;background-repeat:no-repeats");
        this->setCentralWidget(container);

        //Connecting button to slot
        connect(button1,SIGNAL(clicked()),this,SLOT(onLoginPressed()));
        connect(button1,SIGNAL(clicked()),this,SLOT(checkAdminAvailability()));
        connect(button1,SIGNAL(clicked()),this,SLOT(checkStaffAvailability()));
        connect(button1,SIGNAL(clicked()),this,SLOT(checkStudentAvailability()));

        //Connecting clickable label to slot
        connect(regLbl,SIGNAL(clicked()),this,SLOT(regNewUser()));



        }
void MainWindow::onLoginPressed(){
    qDebug()<<"user name is : " << usrEdit->text();
    qDebug() <<"password is : " << passEdit->text();
    button1->setStyleSheet("background-color:black;color:white;border-radius:15px");

}
void MainWindow::checkAdminAvailability()
{

    if (usrEdit->text()[0]=='A' && adminRB->isChecked()) //Admin from radio button is selected
    {
        Admin userA;
     userA.setId(usrEdit->text().toLongLong());
     if(userA.getFirstName()=="")
     {
          qDebug()<<"Fisrtname is:"<<userA.getFirstName();
          errLbl->setText("Try again username or password is incorrect");
          formlayout->insertRow(0,"       ",errLbl); //may increase the tab spacing
          errLbl->show();
          regLbl->setText("Regeister New User?");
          regLbl->show();
     }

    //    this->setCentralWidget(dash); //admin dashboard


    }
        //send usrEdit->text() to adminTable in the database
        //if query is available in adminTable in the database
            //emit usrAvailable(); //maybe won't be used



        //else
        //emit usrNotAvailable(); //maybe won't be used
        //errLbl->setText("Try again username or password is incorrect");
        //formlayout->insertRow(0,"       ",errLbl); //may increase the tab spacing
        //errLbl->show();
        //regLbl->setText("Regeister New User?");
        //regLbl->show();


    //if (usrEdit->text()[0]=='S'&&staffMemberRB->isChecked())
   // {
     //   StaffMember userS;
        //send usrEdit->text() to staffTable in the database
        //if query is available in staffTable in the database
            //emit usrAvailable(); //maybe won't be used
            //this->setCentralWidget(dash); //staff dashboard
    //}
        //else
            //errLbl->setText("Try again username or password is incorrect");
             //formlayout->insertRow(0,"       ",errLbl); //may increase the tab spacing
            //errLbl->show();
            //regLbl->setText("Regeister New User?");
            //regLbl->show();
    //else
    Student user;
        //send usrEdit->text() to studentTable in the database
        //if query is available in studentTable in the database
            //emit usrAvailable(); //maybe won't be used
            //this->setCentralWidget(dash); //student dashboard

        //else
            //errLbl->setText("Try again username or password is incorrect");
            //formlayout->insertRow(0,"       ",errLbl); //may increase the tab spacing
            //errLbl->show();
            //regLbl->setText("Regeister New User?");
            //regLbl->show();



}
void MainWindow::checkStaffAvailability(){}
void MainWindow::checkStudentAvailability(){}
void MainWindow::regNewUser(){
    this->setCentralWidget(reg);
}

MainWindow::~MainWindow(){
}

