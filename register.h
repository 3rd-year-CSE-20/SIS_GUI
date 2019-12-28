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

class Register : public QWidget{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

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

signals :
    void back();
    void save();

private slots:
    void onBackClicked();
    void onSaveClicked();
    void onBrowseClicked();
};

#endif // REGISTER_H
