#ifndef CONSOLEIN_H
#define CONSOLEIN_H

#include <QWidget>
#include <QLineEdit>
#include <QKeyEvent>

class ConsoleIn : public QLineEdit
{
    Q_OBJECT
public:
    explicit ConsoleIn(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *) override;

private:
    std::list<QString> command_history;

private slots:
    void console_enter();
    void show_last_command();

signals:
    void key_up_pressed();
};

#endif // CONSOLEIN_H
