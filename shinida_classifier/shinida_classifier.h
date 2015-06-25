#ifndef SHINIDA_CLASSIFIER_H
#define SHINIDA_CLASSIFIER_H

#include <QtWidgets/QWidget>
#include "ui_shinida_classifier.h"



class QSettings;
class QLabel;
class QPixmap;
class QLineEdit;
class QPushButton;
class QLCDNumber;
class QCheckBox;
class QTextEdit;
class QClickableLabel;
class QSlider;


class shinida_classifier : public QWidget
{
	Q_OBJECT

public:
	shinida_classifier(QWidget *parent = 0);
	~shinida_classifier();

private:
	//Ui::shinida_classifierClass ui;
	QSettings* appsettings;

	QPushButton* but_pppp;
	QPushButton* but_ppp;
	QPushButton* but_pp;
	QPushButton* but_p;
	QPushButton* but_nnnn;
	QPushButton* but_nnn;
	QPushButton* but_nn;
	QPushButton* but_n;


	QPushButton* but_blur;
	QPushButton* but_track;
	QPushButton* but_scratch;
	QPushButton* but_1vtx;
	QPushButton* but_alpha;
	QPushButton* but_2vtx;

	QLabel* label_file;
	QPushButton* but_readfile;


	private slots:

	void loadDir();
};

#endif // SHINIDA_CLASSIFIER_H
