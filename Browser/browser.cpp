#include "browser.h"
#include "ui_mainwindow.h"

Browser::Browser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);
    ui->address->setText("https://");
}

Browser::~Browser()
{
    delete ui;
}

void Browser::go()
{

}
