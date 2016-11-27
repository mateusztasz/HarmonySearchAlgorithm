#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define M_E 2.71828182845904523536

#include <QMainWindow>
#include <string>
#include "optimization_problem.hh"
#include <QVBoxLayout>
#include <QMap>
#include <QStandardItem>

#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QProgressBar>
#include <QPainter>
#include <QDesktopServices>
#include <QMessageBox>
#include <QDialog>

#include <iomanip>
#include <QTableWidgetItem>
#include <QSignalMapper>

#include <QTimer>
#include <QTime>

#include <iostream>
#include <string>
#include <list>
#include <set>

#include <QApplication>
#include <QDesktopWidget>

#include "harmony.hh"
#include "Lepton.h"
#include "mylepton.hh"
#include "mymenuwidget.h"
#include "meshmainwindow.h"

#include "add_eqn.h"

using namespace std;

namespace Ui
{
class MainWindow;
class AddEqn;
}

enum StateWelcomePage
{
    HIDDEN,
    SHOWED,
    RUNNING
};

enum StateComputation
{
    WORKING,
    IDLE
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class Our_function_to_Plot;
    friend class MeshMainWindow;
    friend class Add_Eqn;

    explicit MainWindow(QWidget* parent = 0);

    void CreateTableForLimits();
    ~MainWindow();

public slots:

    // void on_UpdateEquationButton_clicked();

    void on_ComputeButton_clicked();

private slots:
    void mySlot_Authors_For_WelcomePage_Clicked();

    void mySlot_Documentation_For_WelcomePage_Clicked();

    void mySlot_HS_Standard_ForWelcomePage_Clicked();

    void ForWelcomePage_AnimationEnded();

    void button_SlideOut_WelocomePage_on_clicked();

    void handleQLineEdit_ForVarLimits_hasChanged(QString i);

    void on_Repeat_LineEdit_textEdited(const QString& arg1);

    void on_PAR_SpinBox_valueChanged(double arg1);

    void on_HMCR_SpinBox_valueChanged(double arg1);

    void on_HMS_LineEdit_textEdited(const QString& arg1);

    void Update_Progress_Bar();

    void Recomputate_Stylesheet();

    void receiver(QString, QString);

    /*!
 * \brief Zdarzenie rysowania
 *
 * Metoda rysujaca klepsydre oraz piasek na oknie glownym.
 */
    virtual void paintEvent(QPaintEvent*);

    void on_Visualisation_clicked();

    virtual void enterEvent(QEvent* event)
    {
        // do my own things
        QWidget::enterEvent(event);
    }

    void on_AddFunctionButton_clicked();

    void on_ChooseEquationComboBox_activated(const QString& arg1);

    // void on_Eqn_LineEdit_editingFinished();

    // void on_Eqn_LineEdit_textEdited(const QString &arg1);

    void on_Eqn_LineEdit_editingFinished();

    void on_b_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow* ui;
    Ui::MainWindow* ui_welcome;
    Add_Eqn* AddEqnWindow;

    Optimization_Problem* Problem;

    string eqn;
    double HMS;
    double PAR;
    double HMCR;
    double repeat;
    double bandwidth;

    int problem_size;
    Boundary* WindowVarLimits;
    int Progress;

    bool isProblemInitialized;

    void AfterParameterChanged();

    //==WELCOME PAGE
    QWidget* welcome_page;

    QLabel* logo_ForWelcomePage;
    QPixmap* pixmap_ForWelcomePage;

    QPushButton* Documentation_For_WelcomePage;
    QPushButton* HS_Standard_ForWelcomePage;
    QPushButton* button_SlideOut_WelocomePage;
    QLabel* Text_For_WelcomePage;
    QPushButton* Authors_For_WelcomePage;

    QLabel* loadingGif_canva_ForWelcomePage;
    QMovie* loadingGif_ForWelcomePage;

    QPropertyAnimation* animation_ForWelcomePage;

    MeshMainWindow* visual_window;
    bool wizual_window_exist = false;

    StateWelcomePage State_of_welcomePage;
    StateComputation State_of_Computation;

    QMessageBox* MessageBox;

    /*!
 * \brief Obiekt typu QTimer
 *
 * Dynamiczne stworzenie obiektu umozliwiajacego odliczanie czasu.
 */
    QTimer* Seconds_counter; // "Sekundnik" po angielsku? :)

    QMap<string, string> map_of_equations;

protected:
    void resizeEvent(QResizeEvent* event);
};

int DefineProblemSize_dependingOnEquation(string& eqn);

#endif // MAINWINDOW_H
