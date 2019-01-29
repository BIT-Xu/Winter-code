#include "AgentLayout.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AgentLayout w;
	w.show();
	return a.exec();
}
