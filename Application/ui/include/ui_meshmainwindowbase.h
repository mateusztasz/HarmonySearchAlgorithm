/********************************************************************************
** Form generated from reading UI file 'meshmainwindowbase.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHMAINWINDOWBASE_H
#define UI_MESHMAINWINDOWBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDoubleSpinBox>

QT_BEGIN_NAMESPACE

//class Ui_MainWindow
class Ui_Mesh_MainWindow
{
public:
    //    QAction *openFile;
    //    QAction *openMeshFile;
    QAction *animation;
    QAction *Exit;
    QAction *Box;
    QAction *Frame;
    QAction *None;
    QAction *front;
    QAction *back;
    QAction *right;
    QAction *left;
    QAction *ceil;
    QAction *floor;
    QAction *pointstyle;
    QAction *wireframe;
    QAction *hiddenline;
    QAction *polygon;
    QAction *filledmesh;
    QAction *nodata;
    QAction *floordata;
    QAction *flooriso;
    QAction *floornone;
    //    QAction *normals;
    QAction *axescolor;
    QAction *backgroundcolor;
    QAction *meshcolor;
    QAction *numbercolor;
    QAction *labelcolor;
    QAction *titlecolor;
    QAction *datacolor;
    QAction *resetcolor;
    QAction *numberfont;
    QAction *labelfont;
    QAction *titlefont;
    QAction *resetfont;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QHBoxLayout *hboxLayout1;
    QPushButton *normButton;

    QDoubleSpinBox *Zoom;
    QLabel *ZoomLabel;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *ui_Resolution;
    QLabel *ui_ResolutionLabel;
    QVBoxLayout *verticalLayout;

    //  QPushButton *lighting;
    //   QCheckBox *lightingswitch;
    QVBoxLayout *vboxLayout;
    //   QLabel *label_2;
    //   QSlider *offsSlider;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    //    QLabel *label_3;
    //    QSlider *resSlider;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QFrame *frame;
    QVBoxLayout *vboxLayout2;
    QVBoxLayout *vboxLayout3;
    QCheckBox *projection;
    QCheckBox *colorlegend;
    QCheckBox *autoscale;
    QCheckBox *mouseinput;
    QCheckBox *shader;
    QVBoxLayout *vboxLayout4;
    QLabel *label;
    QHBoxLayout *hboxLayout3;
    //    QSlider *normalsquality;
    //    QSlider *normalslength;
    QMenuBar *menuBar;
    QMenu *filemenu;
    QMenu *colormenu;
    QMenu *fontmenu;
    QToolBar *mainToolbar;
    QToolBar *csToolbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        //        openFile = new QAction(MainWindow);
        //        openFile->setObjectName(QStringLiteral("openFile"));
        QIcon icon;
        //        icon.addFile(QStringLiteral(":/images/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        //        openFile->setIcon(icon);
        //        openMeshFile = new QAction(MainWindow);
        //        openMeshFile->setObjectName(QStringLiteral("openMeshFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/filecell.png"), QSize(), QIcon::Normal, QIcon::Off);
        //        openMeshFile->setIcon(icon1);
        animation = new QAction(MainWindow);
        animation->setObjectName(QStringLiteral("animation"));
        animation->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/movie.png"), QSize(), QIcon::Normal, QIcon::Off);
        animation->setIcon(icon2);
        Exit = new QAction(MainWindow);
        Exit->setObjectName(QStringLiteral("Exit"));
        Box = new QAction(MainWindow);
        Box->setObjectName(QStringLiteral("Box"));
        Box->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        Box->setIcon(icon3);
        Frame = new QAction(MainWindow);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        Frame->setIcon(icon4);
        None = new QAction(MainWindow);
        None->setObjectName(QStringLiteral("None"));
        None->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/none.png"), QSize(), QIcon::Normal, QIcon::Off);
        None->setIcon(icon5);
        front = new QAction(MainWindow);
        front->setObjectName(QStringLiteral("front"));
        front->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/gridfr.png"), QSize(), QIcon::Normal, QIcon::Off);
        front->setIcon(icon6);
        back = new QAction(MainWindow);
        back->setObjectName(QStringLiteral("back"));
        back->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/gridb.png"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon7);
        right = new QAction(MainWindow);
        right->setObjectName(QStringLiteral("right"));
        right->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/gridr.png"), QSize(), QIcon::Normal, QIcon::Off);
        right->setIcon(icon8);
        left = new QAction(MainWindow);
        left->setObjectName(QStringLiteral("left"));
        left->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/gridl.png"), QSize(), QIcon::Normal, QIcon::Off);
        left->setIcon(icon9);
        ceil = new QAction(MainWindow);
        ceil->setObjectName(QStringLiteral("ceil"));
        ceil->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/gridc.png"), QSize(), QIcon::Normal, QIcon::Off);
        ceil->setIcon(icon10);
        floor = new QAction(MainWindow);
        floor->setObjectName(QStringLiteral("floor"));
        floor->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/gridf.png"), QSize(), QIcon::Normal, QIcon::Off);
        floor->setIcon(icon11);
        pointstyle = new QAction(MainWindow);
        pointstyle->setObjectName(QStringLiteral("pointstyle"));
        pointstyle->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/scattered.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointstyle->setIcon(icon12);
        wireframe = new QAction(MainWindow);
        wireframe->setObjectName(QStringLiteral("wireframe"));
        wireframe->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/wireframe.png"), QSize(), QIcon::Normal, QIcon::Off);
        wireframe->setIcon(icon13);
        hiddenline = new QAction(MainWindow);
        hiddenline->setObjectName(QStringLiteral("hiddenline"));
        hiddenline->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/hiddenline.png"), QSize(), QIcon::Normal, QIcon::Off);
        hiddenline->setIcon(icon14);
        polygon = new QAction(MainWindow);
        polygon->setObjectName(QStringLiteral("polygon"));
        polygon->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/polygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        polygon->setIcon(icon15);
        filledmesh = new QAction(MainWindow);
        filledmesh->setObjectName(QStringLiteral("filledmesh"));
        filledmesh->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/filledmesh.png"), QSize(), QIcon::Normal, QIcon::Off);
        filledmesh->setIcon(icon16);
        nodata = new QAction(MainWindow);
        nodata->setObjectName(QStringLiteral("nodata"));
        nodata->setCheckable(true);
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/nodata.png"), QSize(), QIcon::Normal, QIcon::Off);
        nodata->setIcon(icon17);
        floordata = new QAction(MainWindow);
        floordata->setObjectName(QStringLiteral("floordata"));
        floordata->setCheckable(true);
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/images/floordata.png"), QSize(), QIcon::Normal, QIcon::Off);
        floordata->setIcon(icon18);
        flooriso = new QAction(MainWindow);
        flooriso->setObjectName(QStringLiteral("flooriso"));
        flooriso->setCheckable(true);
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/images/flooriso.png"), QSize(), QIcon::Normal, QIcon::Off);
        flooriso->setIcon(icon19);
        floornone = new QAction(MainWindow);
        floornone->setObjectName(QStringLiteral("floornone"));
        floornone->setCheckable(true);
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/images/floorempty.png"), QSize(), QIcon::Normal, QIcon::Off);
        floornone->setIcon(icon20);
        //       normals = new QAction(MainWindow);
        //      normals->setObjectName(QStringLiteral("normals"));
        //      normals->setCheckable(true);
        QIcon icon21;
        //     icon21.addFile(QStringLiteral(":/images/normals.png"), QSize(), QIcon::Normal, QIcon::Off);
        //     normals->setIcon(icon21);
        axescolor = new QAction(MainWindow);
        axescolor->setObjectName(QStringLiteral("axescolor"));
        backgroundcolor = new QAction(MainWindow);
        backgroundcolor->setObjectName(QStringLiteral("backgroundcolor"));
        meshcolor = new QAction(MainWindow);
        meshcolor->setObjectName(QStringLiteral("meshcolor"));
        numbercolor = new QAction(MainWindow);
        numbercolor->setObjectName(QStringLiteral("numbercolor"));
        labelcolor = new QAction(MainWindow);
        labelcolor->setObjectName(QStringLiteral("labelcolor"));
        titlecolor = new QAction(MainWindow);
        titlecolor->setObjectName(QStringLiteral("titlecolor"));
        datacolor = new QAction(MainWindow);
        datacolor->setObjectName(QStringLiteral("datacolor"));
        resetcolor = new QAction(MainWindow);
        resetcolor->setObjectName(QStringLiteral("resetcolor"));
        numberfont = new QAction(MainWindow);
        numberfont->setObjectName(QStringLiteral("numberfont"));
        labelfont = new QAction(MainWindow);
        labelfont->setObjectName(QStringLiteral("labelfont"));
        titlefont = new QAction(MainWindow);
        titlefont->setObjectName(QStringLiteral("titlefont"));
        resetfont = new QAction(MainWindow);
        resetfont->setObjectName(QStringLiteral("resetfont"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(8, 8, 8, 8);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        normButton = new QPushButton(centralWidget);
        normButton->setObjectName(QStringLiteral("normButton"));

        hboxLayout1->addWidget(normButton);



        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        hboxLayout1->addLayout(verticalLayout_2);

        ZoomLabel = new QLabel(centralWidget);
        ZoomLabel ->setObjectName(QStringLiteral("ZoomLabel"));
        verticalLayout_2->addWidget(ZoomLabel );

        Zoom = new QDoubleSpinBox(centralWidget);
        Zoom ->setObjectName(QStringLiteral("Zoom"));
        verticalLayout_2->addWidget(Zoom );


        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        hboxLayout1->addLayout(verticalLayout);

        ui_ResolutionLabel = new QLabel(centralWidget);
        ui_ResolutionLabel ->setObjectName(QStringLiteral("ui_ResolutionLabel"));
        verticalLayout->addWidget(ui_ResolutionLabel );

        ui_Resolution = new QDoubleSpinBox(centralWidget);
        ui_Resolution ->setObjectName(QStringLiteral("ui_Resolution"));
        verticalLayout->addWidget(ui_Resolution );


        /*
        lighting = new QPushButton(centralWidget);
        lighting->setObjectName(QStringLiteral("lighting"));
        lighting->setEnabled(false);

        hboxLayout1->addWidget(lighting);

        lightingswitch = new QCheckBox(centralWidget);
        lightingswitch->setObjectName(QStringLiteral("lightingswitch"));

        hboxLayout1->addWidget(lightingswitch);
*/
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        /*        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        vboxLayout->addWidget(label_2);

        offsSlider = new QSlider(centralWidget);
        offsSlider->setObjectName(QStringLiteral("offsSlider"));
        offsSlider->setMaximum(30);
        offsSlider->setPageStep(5);
        offsSlider->setValue(5);
        offsSlider->setOrientation(Qt::Horizontal);
        offsSlider->setTickPosition(QSlider::TicksAbove);
        offsSlider->setTickInterval(2);

        vboxLayout->addWidget(offsSlider);
*/

        hboxLayout1->addLayout(vboxLayout);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        /*        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        vboxLayout1->addWidget(label_3);

        resSlider = new QSlider(centralWidget);
        resSlider->setObjectName(QStringLiteral("resSlider"));
        resSlider->setMinimum(1);
        resSlider->setMaximum(100);
        resSlider->setOrientation(Qt::Horizontal);
        resSlider->setTickPosition(QSlider::TicksAbove);
        resSlider->setTickInterval(5);

        vboxLayout1->addWidget(resSlider);
*/

        hboxLayout1->addLayout(vboxLayout1);


        hboxLayout->addLayout(hboxLayout1);

        spacerItem1 = new QSpacerItem(71, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);

        hboxLayout2->addWidget(frame);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        vboxLayout3 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        projection = new QCheckBox(centralWidget);
        projection->setObjectName(QStringLiteral("projection"));
        projection->setChecked(true);

        vboxLayout3->addWidget(projection);

        colorlegend = new QCheckBox(centralWidget);
        colorlegend->setObjectName(QStringLiteral("colorlegend"));

        vboxLayout3->addWidget(colorlegend);

        autoscale = new QCheckBox(centralWidget);
        autoscale->setObjectName(QStringLiteral("autoscale"));
        autoscale->setChecked(true);

        vboxLayout3->addWidget(autoscale);

        mouseinput = new QCheckBox(centralWidget);
        mouseinput->setObjectName(QStringLiteral("mouseinput"));
        mouseinput->setChecked(true);

        vboxLayout3->addWidget(mouseinput);

        shader = new QCheckBox(centralWidget);
        shader->setObjectName(QStringLiteral("shader"));
        shader->setChecked(true);

        vboxLayout3->addWidget(shader);


        vboxLayout2->addLayout(vboxLayout3);

        vboxLayout4 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout4->setSpacing(6);
