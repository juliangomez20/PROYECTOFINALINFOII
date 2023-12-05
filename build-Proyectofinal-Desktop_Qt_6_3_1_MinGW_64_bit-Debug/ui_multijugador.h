/********************************************************************************
** Form generated from reading UI file 'multijugador.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIJUGADOR_H
#define UI_MULTIJUGADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multijugador
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Multijugador)
    {
        if (Multijugador->objectName().isEmpty())
            Multijugador->setObjectName(QString::fromUtf8("Multijugador"));
        Multijugador->resize(1200, 600);
        graphicsView = new QGraphicsView(Multijugador);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1200, 600));

        retranslateUi(Multijugador);

        QMetaObject::connectSlotsByName(Multijugador);
    } // setupUi

    void retranslateUi(QWidget *Multijugador)
    {
        Multijugador->setWindowTitle(QCoreApplication::translate("Multijugador", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multijugador: public Ui_Multijugador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIJUGADOR_H
