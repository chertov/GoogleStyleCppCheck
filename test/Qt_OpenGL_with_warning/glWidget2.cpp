#include "glWidget2.hpp"

GLWidget2::GLWidget2 (QWidget *parent , const QGLWidget *shareWidget, Qt::WindowFlags f) : QGLWidget(parent, shareWidget, f)
{
	this->setWindowTitle(QString("Context 2"));
	this->setGeometry(this->pos().x(), this->pos().y(), 300, 200);
	startTimer( 11 ); //64-65fps
}

void GLWidget2::initializeGL()
{
	makeCurrent();
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
	glClearColor(0.85f, 0.85f, 0.85f, 0.f);
	glewInit();

	Phi = 30*PI/180.0; Tet = 12*PI/180.0; R = 5;
	leftPress = false;

	x = R*sin(PI/2.0 - Tet)*cos(Phi);
	y = R*sin(PI/2.0 - Tet)*sin(Phi);
	z = R*cos(PI/2.0 - Tet);
}

void GLWidget2::paintGL()
{
	makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(	x,		y,		z,		// откуда смотри      
				0,		0,		0,		// куда смотрим
				0,		0,		1);		// где верх

	glColor3ub(0,0,255);
	glBegin(GL_LINES);
	glVertex3d(1,0,0);
	glVertex3d(-1,0,0);
	glVertex3d(0,1,0);
	glVertex3d(0,-1,0);
	glVertex3d(0,0,1);
	glVertex3d(0,0,-1);
	glEnd();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, BufferName[VertexBuffer]);
	glVertexPointer(3, GL_FLOAT, 0, 0);

	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, BufferName[IndexBuffer]);

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, BufferName[ColorBuffer]);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, 0);

	glDrawElements(GL_TRIANGLE_STRIP, vertexCount, GL_UNSIGNED_SHORT, 0);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	//this->swapBuffers();
}

void GLWidget2::resizeGL(int width, int height)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (height == 0) height = 1;
    
	glViewport(0, 0 , width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.01f, 100000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget2::keyPressEvent(QKeyEvent *event)
{
	//if(event->key() == Qt::Key::Key_Left)
}

void GLWidget2::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
	{
		lastX = event->x();
		lastY = event->y();
		leftPress = true;
	}
}

void GLWidget2::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
	{
		lastX = event->x();
		lastY = event->y();
		leftPress = false;
	}
}

void GLWidget2::mouseMoveEvent(QMouseEvent *event)
{
	if (leftPress)
	{
		double deltaX = event->x() - lastX;
		double deltaY = event->y() - lastY;

		Phi -= deltaX*0.01; Tet += deltaY*0.01;

		while (Phi > PI) Phi -= 2*PI;
		while (Phi < -PI) Phi += 2*PI;

		if(Tet > PI/2.0) Tet = PI/2.0 - 0.001;
		if(Tet < -PI/2.0) Tet = -PI/2.0 + 0.001;

		x = R*sin(PI/2.0 - Tet)*cos(Phi);
		y = R*sin(PI/2.0 - Tet)*sin(Phi);
		z = R*cos(PI/2.0 - Tet);

		lastX = event->x();
		lastY = event->y();
	}
}

void GLWidget2::wheelEvent(QWheelEvent *event)
{
	R *= 1 - event->delta()/abs(event->delta())*0.1;

	x = R*sin(PI/2.0 - Tet)*cos(Phi);
	y = R*sin(PI/2.0 - Tet)*sin(Phi);
	z = R*cos(PI/2.0 - Tet);
}

void GLWidget2::timerEvent(QTimerEvent *event)
{
    updateGL();
}
