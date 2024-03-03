#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include <QString>
#include <QDialog>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();
    bool check_username();
    bool check_retype();
    bool check_date();
    bool all_check();
    bool genere_check();
    QString name;
    QString password;
    QString retypepass;
    QString month;
    int day;
    int year;
    int age;

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegisterWindow *ui;


};

#endif // REGISTERWINDOW_H
