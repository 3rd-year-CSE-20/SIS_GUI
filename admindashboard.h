#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QRadioButton>

class AdminDashboard:public QWidget{
    Q_OBJECT
public:
    AdminDashboard(QWidget *parent = nullptr);
    ~AdminDashboard();

private:
    QWidget *container;
    QWidget *studentWidget;
    QWidget *academicWidget;
    QVBoxLayout *_mainLayout;
    QVBoxLayout *mainLayout;
    QVBoxLayout *studentLay;
    QVBoxLayout *academicLay;
    QTabWidget *tabWidget;
    QLineEdit *studentSearchtxt;
    QPushButton *searchStudentBtn;
    QPushButton *addStudentBtn;
    QTableWidget *StudentTable;
    QRadioButton *studentSearchByName;
    QRadioButton *studentSearchByID;
    QLineEdit *academicSearchtxt;
    QPushButton *searchAcademicBtn;
    QPushButton *addAcademicBtn;
    QTableWidget *academicTable;
    QPushButton *signout;

    void initStudentTable();
    void initAcademicTable();

private slots:
    void onSignoutClicked();
    void onaddStudentClicked();

signals:
    void Signout();
    void addStudent();

};

#endif // ADMINDASHBOARD_H
