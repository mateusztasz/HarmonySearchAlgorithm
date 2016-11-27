#include "add_eqn.h"
#include "ui_add_eqn.h"

#include "Lepton.h"
using namespace std;
Add_Eqn::Add_Eqn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Eqn)
{
    ui->setupUi(this);
    Mbox = new QMessageBox();

}

Add_Eqn::~Add_Eqn()
{
    delete ui;
}
#include <string.h>
#include <map>
void Add_Eqn::on_OK_Button_clicked()
{
    // kliknieto OK

    QString name = ui->Fcn_name->text();
    QString formula = ui->Fcn_Formula->text();

    bool error = false;
    Lepton::CompiledExpression expression;
    try{
        std::map<string, double> constants;
        constants["pi"] = M_PI;
        constants["e"] = M_E;
        expression  = Lepton::Parser::parse(ui->Fcn_Formula->text().toStdString()).optimize(constants).createCompiledExpression();

    }
    catch(...){
        error =true;
    }


    if(name == ""){
        Mbox->warning(0,"Error","Function's name is not declared!");
        return;
    }
    else if(formula == ""  ){
        Mbox->warning(0,"Error","Function's formula is not declared!");
        return;
    }
    else if(error  ){
        Mbox->warning(0,"Error","The parsing error has occured!\n\nCheck the syntax of objective function.");
        return;
    }
    else if(expression.getVariables().size() == 0 ){
        Mbox->warning(0,"Error","The constant function cannot be optimized!");
        return;
    }

    ui->Fcn_name->clear();
    ui->Fcn_Formula->clear();

    emit send(name, formula);

    ui->Fcn_name->setEchoMode(QLineEdit::Normal);
    ui->Fcn_Formula->setEchoMode(QLineEdit::Normal);
    this->close();

}

void Add_Eqn::on_buttonBox_rejected_clicked()
{
    ui->Fcn_name->clear();
    ui->Fcn_Formula->clear();
    ui->Fcn_name->setEchoMode(QLineEdit::Normal);
    ui->Fcn_Formula->setEchoMode(QLineEdit::Normal);
    this->close();
}
