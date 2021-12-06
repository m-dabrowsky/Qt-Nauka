/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Tue 25. Dec 09:26:32 2007
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
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLabel *labelHTTP;
    QLineEdit *lineEdit;
    QPushButton *pushButtonGet;
    QPushButton *pushButtonQuit;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(534, 117);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    gridLayout = new QGridLayout(Form);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    labelHTTP = new QLabel(Form);
    labelHTTP->setObjectName(QString::fromUtf8("labelHTTP"));

    gridLayout->addWidget(labelHTTP, 0, 0, 1, 1);

    lineEdit = new QLineEdit(Form);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 1, 0, 1, 3);

    pushButtonGet = new QPushButton(Form);
    pushButtonGet->setObjectName(QString::fromUtf8("pushButtonGet"));

    gridLayout->addWidget(pushButtonGet, 2, 1, 1, 1);

    pushButtonQuit = new QPushButton(Form);
    pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));

    gridLayout->addWidget(pushButtonQuit, 2, 2, 1, 1);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Pobieranie pliku w protokole HTTP", 0, QApplication::UnicodeUTF8));
    labelHTTP->setText(QApplication::translate("Form", "Podaj adres:", 0, QApplication::UnicodeUTF8));
    lineEdit->setToolTip(QApplication::translate("Form", "Adres URI zasobu (pliku)", 0, QApplication::UnicodeUTF8));
    lineEdit->setText(QApplication::translate("Form", "http://", 0, QApplication::UnicodeUTF8));
    pushButtonGet->setToolTip(QApplication::translate("Form", "Pobierz wsskazany plik", 0, QApplication::UnicodeUTF8));
    pushButtonGet->setText(QApplication::translate("Form", "Pobierz", 0, QApplication::UnicodeUTF8));
    pushButtonQuit->setToolTip(QApplication::translate("Form", "Zako\305\204czenie dzia\305\202ania programu", 0, QApplication::UnicodeUTF8));
    pushButtonQuit->setText(QApplication::translate("Form", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
