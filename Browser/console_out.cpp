#include "console_out.h"

ConsoleOut::ConsoleOut(QWidget *parent) : QPlainTextEdit(parent)
{

}

void ConsoleOut::console_enter()
{
    if (input_buffer.size() > 0) {
        append_input(input_buffer);
        append_output(js_eval(input_buffer));
        input_buffer = "";
    }
}

void ConsoleOut::append_input(std::string text)
{
    std::string out = get_time() + " → " + text;
    appendPlainText(QString::fromStdString(out));
}

void ConsoleOut::append_output(std::string text)
{
    std::string out = get_time() + " ← " + text;
    appendPlainText(QString::fromStdString(out));
}

void ConsoleOut::console_input_changed(QString text)
{
    input_buffer = text.toUtf8().constData();
}

std::string ConsoleOut::js_eval(std::string code)
{
    js::Tokenizer t = js::Tokenizer(code);
    auto p = js::Parser(t);
    std::shared_ptr<js::Program> program;
    try {
        program = p.parse_program();
    } catch (js::SyntaxError e) {
        return "Syntax error: " + e.message;
    }
    js::Interpreter interpreter;
    auto result = interpreter.run(program);

    return result.get_value();
}


std::string ConsoleOut::get_time()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%T");

    return oss.str();
}
