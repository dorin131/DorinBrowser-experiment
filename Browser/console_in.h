#ifndef CONSOLEIN_H
#define CONSOLEIN_H

#include <QWidget>
#include <QLineEdit>

class ConsoleIn : public QLineEdit
{
    Q_OBJECT
public:
    explicit ConsoleIn(QWidget *parent = nullptr);

private slots:
    void console_enter();

signals:

};

#endif // CONSOLEIN_H
