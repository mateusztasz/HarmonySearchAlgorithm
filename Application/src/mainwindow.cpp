#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleSpinBox>

using namespace std;
using namespace Lepton;

bool Before_Problem = true;

class My: public QWidget {
public:
    QTableWidgetItem *name;
    QDoubleSpinBox *Low;
    QDoubleSpinBox *Up;
    My();
};

My::My(){
    Low = new QDoubleSpinBox();
    Up = new QDoubleSpinBox();
    QLocale curLocale(QLocale("C"));
    Low->setLocale(curLocale);
    Low->setMinimum(-1000.00);
    Low->setMaximum(1000.00);
    Low->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Up->setLocale(curLocale);
    Up->setMinimum(-1000.00);
    Up->setMaximum(1000.00);
    Up->setButtonSymbols(QAbstractSpinBox::NoButtons);
    name = new QTableWidgetItem("<   x    <");
    name->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

#include <QMovie>

#include <QDeclarativeView>
#include <QtQuick/QQuickView>
#include <QProgressBar>
#include "add_eqn.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);



    QRect scr = QApplication::desktop()->screenGeometry();
    this->move( scr.center() - this->rect().center() );

    //===============================================
    //==========WELCOME PAGE=========================

    //Put a welcome page widget on the mainwindow
    welcome_page = new QWidget(this);
    welcome_page->setStyleSheet("background-color:gray;");
    welcome_page->setGeometry(0,0,this->width(),this->height());

    //Add button to provide sliding the welcome page down on the main window
    button_SlideOut_WelocomePage = new QPushButton(welcome_page);
    button_SlideOut_WelocomePage->hide();

    //Add Logo
    logo_ForWelcomePage = new QLabel(welcome_page);
    pixmap_ForWelcomePage = new QPixmap(":/photos/icon.ico");
    //Central the logo
    logo_ForWelcomePage->setPixmap(*pixmap_ForWelcomePage);
    logo_ForWelcomePage->setGeometry(welcome_page->width()/2 - 64, -128,welcome_page->width(),welcome_page->height());
    logo_ForWelcomePage->setPixmap(pixmap_ForWelcomePage->scaled(welcome_page->width()/4,welcome_page->height()/4,Qt::KeepAspectRatio, Qt::SmoothTransformation));




    //Add Button HS Standard
    int button_size = 0.1*min(welcome_page->width(),welcome_page->height());
    HS_Standard_ForWelcomePage = new QPushButton(welcome_page);
    HS_Standard_ForWelcomePage->setText("Go to Algorithm");
    HS_Standard_ForWelcomePage->setObjectName("HS_Standard_ForWelcomePage");
    HS_Standard_ForWelcomePage->setStyleSheet("QPushButton#HS_Standard_ForWelcomePage{ \
                                              background-color: #FF3333 ;   \
            border-style: outset;   \
    border-width: 2px;  \
    border-radius: 10px;\
    border-color: beige;\
font: bold 14px;\
    min-width: 10em;\
padding: 6px;\
width:100px;\
height:30px;\
color: white;} \
QPushButton#HS_Standard_ForWelcomePage:hover{\
                                           background-color: #CC0033}");

  HS_Standard_ForWelcomePage->setGeometry(welcome_page->width()/2 - HS_Standard_ForWelcomePage->frameGeometry().width(), 0.6*welcome_page->height(),100,button_size);


//Add Button Documentation
Documentation_For_WelcomePage = new QPushButton(welcome_page);
Documentation_For_WelcomePage->setText("Documentation");

Documentation_For_WelcomePage->setObjectName("Documentation_For_WelcomePage");
Documentation_For_WelcomePage->setStyleSheet("QPushButton#Documentation_For_WelcomePage{ \
                                             background-color: #FF3333 ;   \
border-style: outset;   \
border-width: 2px;  \
border-radius: 10px;\
border-color: beige;\
font: bold 14px;\
min-width: 10em;\
padding: 6px;\
width:100px;\
height:30px;\
color: white;} \
QPushButton#Documentation_For_WelcomePage:hover{\
                                              background-color: #CC0033}");

  Documentation_For_WelcomePage->setGeometry(welcome_page->width()/2 - Documentation_For_WelcomePage->frameGeometry().width(), 0.8*welcome_page->height(),100,button_size);

QObject::connect(Documentation_For_WelcomePage,SIGNAL(clicked()),this,SLOT(mySlot_Documentation_For_WelcomePage_Clicked()));


//Add Authors
Authors_For_WelcomePage = new QPushButton(welcome_page);
Authors_For_WelcomePage->setObjectName("Authors_For_WelcomePage");
Authors_For_WelcomePage->setGeometry(
        welcome_page->width()*0.75,
        welcome_page->height()*0.8,
        welcome_page->width()*0.25,
        welcome_page->height()*0.2);
Authors_For_WelcomePage->setText("Authors: \nDaria Nowicka, Mateusz Tasz \nEmbedded Robotics \nWrocław University of Technology, 2016");
QObject::connect(Authors_For_WelcomePage,SIGNAL(clicked()),this,SLOT(mySlot_Authors_For_WelcomePage_Clicked()));
Authors_For_WelcomePage->setStyleSheet("QPushButton#Authors_For_WelcomePage:hover {\
                                       background-color: #5f5f5f}");


Text_For_WelcomePage = new QLabel(welcome_page);
Text_For_WelcomePage->setAlignment(Qt::AlignTop | Qt::AlignLeft);
Text_For_WelcomePage->setContentsMargins(0,0,0,0);
Text_For_WelcomePage->setSizePolicy(QSizePolicy::MinimumExpanding,
                                    QSizePolicy::MinimumExpanding);
Text_For_WelcomePage->setText("Hello to Harmony Search Application.<br/> \
                              Choose the action.");
                              Text_For_WelcomePage->setStyleSheet("color: white; font-family:Josefin Slab; font-size: 30px;");
Text_For_WelcomePage->adjustSize();
Text_For_WelcomePage->setGeometry(welcome_page->width()/2 -Text_For_WelcomePage->width()/2,
                                  welcome_page->height()*0.4  ,
                                  Text_For_WelcomePage->width(),
                                  Text_For_WelcomePage->height() );




//Connect clicking action with specialized slot
QObject::connect(HS_Standard_ForWelcomePage,SIGNAL(clicked()),this,SLOT(mySlot_HS_Standard_ForWelcomePage_Clicked()));


ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

//===============================================
//==========GENERAL SETTINGS=====================

//Define title and logo of application
this->setWindowTitle("Harmony Search Algorithm Application");
this->setWindowIcon(QIcon("://icon.ico"));


ui->progressBar->setTextVisible(false);


//===============================================
//==========LOADING GIF=====================
/*
    loadingGif_ForWelcomePage = new QMovie(":/photos/loading.gif");

    loadingGif_canva_ForWelcomePage = new QLabel(this);
    loadingGif_canva_ForWelcomePage->setGeometry(width()/2 - 60,height()/2 -120,width()/2,height()/2);
    loadingGif_canva_ForWelcomePage->setMovie(loadingGif_ForWelcomePage);

    loadingGif_canva_ForWelcomePage->setVisible(false);
    loadingGif_ForWelcomePage->start();

*/
//==============================================
//============ PROGRESS BAR =====================

ui->progressBar->setMinimum(0);
ui->progressBar->setMaximum(100);
ui->progressBar->setValue(0);

State_of_welcomePage = SHOWED;

//===============================================
//=============MAIN SETTINGS FOR MAINWINDOW=======

eqn = "";
HMS = 5;
PAR = 0.35;
HMCR = 0.9;
repeat = 5000;
bandwidth = 0.15;

isProblemInitialized = false;

ui->ChooseEquationComboBox->addItem("--- choose a function ---");
int row = ui->ChooseEquationComboBox->findText("--- choose a function ---");
qobject_cast<QStandardItemModel *>(ui->ChooseEquationComboBox->model())->item( row )->setEnabled( false );
map_of_equations["Rosenbrock"] = "100*(x2-x1)^2+(1-x1)^2";
//map_of_equations["Goldenstein-Price"] = "(1+(x1+x2+1)^2*(19-14*x1+3*x1^2-14*x2+6*x1*x2+3*x2^2))*(30+(2*x1-3*x2)^2*(18-32*x1+12*x1^2+48*x2-36*x1*x2+27*x2^2))";
map_of_equations["Eggholder function"] = "-(y+47)*sin(sqrt(abs(x/2+(y+47))))-x*sin(sqrt(abs(x-(y+47))))";
map_of_equations["Himmelblau's function"] = "(x^2+y-11)^2+(x+y^2-7)^2";
map_of_equations["Beale's function"] = "(1.5-x+x*y)^2+(2.25-x+x*y^2)^2+(2.625-x+x*y^3)^2";
//map_of_equations["test function"] = "(x1-2)^2+(x1-x2^2)^2";
map_of_equations["Geem's function"] = "4*x1^2-2.1*x1^4+1/3*x1^6+x1*x2-4*x2^2+4*x2^4";
map_of_equations["Ackley's second-order function"] = "-20*exp(-0.2*sqrt(1/2)*(x^2+y^2))-exp(0.5*(cos(2*pi*x)+cos(2*pi*y)))";
map_of_equations["Rastrigin's second-order function"] = "(x^2-cos(18*x))+(y^2-cos(18*y))";

QMapIterator<string, string> iter(map_of_equations);
while (iter.hasNext()) {
    iter.next();
    ui->ChooseEquationComboBox->addItem(QString::fromStdString(iter.key()));
}
ui->Eqn_LineEdit->setEnabled(false);
AddEqnWindow = new Add_Eqn(this);
connect( AddEqnWindow, SIGNAL(send(QString,QString)), this, SLOT(receiver(QString,QString)) );

ui->HMS_LineEdit->setText(QString::number(HMS));
ui->PAR_SpinBox->setValue(PAR);
ui->HMCR_SpinBox->setValue(HMCR);
ui->Repeat_LineEdit->setText(QString::number(repeat));
ui->b_doubleSpinBox->setValue(bandwidth);

ui->HMS_LineEdit->setValidator(new QIntValidator(1, 500, this));
ui->Repeat_LineEdit->setValidator(new QIntValidator(1, 100000000, this));

QLocale curLocale(QLocale("C"));
ui->PAR_SpinBox->setLocale(curLocale);
ui->PAR_SpinBox->setMinimum(0.00);
ui->PAR_SpinBox->setMaximum(1.00);
ui->PAR_SpinBox->setSingleStep(0.01);
ui->HMCR_SpinBox->setLocale(curLocale);
ui->HMCR_SpinBox->setMinimum(0.00);
ui->HMCR_SpinBox->setMaximum(1.00);
ui->HMCR_SpinBox->setSingleStep(0.01);
ui->b_doubleSpinBox->setLocale(curLocale);
ui->b_doubleSpinBox->setMinimum(0.00);
ui->b_doubleSpinBox->setMaximum(1.00);
ui->b_doubleSpinBox->setSingleStep(0.01);


ui->DisplaySolution->setReadOnly(true);

// Sekundnik, czyli Timer liczacy po sekundzie :)
Seconds_counter = new QTimer(this);

//==============================================
//============ CHECK BOX TO WRITE TO FILE =====================
ui->PDF_CheckBox->setChecked(true);


State_of_Computation = IDLE;


}


