#include "shinida_classifier.h"


#include "qsettings.h"

#include "qlineedit.h"
#include "qpushbutton.h"
#include "qlayout.h"
#include "qlabel.h"
#include "qstring.h"
#include "qlcdnumber.h"
#include "qcheckbox.h"
#include "qtextedit.h"
#include "qtextstream.h"
#include "qslider.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "qdebug.h"

#include "qfiledialog.h"
#include "qdir.h"
#include "qmenu.h"
#include <QMouseEvent>


#include <stdio.h>
#include <stdlib.h>
#include <string>


shinida_classifier::shinida_classifier(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);


	appsettings = new QSettings("shinida_classifier.ini", QSettings::IniFormat);

	QVBoxLayout *lay = new QVBoxLayout();



	//image
	QHBoxLayout *lay_disp = new QHBoxLayout();
	but_pppp = new QPushButton(tr("<1000"));
	lay_disp->addWidget(but_pppp);
	but_ppp = new QPushButton(tr("<100"));
	lay_disp->addWidget(but_ppp);
	but_pp = new QPushButton(tr("<10"));
	lay_disp->addWidget(but_pp);
	but_p = new QPushButton(tr("<"));
	lay_disp->addWidget(but_p);




	but_n = new QPushButton(tr(">"));
	lay_disp->addWidget(but_n);
	but_nn = new QPushButton(tr(">10"));
	lay_disp->addWidget(but_nn);
	but_nnn = new QPushButton(tr(">100"));
	lay_disp->addWidget(but_nnn);
	but_nnnn = new QPushButton(tr(">1000"));
	lay_disp->addWidget(but_nnnn);
	lay->addLayout(lay_disp);


	//classify
	QHBoxLayout *lay_cat = new QHBoxLayout();
	but_blur = new QPushButton(tr("blur"));
	lay_cat->addWidget(but_blur);
	but_track = new QPushButton(tr("track"));
	lay_cat->addWidget(but_track);
	but_scratch = new QPushButton(tr("scratch"));
	lay_cat->addWidget(but_scratch);
	but_1vtx = new QPushButton(tr("1vtx"));
	lay_cat->addWidget(but_1vtx);
	but_alpha = new QPushButton(tr("alpha"));
	lay_cat->addWidget(but_alpha);
	but_2vtx = new QPushButton(tr("2vtx"));
	lay_cat->addWidget(but_2vtx);
	lay->addLayout(lay_cat);

	//file path
	QHBoxLayout *lay_file = new QHBoxLayout();
	label_file = new QLabel(QString("no file yet"));
	lay_file->addWidget(label_file);
	but_readfile = new QPushButton(tr("&Read file"));
	lay_file->addWidget(but_readfile);

	lay->addLayout(lay_file);

	//layout
	setLayout(lay);


	/*
	//click info
	QHBoxLayout *lay_click = new QHBoxLayout();
	lab_pix = new QLabel();
	lab_pix->setFont(QFont("Arial", 10));
	lay_click->addWidget(lab_pix);
	lab_pix_cl = new QLabel();
	lab_pix_cl->setFont(QFont("Arial", 10));
	lay_click->addWidget(lab_pix_cl);
	lab_pix_dr = new QLabel();
	lab_pix_dr->setFont(QFont("Arial", 10));
	lay_click->addWidget(lab_pix_dr);
	lay->addLayout(lay_click, 4, 0, 1, 2);

	QHBoxLayout *lay_stage = new QHBoxLayout();
	lab_stg = new QLabel();
	lab_stg->setFont(QFont("Arial", 10));
	lay_stage->addWidget(lab_stg);
	lab_stg_cl = new QLabel();
	lab_stg_cl->setFont(QFont("Arial", 10));
	lay_stage->addWidget(lab_stg_cl);
	lab_stg_dr = new QLabel();
	lab_stg_dr->setFont(QFont("Arial", 10));
	lay_stage->addWidget(lab_stg_dr);
	lay->addLayout(lay_stage, 5, 0, 1, 2);



	//file path
	QHBoxLayout *lay_file = new QHBoxLayout();
	line_file = new QLineEdit(QString("no file yet"));
	but_file = new QPushButton(tr("&Read file"));
	lcd_img = new QLCDNumber();
	chk_filterd = new QCheckBox("filterd");
	//chk_filterd->setCheckState(Qt::Checked);
	lay_file->addWidget(line_file);
	lay_file->addWidget(but_file);
	lay_file->addWidget(lcd_img);
	lay_file->addWidget(chk_filterd);
	lay->addLayout(lay_file, 6, 0, 1, 2);

	sli_z = new QSlider();
	lay->addWidget(sli_z, 0, 2, 6, 1);

	//texteditarea
	txt_clicked = new QTextEdit();
	txt_clicked->setFixedWidth(170);
	lay->addWidget(txt_clicked, 0, 3, 5, 1);
	but_writxt = new QPushButton(tr("&Save File"));
	lay->addWidget(but_writxt, 5, 3, 1, 1);
	//but_make = new QPushButton(tr("&Make pict"));
	//lay->addWidget(but_make, 4, 2, 1, 1);





	//connect signal-slot
	connect(but_file, SIGNAL(clicked()), this, SLOT(loadImg()));
	connect(but_up, SIGNAL(clicked()), this, SLOT(imgUp()));
	connect(but_down, SIGNAL(clicked()), this, SLOT(imgDown()));

	connect(but_writxt, SIGNAL(clicked()), this, SLOT(writeTxtFile()));
	connect(this, SIGNAL(wheelEvent(QWheelEvent*)), this, SLOT(changeLayer(QWheelEvent*)));
	connect(lab_img, SIGNAL(mousePressed(QMouseEvent*)), this, SLOT(labMouseClicked(QMouseEvent*)));
	connect(lab_img, SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(labMouseMoved(QMouseEvent*)));
	connect(sli_z, SIGNAL(valueChanged(int)), this, SLOT(changeToNthLayer(int)));

	but_up->setDisabled(true);
	but_down->setDisabled(true);
	sli_z->setDisabled(true);
	*/
}

shinida_classifier::~shinida_classifier()
{

}
