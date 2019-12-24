#ifndef LOGIN_H
#define LOGIN_H

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


class Login : public QWidget{
//    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private :
    QWidget *container;
    QPushButton *button1;
    QWidget *_leftWidget;
    QWidget *_rightWidget;
    QLabel *img;
    QHBoxLayout *_mainLayout;
    QVBoxLayout *_leftLayout;
    QVBoxLayout *_rightLayout;
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

//signals :
//    void test();
};

#endif // LOGIN_H
