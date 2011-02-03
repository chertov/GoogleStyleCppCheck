
// Copyright (c) 2009 Chertov Maxim <chertovm@gmail.com>

#ifndef TEST_QT_OPENGL_WITHOUT_WARNING_GLTHREAD_H_
#define TEST_QT_OPENGL_WITHOUT_WARNING_GLTHREAD_H_

#pragma once
#include <QThread>

#include "glWidget.hpp"
#include "glWidget1.hpp"
#include "glWidget2.hpp"

/// doxygen comment
class CGLThread : public QThread
{
    Q_OBJECT

 protected:
    void run();
};

#endif  // TEST_QT_OPENGL_WITHOUT_WARNING_GLTHREAD_H_
