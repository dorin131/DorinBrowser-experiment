#include "console_in.h"

ConsoleIn::ConsoleIn(QWidget *parent) : QLineEdit(parent)
{

}

void ConsoleIn::console_enter()
{
    command_history.push_back(text());
    setText("");
}

void ConsoleIn::show_last_command()
{
    if (command_history.size() > 0) {
        auto last = command_history.back();
        if (last.size() > 0) {
            setText(last);
        }
        command_history.pop_back();
    }

}

void ConsoleIn::keyPressEvent(QKeyEvent * ev)
{
    if (ev->key() == Qt::Key_Up) {
        emit key_up_pressed();
    } else {
        QLineEdit::keyPressEvent(ev);
    }

}
