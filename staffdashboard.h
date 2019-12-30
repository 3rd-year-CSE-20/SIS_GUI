#ifndef STAFFDASHBOARD_H
#define STAFFDASHBOARD_H
#include <QFormLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QSize>
#include <QString>
#include <QPalette>
#include <QTabWidget>
#include "staffmember.h"
class StaffDashboard : public QWidget{
    Q_OBJECT


public:
    StaffDashboard(StaffMember *s,QWidget *parent = nullptr, bool fromAdmin = false);
    ~StaffDashboard();
    QFormLayout *formlayout1;
    QFormLayout *formlayout2;
    QVBoxLayout* mainLayout;
    QHBoxLayout* _mainLayout;
    QHBoxLayout *t1;
    QHBoxLayout *t2;
    QVBoxLayout * personalLayout;
    QVBoxLayout * academicLayout;
    QWidget *personalWidget;
    QWidget *academicWidget;
    QWidget *coursesWidget;
    QWidget *container;
    QTabWidget *tabWidget;
    QLabel *firstLabel;
    QLabel *lastLabel;
    QLabel *gendreLabel;
    QLabel *birthLabel;
    QLabel *idLabel;
    QLabel *degreelbl;
    QSize *size1;
    QString picPath;
    QPalette *pal;
    QFont *font1;
    QLabel* degreeLabel;
    QLabel* graduationyearLabel;
    QLabel* teachingcoursesLabel;
    QLabel* departmentLabel;


    QLabel *fnameDBlbl;
    QLabel *lnameDBlbl;
    QLabel *departDBlbl;
    QLabel *degreeDBlbl;
    QLabel *gendreDBlbl;
    QLabel *birthDBlbl;
    QLabel *idDBlbl;
    QLabel *piclbl1;
    QLabel *piclbl2;
    QLabel* graduationyearLabelfromDatabase;
    QLabel* teachingcoursesLabelfromDatabase;
    QPushButton *signout;
    StaffMember s;
    QPushButton *backBtn;
    QPushButton *deleteBtn;

    void onSignoutClicked();
    void onBackClicked();
    void onDeleteClicked();
signals:
   void Signout();
   void Back();
   void Delete();
};

#endif // STAFFDASHBOARD_H
