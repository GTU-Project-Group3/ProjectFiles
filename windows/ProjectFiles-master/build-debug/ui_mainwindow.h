/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDoktor_Ekle;
    QAction *actionHem_ire_Ekle;
    QAction *actionHasta_Ekle;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *msg;
    QTableWidget *TableDoktor;
    QTableWidget *TableHasta;
    QWidget *page_2;
    QMenuBar *menuBar;
    QMenu *menuSe_enekler;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1602, 742);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1602, 768));
        actionDoktor_Ekle = new QAction(MainWindow);
        actionDoktor_Ekle->setObjectName(QStringLiteral("actionDoktor_Ekle"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/messageDoctor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDoktor_Ekle->setIcon(icon);
        actionHem_ire_Ekle = new QAction(MainWindow);
        actionHem_ire_Ekle->setObjectName(QStringLiteral("actionHem_ire_Ekle"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/messageNurse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHem_ire_Ekle->setIcon(icon1);
        actionHasta_Ekle = new QAction(MainWindow);
        actionHasta_Ekle->setObjectName(QStringLiteral("actionHasta_Ekle"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/messageUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHasta_Ekle->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QLatin1String("color:rgb(52, 101, 164);\n"
"font: 75 italic 12pt \"Noto Sans\";\n"
"height:12pt;\n"
""));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        msg = new QLabel(page);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(msg);

        TableDoktor = new QTableWidget(page);
        TableDoktor->setObjectName(QStringLiteral("TableDoktor"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TableDoktor->sizePolicy().hasHeightForWidth());
        TableDoktor->setSizePolicy(sizePolicy2);
        TableDoktor->setMinimumSize(QSize(400, 0));
        TableDoktor->setMaximumSize(QSize(400, 16777215));
        TableDoktor->setAutoFillBackground(true);
        TableDoktor->setStyleSheet(QLatin1String("color: rgb(32, 74, 135);\n"
""));
        TableDoktor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableDoktor->setAutoScroll(false);
        TableDoktor->setSelectionMode(QAbstractItemView::NoSelection);
        TableDoktor->setSortingEnabled(true);

        horizontalLayout_3->addWidget(TableDoktor);

        TableHasta = new QTableWidget(page);
        TableHasta->setObjectName(QStringLiteral("TableHasta"));
        TableHasta->setEnabled(true);
        sizePolicy2.setHeightForWidth(TableHasta->sizePolicy().hasHeightForWidth());
        TableHasta->setSizePolicy(sizePolicy2);
        TableHasta->setMinimumSize(QSize(620, 600));
        TableHasta->setMaximumSize(QSize(620, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        TableHasta->setFont(font);
        TableHasta->setLayoutDirection(Qt::LeftToRight);
        TableHasta->setAutoFillBackground(true);
        TableHasta->setStyleSheet(QLatin1String("color: rgb(32, 74, 135);\n"
""));
        TableHasta->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableHasta->setAutoScroll(false);
        TableHasta->setSelectionMode(QAbstractItemView::NoSelection);
        TableHasta->setGridStyle(Qt::SolidLine);
        TableHasta->setSortingEnabled(true);
        TableHasta->setWordWrap(true);
        TableHasta->setCornerButtonEnabled(true);

        horizontalLayout_3->addWidget(TableHasta);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1602, 21));
        menuSe_enekler = new QMenu(menuBar);
        menuSe_enekler->setObjectName(QStringLiteral("menuSe_enekler"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSe_enekler->menuAction());
        menuSe_enekler->addSeparator();
        menuSe_enekler->addAction(actionDoktor_Ekle);
        menuSe_enekler->addAction(actionHem_ire_Ekle);
        menuSe_enekler->addAction(actionHasta_Ekle);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionDoktor_Ekle->setText(QApplication::translate("MainWindow", "Doktor Ekle", 0));
        actionHem_ire_Ekle->setText(QApplication::translate("MainWindow", "Hem\305\237ire Ekle", 0));
        actionHasta_Ekle->setText(QApplication::translate("MainWindow", "Hasta Ekle", 0));
        label->setText(QApplication::translate("MainWindow", "Gebze Teknik \303\234niversitesi", 0));
        msg->setText(QString());
        menuSe_enekler->setTitle(QApplication::translate("MainWindow", "Se\303\247enekler", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
