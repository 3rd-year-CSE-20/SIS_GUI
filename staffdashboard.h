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
class StaffDashboard : public QWidget{
    Q_OBJECT


public:
    explicit StaffDashboard(QWidget *parent = nullptr);
    ~StaffDashboard();
    QFormLayout *formlayout;
    QHBoxLayout* mainLayout;
    QVBoxLayout * personalLayout;
    QVBoxLayout * academicLayout;
    QLabel *firstLabel;
    QLabel *lastLabel;
    QLabel *gendreLabel;
    QLabel *birthLabel;
    QLabel *idLabel;
    QLabel *picLabel;
    QPixmap *pic;
    QSize *size1;
    QString picPath;
    QPalette *pal;
    QFont *font1;
    QLabel* personalinfoLabel;
    QLabel* academicinfoLabel;
    QLabel* degreeLabel;
    QLabel* graduationyearLabel;
    QLabel* teachingcoursesLabel;
    QLabel* departmentLabel;


    QLabel *firstLabelfromDatabase;
    QLabel *lastLabelfromDatabase;
    QLabel *gendreLabelfromDatabase;
    QLabel *birthLabelfromDatabase;
    QLabel *idLabelfromDatabase;
    QLabel *picLabelfromDatabase;
    QLabel* degreeLabelfromDatabase;
    QLabel* graduationyearLabelfromDatabase;
    QLabel* teachingcoursesLabelfromDatabase;
    QLabel* departmentfromDatabase;

};

#endif // STAFFDASHBOARD_H