MainWindow::~MainWindow(){
    delete ui;
}


int DefineProblemSize_dependingOnEquation(string &eqn){

    std::map<string, double> constants;
    constants["pi"] = M_PI;
    constants["e"] = M_E;
    MyLepton Lep;
    Lep.expression = Lep.P.parse(eqn).optimize(constants).createCompiledExpression();
    Lep.namesOfVariables = Lep.expression.getVariables();

    return Lep.namesOfVariables.size();

}

void MainWindow::mySlot_Authors_For_WelcomePage_Clicked(){
    MessageBox = new QMessageBox();
    MessageBox->about(0,"Authors","<p style=\"line-height: 0.7cm\" > <font size='4' face=\"Josefin slab\"> To get more information, please contact directly to:<br> </font>\
                      </p>Daria Nowicka: <  font color=\"#428bca\"> nowickadaria1@gmail.com <br> </font> \
            Mateusz Tasz: <font color=\"#428bca\"> mateusz.tasz@gmail.com </font> ");

    MessageBox->setModal(false);
}


#include <QFileInfo>
void MainWindow::mySlot_Documentation_For_WelcomePage_Clicked(){

    QUrl url =  QUrl::fromLocalFile(QFileInfo("./bin/Qt_App/harmony_search_raport.pdf").absoluteFilePath());
    QDesktopServices::openUrl(url);

    QUrl url2 =  QUrl::fromLocalFile(QFileInfo("./harmony_search_raport.pdf").absoluteFilePath());
    QDesktopServices::openUrl(url2);
    //QDesktopServices::openUrl(QUrl("file://$$PWD/Application/resources/pdf/Lepton_User_Manual.pdf", QUrl::TolerantMode));
    //QDesktopServices::openUrl(QUrl("file:///C:/Users/Mateusz/Dropbox/HarmonySearchAlgorithm/prj/Application/resources/pdf/Lepton_User_Manual.pdf", QUrl::TolerantMode));
    //QDesktopServices::openUrl(QUrl("http://jestemlosiem.ddns.net/blog.php"));
}


