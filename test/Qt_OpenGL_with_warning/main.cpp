#include <QApplication>

#include "GLThread.hpp"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian"); 

	QApplication a(argc, argv);

	GLWidget *glWidget = new GLWidget();
	GLWidget1 *glWidget1 = new GLWidget1(NULL, glWidget);
	GLWidget2 *glWidget2 = new GLWidget2(NULL, glWidget);

	glWidget->show();
	glWidget1->show();
	glWidget2->show();

	GLThread *glThread = new GLThread();

	glThread->start();
	

	return a.exec();
}
