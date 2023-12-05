/********************************************************************************
** Form generated from reading UI file 'findeljuego.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDELJUEGO_H
#define UI_FINDELJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Findeljuego
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *Findeljuego)
    {
        if (Findeljuego->objectName().isEmpty())
            Findeljuego->setObjectName(QString::fromUtf8("Findeljuego"));
        Findeljuego->resize(840, 486);
        gridLayout = new QGridLayout(Findeljuego);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Findeljuego);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Personaje/Fondo/gamerover.jpg")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Findeljuego);

        QMetaObject::connectSlotsByName(Findeljuego);
    } // setupUi

    void retranslateUi(QWidget *Findeljuego)
    {
        Findeljuego->setWindowTitle(QCoreApplication::translate("Findeljuego", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Findeljuego: public Ui_Findeljuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDELJUEGO_H
