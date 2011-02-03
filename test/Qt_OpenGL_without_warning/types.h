
// Copyright (c) 2009 Chertov Maxim <chertovm@gmail.com>


#ifndef TEST_QT_OPENGL_WITHOUT_WARNING_TYPES_H_
#define TEST_QT_OPENGL_WITHOUT_WARNING_TYPES_H_

#pragma once
#include <GL/glew.h>
#include <gl/glut.h>  // заголовочный файл для библиотеки GLut

#include <stdlib.h>
#include <iostream>
#include <vector>

struct Svertex  // структура вертекса 
{
public:
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

struct StextureCoord  // текстурные координаты 
{
public:
    GLfloat u;
    GLfloat v;
};

struct Scolor  // структура цвета 
{
public:
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
};


#define PI 3.141592653589793238462643383279

enum
{
    VertexBuffer,
    IndexBuffer,
    ColorBuffer,
    TextureCoordBuffer
};

extern GLuint BufferName[4];
extern GLushort vertexCount;
extern GLushort idCount;

#endif  // TEST_QT_OPENGL_WITHOUT_WARNING_TYPES_H_