#endif
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
        vboxLayout4->setObjectName(QStringLiteral("vboxLayout4"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        vboxLayout4->addWidget(label);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        //   normalsquality = new QSlider(centralWidget);
        //  normalsquality->setObjectName(QStringLiteral("normalsquality"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        //      sizePolicy2.setHeightForWidth(normalsquality->sizePolicy().hasHeightForWidth());
        //   normalsquality->setSizePolicy(sizePolicy2);
        //  normalsquality->setMinimum(3);
        //  normalsquality->setMaximum(32);
        // normalsquality->setPageStep(4);
        //  normalsquality->setValue(3);
        // normalsquality->setOrientation(Qt::Vertical);
        // normalsquality->setInvertedAppearance(true);
        //normalsquality->setTickPosition(QSlider::TicksAbove);
        /*
        hboxLayout3->addWidget(normalsquality);

        normalslength = new QSlider(centralWidget);
        normalslength->setObjectName(QStringLiteral("normalslength"));
        sizePolicy2.setHeightForWidth(normalslength->sizePolicy().hasHeightForWidth());
        normalslength->setSizePolicy(sizePolicy2);
        normalslength->setMinimum(1);
        normalslength->setMaximum(100);
        normalslength->setPageStep(5);
        normalslength->setValue(8);
        normalslength->setOrientation(Qt::Vertical);
        normalslength->setInvertedAppearance(true);
        normalslength->setTickPosition(QSlider::TicksAbove);

        hboxLayout3->addWidget(normalslength);
*/

        vboxLayout4->addLayout(hboxLayout3);


        vboxLayout2->addLayout(vboxLayout4);


        hboxLayout2->addLayout(vboxLayout2);


        gridLayout->addLayout(hboxLayout2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 18));
        filemenu = new QMenu(menuBar);
        filemenu->setObjectName(QStringLiteral("filemenu"));
        colormenu = new QMenu(menuBar);
        colormenu->setObjectName(QStringLiteral("colormenu"));
        fontmenu = new QMenu(menuBar);
        fontmenu->setObjectName(QStringLiteral("fontmenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolbar = new QToolBar(MainWindow);
        mainToolbar->setObjectName(QStringLiteral("mainToolbar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolbar);
        csToolbar = new QToolBar(MainWindow);
        csToolbar->setObjectName(QStringLiteral("csToolbar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, csToolbar);

        menuBar->addAction(filemenu->menuAction());
        menuBar->addAction(colormenu->menuAction());
        menuBar->addAction(fontmenu->menuAction());
        //   filemenu->addAction(openFile);
        //     filemenu->addAction(openMeshFile);
        filemenu->addAction(animation);
        filemenu->addAction(Exit);
        colormenu->addAction(axescolor);
        colormenu->addAction(backgroundcolor);
        colormenu->addAction(meshcolor);
        colormenu->addAction(numbercolor);
        colormenu->addAction(labelcolor);
        colormenu->addAction(titlecolor);
        colormenu->addAction(datacolor);
        colormenu->addAction(resetcolor);
        fontmenu->addAction(numberfont);
        fontmenu->addAction(labelfont);
        fontmenu->addAction(titlefont);
        fontmenu->addAction(resetfont);
        //mainToolbar->addAction(openFile);
        //    mainToolbar->addAction(openMeshFile);
        mainToolbar->addSeparator();
        mainToolbar->addAction(animation);
        mainToolbar->addSeparator();
        csToolbar->addAction(Box);
        csToolbar->addAction(Frame);
        csToolbar->addAction(None);
        csToolbar->addAction(front);
        csToolbar->addAction(back);
        csToolbar->addAction(right);
        csToolbar->addAction(left);
        csToolbar->addAction(ceil);
        csToolbar->addAction(floor);
        csToolbar->addAction(pointstyle);
        csToolbar->addAction(wireframe);
        csToolbar->addAction(hiddenline);
        csToolbar->addAction(polygon);
        csToolbar->addAction(filledmesh);
        csToolbar->addAction(nodata);
        csToolbar->addAction(floordata);
        csToolbar->addAction(flooriso);
        csToolbar->addAction(floornone);
        //   csToolbar->addAction(normals);

        retranslateUi(MainWindow);
        //      QObject::connect(lightingswitch, SIGNAL(toggled(bool)), lighting, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mesh2", 0));
        //     openFile->setText(QApplication::translate("MainWindow", "Open File", 0));
        //     openFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        //      openMeshFile->setText(QApplication::translate("MainWindow", "Open FEM File", 0));
        animation->setText(QApplication::translate("MainWindow", "Animation", 0));
        Exit->setText(QApplication::translate("MainWindow", "Exit", 0));
        Exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        Box->setText(QApplication::translate("MainWindow", "Box", 0));
        Frame->setText(QApplication::translate("MainWindow", "Frame", 0));
        None->setText(QApplication::translate("MainWindow", "None", 0));
        front->setText(QApplication::translate("MainWindow", "front", 0));
        back->setText(QApplication::translate("MainWindow", "back", 0));
        right->setText(QApplication::translate("MainWindow", "right", 0));
        left->setText(QApplication::translate("MainWindow", "left", 0));
        ceil->setText(QApplication::translate("MainWindow", "ceil", 0));
        floor->setText(QApplication::translate("MainWindow", "floor", 0));
        pointstyle->setText(QApplication::translate("MainWindow", "pointstyle", 0));
        wireframe->setText(QApplication::translate("MainWindow", "wireframe", 0));
        hiddenline->setText(QApplication::translate("MainWindow", "hiddenline", 0));
        polygon->setText(QApplication::translate("MainWindow", "polygon", 0));
        filledmesh->setText(QApplication::translate("MainWindow", "filledmesh", 0));
        nodata->setText(QApplication::translate("MainWindow", "nodata", 0));
        floordata->setText(QApplication::translate("MainWindow", "floordata", 0));
        flooriso->setText(QApplication::translate("MainWindow", "flooriso", 0));
        floornone->setText(QApplication::translate("MainWindow", "floornone", 0));
        //   normals->setText(QApplication::translate("MainWindow", "normals", 0));
        axescolor->setText(QApplication::translate("MainWindow", "&Axes", 0));
        backgroundcolor->setText(QApplication::translate("MainWindow", "&Background", 0));
        meshcolor->setText(QApplication::translate("MainWindow", "&Mesh", 0));
        numbercolor->setText(QApplication::translate("MainWindow", "&Numbers", 0));
        labelcolor->setText(QApplication::translate("MainWindow", "&Label", 0));
        titlecolor->setText(QApplication::translate("MainWindow", "&Caption", 0));
        datacolor->setText(QApplication::translate("MainWindow", "Data Color", 0));
        resetcolor->setText(QApplication::translate("MainWindow", "&Reset", 0));
        numberfont->setText(QApplication::translate("MainWindow", "&Scale numbering", 0));
        labelfont->setText(QApplication::translate("MainWindow", "&Axes label", 0));
        titlefont->setText(QApplication::translate("MainWindow", "&Caption", 0));
        resetfont->setText(QApplication::translate("MainWindow", "&Reset", 0));
        normButton->setText(QApplication::translate("MainWindow", "Default position", 0));

        ui_ResolutionLabel->setText(QApplication::translate("MainWindow", "Set resolution", 0));
        ZoomLabel->setText(QApplication::translate("MainWindow", "Set zoom", 0));

        //       lighting->setText(QApplication::translate("MainWindow", "Lighting", 0));
        //       lightingswitch->setText(QString());
        // label_2->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Polygon Offset</p></body></html>", 0));
        // label_3->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Resolution</p></body></html>", 0));
        projection->setText(QApplication::translate("MainWindow", "Ortho", 0));
        colorlegend->setText(QApplication::translate("MainWindow", "Legend", 0));
        autoscale->setText(QApplication::translate("MainWindow", "Autoscale", 0));
        mouseinput->setText(QApplication::translate("MainWindow", "Mouse", 0));
        shader->setText(QApplication::translate("MainWindow", "Shading", 0));
        //       label->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Normals</p></body></html>", 0));
        filemenu->setTitle(QApplication::translate("MainWindow", "File", 0));
        colormenu->setTitle(QApplication::translate("MainWindow", "Color", 0));
        fontmenu->setTitle(QApplication::translate("MainWindow", "Fonts", 0));
        mainToolbar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        csToolbar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
class Mesh_MainWindow: public Ui_Mesh_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHMAINWINDOWBASE_H
