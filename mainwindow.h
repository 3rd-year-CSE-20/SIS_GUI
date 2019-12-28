#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QDebug>
#include <QPalette>
#include <QPixmap>
#include <QFont>
#include <QSpacerItem>
#include "dashboard.h"
#include "register.h"
#include "clickablelabel.h"
#include "sqliteclass.h"
#include "globalDbObject.h"
#include "admin.h"
#include "student.h"
#include "staffmember.h"
#include "staffdashboard.h"
#include "login.h"
#include "admindashboard.h"
class MainWindow : public QMainWindow{
    Q_OBJECT
private:
    Login *loginWidget;
    Register *regWidget;
    Dashboard *studentDashboard;
    StaffDashboard *staffDashboard;
    AdminDashboard *adminDashboard;
    QWidget *main;
    QWidget *_main;
    QVBoxLayout *mainLayout;
    QHBoxLayout *_mainLayout;
    QSpacerItem *s1;
    void loadStyles();
    void checkStudentAvailability();

public:
    MainWindow(QWidget *parent = nullptr);
    void setWidget(QWidget *);
    ~MainWindow();

private slots:
    void setSignupWidget();
    void setLoginWidget();
    void login(QString,QString);
    void Signout();
    void adminSignout();
    void adminAddStudent();
    void adminDash();
};
#endif // MAINWINDOW_H
