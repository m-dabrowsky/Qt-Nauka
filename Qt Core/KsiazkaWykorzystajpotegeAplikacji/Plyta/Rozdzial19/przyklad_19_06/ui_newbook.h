/********************************************************************************
** Form generated from reading ui file 'newbook.ui'
**
** Created: Sat 9. Feb 13:24:33 2008
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEWBOOK_H
#define UI_NEWBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTreeView>

class Ui_DialogNewBook
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEditTYTUL;
    QLabel *label;
    QLabel *label_2;
    QTreeView *treeView;

    void setupUi(QDialog *DialogNewBook)
    {
    if (DialogNewBook->objectName().isEmpty())
        DialogNewBook->setObjectName(QString::fromUtf8("DialogNewBook"));
    DialogNewBook->resize(308, 228);
    DialogNewBook->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    gridLayout = new QGridLayout(DialogNewBook);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    buttonBox = new QDialogButtonBox(DialogNewBook);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    gridLayout->addWidget(buttonBox, 8, 0, 1, 1);

    lineEditTYTUL = new QLineEdit(DialogNewBook);
    lineEditTYTUL->setObjectName(QString::fromUtf8("lineEditTYTUL"));
    lineEditTYTUL->setMaxLength(20);

    gridLayout->addWidget(lineEditTYTUL, 1, 0, 1, 1);

    label = new QLabel(DialogNewBook);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    label_2 = new QLabel(DialogNewBook);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 2, 0, 1, 1);

    treeView = new QTreeView(DialogNewBook);
    treeView->setObjectName(QString::fromUtf8("treeView"));

    gridLayout->addWidget(treeView, 3, 0, 5, 1);

    QWidget::setTabOrder(lineEditTYTUL, buttonBox);

    retranslateUi(DialogNewBook);
    QObject::connect(buttonBox, SIGNAL(accepted()), DialogNewBook, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), DialogNewBook, SLOT(reject()));

    QMetaObject::connectSlotsByName(DialogNewBook);
    } // setupUi

    void retranslateUi(QDialog *DialogNewBook)
    {
    DialogNewBook->setWindowTitle(QApplication::translate("DialogNewBook", "Nowa ksi\304\205\305\274ka", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("DialogNewBook", "Podaj tytu\305\202", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("DialogNewBook", "Wybierz autora", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(DialogNewBook);
    } // retranslateUi

};

namespace Ui {
    class DialogNewBook: public Ui_DialogNewBook {};
} // namespace Ui

#endif // UI_NEWBOOK_H
