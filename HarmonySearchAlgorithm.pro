#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T20:42:33
#
#-------------------------------------------------

TARGET      = HarmonySearchAlgorithm
TEMPLATE    = app
QT          += core gui widgets declarative opengl
CONFIG      += c++11 qt warn_on thread release qwt

## Add qwt library
#include ( ${QWT_ROOT}\features\qwt.prf )

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG(debug, debug|release) {
    DESTDIR = build/debug
}
 CONFIG(release, debug|release) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui


#INCLUDEPATH += "C:\Qwt-6.1.2\qwtplot3d\include"
#LIBS += -L"C:\Qwt-6.1.2\qwtplot3d\lib"

#======QWT3D==============
INCLUDEPATH += "lib/qwt3D/include"
LIBS += -L"lib/qwt3D/lib"
LIBS += \
    -lqwtplot3d

#====== Program files ==============
INCLUDEPATH    += Program/include
INCLUDEPATH    += Program/Lepton_parser/include/lepton
INCLUDEPATH    += Program/Lepton_parser/include

#====== Application files ==============
INCLUDEPATH    += Application/ui/include
INCLUDEPATH    += Application/include

DEPENDPATH	= $$INCLUDEPATH

SOURCES += \
    Application/src/main.cpp\
    Application/src/mainwindow.cpp \
    Application/src/mymenuwidget.cpp \
    \
    Program/src/boundary.cpp \
    Program/src/harmony.cpp \
    Program/src/optimization_problem.cpp \
    \
    Program/Lepton_parser/src/CompiledExpression.cpp \
    Program/Lepton_parser/src/ExpressionProgram.cpp \
    Program/Lepton_parser/src/ExpressionTreeNode.cpp \
    Program/Lepton_parser/src/Operation.cpp \
    Program/Lepton_parser/src/ParsedExpression.cpp \
    Program/Lepton_parser/src/Parser.cpp \
    \
    lib/qwt3D/src/qwt3d_appearance.cpp \
    lib/qwt3D/src/qwt3d_autoscaler.cpp \
    lib/qwt3D/src/qwt3d_axis.cpp \
    lib/qwt3D/src/qwt3d_color_std.cpp \
    lib/qwt3D/src/qwt3d_colorlegend.cpp \
    lib/qwt3D/src/qwt3d_coordsys.cpp \
    lib/qwt3D/src/qwt3d_data.cpp \
    lib/qwt3D/src/qwt3d_drawable.cpp \
    lib/qwt3D/src/qwt3d_enrichment_std.cpp \
    lib/qwt3D/src/qwt3d_extglwidget.cpp \
    lib/qwt3D/src/qwt3d_function.cpp \
    lib/qwt3D/src/qwt3d_graphplot.cpp \
    lib/qwt3D/src/qwt3d_gridmapping.cpp \
    lib/qwt3D/src/qwt3d_gridplot.cpp \
    lib/qwt3D/src/qwt3d_io.cpp \
    lib/qwt3D/src/qwt3d_io_reader.cpp \
    lib/qwt3D/src/qwt3d_label.cpp \
    lib/qwt3D/src/qwt3d_lighting.cpp \
    lib/qwt3D/src/qwt3d_meshplot.cpp \
    lib/qwt3D/src/qwt3d_parametricsurface.cpp \
    lib/qwt3D/src/qwt3d_plot3d.cpp \
    lib/qwt3D/src/qwt3d_scale.cpp \
    lib/qwt3D/src/qwt3d_surfaceplot.cpp \
    lib/qwt3D/src/qwt3d_types.cpp \
    lib/qwt3D/src/qwt3d_volumeplot.cpp \
    Application/src/meshmainwindow.cpp \
    Application/src/lightingdialog.cpp \
    Application/src/add_eqn.cpp

HEADERS  += \
    Application/include/mainwindow.h \
    Application/include/mymenuwidget.h \
    \
    Program/include/boundary.hh \
    Program/include/harmony.hh \
    Program/include/mylepton.hh \
    Program/include/optimization_problem.hh \
    \
    Program/Lepton_parser/include/lepton/CompiledExpression.h \
    Program/Lepton_parser/include/lepton/CustomFunction.h \
    Program/Lepton_parser/include/lepton/Exception.h \
    Program/Lepton_parser/include/lepton/ExpressionProgram.h \
    Program/Lepton_parser/include/lepton/ExpressionTreeNode.h \
    Program/Lepton_parser/include/lepton/Operation.h \
    Program/Lepton_parser/include/lepton/ParsedExpression.h \
    Program/Lepton_parser/include/lepton/Parser.h \
    Program/Lepton_parser/include/lepton/windowsIncludes.h \
    Program/Lepton_parser/include/Lepton.h \
    Program/Lepton_parser/src/MSVC_erfc.h \
    \
    lib/qwt3D/include/qwt3d_appearance.h \
    lib/qwt3D/include/qwt3d_autoscaler.h \
    lib/qwt3D/include/qwt3d_axis.h \
    lib/qwt3D/include/qwt3d_color.h \
    lib/qwt3D/include/qwt3d_color_std.h \
    lib/qwt3D/include/qwt3d_colorlegend.h \
    lib/qwt3D/include/qwt3d_coordsys.h \
    lib/qwt3D/include/qwt3d_data.h \
    lib/qwt3D/include/qwt3d_drawable.h \
    lib/qwt3D/include/qwt3d_enrichment.h \
    lib/qwt3D/include/qwt3d_enrichment_std.h \
    lib/qwt3D/include/qwt3d_extglwidget.h \
    lib/qwt3D/include/qwt3d_function.h \
    lib/qwt3D/include/qwt3d_global.h \
    lib/qwt3D/include/qwt3d_graphplot.h \
    lib/qwt3D/include/qwt3d_gridmapping.h \
    lib/qwt3D/include/qwt3d_gridplot.h \
    lib/qwt3D/include/qwt3d_helper.h \
    lib/qwt3D/include/qwt3d_io.h \
    lib/qwt3D/include/qwt3d_io_reader.h \
    lib/qwt3D/include/qwt3d_label.h \
    lib/qwt3D/include/qwt3d_mapping.h \
    lib/qwt3D/include/qwt3d_meshplot.h \
    lib/qwt3D/include/qwt3d_openglhelper.h \
    lib/qwt3D/include/qwt3d_parametricsurface.h \
    lib/qwt3D/include/qwt3d_plot3d.h \
    lib/qwt3D/include/qwt3d_portability.h \
    lib/qwt3D/include/qwt3d_scale.h \
    lib/qwt3D/include/qwt3d_surfaceplot.h \
    lib/qwt3D/include/qwt3d_types.h \
    lib/qwt3D/include/qwt3d_valueptr.h \
    lib/qwt3D/include/qwt3d_volumeplot.h \
    Application/ui/include/ui_meshmainwindowbase.h \
    Application/include/lightingdialog.h \
    Application/include/meshmainwindow.h \
    Application/ui/creator_form/add_eqn.h \
    Application/include/add_eqn.h

FORMS    += Application/ui/creator_form/mainwindow.ui \
    Application/ui/creator_form/lightingdialogbase.ui \
    Application/ui/creator_form/meshmainwindowbase.ui \
    Application/ui/creator_form/add_eqn.ui


RESOURCES += \
    Application/resources/reSources_definition.qrc \
    Application/resources/images.qrc


RC_FILE = Application/rcc/myapp.rc

