/********************************************************************************
** Form generated from reading UI file 'browser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSER_H
#define UI_BROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <canvas.h>
#include <console_in.h>
#include <console_out.h>

QT_BEGIN_NAMESPACE

class Ui_Browser
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *address;
    QPushButton *goButton;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    Canvas *canvas;
    QTabWidget *tools;
    QWidget *console;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    ConsoleOut *consoleOutput;
    ConsoleIn *consoleInput;
    QWidget *source;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Browser)
    {
        if (Browser->objectName().isEmpty())
            Browser->setObjectName(QString::fromUtf8("Browser"));
        Browser->resize(818, 587);
        Browser->setAutoFillBackground(false);
        centralwidget = new QWidget(Browser);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        address = new QLineEdit(centralwidget);
        address->setObjectName(QString::fromUtf8("address"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(address->sizePolicy().hasHeightForWidth());
        address->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(address);

        goButton = new QPushButton(centralwidget);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        horizontalLayout->addWidget(goButton);


        verticalLayout->addLayout(horizontalLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 68));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        canvas = new Canvas(scrollAreaWidgetContents);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(canvas);

        scrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(scrollArea);
        tools = new QTabWidget(splitter);
        tools->setObjectName(QString::fromUtf8("tools"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tools->sizePolicy().hasHeightForWidth());
        tools->setSizePolicy(sizePolicy3);
        tools->setMinimumSize(QSize(0, 100));
        tools->setBaseSize(QSize(0, 0));
        console = new QWidget();
        console->setObjectName(QString::fromUtf8("console"));
        verticalLayout_3 = new QVBoxLayout(console);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea_2 = new QScrollArea(console);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setLineWidth(0);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 778, 339));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        consoleOutput = new ConsoleOut(scrollAreaWidgetContents_2);
        consoleOutput->setObjectName(QString::fromUtf8("consoleOutput"));
        QFont font;
        font.setFamily(QString::fromUtf8("Source Code Pro"));
        consoleOutput->setFont(font);
        consoleOutput->setReadOnly(true);

        verticalLayout_4->addWidget(consoleOutput);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(scrollArea_2);

        consoleInput = new ConsoleIn(console);
        consoleInput->setObjectName(QString::fromUtf8("consoleInput"));
        consoleInput->setFont(font);

        verticalLayout_3->addWidget(consoleInput);

        tools->addTab(console, QString());
        source = new QWidget();
        source->setObjectName(QString::fromUtf8("source"));
        tools->addTab(source, QString());
        splitter->addWidget(tools);

        verticalLayout->addWidget(splitter);

        Browser->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Browser);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 818, 22));
        Browser->setMenuBar(menubar);
        statusbar = new QStatusBar(Browser);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Browser->setStatusBar(statusbar);

        retranslateUi(Browser);

        tools->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Browser);
    } // setupUi

    void retranslateUi(QMainWindow *Browser)
    {
        Browser->setWindowTitle(QCoreApplication::translate("Browser", "Dorin Browser", nullptr));
        goButton->setText(QCoreApplication::translate("Browser", "Go", nullptr));
        tools->setTabText(tools->indexOf(console), QCoreApplication::translate("Browser", "Console", nullptr));
        tools->setTabText(tools->indexOf(source), QCoreApplication::translate("Browser", "Source", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Browser: public Ui_Browser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSER_H