void MainWindow::Update_Progress_Bar(){
    int Progress = ( (Problem->ReturnProgress()+1)*100)/repeat;
    ui->progressBar->setValue(Progress);
}

void MainWindow::on_ComputeButton_clicked(){

    if(isProblemInitialized){


        if(State_of_Computation == IDLE) {
            State_of_Computation = WORKING;
            ui->ComputeButton->setText("STOP");
            ui->HMS_LineEdit->setDisabled(true);
            ui->PAR_SpinBox->setDisabled(true);
            ui->b_doubleSpinBox->setDisabled(true);
            ui->HMCR_SpinBox->setDisabled(true);
            ui->Repeat_LineEdit->setDisabled(true);
            ui->tableWidget->setDisabled(true);
            ui->AddFunctionButton->setDisabled(true);
            ui->ChooseEquationComboBox->setDisabled(true);
            Problem->_algorithm_stop = false;

            //Show loading gif
            //loadingGif_canva_ForWelcomePage->setVisible(true);

            Problem->InitHarmonyMemory();

            Problem->PrintHarmonyMemory();

            connect(Seconds_counter, SIGNAL(timeout()), this, SLOT(Update_Progress_Bar()));

            Seconds_counter->start(1);

            /************************************************************************/
            /* jezeli zaznaczono, zeby zapisac do pliku, to zapisz */
            if(ui->PDF_CheckBox->isChecked()){
                //    cout << "Zaznaczono, zeby zapisywac\n";
                Problem->write_to_text_file = true;
            }
            else{
                //      cout <<"Nie bede zapisywac\n";
                Problem->write_to_text_file = false;
            }
            /************************************************************************/

            bool ok = Problem->Search();
            Seconds_counter->stop();
            if(ok) ui->progressBar->setValue(100);


            //  disconnect(Seconds_counter, SIGNAL(timeout()), this, SLOT(Update_Progress_Bar()));

            Problem->PrintHarmonyMemory();

            /* HERE PRINT THE SOLUTION */

            ui->DisplaySolution->clear();
            QString s;

            s.push_back(" The optimal value is: f(x) = ");
            s.push_back("<b><font color=\"#428bca\">"+QString::number(Problem->ReturnBestSolution().GetValue())+"</font></b>");
            s.push_back("<br>and the optimal values of variables are:<br>");
            int ind=0;
            for(string it:Problem->Lep.namesOfVariables){
                s.push_back(QString::fromStdString(it));
                s.push_back(" = <font color=\"#428bca\"> ");
                s.push_back(QString::number( Problem->ReturnBestSolution().GetVarX_of(ind) ) );
                if(ind < Problem->Lep.namesOfVariables.size() - 1 ){
                    s.push_back("</font><br>");
                }
                ind++;
            }
            ui->DisplaySolution->append(s);
            ui->DisplaySolution->setStyleSheet("font-family: CMU Bright");

            ui->DisplaySolution->setHtml(s);


            //Hide loading gif
            //loadingGif_canva_ForWelcomePage->setVisible(false);
        }

        if(State_of_Computation == WORKING) {
            State_of_Computation = IDLE;
            ui->ComputeButton->setText("COMPUTE");
            ui->HMS_LineEdit->setDisabled(false);
            ui->PAR_SpinBox->setDisabled(false);
            ui->b_doubleSpinBox->setDisabled(false);
            ui->HMCR_SpinBox->setDisabled(false);
            ui->Repeat_LineEdit->setDisabled(false);
            ui->tableWidget->setDisabled(false);
            ui->ChooseEquationComboBox->setDisabled(false);
            ui->AddFunctionButton->setDisabled(false);
            Problem->_algorithm_stop = true;
        }

    }
    else {
        MessageBox = new QMessageBox();
        MessageBox->warning(0,"Error","The optimization problem hasn't been initialized!\n\nChoose or define the objective function.");
    }


}


