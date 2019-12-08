#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QRadioButton>

class Register : public QWidget{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    QVBoxLayout *mainVlayout;
    QHBoxLayout *mainHlayout;
    QFormLayout *subMain_R_FLayout;
    QFormLayout *subMain_L_FLayout;
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
};

#endif // REGISTER_H
