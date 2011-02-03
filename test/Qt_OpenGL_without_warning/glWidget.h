
// Copyright (c) 2009 Chertov Maxim <chertovm@gmail.com>

#ifndef TEST_QT_OPENGL_WITHOUT_WARNING_GLWIDGET_H_
#define TEST_QT_OPENGL_WITHOUT_WARNING_GLWIDGET_H_

#pragma once

#include <GL/glew.h>
#include <gl/glut.h>
#include <QGLWidget>
#include <QtOpenGL>
#include <math.h>

#include "types.hpp"

/// doxygen comment
class CGLWidget : public QGLWidget
{
 public:
    CGLWidget(QWidget *parent = 0,
                const QGLWidget *shareWidget = 0,
                Qt::WindowFlags f = 0);

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

#endif  // TEST_QT_OPENGL_WITHOUT_WARNING_GLWIDGET_H_
