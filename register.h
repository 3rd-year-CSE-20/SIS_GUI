#ifndef REGISTER_H
#define REGISTER_H

#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QRadioButton>
#include <QFileDialog>
#include <QComboBox>
#include <QStringList>
#include "student.h"
#include "staffmember.h"

class Register : public QWidget{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr,bool fromAdmin = false, bool academic = false);
    ~Register();

private :
    QString path;
    QWidget *container;
    QWidget *_leftWidget;
    QWidget *_rightWidget;
    QHBoxLayout *_mainLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *_leftLayout;
    QVBoxLayout *_rightLayout;
    QLabel *pic;
    QLineEdit *firstNameTxt;
    QLineEdit *lastNameTxt;
    QLineEdit *birthDateTxt;
    QLineEdit *addressTxt;
    QLineEdit *mobileTxt;
    QCalendarWidget *birthDate;
    QWidget *genderGBox;
    QHBoxLayout *genderLayout;
    QRadioButton *maleRB;
    QRadioButton *femaleRB;
    QPushButton *browsePic;
    QPushButton *saveBtn;
    QPushButton *backBtn;
    QPushButton *generateID;
    QLineEdit *password;
    QLineEdit *rewritePassword;
    QLineEdit *studentID;
    QLabel *wrongPassword;
    QLabel *generatedID;
    QLabel *studentIdLbl;
    QLabel *deplbl;
    QComboBox *depCombo;
    bool fromAdmin;
    bool isAcademic;
//    QStringList departments;

signals :
    void back();
    void save();

private slots:
    void onBackClicked();
    void onSaveClicked();
    void onBrowseClicked();
    void ongenerateClicked();
    void onWritePassword(QString);
    void onPassword(QString);
};

#endif // REGISTER_H
