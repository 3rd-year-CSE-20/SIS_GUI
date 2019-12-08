#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include "dashboard.h"
#include "register.h"
#include "clickablelabel.h"
#include "sqliteclass.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Dashboard *dash;
    Register *reg;

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
signals:
    void usrAvailable();
    void usrNotAvailable();

private slots:
   void onLoginPressed();
    void regNewUser();
    void checkAvailability();


};
#endif // MAINWINDOW_H
