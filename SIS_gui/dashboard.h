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
class Dashboard : public QWidget
{
    Q_OBJECT


public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();
    QHBoxLayout* mainLayout;
    QVBoxLayout *personalLayout;
    QVBoxLayout *academicLayout;
    QLabel *firstLabel;
    QLabel *lastLabel;
    QLabel *gendreLabel;
    QLabel *addressLabel;
    QLabel *phoneLabel;
    QLabel *birthLabel;
    QLabel *idLabel;
    QLabel *picLabel;
    QPixmap *pic;
    QSize *size1;
    QString picPath;
    QPalette *pal;
    QFont *font1;
    QLabel *personalinfoLabel;
};

#endif // DASHBOARD_H
