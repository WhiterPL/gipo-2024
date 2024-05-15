#ifndef GLWIDGET_H
#define GLWIDGET_H

#if QT_VERSION_MAJOR >= 6
    #include <QtOpenGLWidgets/QOpenGLWidget>
#else
    #include <QOpenGLWidget>
#endif

#include "glslprogram.h"
#include "geometry.h"
#include <QOpenGLFunctions_3_3_Core>
#include <QMap>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>

#include "mathgl.h"
#include "frame.h"


class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    QMap<QString, GLSLProgram*> programs;
    QMap<QString, Geometry*> geometries;

    Frame camera;

    glm::mat4 MVMat;
    glm::mat4 PMat;

    QTimer timer;

    QSet<Qt::Key> key_pressed;
    int screen_width;
    int screen_height;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void process_keys();
public:
    GLWidget();
};


#endif // GLWIDGET_H
