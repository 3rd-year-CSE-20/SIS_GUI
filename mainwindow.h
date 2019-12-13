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
#include <QtQuick/QQuickView>
#include <QFont>
#include <QRadioButton>
#include "dashboard.h"
#include "register.h"
#include "clickablelabel.h"
#include "sqliteclass.h"
#include "globalDbObject.h"
#include "admin.h"
#include "student.h"
#include "staffmember.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Dashboard *dash;
    Register *reg;
    SQLiteClass *db;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   QWidget *container;
   QPushButton *button1;
   QFormLayout *formlayout;
   QLineEdit *usrEdit;
   QLineEdit *passEdit;
   QLabel *usrLbl;
   QLabel *passLbl;
   ClickableLabel * regLbl;
    QLabel *errLbl;
    QRadioButton *adminRB;
    QRadioButton *staffMemberRB;
    QRadioButton *studentRB;
    QHBoxLayout *userLayout;
    QGroupBox *userWidget;
signals:
    void usrAvailable();
    void usrNotAvailable();
    void toggled(bool);

private slots:
   void onLoginPressed();
    void regNewUser();
    void checkAdminAvailability();
    void checkStaffAvailability();
    void checkStudentAvailability();


};
#endif // MAINWINDOW_H
