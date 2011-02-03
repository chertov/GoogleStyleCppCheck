#pragma once
#include <QThread>

#include "glWidget.hpp"
#include "glWidget1.hpp"
#include "glWidget2.hpp"

class GLThread : public QThread
{
	Q_OBJECT

protected:
	void run();
};