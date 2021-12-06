/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Sat 16. Feb 18:57:56 2008
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
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLabel *label;
    QSpacerItem *spacerItem;
    QPushButton *pushButtonThread;
    QPushButton *pushButtonStd;

    void setupUi(QDialog *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(258, 436);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    gridLayout = new QGridLayout(Form);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    listWidget = new QListWidget(Form);
    listWidget->setObjectName(QString::fromUtf8("listWidget"));

    gridLayout->addWidget(listWidget, 0, 0, 1, 3);

    label = new QLabel(Form);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 1, 0, 1, 2);

    spacerItem = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(spacerItem, 2, 0, 1, 1);

    pushButtonThread = new QPushButton(Form);
    pushButtonThread->setObjectName(QString::fromUtf8("pushButtonThread"));

    gridLayout->addWidget(pushButtonThread, 2, 2, 1, 1);

    pushButtonStd = new QPushButton(Form);
    pushButtonStd->setObjectName(QString::fromUtf8("pushButtonStd"));

    gridLayout->addWidget(pushButtonStd, 2, 1, 1, 1);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QDialog *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Liczby pierwsze", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Form", "Pozosta\305\202o w\304\205tk\303\263w:", 0, QApplication::UnicodeUTF8));
    pushButtonThread->setText(QApplication::translate("Form", "W\304\205tki", 0, QApplication::UnicodeUTF8));
    pushButtonStd->setText(QApplication::translate("Form", "Standard", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