void MainWindow::on_Repeat_LineEdit_textEdited(const QString &arg1){
    repeat = arg1.toInt();
    if(isProblemInitialized){
        this->AfterParameterChanged();
    }
    else cout<<"Error: Problem is not initialized."<<endl;
}


void MainWindow::on_HMCR_SpinBox_valueChanged(double arg1)
{
    HMCR = arg1;
    if(isProblemInitialized){
        this->AfterParameterChanged();
    }
    else cout<<"Error: Problem is not initialized."<<endl;
}


void MainWindow::on_PAR_SpinBox_valueChanged(double arg1)
{
    PAR = arg1;
    if(isProblemInitialized){
        this->AfterParameterChanged();
    }
    else cout<<"Error: Problem is not initialized."<<endl;
}

void MainWindow::on_HMS_LineEdit_textEdited(const QString &arg1){
    HMS = arg1.toInt();
    if(isProblemInitialized){

        this->AfterParameterChanged();
    }
    else cout<<"Error: Problem is not initialized."<<endl;
}


void MainWindow::AfterParameterChanged(){

    this->WindowVarLimits = Problem->VariableLimits;
    ui->progressBar->reset();

    Problem = new Optimization_Problem();
    //  eqn = ui->ChooseEquationComboBox->currentText().toStdString();
    QMap<string, string>::iterator iter2 = map_of_equations.find(ui->ChooseEquationComboBox->currentText().toStdString());
    eqn = iter2.value();

    problem_size = DefineProblemSize_dependingOnEquation(eqn);
    Problem->SetEquation(eqn);
    //    ui->ProblemSizeLCD->display(problem_size);

    Problem->Initialize(HMS,PAR,problem_size,HMCR,repeat,bandwidth);
    Problem->SetEquation(eqn);

    Problem->VariableLimits = this->WindowVarLimits;
    Problem->InitHarmonyMemory();

    this->CreateTableForLimits();
}



