#ifndef mesh2mainwindow_h__2004_03_07_13_38_begin_guarded_code
#define mesh2mainwindow_h__2004_03_07_13_38_begin_guarded_code

#include <math.h>
#include <qapplication.h>
#include <qwt3d_gridplot.h>
#include <qwt3d_function.h>
#include <string>

#include "ui_meshmainwindowbase.h"

using namespace Qwt3D;


class QLabel;
class QTimer;
class QAction;
class QFileDialog;
class LightingDlg;
class ColorMapPreview;
class MainWindow;

class Our_function_to_Plot : public Function
{
public:
    //Our_function_to_Plot(MainWindow *parent);

    Our_function_to_Plot(GridPlot* pw,MainWindow *parent);
    // Our_function_to_Plot(GridPlot* pw);
    MainWindow *Window_connection;
    double operator()(double x, double y);
};


class MeshMainWindow : public QMainWindow, protected Ui::Mesh_MainWindow
{
    Q_OBJECT
public:
    MeshMainWindow(MainWindow *parent = 0 );
    MainWindow *Window_connection;
    ~MeshMainWindow();

    Qwt3D::GridPlot* dataWidget;

    int Res;
public slots:
    void mySlot_Zoom_changed(double);
    void mySlot_Resolution_changed(double);

    void open();

    void createFunction(MainWindow *parent);
    void createPSurface(QString const& name);

    void pickCoordSystem( QAction* );
    void pickPlotStyle( QAction* );
    void pickFloorStyle( QAction* );
    void pickAxesColor();
    void pickBgColor();
    void pickMeshColor();
    void pickNumberColor();
    void pickLabelColor();
    void pickTitleColor();
    void pickDataColor();
    void pickLighting();
    void resetColors();
    void pickNumberFont();
    void pickLabelFont();
    void pickTitleFont();
    void resetFonts();
    void setStandardView();
    void toggleAnimation(bool);
    void toggleProjectionMode(bool);
    void toggleColorLegend(bool);
    void toggleAutoScale(bool val);
    void toggleShader(bool val);
    void rotate();
    void setPolygonOffset(int);

    void showRotate(double x, double y, double z);
    void showShift(double x, double y);
    void showScale(double x, double y, double z);
    void showZoom(double z);
    void showNormals(bool val);
    void setNormalQuality(int);
    void setNormalLength(int);
    bool openColorMap(Qwt3D::ColorVector& cv, QString fname);
    void adaptDataColors(const QString&);
    void updateColorLegend(int majors, int minors);

    void setLeftGrid( bool b );
    void setRightGrid( bool b );
    void setCeilGrid( bool b );
    void setFloorGrid( bool b );
    void setFrontGrid( bool b );
    void setBackGrid( bool b );
    void setGrid( Qwt3D::SIDE, bool );

    void enableLighting(bool val);

private:
    QLabel *filenameWidget, *dimWidget,
    *rotateLabel, *shiftLabel, *scaleLabel, *zoomLabel;

    QTimer* timer;
    int redrawWait;

    QAction* activeCoordSystem;

    bool legend_;
    Qwt3D::StandardColor* col_;

    QFileDialog* datacolordlg_;
    LightingDlg* lightingdlg_;
    QActionGroup* grids;

    Our_function_to_Plot *FCN;


};

#endif /* include guarded */
