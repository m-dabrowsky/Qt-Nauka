/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Sat 2. Feb 16:35:31 2008
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QVBoxLayout *vboxLayout;
    QSplitter *splitter_2;
    QTableView *table;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QTextEdit *sqlEdit;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonExec;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(596, 468);
    Form->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    vboxLayout = new QVBoxLayout(Form);
    vboxLayout->setSpacing(6);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(8, 8, 8, 8);
    splitter_2 = new QSplitter(Form);
    splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
    splitter_2->setSizePolicy(sizePolicy);
    splitter_2->setOrientation(Qt::Horizontal);
    table = new QTableView(splitter_2);
    table->setObjectName(QString::fromUtf8("table"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(2);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
    table->setSizePolicy(sizePolicy1);
    table->setContextMenuPolicy(Qt::ActionsContextMenu);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    splitter_2->addWidget(table);

    vboxLayout->addWidget(splitter_2);

    groupBox = new QGroupBox(Form);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
    groupBox->setSizePolicy(sizePolicy2);
    groupBox->setMaximumSize(QSize(16777215, 180));
    vboxLayout1 = new QVBoxLayout(groupBox);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(9, 9, 9, 9);
    sqlEdit = new QTextEdit(groupBox);
    sqlEdit->setObjectName(QString::fromUtf8("sqlEdit"));
    QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(sqlEdit->sizePolicy().hasHeightForWidth());
    sqlEdit->setSizePolicy(sizePolicy3);
    sqlEdit->setMinimumSize(QSize(0, 18));
    sqlEdit->setBaseSize(QSize(0, 120));

    vboxLayout1->addWidget(sqlEdit);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    hboxLayout->setContentsMargins(1, 1, 1, 1);
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    pushButtonClear = new QPushButton(groupBox);
    pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

    hboxLayout->addWidget(pushButtonClear);

    pushButtonExec = new QPushButton(groupBox);
    pushButtonExec->setObjectName(QString::fromUtf8("pushButtonExec"));

    hboxLayout->addWidget(pushButtonExec);


    vboxLayout1->addLayout(hboxLayout);


    vboxLayout->addWidget(groupBox);

    QWidget::setTabOrder(sqlEdit, pushButtonClear);
    QWidget::setTabOrder(pushButtonClear, pushButtonExec);
    QWidget::setTabOrder(pushButtonExec, table);

    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Zapytania SQL", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Form", "Zapytanie SQL", 0, QApplication::UnicodeUTF8));
    pushButtonClear->setText(QApplication::translate("Form", "Czy\305\233\304\207", 0, QApplication::UnicodeUTF8));
    pushButtonExec->setText(QApplication::translate("Form", "Wykonaj", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_WINDOW_H