void MainWindow::handleQLineEdit_ForVarLimits_hasChanged(QString input ) {

    //Cut the input to obtain the number of row and column in the tablewidget
    int col = input.mid(0,1).toInt();
    int row = input.mid(2).toInt();

    //Cast the cell from table widget  to QLineEdit
    QWidget *CellWidget = ui->tableWidget->cellWidget(row,col);
    //  QLineEdit* Member = qobject_cast<QLineEdit*>(CellWidget);
    QDoubleSpinBox* Member = qobject_cast<QDoubleSpinBox*>(CellWidget);

    /***************************************************************/
    // skoro uzywamy SpinBox, zmienna bool isNumber chyba jest juz niepotrzebna, prawda?
    //TAK
    /****************************************************************/

    //Take the value of the table cell
    double value = Member->value();

    //Get name of variable
    std::set<string>::iterator it = Problem->Lep.namesOfVariables.begin();
    std::advance(it, row);
    string var_of_row = *it;

    //col = 0 means the left one, so the min value of variable
    if(col == 0){
        Problem->SetVariableLimitLow(var_of_row,value);
    }
    //col = 2 means the right one, so the max value of variable
    else if(col == 2){
        Problem->SetVariableLimitUpper(var_of_row,value);
    }
}


void MainWindow::CreateTableForLimits(){
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);

    QSignalMapper *mapper = new QSignalMapper(this) ;
    ui->tableWidget->horizontalHeader()->setEnabled(false);

    int height = (ui->tableWidget->height() - ui->tableWidget->horizontalHeader()->height() - 5)/Problem->Lep.namesOfVariables.size();
    if(height<15) height = 15;

    int index = 0;
    for(string it:Problem->Lep.namesOfVariables){

        ui->tableWidget->setRowCount( ui->tableWidget->rowCount()+1 );
        My *my = new My();

        double low=0,up=0;

        Problem->VariableLimits[index].Get(low,up);

        my->name->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        my->Low->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        my->Up->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);



        //        my->Low->setText(QString::number(low));
        my->Low->setValue(low);
        //        my->Up->setText(QString::number(up));
        my->Up->setValue(up);
        my->name->setText(QString::fromStdString(it));

        ui->tableWidget->setCellWidget(index,0,my->Low);
        ui->tableWidget->setItem(index,1,my->name);
        ui->tableWidget->setCellWidget(index,2,my->Up);

        ui->tableWidget->setRowHeight(index,height);

        //        connect(my->Low, SIGNAL(textChanged(QString )), mapper, SLOT(map()));
        //        connect(my->Up, SIGNAL(textChanged( QString)), mapper, SLOT(map()));
        connect(my->Low, SIGNAL(valueChanged(double)), mapper, SLOT(map()));
        connect(my->Up,  SIGNAL(valueChanged(double)), mapper, SLOT(map()));


        QString L = "0_"+QString::number(index);
        QString U = "2_"+QString::number(index);
        mapper->setMapping( my->Low, L ) ;
        mapper->setMapping( my->Up, U ) ;

        index++;
    }

    connect( mapper, SIGNAL(mapped(QString)), this, SLOT(handleQLineEdit_ForVarLimits_hasChanged(QString)) ) ;


    if( ui->tableWidget->verticalHeader()->isVisible() ){
        int v = ui->tableWidget->verticalHeader()->width();
        ui->tableWidget->setColumnWidth(0,(ui->tableWidget->width()-v)/3 - 10);
        ui->tableWidget->setColumnWidth(1,(ui->tableWidget->width()-v)/3 - 10);
        ui->tableWidget->setColumnWidth(2,(ui->tableWidget->width()-v)/3 - 10);
    }
    else{
        ui->tableWidget->setColumnWidth(0,ui->tableWidget->width()/3 - 5);
        ui->tableWidget->setColumnWidth(1,ui->tableWidget->width()/3 - 5);
        ui->tableWidget->setColumnWidth(2,ui->tableWidget->width()/3 - 5);
    }


    ui->tableWidget->setShowGrid( true );
    ui->tableWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
    ui->tableWidget->verticalHeader()->hide();

    QStringList list;
    list << "Min" << "Name" << "Max";
    ui->tableWidget->setHorizontalHeaderLabels( list );

}

