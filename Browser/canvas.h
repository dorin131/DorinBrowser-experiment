#ifndef CANVAS_H
#define CANVAS_H

#include <QOpenGLWidget>

class Canvas : public QOpenGLWidget
{
public:
    Canvas(QWidget* parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // CANVAS_H
