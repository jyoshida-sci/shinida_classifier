#ifndef SHINIDA_CLASSIFIER_H
#define SHINIDA_CLASSIFIER_H

#include <QtWidgets/QWidget>
#include "ui_shinida_classifier.h"

class shinida_classifier : public QWidget
{
	Q_OBJECT

public:
	shinida_classifier(QWidget *parent = 0);
	~shinida_classifier();

private:
	Ui::shinida_classifierClass ui;
};

#endif // SHINIDA_CLASSIFIER_H
