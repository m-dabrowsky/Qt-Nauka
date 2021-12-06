/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Thu 13. Dec 04:53:14 2007
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_1;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(431, 235);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    pushButton_1 = new QPushButton(Form);
    pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
    pushButton_1->setGeometry(QRect(10, 10, 413, 27));
    pushButton_2 = new QPushButton(Form);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(10, 50, 413, 27));
    pushButton_3 = new QPushButton(Form);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(10, 90, 413, 27));
    pushButton_4 = new QPushButton(Form);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(10, 130, 413, 27));
    label_1 = new QLabel(Form);
    label_1->setObjectName(QString::fromUtf8("label_1"));
    label_1->setGeometry(QRect(10, 170, 411, 18));
    label_2 = new QLabel(Form);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 200, 411, 18));

    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Okna pobierania danych", 0, QApplication::UnicodeUTF8));
    pushButton_1->setText(QApplication::translate("Form", "QInputDialog::getDouble", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("Form", "QInputDialog::getInteger", 0, QApplication::UnicodeUTF8));
    pushButton_3->setText(QApplication::translate("Form", "QInputDialog::getItem", 0, QApplication::UnicodeUTF8));
    pushButton_4->setText(QApplication::translate("Form", "QInputDialog::getText", 0, QApplication::UnicodeUTF8));
    label_1->setText(QString());
    label_2->setText(QString());
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
