/********************************************************************************
** Form generated from reading UI file 'shinida_classifier.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHINIDA_CLASSIFIER_H
#define UI_SHINIDA_CLASSIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shinida_classifierClass
{
public:

    void setupUi(QWidget *shinida_classifierClass)
    {
        if (shinida_classifierClass->objectName().isEmpty())
            shinida_classifierClass->setObjectName(QStringLiteral("shinida_classifierClass"));
        shinida_classifierClass->resize(600, 400);

        retranslateUi(shinida_classifierClass);

        QMetaObject::connectSlotsByName(shinida_classifierClass);
    } // setupUi

    void retranslateUi(QWidget *shinida_classifierClass)
    {
        shinida_classifierClass->setWindowTitle(QApplication::translate("shinida_classifierClass", "shinida_classifier", 0));
    } // retranslateUi

};

namespace Ui {
    class shinida_classifierClass: public Ui_shinida_classifierClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHINIDA_CLASSIFIER_H
