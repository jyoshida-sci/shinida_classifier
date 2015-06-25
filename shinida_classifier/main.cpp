#include "shinida_classifier.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	shinida_classifier w;
	w.show();
	return a.exec();
}
