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

	QVBoxLayout *lay_prev = new QVBoxLayout();
	but_pppp = new QPushButton(tr("<1000"));
	lay_prev->addWidget(but_pppp);
	but_ppp = new QPushButton(tr("<100"));
	lay_prev->addWidget(but_ppp);
	but_pp = new QPushButton(tr("<10"));
	lay_prev->addWidget(but_pp);
	but_p = new QPushButton(tr("<"));
	lay_prev->addWidget(but_p);
	lay_disp->addLayout(lay_prev);

	label_small = new QLabel();
	lay_disp->addWidget(label_small);
	label_hough = new QLabel();
	lay_disp->addWidget(label_hough);
	label_large = new QLabel();
	lay_disp->addWidget(label_large);

	QVBoxLayout *lay_next = new QVBoxLayout();
	but_nnnn = new QPushButton(tr(">1000"));
	lay_next->addWidget(but_nnnn);
	but_nnn = new QPushButton(tr(">100"));
	lay_next->addWidget(but_nnn);
	but_nn = new QPushButton(tr(">10"));
	lay_next->addWidget(but_nn);
	but_n = new QPushButton(tr(">"));
	lay_next->addWidget(but_n);
	lay_disp->addLayout(lay_next);



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
	but_writefile = new QPushButton(tr("&Write file"));
	but_writefile->setDisabled(true);
	lay_file->addWidget(but_writefile);

	lay->addLayout(lay_file);

	//layout
	setLayout(lay);


	//connect signal-slot
	connect(but_n, SIGNAL(clicked()), this, SLOT(gon()));
	connect(but_nn, SIGNAL(clicked()), this, SLOT(gonn()));
	connect(but_nnn, SIGNAL(clicked()), this, SLOT(gonnn()));
	connect(but_nnnn, SIGNAL(clicked()), this, SLOT(gonnnn()));
	connect(but_p, SIGNAL(clicked()), this, SLOT(gop()));
	connect(but_pp, SIGNAL(clicked()), this, SLOT(gopp()));
	connect(but_ppp, SIGNAL(clicked()), this, SLOT(goppp()));
	connect(but_pppp, SIGNAL(clicked()), this, SLOT(gopppp()));

	connect(but_blur, SIGNAL(clicked()), this, SLOT(pushed_blur()));
	connect(but_track, SIGNAL(clicked()), this, SLOT(pushed_track()));
	connect(but_scratch, SIGNAL(clicked()), this, SLOT(pushed_scratch()));
	connect(but_1vtx, SIGNAL(clicked()), this, SLOT(pushed_1vtx()));
	connect(but_alpha, SIGNAL(clicked()), this, SLOT(pushed_alpha()));
	connect(but_2vtx, SIGNAL(clicked()), this, SLOT(pushed_2vtx()));


	connect(but_readfile, SIGNAL(clicked()), this, SLOT(loadDir()));
	connect(but_writefile, SIGNAL(clicked()), this, SLOT(writeFile()));
}



shinida_classifier::~shinida_classifier()
{

}




void shinida_classifier::loadDir(){
	
	QDir defaultdir = appsettings->value("readdir").toString();

	QString dirname = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		defaultdir.absolutePath(),
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	appsettings->setValue("readdir", dirname);
	QDir dir = QDir(dirname);
	dir.setNameFilters(QStringList() << "*.png");
	filesList = dir.entryList(QDir::Files);



	QString fileName;
	foreach(fileName, filesList) {
		qDebug() << "FileName " << fileName;
		vfilename.push_back(QString("%1\\%2").arg(dirname).arg(fileName));
		vvtxname.push_back(fileName);
		vclass.push_back(QString("-"));
	}

	ipict = 0;
	dispImg();

	but_writefile->setEnabled(true);
}



void shinida_classifier::gop(){
	if (ipict - 1 < 0) return;
	ipict -= 1;
	dispImg();
}
void shinida_classifier::gopp(){
	if (ipict - 10 < 0) return;
	ipict -= 10;
	dispImg();
}
void shinida_classifier::goppp(){
	if (ipict - 100  < 0) return;
	ipict -= 100;
	dispImg();
}
void shinida_classifier::gopppp(){
	if (ipict - 1000  < 0) return;
	ipict -= 1000;
	dispImg();
}

void shinida_classifier::gon(){
	if (ipict + 1 > vfilename.size() / 2 - 1) return;
	ipict += 1;
	dispImg();
}
void shinida_classifier::gonn(){
	if (ipict + 10 > vfilename.size() / 2 - 1) return;
	ipict += 10;
	dispImg();
}
void shinida_classifier::gonnn(){
	if (ipict + 100 > vfilename.size() / 2 - 1) return;
	ipict += 100;
	dispImg();
}
void shinida_classifier::gonnnn(){
	if (ipict + 1000 > vfilename.size() / 2 - 1) return;
	ipict += 1000;
	dispImg();
}


void shinida_classifier::pushed_blur(){
	vclass[ipict * 2 + 1] = "b";
	gon();
}

void shinida_classifier::pushed_track(){
	vclass[ipict * 2 + 1] = "t";
	gon();

}

void shinida_classifier::pushed_scratch(){
	vclass[ipict * 2 + 1] = "s";
	gon();

}

void shinida_classifier::pushed_1vtx(){
	vclass[ipict * 2 + 1] = "v";
	gon();

}

void shinida_classifier::pushed_alpha(){
	vclass[ipict * 2 + 1] = "a";
	gon();

}

void shinida_classifier::pushed_2vtx(){
	vclass[ipict * 2 + 1] = "w";
	gon();

}



void shinida_classifier::dispImg(){

	QImage img_small;
	QImage img_hough;
	QImage img_large;
	img_small.load(vfilename[ipict*2 + 1]);
	img_small = img_small.convertToFormat(QImage::Format_RGB32);
	label_small->setPixmap(QPixmap::fromImage(img_small));

	img_hough.load(vfilename[ipict * 2]);
	img_hough = img_hough.convertToFormat(QImage::Format_RGB32);
	label_hough->setPixmap(QPixmap::fromImage(img_hough));


	img_large.load(vfilename[ipict * 2 + 1]);
	img_large = img_large.convertToFormat(QImage::Format_RGB32);
	img_large = img_large.scaled(2 * img_large.size());
	label_large->setPixmap(QPixmap::fromImage(img_large));

	QString str = QString("%1  %2  %3").arg(ipict).arg(vvtxname[ipict*2+1]).arg(vclass[ipict*2+1]);
	label_file->setText(str);

}


/*

QImage myImage;
myImage.load("test.png");

QLabel myLabel;
myLabel.setPixmap(QPixmap::fromImage(myImage));
*/



void shinida_classifier::writeFile(){

	QDir dir = appsettings->value("writedir").toString();
	qDebug() << dir.absolutePath();
	//dialog
	QString selFilter = "All files (*.txt)";
	QString fileName = QFileDialog::getSaveFileName(
		this,
		"Save file",
		dir.absolutePath(),
		"Text files (*.txt);;All files (*.*)",
		&selFilter);

	dir = QFileInfo(fileName).absoluteDir();
	appsettings->setValue("writedir", dir.absolutePath());

	// write text file 
	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly)) {
		for (int i = 0; i < vvtxname.size(); i+=2){
			QTextStream stream(&file);
			QString str = QString("%1  %2\n").arg(vvtxname[i+1]).arg(vclass[i+1]);
			stream << str;
		}
	}

}