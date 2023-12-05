/********************************************************************************
** Form generated from reading UI file 'winer.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINER_H
#define UI_WINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Winer
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *Winer)
    {
        if (Winer->objectName().isEmpty())
            Winer->setObjectName(QString::fromUtf8("Winer"));
        Winer->resize(969, 428);
        gridLayout = new QGridLayout(Winer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Winer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Personaje/Fondo/Win.jpg")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Winer);

        QMetaObject::connectSlotsByName(Winer);
    } // setupUi

    void retranslateUi(QWidget *Winer)
    {
        Winer->setWindowTitle(QCoreApplication::translate("Winer", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Winer: public Ui_Winer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINER_H
