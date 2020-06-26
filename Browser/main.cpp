#include "browser.h"

#include <QApplication>
#include "../HTML/html.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Browser w;
    w.show();

    html::HTML().parse("yo");

    return a.exec();
}
