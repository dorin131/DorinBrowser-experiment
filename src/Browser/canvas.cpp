#include "canvas.h"

Canvas::Canvas(QWidget* parent): QOpenGLWidget(parent)
{

}

void Canvas::initializeGL()
{
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void Canvas::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    render_html();
}

void Canvas::set_ast(std::string ast)
{
    html_ast = ast;
    update();
}

void Canvas::render_html()
{
    draw_text(0, 0, html_ast);
}

void Canvas::draw_text(int x, int y, std::string text)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.drawText(x, y, width(), height(), Qt::AlignLeft, QString::fromStdString(text));
    painter.end();
}
