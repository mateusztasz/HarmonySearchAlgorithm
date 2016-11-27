#ifndef ADD_EQN_H
#define ADD_EQN_H

#include <QDialog>
#include <QMessageBox>
#define M_E        2.71828182845904523536
class MainWindow;

namespace Ui {
class Add_Eqn;
}

class Add_Eqn : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Eqn(QWidget *parent = 0);
    ~Add_Eqn();

private slots:

    //    void on_buttonBox_rejected();
    void on_OK_Button_clicked();

    void on_buttonBox_rejected_clicked();

private:
    Ui::Add_Eqn *ui;
    QMessageBox *Mbox;



signals:
    void send( QString , QString );
};

#endif // ADD_EQN_H
