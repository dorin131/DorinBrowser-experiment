#ifndef CANVAS_H
#define CANVAS_H

#include <QOpenGLWidget>
#include <QPainter>

class Canvas : public QOpenGLWidget
{
public:
    Canvas(QWidget* parent = nullptr);

    void draw_text(int x, int y, std::string text);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // CANVAS_H
