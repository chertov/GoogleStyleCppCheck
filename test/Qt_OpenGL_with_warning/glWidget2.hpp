#pragma once

#include <GL/glew.h>
#include <gl/glut.h>
#include <QGLWidget>
#include <QtOpenGL>
#include <math.h>

#include "types.hpp"

class GLWidget2 : public QGLWidget
{
public:
	GLWidget2(QWidget *parent = 0, const QGLWidget *shareWidget = 0, Qt::WindowFlags f = 0 );

protected:
    void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void keyPressEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
    void timerEvent(QTimerEvent *event);

private:
	double x, y, z;
	double Phi, Tet, R;
	double lastX, lastY;
	bool leftPress;
};
