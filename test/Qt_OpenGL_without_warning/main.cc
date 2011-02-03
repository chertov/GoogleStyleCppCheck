
// Copyright (c) 2009 Chertov Maxim <chertovm@gmail.com>

#include <QApplication>

#include "GLThread.hpp"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian"); 

	QApplication a(argc, argv);

	GLWidget *glWidget = new GLWidget();

	glWidget->show();

	GLThread *glThread = new GLThread();

	glThread->start();
	

	return a.exec();
}
