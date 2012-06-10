/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jun 10 22:58:06 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *hide_button;
    QLabel *labelException;
    QWidget *widget_2;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonRadiant;
    QRadioButton *radioButtonDegre;
    QPushButton *show_keyboard;
    QTextEdit *textEdit;
    QLabel *label_2;
    QWidget *widget_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonComplexe;
    QRadioButton *radioButtonNonComplexe;
    QLineEdit *lineEdit;
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonEntiere;
    QRadioButton *radioButtonRationnelle;
    QRadioButton *radioButtonReelle;
    QFrame *keyBoard;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *button9;
    QPushButton *button8;
    QPushButton *button7;
    QPushButton *button6;
    QPushButton *button5;
    QPushButton *button4;
    QPushButton *button3;
    QPushButton *button2;
    QPushButton *button1;
    QPushButton *buttonEntrer;
    QPushButton *buttonAnnuler;
    QPushButton *buttonRetablir;
    QPushButton *buttonDollar;
    QPushButton *button0;
    QPushButton *buttonVirgule;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QPushButton *divButton;
    QPushButton *buttonPow;
    QPushButton *mulButton;
    QPushButton *buttonMod;
    QPushButton *subButton;
    QPushButton *addButton;
    QPushButton *buttonSign;
    QPushButton *buttonExp;
    QGridLayout *gridLayout_3;
    QPushButton *buttonSin;
    QPushButton *buttonSinh;
    QPushButton *buttonLn;
    QPushButton *buttonSqrt;
    QPushButton *buttonFacto;
    QPushButton *buttonCos;
    QPushButton *buttonCosh;
    QPushButton *buttonLog;
    QPushButton *buttonSqr;
    QPushButton *buttonEval;
    QPushButton *buttonTan;
    QPushButton *buttonTanh;
    QPushButton *buttonInv;
    QPushButton *buttonCube;
    QPushButton *buttonPI;
    QSpacerItem *verticalSpacer;
    QPushButton *spaceButton;
    QPushButton *supprButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(493, 639);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        hide_button = new QPushButton(centralWidget);
        hide_button->setObjectName(QString::fromUtf8("hide_button"));
        hide_button->setGeometry(QRect(10, 293, 471, 15));
        hide_button->setIconSize(QSize(16, 16));
        labelException = new QLabel(centralWidget);
        labelException->setObjectName(QString::fromUtf8("labelException"));
        labelException->setGeometry(QRect(20, 150, 421, 21));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(150, 210, 101, 80));
        layoutWidget_3 = new QWidget(widget_2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 20, 67, 44));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButtonRadiant = new QRadioButton(layoutWidget_3);
        radioButtonRadiant->setObjectName(QString::fromUtf8("radioButtonRadiant"));
        radioButtonRadiant->setChecked(true);

        verticalLayout_2->addWidget(radioButtonRadiant);

        radioButtonDegre = new QRadioButton(layoutWidget_3);
        radioButtonDegre->setObjectName(QString::fromUtf8("radioButtonDegre"));

        verticalLayout_2->addWidget(radioButtonDegre);

        show_keyboard = new QPushButton(centralWidget);
        show_keyboard->setObjectName(QString::fromUtf8("show_keyboard"));
        show_keyboard->setGeometry(QRect(10, 290, 471, 15));
        show_keyboard->setIconSize(QSize(16, 16));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(140, 10, 261, 141));
        textEdit->setReadOnly(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 180, 111, 21));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(270, 210, 120, 80));
        layoutWidget_2 = new QWidget(widget_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 97, 44));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonComplexe = new QRadioButton(layoutWidget_2);
        radioButtonComplexe->setObjectName(QString::fromUtf8("radioButtonComplexe"));
        radioButtonComplexe->setChecked(true);

        verticalLayout_3->addWidget(radioButtonComplexe);

        radioButtonNonComplexe = new QRadioButton(layoutWidget_2);
        radioButtonNonComplexe->setObjectName(QString::fromUtf8("radioButtonNonComplexe"));

        verticalLayout_3->addWidget(radioButtonNonComplexe);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 180, 261, 21));
        lineEdit->setReadOnly(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 210, 111, 80));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 91, 68));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonEntiere = new QRadioButton(layoutWidget);
        radioButtonEntiere->setObjectName(QString::fromUtf8("radioButtonEntiere"));
        radioButtonEntiere->setChecked(false);

        verticalLayout->addWidget(radioButtonEntiere);

        radioButtonRationnelle = new QRadioButton(layoutWidget);
        radioButtonRationnelle->setObjectName(QString::fromUtf8("radioButtonRationnelle"));

        verticalLayout->addWidget(radioButtonRationnelle);

        radioButtonReelle = new QRadioButton(layoutWidget);
        radioButtonReelle->setObjectName(QString::fromUtf8("radioButtonReelle"));
        radioButtonReelle->setChecked(true);

        verticalLayout->addWidget(radioButtonReelle);

        keyBoard = new QFrame(centralWidget);
        keyBoard->setObjectName(QString::fromUtf8("keyBoard"));
        keyBoard->setGeometry(QRect(0, 310, 491, 291));
        keyBoard->setFrameShape(QFrame::StyledPanel);
        keyBoard->setFrameShadow(QFrame::Raised);
        layoutWidget_6 = new QWidget(keyBoard);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(20, 10, 453, 269));
        gridLayout_4 = new QGridLayout(layoutWidget_6);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button9 = new QPushButton(layoutWidget_6);
        button9->setObjectName(QString::fromUtf8("button9"));

        gridLayout->addWidget(button9, 0, 0, 1, 1);

        button8 = new QPushButton(layoutWidget_6);
        button8->setObjectName(QString::fromUtf8("button8"));

        gridLayout->addWidget(button8, 0, 1, 1, 1);

        button7 = new QPushButton(layoutWidget_6);
        button7->setObjectName(QString::fromUtf8("button7"));

        gridLayout->addWidget(button7, 0, 2, 1, 1);

        button6 = new QPushButton(layoutWidget_6);
        button6->setObjectName(QString::fromUtf8("button6"));

        gridLayout->addWidget(button6, 1, 0, 1, 1);

        button5 = new QPushButton(layoutWidget_6);
        button5->setObjectName(QString::fromUtf8("button5"));

        gridLayout->addWidget(button5, 1, 1, 1, 1);

        button4 = new QPushButton(layoutWidget_6);
        button4->setObjectName(QString::fromUtf8("button4"));

        gridLayout->addWidget(button4, 1, 2, 1, 1);

        button3 = new QPushButton(layoutWidget_6);
        button3->setObjectName(QString::fromUtf8("button3"));

        gridLayout->addWidget(button3, 2, 0, 1, 1);

        button2 = new QPushButton(layoutWidget_6);
        button2->setObjectName(QString::fromUtf8("button2"));

        gridLayout->addWidget(button2, 2, 1, 1, 1);

        button1 = new QPushButton(layoutWidget_6);
        button1->setObjectName(QString::fromUtf8("button1"));

        gridLayout->addWidget(button1, 2, 2, 1, 1);

        buttonEntrer = new QPushButton(layoutWidget_6);
        buttonEntrer->setObjectName(QString::fromUtf8("buttonEntrer"));

        gridLayout->addWidget(buttonEntrer, 5, 0, 1, 1);

        buttonAnnuler = new QPushButton(layoutWidget_6);
        buttonAnnuler->setObjectName(QString::fromUtf8("buttonAnnuler"));

        gridLayout->addWidget(buttonAnnuler, 5, 1, 1, 1);

        buttonRetablir = new QPushButton(layoutWidget_6);
        buttonRetablir->setObjectName(QString::fromUtf8("buttonRetablir"));

        gridLayout->addWidget(buttonRetablir, 5, 2, 1, 1);

        buttonDollar = new QPushButton(layoutWidget_6);
        buttonDollar->setObjectName(QString::fromUtf8("buttonDollar"));

        gridLayout->addWidget(buttonDollar, 3, 0, 1, 1);

        button0 = new QPushButton(layoutWidget_6);
        button0->setObjectName(QString::fromUtf8("button0"));

        gridLayout->addWidget(button0, 3, 1, 1, 1);

        buttonVirgule = new QPushButton(layoutWidget_6);
        buttonVirgule->setObjectName(QString::fromUtf8("buttonVirgule"));

        gridLayout->addWidget(buttonVirgule, 3, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        divButton = new QPushButton(layoutWidget_6);
        divButton->setObjectName(QString::fromUtf8("divButton"));

        gridLayout_2->addWidget(divButton, 0, 0, 1, 1);

        buttonPow = new QPushButton(layoutWidget_6);
        buttonPow->setObjectName(QString::fromUtf8("buttonPow"));

        gridLayout_2->addWidget(buttonPow, 0, 1, 1, 1);

        mulButton = new QPushButton(layoutWidget_6);
        mulButton->setObjectName(QString::fromUtf8("mulButton"));

        gridLayout_2->addWidget(mulButton, 1, 0, 1, 1);

        buttonMod = new QPushButton(layoutWidget_6);
        buttonMod->setObjectName(QString::fromUtf8("buttonMod"));

        gridLayout_2->addWidget(buttonMod, 1, 1, 1, 1);

        subButton = new QPushButton(layoutWidget_6);
        subButton->setObjectName(QString::fromUtf8("subButton"));

        gridLayout_2->addWidget(subButton, 2, 0, 1, 1);

        addButton = new QPushButton(layoutWidget_6);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout_2->addWidget(addButton, 3, 0, 1, 1);

        buttonSign = new QPushButton(layoutWidget_6);
        buttonSign->setObjectName(QString::fromUtf8("buttonSign"));

        gridLayout_2->addWidget(buttonSign, 2, 1, 1, 1);

        buttonExp = new QPushButton(layoutWidget_6);
        buttonExp->setObjectName(QString::fromUtf8("buttonExp"));

        gridLayout_2->addWidget(buttonExp, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        buttonSin = new QPushButton(layoutWidget_6);
        buttonSin->setObjectName(QString::fromUtf8("buttonSin"));

        gridLayout_3->addWidget(buttonSin, 0, 0, 1, 1);

        buttonSinh = new QPushButton(layoutWidget_6);
        buttonSinh->setObjectName(QString::fromUtf8("buttonSinh"));

        gridLayout_3->addWidget(buttonSinh, 0, 1, 1, 1);

        buttonLn = new QPushButton(layoutWidget_6);
        buttonLn->setObjectName(QString::fromUtf8("buttonLn"));

        gridLayout_3->addWidget(buttonLn, 0, 2, 1, 1);

        buttonSqrt = new QPushButton(layoutWidget_6);
        buttonSqrt->setObjectName(QString::fromUtf8("buttonSqrt"));

        gridLayout_3->addWidget(buttonSqrt, 0, 3, 1, 1);

        buttonFacto = new QPushButton(layoutWidget_6);
        buttonFacto->setObjectName(QString::fromUtf8("buttonFacto"));

        gridLayout_3->addWidget(buttonFacto, 0, 4, 1, 1);

        buttonCos = new QPushButton(layoutWidget_6);
        buttonCos->setObjectName(QString::fromUtf8("buttonCos"));

        gridLayout_3->addWidget(buttonCos, 1, 0, 1, 1);

        buttonCosh = new QPushButton(layoutWidget_6);
        buttonCosh->setObjectName(QString::fromUtf8("buttonCosh"));

        gridLayout_3->addWidget(buttonCosh, 1, 1, 1, 1);

        buttonLog = new QPushButton(layoutWidget_6);
        buttonLog->setObjectName(QString::fromUtf8("buttonLog"));

        gridLayout_3->addWidget(buttonLog, 1, 2, 1, 1);

        buttonSqr = new QPushButton(layoutWidget_6);
        buttonSqr->setObjectName(QString::fromUtf8("buttonSqr"));

        gridLayout_3->addWidget(buttonSqr, 1, 3, 1, 1);

        buttonEval = new QPushButton(layoutWidget_6);
        buttonEval->setObjectName(QString::fromUtf8("buttonEval"));

        gridLayout_3->addWidget(buttonEval, 1, 4, 1, 1);

        buttonTan = new QPushButton(layoutWidget_6);
        buttonTan->setObjectName(QString::fromUtf8("buttonTan"));

        gridLayout_3->addWidget(buttonTan, 2, 0, 1, 1);

        buttonTanh = new QPushButton(layoutWidget_6);
        buttonTanh->setObjectName(QString::fromUtf8("buttonTanh"));

        gridLayout_3->addWidget(buttonTanh, 2, 1, 1, 1);

        buttonInv = new QPushButton(layoutWidget_6);
        buttonInv->setObjectName(QString::fromUtf8("buttonInv"));

        gridLayout_3->addWidget(buttonInv, 2, 2, 1, 1);

        buttonCube = new QPushButton(layoutWidget_6);
        buttonCube->setObjectName(QString::fromUtf8("buttonCube"));

        gridLayout_3->addWidget(buttonCube, 2, 3, 1, 1);

        buttonPI = new QPushButton(layoutWidget_6);
        buttonPI->setObjectName(QString::fromUtf8("buttonPI"));

        gridLayout_3->addWidget(buttonPI, 2, 4, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);

        spaceButton = new QPushButton(centralWidget);
        spaceButton->setObjectName(QString::fromUtf8("spaceButton"));
        spaceButton->setGeometry(QRect(400, 250, 75, 23));
        supprButton = new QPushButton(centralWidget);
        supprButton->setObjectName(QString::fromUtf8("supprButton"));
        supprButton->setGeometry(QRect(400, 220, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 493, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        hide_button->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        labelException->setText(QString());
        radioButtonRadiant->setText(QApplication::translate("MainWindow", "Radiant", 0, QApplication::UnicodeUTF8));
        radioButtonDegre->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        show_keyboard->setText(QApplication::translate("MainWindow", "v", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Ligne de commande:", 0, QApplication::UnicodeUTF8));
        radioButtonComplexe->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        radioButtonNonComplexe->setText(QApplication::translate("MainWindow", "Non Complexe", 0, QApplication::UnicodeUTF8));
        radioButtonEntiere->setText(QApplication::translate("MainWindow", "Enti\303\250re", 0, QApplication::UnicodeUTF8));
        radioButtonRationnelle->setText(QApplication::translate("MainWindow", "Rationnelle", 0, QApplication::UnicodeUTF8));
        radioButtonReelle->setText(QApplication::translate("MainWindow", "R\303\251elle", 0, QApplication::UnicodeUTF8));
        button9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        button9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        button8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        button8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        button7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        button7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        button6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        button6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        button5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        button5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        button4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        button4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        button3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        button3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        button2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        button2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        button1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        button1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        buttonEntrer->setText(QApplication::translate("MainWindow", "Entrer", 0, QApplication::UnicodeUTF8));
        buttonEntrer->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        buttonAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        buttonAnnuler->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        buttonRetablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        buttonRetablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        buttonDollar->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        buttonDollar->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        button0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        button0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        buttonVirgule->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        buttonVirgule->setShortcut(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        divButton->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        divButton->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        buttonPow->setText(QApplication::translate("MainWindow", "Pow", 0, QApplication::UnicodeUTF8));
        buttonPow->setShortcut(QApplication::translate("MainWindow", "P, O, W", 0, QApplication::UnicodeUTF8));
        mulButton->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        mulButton->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        buttonMod->setText(QApplication::translate("MainWindow", "Mod", 0, QApplication::UnicodeUTF8));
        buttonMod->setShortcut(QApplication::translate("MainWindow", "M, O, D", 0, QApplication::UnicodeUTF8));
        subButton->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        subButton->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        addButton->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        buttonSign->setText(QApplication::translate("MainWindow", "Sign", 0, QApplication::UnicodeUTF8));
        buttonSign->setShortcut(QApplication::translate("MainWindow", "S, I, G, N", 0, QApplication::UnicodeUTF8));
        buttonExp->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        buttonExp->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        buttonSin->setText(QApplication::translate("MainWindow", "Sin", 0, QApplication::UnicodeUTF8));
        buttonSin->setShortcut(QApplication::translate("MainWindow", "S, I, N", 0, QApplication::UnicodeUTF8));
        buttonSinh->setText(QApplication::translate("MainWindow", "Sinh (sh)", 0, QApplication::UnicodeUTF8));
        buttonSinh->setShortcut(QApplication::translate("MainWindow", "S, H", 0, QApplication::UnicodeUTF8));
        buttonLn->setText(QApplication::translate("MainWindow", "Ln", 0, QApplication::UnicodeUTF8));
        buttonLn->setShortcut(QApplication::translate("MainWindow", "L, N", 0, QApplication::UnicodeUTF8));
        buttonSqrt->setText(QApplication::translate("MainWindow", "Sqrt", 0, QApplication::UnicodeUTF8));
        buttonSqrt->setShortcut(QApplication::translate("MainWindow", "S, Q, R, T", 0, QApplication::UnicodeUTF8));
        buttonFacto->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        buttonFacto->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        buttonCos->setText(QApplication::translate("MainWindow", "Cos", 0, QApplication::UnicodeUTF8));
        buttonCos->setShortcut(QApplication::translate("MainWindow", "C, O, S", 0, QApplication::UnicodeUTF8));
        buttonCosh->setText(QApplication::translate("MainWindow", "Cosh (ch)", 0, QApplication::UnicodeUTF8));
        buttonCosh->setShortcut(QApplication::translate("MainWindow", "C, H", 0, QApplication::UnicodeUTF8));
        buttonLog->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        buttonLog->setShortcut(QApplication::translate("MainWindow", "L, O, G", 0, QApplication::UnicodeUTF8));
        buttonSqr->setText(QApplication::translate("MainWindow", "Sqr", 0, QApplication::UnicodeUTF8));
        buttonSqr->setShortcut(QApplication::translate("MainWindow", "S, Q, R", 0, QApplication::UnicodeUTF8));
        buttonEval->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        buttonEval->setShortcut(QApplication::translate("MainWindow", "E, V, A, L", 0, QApplication::UnicodeUTF8));
        buttonTan->setText(QApplication::translate("MainWindow", "Tan", 0, QApplication::UnicodeUTF8));
        buttonTan->setShortcut(QApplication::translate("MainWindow", "T, A, N", 0, QApplication::UnicodeUTF8));
        buttonTanh->setText(QApplication::translate("MainWindow", "Tanh (th)", 0, QApplication::UnicodeUTF8));
        buttonTanh->setShortcut(QApplication::translate("MainWindow", "T, H", 0, QApplication::UnicodeUTF8));
        buttonInv->setText(QApplication::translate("MainWindow", "Inv", 0, QApplication::UnicodeUTF8));
        buttonInv->setShortcut(QApplication::translate("MainWindow", "I, N, V", 0, QApplication::UnicodeUTF8));
        buttonCube->setText(QApplication::translate("MainWindow", "Cube", 0, QApplication::UnicodeUTF8));
        buttonCube->setShortcut(QApplication::translate("MainWindow", "C, U, B, E", 0, QApplication::UnicodeUTF8));
        buttonPI->setText(QApplication::translate("MainWindow", "PI", 0, QApplication::UnicodeUTF8));
        buttonPI->setShortcut(QApplication::translate("MainWindow", "P, I", 0, QApplication::UnicodeUTF8));
        spaceButton->setText(QApplication::translate("MainWindow", "Espace", 0, QApplication::UnicodeUTF8));
        spaceButton->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        supprButton->setText(QApplication::translate("MainWindow", "Retour", 0, QApplication::UnicodeUTF8));
        supprButton->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
