/********************************************************************************
** Form generated from reading UI file 'registrarse.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRARSE_H
#define UI_REGISTRARSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registrarse
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Usuario;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_Contrasea;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Registrarse)
    {
        if (Registrarse->objectName().isEmpty())
            Registrarse->setObjectName(QString::fromUtf8("Registrarse"));
        Registrarse->resize(468, 310);
        Registrarse->setStyleSheet(QString::fromUtf8("background-image: url(:/Personaje/menu/Fondo_2.jpg);"));
        groupBox = new QGroupBox(Registrarse);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(70, 90, 291, 161));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(26, 30, 184, 22));
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

        horizontalLayout->addWidget(lineEdit_Usuario);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(16, 70, 221, 31));
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
        lineEdit_Contrasea->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Contrasea);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 110, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(Registrarse);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 20, 61, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        retranslateUi(Registrarse);

        QMetaObject::connectSlotsByName(Registrarse);
    } // setupUi

    void retranslateUi(QWidget *Registrarse)
    {
        Registrarse->setWindowTitle(QCoreApplication::translate("Registrarse", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Registrarse", "Nuevo Usuario", nullptr));
        label->setText(QCoreApplication::translate("Registrarse", "Usuario", nullptr));
        label_2->setText(QCoreApplication::translate("Registrarse", "Contrase\303\261a", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton->setWhatsThis(QCoreApplication::translate("Registrarse", "<html><head/><body><p>cxsda</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton->setText(QCoreApplication::translate("Registrarse", "Login", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("Registrarse", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QCoreApplication::translate("Registrarse", "Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registrarse: public Ui_Registrarse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRARSE_H
