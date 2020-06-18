#include "browser.h"
#include "ui_mainwindow.h"

Browser::Browser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);
    ui->address->setText("https://");

    connect(ui->goButton, SIGNAL(released()), this, SLOT(go()));
}

Browser::~Browser()
{
    delete ui;
}

void Browser::go()
{
    QMessageBox* d = new QMessageBox(this);
    d->setText("Getting: " + ui->address->text());
    d->exec();
}
