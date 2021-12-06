/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Thu 3. Jan 20:59:41 2008
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "glwidget.h"

class Ui_Form
{
public:
    QVBoxLayout *vboxLayout;
    GLWidget *glwidget;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(345, 272);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    vboxLayout = new QVBoxLayout(Form);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    glwidget = new GLWidget(Form);
    glwidget->setObjectName(QString::fromUtf8("glwidget"));

    vboxLayout->addWidget(glwidget);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Okno OpenGL", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
