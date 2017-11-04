/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QListWidget *faceList;
    QListWidget *halfEdgeList;
    QListWidget *vertexList;
    QLabel *faceLabel;
    QLabel *halfEdgeLabel;
    QLabel *vertexLabel;
    QPushButton *splitEdgeButton;
    QPushButton *triangulateFaceButton;
    QLabel *label;
    QPushButton *subdivideButton;
    QPushButton *extrudeButton;
    QPushButton *bevelEdgeButton;
    QDoubleSpinBox *rDoubleSpinBox;
    QDoubleSpinBox *gDoubleSpinBox;
    QLabel *rLabel;
    QLabel *gLabel;
    QDoubleSpinBox *bDoubleSpinBox;
    QLabel *bLabel;
    QLabel *xLabel;
    QDoubleSpinBox *xDoubleSpinBox;
    QLabel *yLabel;
    QDoubleSpinBox *yDoubleSpinBox;
    QLabel *zLabel;
    QDoubleSpinBox *zDoubleSpinBox;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName(QStringLiteral("gui"));
        gui->resize(494, 474);
        QFont font;
        font.setFamily(QStringLiteral("Magneto"));
        gui->setFont(font);
        faceList = new QListWidget(gui);
        faceList->setObjectName(QStringLiteral("faceList"));
        faceList->setGeometry(QRect(10, 60, 141, 331));
        halfEdgeList = new QListWidget(gui);
        halfEdgeList->setObjectName(QStringLiteral("halfEdgeList"));
        halfEdgeList->setGeometry(QRect(170, 60, 151, 331));
        vertexList = new QListWidget(gui);
        vertexList->setObjectName(QStringLiteral("vertexList"));
        vertexList->setGeometry(QRect(340, 60, 141, 331));
        faceLabel = new QLabel(gui);
        faceLabel->setObjectName(QStringLiteral("faceLabel"));
        faceLabel->setGeometry(QRect(40, 10, 71, 31));
        QFont font1;
        font1.setPointSize(20);
        faceLabel->setFont(font1);
        faceLabel->setTextFormat(Qt::AutoText);
        halfEdgeLabel = new QLabel(gui);
        halfEdgeLabel->setObjectName(QStringLiteral("halfEdgeLabel"));
        halfEdgeLabel->setGeometry(QRect(170, 10, 141, 31));
        halfEdgeLabel->setFont(font1);
        vertexLabel = new QLabel(gui);
        vertexLabel->setObjectName(QStringLiteral("vertexLabel"));
        vertexLabel->setGeometry(QRect(360, 10, 91, 31));
        vertexLabel->setFont(font1);
        splitEdgeButton = new QPushButton(gui);
        splitEdgeButton->setObjectName(QStringLiteral("splitEdgeButton"));
        splitEdgeButton->setGeometry(QRect(210, 400, 81, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Ebrima"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        splitEdgeButton->setFont(font2);
        triangulateFaceButton = new QPushButton(gui);
        triangulateFaceButton->setObjectName(QStringLiteral("triangulateFaceButton"));
        triangulateFaceButton->setGeometry(QRect(10, 400, 81, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Ebrima"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        triangulateFaceButton->setFont(font3);
        label = new QLabel(gui);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 421, 16));
        QFont font4;
        font4.setFamily(QStringLiteral("Corbel"));
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        subdivideButton = new QPushButton(gui);
        subdivideButton->setObjectName(QStringLiteral("subdivideButton"));
        subdivideButton->setGeometry(QRect(400, 400, 81, 31));
        subdivideButton->setFont(font3);
        extrudeButton = new QPushButton(gui);
        extrudeButton->setObjectName(QStringLiteral("extrudeButton"));
        extrudeButton->setGeometry(QRect(100, 400, 101, 31));
        extrudeButton->setFont(font3);
        bevelEdgeButton = new QPushButton(gui);
        bevelEdgeButton->setObjectName(QStringLiteral("bevelEdgeButton"));
        bevelEdgeButton->setGeometry(QRect(300, 400, 91, 31));
        bevelEdgeButton->setFont(font3);
        rDoubleSpinBox = new QDoubleSpinBox(gui);
        rDoubleSpinBox->setObjectName(QStringLiteral("rDoubleSpinBox"));
        rDoubleSpinBox->setGeometry(QRect(20, 440, 61, 22));
        QFont font5;
        font5.setFamily(QStringLiteral("Fixedsys"));
        font5.setPointSize(6);
        rDoubleSpinBox->setFont(font5);
        rDoubleSpinBox->setMaximum(1);
        rDoubleSpinBox->setSingleStep(0.01);
        gDoubleSpinBox = new QDoubleSpinBox(gui);
        gDoubleSpinBox->setObjectName(QStringLiteral("gDoubleSpinBox"));
        gDoubleSpinBox->setGeometry(QRect(100, 440, 62, 22));
        gDoubleSpinBox->setFont(font5);
        gDoubleSpinBox->setMaximum(1);
        gDoubleSpinBox->setSingleStep(0.01);
        rLabel = new QLabel(gui);
        rLabel->setObjectName(QStringLiteral("rLabel"));
        rLabel->setGeometry(QRect(10, 440, 16, 21));
        rLabel->setFont(font5);
        gLabel = new QLabel(gui);
        gLabel->setObjectName(QStringLiteral("gLabel"));
        gLabel->setGeometry(QRect(90, 440, 16, 21));
        gLabel->setFont(font5);
        bDoubleSpinBox = new QDoubleSpinBox(gui);
        bDoubleSpinBox->setObjectName(QStringLiteral("bDoubleSpinBox"));
        bDoubleSpinBox->setGeometry(QRect(180, 440, 62, 22));
        bDoubleSpinBox->setFont(font5);
        bDoubleSpinBox->setMaximum(1);
        bDoubleSpinBox->setSingleStep(0.01);
        bLabel = new QLabel(gui);
        bLabel->setObjectName(QStringLiteral("bLabel"));
        bLabel->setGeometry(QRect(170, 440, 16, 21));
        bLabel->setFont(font5);
        xLabel = new QLabel(gui);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setGeometry(QRect(250, 440, 16, 21));
        xLabel->setFont(font5);
        xDoubleSpinBox = new QDoubleSpinBox(gui);
        xDoubleSpinBox->setObjectName(QStringLiteral("xDoubleSpinBox"));
        xDoubleSpinBox->setGeometry(QRect(260, 440, 62, 22));
        xDoubleSpinBox->setFont(font5);
        xDoubleSpinBox->setMinimum(-1e+41);
        xDoubleSpinBox->setMaximum(1e+100);
        yLabel = new QLabel(gui);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setGeometry(QRect(330, 440, 16, 21));
        yLabel->setFont(font5);
        yDoubleSpinBox = new QDoubleSpinBox(gui);
        yDoubleSpinBox->setObjectName(QStringLiteral("yDoubleSpinBox"));
        yDoubleSpinBox->setGeometry(QRect(340, 440, 62, 22));
        yDoubleSpinBox->setFont(font5);
        yDoubleSpinBox->setMinimum(-1e+41);
        yDoubleSpinBox->setMaximum(1e+100);
        zLabel = new QLabel(gui);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setGeometry(QRect(410, 440, 16, 21));
        zLabel->setFont(font5);
        zDoubleSpinBox = new QDoubleSpinBox(gui);
        zDoubleSpinBox->setObjectName(QStringLiteral("zDoubleSpinBox"));
        zDoubleSpinBox->setGeometry(QRect(420, 440, 62, 22));
        zDoubleSpinBox->setFont(font5);
        zDoubleSpinBox->setMinimum(-1e+41);
        zDoubleSpinBox->setMaximum(1e+100);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QApplication::translate("gui", "Editor", 0));
        faceLabel->setText(QApplication::translate("gui", "Face", 0));
        halfEdgeLabel->setText(QApplication::translate("gui", "HalfEdge", 0));
        vertexLabel->setText(QApplication::translate("gui", "Vertex", 0));
        splitEdgeButton->setText(QApplication::translate("gui", "Split Edge", 0));
        triangulateFaceButton->setText(QApplication::translate("gui", "Split Face", 0));
        label->setText(QApplication::translate("gui", "Please use LMB to select vertex, RMB to select half edge and MMB to select face.", 0));
        subdivideButton->setText(QApplication::translate("gui", "Subdivide", 0));
        extrudeButton->setText(QApplication::translate("gui", "Extrude Face", 0));
        bevelEdgeButton->setText(QApplication::translate("gui", "Bevel Edge", 0));
        rLabel->setText(QApplication::translate("gui", "R", 0));
        gLabel->setText(QApplication::translate("gui", "G", 0));
        bLabel->setText(QApplication::translate("gui", "B", 0));
        xLabel->setText(QApplication::translate("gui", "X", 0));
        yLabel->setText(QApplication::translate("gui", "Y", 0));
        zLabel->setText(QApplication::translate("gui", "Z", 0));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
