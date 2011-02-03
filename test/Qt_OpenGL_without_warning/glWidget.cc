
// Copyright (c) 2009 Chertov Maxim <chertovm@gmail.com>

#include "glWidget.hpp"

GLuint BufferName[4];
GLushort resolution;
GLushort vertexCount;
GLushort idCount;

GLWidget::GLWidget(QWidget *parent ,
                    const QGLWidget *shareWidget,
                    Qt::WindowFlags f) :
    QGLWidget(parent, shareWidget, f)
{
    this->setWindowTitle(QString("Shared context"));
    this->setGeometry(pos().x(), pos().y(), 500, 300);
    // startTimer( 11 ); //64-65fps
}

void GLWidget::initializeGL()
{
    makeCurrent();
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
    glClearColor(0.85f, 0.85f, 0.85f, 0.f);
    glewInit();

    Phi = 45*PI/180.0;
    Tet = 12*PI/180.0;
    R = 5;
    leftPress = false;

    x = R*sin(PI/2.0 - Tet)*cos(Phi);
    y = R*sin(PI/2.0 - Tet)*sin(Phi);
    z = R*cos(PI/2.0 - Tet);

    // glGenBuffers(4, BufferName);
    glGenBuffersARB(4, BufferName);
    vertexCount = 4;

    vertex *vB = new vertex[vertexCount];
    vB[0].x = 1;
    vB[0].y = 1;
    vB[0].z = 0;
    vB[1].x = 2;
    vB[1].y = 1;
    vB[1].z = 0;
    vB[2].x = 2;
    vB[2].y = 2;
    vB[2].z = 0;
    vB[3].x = 1;
    vB[3].y = 2;
    vB[3].z = 0;
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, BufferName[VertexBuffer]);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB,
                    vertexCount * sizeof(vertex),
                    vB, GL_STATIC_DRAW);
    delete [] vB;

    GLushort *iB = new GLushort[vertexCount];
    iB[0] = 0;
    iB[1] = 1;
    iB[2] = 3;
    iB[3] = 2;
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB,
                    BufferName[IndexBuffer]);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB,
                    vertexCount * sizeof(GLushort),
                    iB, GL_STATIC_DRAW);
    delete [] iB;

    color* cB = new color[vertexCount];
    cB[0].r = 255;
    cB[0].g = 0;
    cB[0].b = 0;
    cB[0].a = 0;
    cB[1].r = 0;
    cB[1].g = 255;
    cB[1].b = 0;
    cB[1].a = 0;
    cB[2].r = 0;
    cB[2].g = 0;
    cB[2].b = 255;
    cB[2].a = 0;
    cB[3].r = 0;
    cB[3].g = 0;
    cB[3].b = 0;
    cB[3].a = 0;

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, BufferName[ColorBuffer]);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB,
                    vertexCount * sizeof(textureCoord),
                    cB, GL_STATIC_DRAW);
    delete [] cB;
}

void GLWidget::paintGL()
{
    makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(x, y, z, // откуда смотрим
                0, 0, 0, // куда смотрим
                0, 0, 1); // где верх

    glColor3ub(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3d(1, 0, 0);
    glVertex3d(-1, 0, 0);
    glVertex3d(0, 1, 0);
    glVertex3d(0, -1, 0);
    glVertex3d(0, 0, 1);
    glVertex3d(0, 0, -1);
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

    // this->swapBuffers();
}

void GLWidget::resizeGL(int width, int height)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (height == 0) height = 1;

    glViewport(0, 0 , width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.01f, 100000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    // if(event->key() == Qt::Key::Key_Left)
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::LeftButton)
    {
        lastX = event->x();
        lastY = event->y();
        leftPress = true;
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::LeftButton)
    {
        lastX = event->x();
        lastY = event->y();
        leftPress = false;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (leftPress)
    {
        double deltaX = event->x() - lastX;
        double deltaY = event->y() - lastY;

        Phi -= deltaX*0.01;
        Tet += deltaY*0.01;

        while (Phi > PI) Phi -= 2*PI;
        while (Phi < -PI) Phi += 2*PI;

        if (Tet > PI/2.0) Tet = PI/2.0 - 0.001;
        if (Tet < -PI/2.0) Tet = -PI/2.0 + 0.001;

        x = R*sin(PI/2.0 - Tet)*cos(Phi);
        y = R*sin(PI/2.0 - Tet)*sin(Phi);
        z = R*cos(PI/2.0 - Tet);

        lastX = event->x();
        lastY = event->y();
    }

    this->paintGL();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    R *= 1 - event->delta()/abs(event->delta())*0.1;

    x = R*sin(PI/2.0 - Tet)*cos(Phi);
    y = R*sin(PI/2.0 - Tet)*sin(Phi);
    z = R*cos(PI/2.0 - Tet);
}

void GLWidget::timerEvent(QTimerEvent *event)
{
    updateGL();
}
