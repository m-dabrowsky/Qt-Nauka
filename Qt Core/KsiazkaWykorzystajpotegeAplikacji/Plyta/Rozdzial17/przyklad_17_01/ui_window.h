/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Sat 22. Dec 06:25:59 2007
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
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLabel *labelFTP;
    QLineEdit *lineEdit;
    QTreeWidget *treeWidget;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QPushButton *pushButtonCdUp;
    QPushButton *pushButtonGet;
    QFrame *line;
    QPushButton *pushButtonQuit;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(534, 345);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    gridLayout = new QGridLayout(Form);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    labelFTP = new QLabel(Form);
    labelFTP->setObjectName(QString::fromUtf8("labelFTP"));

    gridLayout->addWidget(labelFTP, 0, 0, 1, 1);

    lineEdit = new QLineEdit(Form);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 0, 1, 1, 4);

    treeWidget = new QTreeWidget(Form);
    treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
    treeWidget->setEnabled(false);

    gridLayout->addWidget(treeWidget, 1, 0, 1, 5);

    pushButtonConnect = new QPushButton(Form);
    pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

    gridLayout->addWidget(pushButtonConnect, 2, 1, 1, 1);

    pushButtonDisconnect = new QPushButton(Form);
    pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));
    pushButtonDisconnect->setEnabled(false);

    gridLayout->addWidget(pushButtonDisconnect, 2, 2, 1, 1);

    pushButtonCdUp = new QPushButton(Form);
    pushButtonCdUp->setObjectName(QString::fromUtf8("pushButtonCdUp"));
    pushButtonCdUp->setEnabled(false);
    pushButtonCdUp->setIcon(QIcon(QString::fromUtf8(":/images/cdtoparent.png")));

    gridLayout->addWidget(pushButtonCdUp, 2, 3, 1, 1);

    pushButtonGet = new QPushButton(Form);
    pushButtonGet->setObjectName(QString::fromUtf8("pushButtonGet"));
    pushButtonGet->setEnabled(false);

    gridLayout->addWidget(pushButtonGet, 2, 4, 1, 1);

    line = new QFrame(Form);
    line->setObjectName(QString::fromUtf8("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    gridLayout->addWidget(line, 3, 0, 1, 5);

    pushButtonQuit = new QPushButton(Form);
    pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));

    gridLayout->addWidget(pushButtonQuit, 4, 4, 1, 1);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Klient FTP", 0, QApplication::UnicodeUTF8));
    labelFTP->setText(QApplication::translate("Form", "Serwer FTP", 0, QApplication::UnicodeUTF8));
    lineEdit->setToolTip(QApplication::translate("Form", "Adres URL zdalnego komputera", 0, QApplication::UnicodeUTF8));
    lineEdit->setText(QApplication::translate("Form", "ftp://", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(0, QApplication::translate("Form", "Nazwa", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(1, QApplication::translate("Form", "Rozmiar", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(2, QApplication::translate("Form", "W\305\202a\305\233ciciel", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(3, QApplication::translate("Form", "Grupa", 0, QApplication::UnicodeUTF8));
    treeWidget->headerItem()->setText(4, QApplication::translate("Form", "Czas", 0, QApplication::UnicodeUTF8));
    treeWidget->setToolTip(QApplication::translate("Form", "Pliki i foldery na zdalnym komputerze", 0, QApplication::UnicodeUTF8));
    pushButtonConnect->setToolTip(QApplication::translate("Form", "Po\305\202\304\205czenie ze zdalnym komputerem", 0, QApplication::UnicodeUTF8));
    pushButtonConnect->setText(QApplication::translate("Form", "Po\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
    pushButtonDisconnect->setToolTip(QApplication::translate("Form", "Roz\305\202\304\205czenie po\305\202\304\205czenia ze zdalnym komputerem", 0, QApplication::UnicodeUTF8));
    pushButtonDisconnect->setText(QApplication::translate("Form", "Roz\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
    pushButtonCdUp->setToolTip(QApplication::translate("Form", "Przej\305\233cie do folderu nadrz\304\231dnego", 0, QApplication::UnicodeUTF8));
    pushButtonCdUp->setText(QString());
    pushButtonGet->setToolTip(QApplication::translate("Form", "Pobranie pliku", 0, QApplication::UnicodeUTF8));
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