void MainWindow::Recomputate_Stylesheet(){
    QFile file(":/qss/qss/stylesheet.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);
}

void createe();

void MainWindow::mySlot_HS_Standard_ForWelcomePage_Clicked(){
    //   createe();
    State_of_welcomePage = RUNNING;
    QRect begin_pos = QRect();

    begin_pos.setX(welcome_page->x());
    begin_pos.setY(welcome_page->y());
    begin_pos.setHeight(welcome_page->height());
    begin_pos.setWidth(welcome_page->width());
    QRect end_pos = QRect();

    end_pos.setX(welcome_page->x() );
    end_pos.setY(welcome_page->y() );
    end_pos.setHeight(30);
    end_pos.setWidth(welcome_page->width());

    animation_ForWelcomePage = new QPropertyAnimation(welcome_page,"geometry");
    animation_ForWelcomePage->setEasingCurve(QEasingCurve::InOutQuart);
    animation_ForWelcomePage->setLoopCount(1);
    animation_ForWelcomePage->setDuration( 1000 );
    animation_ForWelcomePage->setStartValue( begin_pos );
    animation_ForWelcomePage->setEndValue( end_pos );
    animation_ForWelcomePage->start(QPropertyAnimation::DeleteWhenStopped);

    connect(animation_ForWelcomePage,SIGNAL(finished()),this,SLOT(ForWelcomePage_AnimationEnded()));
}



void MainWindow::button_SlideOut_WelocomePage_on_clicked(){
    State_of_welcomePage = RUNNING;
    button_SlideOut_WelocomePage->hide();

    QRect end_pos = QRect();

    welcome_page->setGeometry(0,0,this->width(),this->height());
    end_pos.setX(welcome_page->x());
    end_pos.setY(welcome_page->y());
    end_pos.setHeight(welcome_page->height());
    end_pos.setWidth(welcome_page->width());
    QRect begin_pos = QRect();

    begin_pos.setX(welcome_page->x() );
    begin_pos.setY(welcome_page->y() );
    begin_pos.setHeight(30);
    begin_pos.setWidth(welcome_page->width());

    animation_ForWelcomePage = new QPropertyAnimation(welcome_page,"geometry");
    animation_ForWelcomePage->setDuration( 1000 );
    animation_ForWelcomePage->setEasingCurve(QEasingCurve::InOutQuart);
    animation_ForWelcomePage->setLoopCount(1);
    animation_ForWelcomePage->setStartValue( begin_pos );
    animation_ForWelcomePage->setEndValue( end_pos );
    animation_ForWelcomePage->start(QPropertyAnimation::DeleteWhenStopped);

    connect(animation_ForWelcomePage,SIGNAL(finished()),this,SLOT(ForWelcomePage_AnimationEnded()));
}

void MainWindow::ForWelcomePage_AnimationEnded(){

    if(welcome_page->height() == 30){
        State_of_welcomePage = HIDDEN;
        button_SlideOut_WelocomePage = new QPushButton(welcome_page);
        button_SlideOut_WelocomePage->setIcon(QIcon(":/photos/scroll_down.png"));
        button_SlideOut_WelocomePage->setIconSize(QSize(32, 32));
        button_SlideOut_WelocomePage->setGeometry(welcome_page->x(),welcome_page->y(),welcome_page->width(),welcome_page->height());
        button_SlideOut_WelocomePage->setStyleSheet("background-color:gray;border:none;");
        button_SlideOut_WelocomePage->show();

        connect(button_SlideOut_WelocomePage ,SIGNAL(clicked()),this,SLOT(button_SlideOut_WelocomePage_on_clicked()));
    }
    else State_of_welcomePage = SHOWED;
}
#include <QScrollBar>

void MainWindow::paintEvent(QPaintEvent *)
{
    //cout<<this->width()<<"x"<<this->height()<<endl;
    //ui->tableWidget->clearSelection();

    //loadingGif_canva_ForWelcomePage->setGeometry(width()/2 - 60,height()/2 -120,width()/2,height()/2);

    if(State_of_welcomePage == SHOWED){
        welcome_page->setGeometry(0,0,this->width(),this->height());
        button_SlideOut_WelocomePage->setGeometry(welcome_page->x(),welcome_page->y(),welcome_page->width(),30);

        int button_size = 0.1*min(welcome_page->width(),welcome_page->height());
        HS_Standard_ForWelcomePage->setGeometry(welcome_page->width()/2 - HS_Standard_ForWelcomePage->sizeHint().width()/2, 0.6*welcome_page->height(),HS_Standard_ForWelcomePage->sizeHint().width(),button_size);
        Documentation_For_WelcomePage->setGeometry(welcome_page->width()/2 - Documentation_For_WelcomePage->sizeHint().width()/2, 0.8*welcome_page->height(),Documentation_For_WelcomePage->sizeHint().width(),button_size);

        logo_ForWelcomePage->setGeometry(welcome_page->width()/2 - 64, -welcome_page->height()/4,welcome_page->width(),welcome_page->height());

        Text_For_WelcomePage->setGeometry(welcome_page->width()/2 -Text_For_WelcomePage->width()/2,
                                          welcome_page->height()*0.4  ,
                                          Text_For_WelcomePage->width(),
                                          Text_For_WelcomePage->height() );

        Authors_For_WelcomePage->setGeometry(
                    welcome_page->width()*0.7,
                    welcome_page->height()*0.85,
                    welcome_page->width()*0.3,
                    welcome_page->height()*0.15);
    }

    if(State_of_welcomePage == HIDDEN){
        welcome_page->setGeometry(0,0,this->width(),30);
        button_SlideOut_WelocomePage->setGeometry(welcome_page->x(),welcome_page->y(),welcome_page->width(),30);

        int height= 1;
        //cout<<"Roz "<<Problem->Lep.namesOfVariables.size()<<endl;
        // cout<<"Hea "<<ui->tableWidget->horizontalHeader()->height()<<endl;
        if(!Before_Problem){
            height = (ui->tableWidget->height() - ui->tableWidget->horizontalHeader()->height() - 5)/Problem->Lep.namesOfVariables.size();
            if(height<15) height = 15;


            //if(!ok) height = 15;
            for(int i = 0; i<Problem->Lep.namesOfVariables.size();++i){
                ui->tableWidget->setRowHeight(i,height);
            }
        }

        if( ui->tableWidget->verticalScrollBar()->isVisible() ){
            const int v = ui->tableWidget->verticalScrollBar()->width();
            ui->tableWidget->setColumnWidth(0,(ui->tableWidget->width()-v-5)/3 );
            ui->tableWidget->setColumnWidth(1,(ui->tableWidget->width()-v-5)/3 );
            ui->tableWidget->setColumnWidth(2,(ui->tableWidget->width()-v-5)/3 );
        }
        else{
            ui->tableWidget->setColumnWidth(0,(ui->tableWidget->width()-5)/3 );
            ui->tableWidget->setColumnWidth(1,(ui->tableWidget->width()-5)/3 );
            ui->tableWidget->setColumnWidth(2,(ui->tableWidget->width()-5)/3 );
        }

    }
    if(State_of_welcomePage == RUNNING){

    }


}


#include <QtWidgets>
#include <QtGui>


void createe()
{
    QString a_strFileName = "./Solution/Solution.pdf";
    QPdfWriter writer(a_strFileName);
    QPainter painter(&writer);

    writer.setPageSize(QPagedPaintDevice::A4);
    cout<<writer.devicePixelRatio()<<endl;
    painter.drawPixmap(QRect(writer.width()/2 -64*8.3,writer.width()*0.1,128*8.3,128*11.7),QPixmap(":/photos/icon.ico"));

    painter.setPen(Qt::red);
    painter.drawText(0,0,"THIS IS MY RED PDF TEXT..");

    painter.setPen(Qt::green);
    painter.drawText(0,500,"THIS IS MY GREEN PDF TEXT..");

    painter.setPen(Qt::blue);
    painter.drawText(0,1000,"THIS IS MY BLUE PDF TEXT..");

    painter.end();

    QMessageBox::information(NULL,"Hi!","Text has been written to the pdf file!");
}



void MainWindow::on_Visualisation_clicked()
{
    if(wizual_window_exist) delete visual_window;


    if(isProblemInitialized){
        visual_window = new MeshMainWindow(this);



        QRect scr = QApplication::desktop()->screenGeometry();
        visual_window->move( scr.center() - visual_window->rect().center() );
        visual_window->createFunction(this);
        visual_window->show();
    }
    else{
        MessageBox = new QMessageBox();
        MessageBox->warning(0,"Error","The optimization problem hasn't been initialized!\n\nTry to define the objective function by pressing \nthe ,,Update Equation'' button.");
    }
}

void MainWindow::on_AddFunctionButton_clicked()
{
    AddEqnWindow->exec();
    //  AddEqnWindow = new Add_Eqn(this);
    //   AddEqnWindow->show();

}

void MainWindow::receiver(QString name,QString formula){

    map_of_equations[name.toStdString()] = formula.toStdString();
    ui->ChooseEquationComboBox->addItem(name);
    ui->ChooseEquationComboBox->setCurrentText(name);
    this->on_ChooseEquationComboBox_activated(name);
}

void MainWindow::on_ChooseEquationComboBox_activated(const QString &arg1)
{
    Problem = new Optimization_Problem();
    ui->Eqn_LineEdit->setEnabled(true);
    // usuwa pierwsza pusta linijke z ComboBox po pierwszym updacie rownania
    int index = ui->ChooseEquationComboBox->findText("--- choose a function ---",Qt::MatchFixedString);
    if (index >= 0)
        ui->ChooseEquationComboBox->removeItem(index);

    QMap<string, string>::iterator iter2 = map_of_equations.find(arg1.toStdString());
    eqn = iter2.value();
    ui->Eqn_LineEdit->setText(QString::fromStdString(eqn));

    //if(ui->ChooseEquationComboBox->findText(ui->ChooseEquationComboBox->currentText()) == -1)
    //        ui->ChooseEquationComboBox->addItem(ui->ChooseEquationComboBox->currentText());
    //  cout << eqn << endl;
    bool error = false;
    try{
        problem_size = DefineProblemSize_dependingOnEquation(eqn);
    }
    catch(...){
        error = true;
    }
    if(!error ){

        if(problem_size != 2)
            ui->Visualisation->setDisabled(true);
        else
            ui->Visualisation->setEnabled(true);

        Problem->SetEquation(eqn);
        Problem->Initialize(HMS,PAR,problem_size,HMCR,repeat,bandwidth);
        Problem->SetEquation(eqn);

        Problem->InitHarmonyMemory();
        Problem->PrintHarmonyMemory();
        Problem->PrintVariableLimits();


        WindowVarLimits = new Boundary[problem_size];
        this->CreateTableForLimits();

        isProblemInitialized = true;
    }
    else{
        MessageBox = new QMessageBox();
        MessageBox->warning(0,"Error","The parsing error has occured!\n\nCheck the syntax of objective function.");
    }

}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    //QWidget::resizeEvent(event);
    //QMainWindow::resizeEvent(event);


}

