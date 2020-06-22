#include "console_out.h"

ConsoleOut::ConsoleOut(QWidget *parent) : QPlainTextEdit(parent)
{

}

void ConsoleOut::console_enter()
{
    if (input_buffer.size() > 0) {
        appendPlainText(input_buffer);
        input_buffer = "";
    }
}

void ConsoleOut::console_input_changed(QString text)
{
    input_buffer = text;
}
