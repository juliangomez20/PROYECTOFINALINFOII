/********************************************************************************
** Form generated from reading UI file 'iniciodesesion.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIODESESION_H
#define UI_INICIODESESION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Iniciodesesion
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Usuario;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_Contrasea;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Iniciodesesion)
    {
        if (Iniciodesesion->objectName().isEmpty())
            Iniciodesesion->setObjectName(QString::fromUtf8("Iniciodesesion"));
        Iniciodesesion->resize(400, 300);
        Iniciodesesion->setStyleSheet(QString::fromUtf8("image: url(:/Personaje/menu/Fondo_2.jpg);\n"
"background-image: url(:/Personaje/menu/Fondo_2.jpg);"));
        groupBox = new QGroupBox(Iniciodesesion);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 80, 261, 161));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 100, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 177, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);

        lineEdit_Usuario = new QLineEdit(layoutWidget);
        lineEdit_Usuario->setObjectName(QString::fromUtf8("lineEdit_Usuario"));
        lineEdit_Usuario->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lineEdit_Usuario);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 60, 197, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_Contrasea = new QLineEdit(layoutWidget_2);
        lineEdit_Contrasea->setObjectName(QString::fromUtf8("lineEdit_Contrasea"));
        lineEdit_Contrasea->setStyleSheet(QString::fromUtf8(""));
        lineEdit_Contrasea->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Contrasea);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 100, 91, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(Iniciodesesion);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 10, 81, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        retranslateUi(Iniciodesesion);

        QMetaObject::connectSlotsByName(Iniciodesesion);
    } // setupUi

    void retranslateUi(QWidget *Iniciodesesion)
    {
        Iniciodesesion->setWindowTitle(QCoreApplication::translate("Iniciodesesion", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Iniciodesesion", "Iniciar Sesion", nullptr));
        pushButton->setText(QCoreApplication::translate("Iniciodesesion", "Login", nullptr));
        label->setText(QCoreApplication::translate("Iniciodesesion", "Usuario", nullptr));
        label_2->setText(QCoreApplication::translate("Iniciodesesion", "Contrase\303\261a", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Iniciodesesion", "Registrarse", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Iniciodesesion", "Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Iniciodesesion: public Ui_Iniciodesesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIODESESION_H
