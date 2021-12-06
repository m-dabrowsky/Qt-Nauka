/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Thu 14. Feb 19:00:20 2008
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
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

class Ui_Form
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(259, 71);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    vboxLayout = new QVBoxLayout(Form);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label = new QLabel(Form);
    label->setObjectName(QString::fromUtf8("label"));

    vboxLayout->addWidget(label);

    pushButton = new QPushButton(Form);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    vboxLayout->addWidget(pushButton);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QDialog *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "W\304\205tki bez synchronizacji", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Form", "a = ", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("Form", "Start", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
