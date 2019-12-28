#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QSize>
#include <QString>
#include <QPalette>
#include <QFormLayout>
#include <QTableWidget>
#include "student.h"

class Dashboard : public QWidget
{
    Q_OBJECT


public:
    Dashboard(Student *s,QWidget *parent = nullptr);
    ~Dashboard();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *_mainLayout;
    QWidget *container;
    QTabWidget *tabWidget;
    QPushButton *backBtn;
    QWidget *personalInfo;
    QWidget *academicInfo;
    QVBoxLayout *personalInfoLayout;
    QVBoxLayout *academicInfoLayout;
    QLabel *pic;
    QLabel *pic2;
    QLabel *fnamelbl;
    QLabel *fnameDBlbl;
    QLabel *lnamelbl;
    QLabel *lnameDBlbl;
    QLabel *addrlbl;
    QLabel *addrDBlbl;
    QLabel *phonelbl;
    QLabel *phoneDBlbl;
    QLabel *gendlbl;
    QLabel *gendDBlbl;
    QLabel *birthlbl;
    QLabel *birthDBlbl;
    QLabel *gpalbl;
    QLabel *gpaDBlbl;
    QLabel *departlbl;
    QLabel *departDBlbl;
    QLabel *idlbl;
    QLabel *idDBlbl;
    QLabel *currentYlbl;
    QLabel *currentYDBlbl;
    QLabel *courseslbl;
    QLabel *coursesDBlbl;
    Student *s;

signals:
    void Signout();

private slots:
    void onSignoutClicked();

};

#endif // DASHBOARD_H
