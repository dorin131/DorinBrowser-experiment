#ifndef CONSOLEOUT_H
#define CONSOLEOUT_H

#include <ctime>
#include <iomanip>
#include <sstream>
#include <QWidget>
#include <QPlainTextEdit>

#include "../JS/interpreter.h"
#include "../JS/tokenizer.h"
#include "../JS/parser.h"

class ConsoleOut : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit ConsoleOut(QWidget *parent = nullptr);

private:
    std::string input_buffer;

private slots:
    void console_enter();
    void console_input_changed(QString);
    void append_input(std::string);
    void append_output(std::string);

    static std::string get_time();
    static std::string js_eval(std::string);
signals:

};

#endif // CONSOLEOUT_H
