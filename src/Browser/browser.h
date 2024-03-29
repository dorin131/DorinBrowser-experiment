#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include <../HTML/html.h>

#include "canvas.h"
#include "ui_browser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Browser; }
QT_END_NAMESPACE

class Browser : public QMainWindow
{
    Q_OBJECT

public:
    Browser(QWidget *parent = nullptr);
    ~Browser();

private:
    Ui::Browser *ui;
private slots:
    void go();
signals:
    void render_page(std::string);
};
#endif // MAINWINDOW_H
