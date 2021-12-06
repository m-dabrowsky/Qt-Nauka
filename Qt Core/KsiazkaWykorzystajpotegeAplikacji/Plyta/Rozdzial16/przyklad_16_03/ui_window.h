/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Fri 14. Dec 08:17:03 2007
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
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QVBoxLayout *vboxLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(317, 284);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    vboxLayout = new QVBoxLayout(Form);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    textEdit = new QTextEdit(Form);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));

    vboxLayout->addWidget(textEdit);

    pushButton_1 = new QPushButton(Form);
    pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));

    vboxLayout->addWidget(pushButton_1);

    pushButton_2 = new QPushButton(Form);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    vboxLayout->addWidget(pushButton_2);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Test czcionki i koloru", 0, QApplication::UnicodeUTF8));
    pushButton_1->setText(QApplication::translate("Form", "Wybierz kolor", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("Form", "Wybierz czcionk\304\231", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
