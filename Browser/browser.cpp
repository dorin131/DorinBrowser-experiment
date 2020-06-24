#include "browser.h"

Browser::Browser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);
    ui->address->setText("https://");

    connect(ui->goButton, SIGNAL(released()), this, SLOT(go()));

    connect(ui->consoleInput, SIGNAL(returnPressed()), ui->consoleOutput, SLOT(console_enter()));
    connect(ui->consoleInput, SIGNAL(textChanged(QString)), ui->consoleOutput, SLOT(console_input_changed(QString)));

    connect(ui->consoleInput, SIGNAL(returnPressed()), ui->consoleInput, SLOT(console_enter()));
    connect(ui->consoleInput, SIGNAL(key_up_pressed()), ui->consoleInput, SLOT(show_last_command()));
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

    Canvas c;
    c.draw_text(0, 0, "hello world!");
}
