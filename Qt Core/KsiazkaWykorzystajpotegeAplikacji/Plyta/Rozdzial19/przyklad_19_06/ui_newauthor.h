/********************************************************************************
** Form generated from reading ui file 'newauthor.ui'
**
** Created: Thu 7. Feb 18:39:18 2008
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEWAUTHOR_H
#define UI_NEWAUTHOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

class Ui_DialogNewAuthor
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEditNAZWISKO;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEditIMIE;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *DialogNewAuthor)
    {
    if (DialogNewAuthor->objectName().isEmpty())
        DialogNewAuthor->setObjectName(QString::fromUtf8("DialogNewAuthor"));
    DialogNewAuthor->resize(308, 153);
    DialogNewAuthor->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    gridLayout = new QGridLayout(DialogNewAuthor);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    lineEditNAZWISKO = new QLineEdit(DialogNewAuthor);
    lineEditNAZWISKO->setObjectName(QString::fromUtf8("lineEditNAZWISKO"));

    gridLayout->addWidget(lineEditNAZWISKO, 3, 0, 1, 1);

    buttonBox = new QDialogButtonBox(DialogNewAuthor);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    gridLayout->addWidget(buttonBox, 4, 0, 1, 1);

    lineEditIMIE = new QLineEdit(DialogNewAuthor);
    lineEditIMIE->setObjectName(QString::fromUtf8("lineEditIMIE"));
    lineEditIMIE->setMaxLength(20);

    gridLayout->addWidget(lineEditIMIE, 1, 0, 1, 1);

    label = new QLabel(DialogNewAuthor);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    label_2 = new QLabel(DialogNewAuthor);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 2, 0, 1, 1);

    QWidget::setTabOrder(lineEditIMIE, lineEditNAZWISKO);
    QWidget::setTabOrder(lineEditNAZWISKO, buttonBox);

    retranslateUi(DialogNewAuthor);
    QObject::connect(buttonBox, SIGNAL(accepted()), DialogNewAuthor, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), DialogNewAuthor, SLOT(reject()));

    QMetaObject::connectSlotsByName(DialogNewAuthor);
    } // setupUi

    void retranslateUi(QDialog *DialogNewAuthor)
    {
    DialogNewAuthor->setWindowTitle(QApplication::translate("DialogNewAuthor", "Nowy autor", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("DialogNewAuthor", "Podaj imi\304\231", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("DialogNewAuthor", "Podaj nazwisko", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(DialogNewAuthor);
    } // retranslateUi

};

namespace Ui {
    class DialogNewAuthor: public Ui_DialogNewAuthor {};
} // namespace Ui

#endif // UI_NEWAUTHOR_H
