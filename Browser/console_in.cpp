#include "console_in.h"

ConsoleIn::ConsoleIn(QWidget *parent) : QLineEdit(parent)
{

}

void ConsoleIn::console_enter()
{
    setText("");
}