void MainWindow::on_Eqn_LineEdit_editingFinished(){

    cout<<"Wywoluje sie"<<endl;
    string eqn_name = ui->ChooseEquationComboBox->currentText().toStdString();
    string eqn_formula = ui->Eqn_LineEdit->text().toStdString();

    bool error = false;
    try{
        problem_size = DefineProblemSize_dependingOnEquation(eqn_formula);
    }
    catch(...){
        error = true;
    }
    if(!error && problem_size>0){

        eqn = eqn_formula;
        map_of_equations.insert(eqn_name,eqn);
        if(problem_size > 2)
            ui->Visualisation->setDisabled(true);
        else
            ui->Visualisation->setEnabled(true);

        Problem->SetEquation(eqn);
        Problem->Initialize(HMS,PAR,problem_size,HMCR,repeat,bandwidth);
        Problem->SetEquation(eqn);

        Problem->InitHarmonyMemory();
        Problem->PrintHarmonyMemory();
        Problem->PrintVariableLimits();

        WindowVarLimits = new Boundary[problem_size];
        this->CreateTableForLimits();

        isProblemInitialized = true;
    }
    else if(problem_size == 0 ){
        MessageBox = new QMessageBox();
        MessageBox->warning(0,"Error","The constant function cannot be optimized!");
        //QMap<string, string>::iterator iter2 = map_of_equations.find(ui->ChooseEquationComboBox->currentText().toStdString());
        //this->eqn = iter2.value();
        // ui->Eqn_LineEdit->setText(QString::fromStdString(this->eqn));
    }
    else {
        MessageBox = new QMessageBox();
        MessageBox->warning(0,"Error","The parsing error has occured!\n\nCheck the syntax of objective function.");
        // ui->Eqn_LineEdit->setText(QString::fromStdString(this->eqn));

    }



}

void MainWindow::on_b_doubleSpinBox_valueChanged(double arg1)
{
    bandwidth = arg1;
    if(isProblemInitialized){
        this->AfterParameterChanged();
    }
    else cout<<"Error: Problem is not initialized."<<endl;
}
