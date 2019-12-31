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
#include <QListWidget>
#include <QPalette>
#include <QTabWidget>
#include <QLineEdit>
#include <QAbstractItemView>
#include <QTableWidget>
#include "student.h"
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

    QLineEdit *editFirstNametxt;
    QLineEdit *editLastNametxt;
    QLineEdit *editBirthdatetxt;
    QPushButton *saveBtn;

    QWidget *coursesAssignWidget;
    QListWidget *coursesList;
    QVBoxLayout *coursesAssignWidgetLay;
    QPushButton *saveCourse;

    void onSignoutClicked();
    void onBackClicked();
    void onDeleteClicked();
    void onSaveClicked();
    void onSaveCoursesClicked();

signals:
   void Signout();
   void Back();
   void Delete();
};

#endif // STAFFDASHBOARD_H
