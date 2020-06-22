#ifndef CONSOLEOUT_H
#define CONSOLEOUT_H

#include <QWidget>
#include <QPlainTextEdit>

class ConsoleOut : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit ConsoleOut(QWidget *parent = nullptr);

private:
    QString input_buffer;

private slots:
    void console_enter();
    void console_input_changed(QString);

signals:

};

#endif // CONSOLEOUT_H
