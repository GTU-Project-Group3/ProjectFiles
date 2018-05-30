/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton;
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *doktorid;
    QLineEdit *nurseid;
    QLineEdit *kalp;
    QLineEdit *kan;
    QLineEdit *seker;
    QLineEdit *oda_numarasi;
    QLineEdit *pansuman;
    QLineEdit *tansiyon;
    QLabel *mesaj;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QStringLiteral("Dialog2"));
        Dialog2->resize(616, 572);
        label = new QLabel(Dialog2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 73, 18));
        label_2 = new QLabel(Dialog2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 73, 18));
        label_3 = new QLabel(Dialog2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 73, 18));
        label_4 = new QLabel(Dialog2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 150, 73, 18));
        label_5 = new QLabel(Dialog2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 190, 73, 18));
        label_6 = new QLabel(Dialog2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 230, 73, 18));
        label_7 = new QLabel(Dialog2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 270, 73, 18));
        label_8 = new QLabel(Dialog2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 310, 111, 18));
        label_9 = new QLabel(Dialog2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 350, 171, 18));
        label_10 = new QLabel(Dialog2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 390, 151, 18));
        pushButton = new QPushButton(Dialog2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 450, 106, 30));
        name = new QLineEdit(Dialog2);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(250, 20, 191, 30));
        surname = new QLineEdit(Dialog2);
        surname->setObjectName(QStringLiteral("surname"));
        surname->setGeometry(QRect(250, 60, 191, 30));
        doktorid = new QLineEdit(Dialog2);
        doktorid->setObjectName(QStringLiteral("doktorid"));
        doktorid->setGeometry(QRect(250, 100, 191, 30));
        nurseid = new QLineEdit(Dialog2);
        nurseid->setObjectName(QStringLiteral("nurseid"));
        nurseid->setGeometry(QRect(250, 140, 191, 30));
        kalp = new QLineEdit(Dialog2);
        kalp->setObjectName(QStringLiteral("kalp"));
        kalp->setGeometry(QRect(250, 180, 191, 30));
        kan = new QLineEdit(Dialog2);
        kan->setObjectName(QStringLiteral("kan"));
        kan->setGeometry(QRect(250, 220, 191, 30));
        seker = new QLineEdit(Dialog2);
        seker->setObjectName(QStringLiteral("seker"));
        seker->setGeometry(QRect(250, 260, 191, 30));
        oda_numarasi = new QLineEdit(Dialog2);
        oda_numarasi->setObjectName(QStringLiteral("oda_numarasi"));
        oda_numarasi->setGeometry(QRect(250, 300, 191, 30));
        pansuman = new QLineEdit(Dialog2);
        pansuman->setObjectName(QStringLiteral("pansuman"));
        pansuman->setGeometry(QRect(250, 340, 191, 30));
        tansiyon = new QLineEdit(Dialog2);
        tansiyon->setObjectName(QStringLiteral("tansiyon"));
        tansiyon->setGeometry(QRect(250, 380, 191, 30));
        mesaj = new QLabel(Dialog2);
        mesaj->setObjectName(QStringLiteral("mesaj"));
        mesaj->setGeometry(QRect(100, 510, 381, 20));

        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QApplication::translate("Dialog2", "Dialog", 0));
        label->setText(QApplication::translate("Dialog2", "Name", 0));
        label_2->setText(QApplication::translate("Dialog2", "Surname", 0));
        label_3->setText(QApplication::translate("Dialog2", "DoktorId", 0));
        label_4->setText(QApplication::translate("Dialog2", "NurseId", 0));
        label_5->setText(QApplication::translate("Dialog2", "Kalp", 0));
        label_6->setText(QApplication::translate("Dialog2", "Kan", 0));
        label_7->setText(QApplication::translate("Dialog2", "Seker", 0));
        label_8->setText(QApplication::translate("Dialog2", "Oda numaras\304\261", 0));
        label_9->setText(QApplication::translate("Dialog2", "Pansuman Kalan Sure", 0));
        label_10->setText(QApplication::translate("Dialog2", "Tansiyon Kalan Sure", 0));
        pushButton->setText(QApplication::translate("Dialog2", "Add", 0));
        mesaj->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
