#include "wizualizeClass.h"
/*#include "mylepton.hh"
#include "mainwindow.h"

double Rosenbrock::operator()(double x, double y){
    int ii = 0;
    for(string it:Window_connection->Problem->Lep.namesOfVariables){
        if(ii==0){
            double &varX =  Window_connection->Problem->Lep.expression.getVariableReference(it);
            varX = x;
        }
        if(ii==1){
            double &varY =  Window_connection->Problem->Lep.expression.getVariableReference(it);
            varY = y;
        }
        ii++;
    }

    double val = Window_connection->Problem->Lep.expression.evaluate();
    return   val;

}

Rosenbrock::Rosenbrock(GridPlot* pw,MainWindow *parent):Function(pw)
{
    Window_connection = parent;
}

Plot::Plot(MainWindow *parent)
{
    parent->wizual_window_exist = true;

    setTitle("A Simple GridPlot Demonstration");

    Rosenbrock rosenbrock(this, parent);

    rosenbrock.setMesh(100,100);    // 200000 polys
    double lowX=0,upX=0,lowY=0,upY=0;
    parent->Problem->VariableLimits[0].Get(lowX,upX);
    parent->Problem->VariableLimits[1].Get(lowY,upY);
    rosenbrock.setDomain(lowX,upX,lowY,upY);

    //rosenbrock.setMinZ(-10);

    rosenbrock.create();

    setRotation(30,0,15);
    setScale(2,2,1.2);
    setShift(0.15,0,0);
    setZoom(0.6);

    for (unsigned i=0; i!=coordinates()->axes.size(); ++i)
    {
        coordinates()->axes[i].setMajors(7);
        coordinates()->axes[i].setMinors(4);
    }
    int i =0;
    std::string var_name_first;
    std::string var_name_second;
    for(string it:parent->Problem->Lep.namesOfVariables){
        if(i==0) var_name_first =  it;
        if(i==1) var_name_second =  it;

        ++i;
    }

    coordinates()->axes[X1].setLabelString(QString::fromStdString(var_name_first)+" - axis");
    coordinates()->axes[Y1].setLabelString(QString::fromStdString(var_name_second)+" - axis");
    //coordinates()->axes[Z1].setLabelString(QChar(0x38f)); // Omega - see http://www.unicode.org/charts/


    setCoordinateStyle(BOX);

    updateData();
    updateGL();

    this->clearFocus();
}
*/
