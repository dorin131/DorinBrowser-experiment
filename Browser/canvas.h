#ifndef CANVAS_H
#define CANVAS_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QGLWidget>

#include <request.h>

class Canvas : public QOpenGLWidget
{
   // Q_OBJECT
public:
    Canvas(QWidget* parent = nullptr);

    void draw_text(int x, int y, std::string text);
    void set_ast(std::string); // will take an AST
private:
    std::string html_ast = "lol"; // will change from a string to an AST type
    void render_html();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // CANVAS_H
