#pragma once
#include <GL/glew.h>
#include <gl/glut.h>  // ������������ ���� ��� ���������� GLut

#include <stdlib.h>
#include <iostream>
#include <vector>

struct vertex  // ��������� �������� 
{
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct textureCoord  // ���������� ���������� 
{
public:
	GLfloat u;
	GLfloat v;
};

struct color  // ��������� ����� 
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