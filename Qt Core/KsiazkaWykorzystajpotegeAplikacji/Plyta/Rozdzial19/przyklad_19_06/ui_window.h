/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Fri 8. Feb 05:31:59 2008
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
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QTableView *tableView;
    QSpacerItem *spacerItem;
    QPushButton *pushButtonDeleteBook;
    QPushButton *pushButtonNewBook;
    QPushButton *pushButtonNewAuthor;
    QSpacerItem *spacerItem1;
    QPushButton *pushButtonExit;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(580, 390);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    gridLayout = new QGridLayout(Form);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(Form);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    tableView = new QTableView(groupBox);
    tableView->setObjectName(QString::fromUtf8("tableView"));

    gridLayout1->addWidget(tableView, 0, 0, 1, 4);

    spacerItem = new QSpacerItem(341, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout1->addItem(spacerItem, 1, 0, 1, 1);

    pushButtonDeleteBook = new QPushButton(groupBox);
    pushButtonDeleteBook->setObjectName(QString::fromUtf8("pushButtonDeleteBook"));

    gridLayout1->addWidget(pushButtonDeleteBook, 1, 1, 1, 1);

    pushButtonNewBook = new QPushButton(groupBox);
    pushButtonNewBook->setObjectName(QString::fromUtf8("pushButtonNewBook"));

    gridLayout1->addWidget(pushButtonNewBook, 1, 2, 1, 1);

    pushButtonNewAuthor = new QPushButton(groupBox);
    pushButtonNewAuthor->setObjectName(QString::fromUtf8("pushButtonNewAuthor"));

    gridLayout1->addWidget(pushButtonNewAuthor, 1, 3, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 2);

    spacerItem1 = new QSpacerItem(461, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(spacerItem1, 1, 0, 1, 1);

    pushButtonExit = new QPushButton(Form);
    pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));

    gridLayout->addWidget(pushButtonExit, 1, 1, 1, 1);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Baza danych SQL", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Form", "Ksi\304\205\305\274ki i autorzy", 0, QApplication::UnicodeUTF8));
    pushButtonDeleteBook->setText(QApplication::translate("Form", "Usu\305\204 ks\304\205\305\274k\304\231", 0, QApplication::UnicodeUTF8));
    pushButtonNewBook->setText(QApplication::translate("Form", "Nowa ksi\304\205\305\274ka", 0, QApplication::UnicodeUTF8));
    pushButtonNewAuthor->setText(QApplication::translate("Form", "Nowy autor", 0, QApplication::UnicodeUTF8));
    pushButtonExit->setText(QApplication::translate("Form", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
