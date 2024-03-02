#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include "Users.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class Loginwindow;
}
QT_END_NAMESPACE

class Loginwindow : public QMainWindow
{
    Q_OBJECT

public:
    Loginwindow(QWidget *parent = nullptr);
    ~Loginwindow();

private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButtonRegister_clicked();

private:
    Ui::Loginwindow *ui;
    QString name;
    QString password;
};
#endif // LOGINWINDOW_H
