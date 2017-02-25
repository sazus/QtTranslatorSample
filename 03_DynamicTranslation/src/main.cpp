#include <QGuiApplication>
#include "uicontrol.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    UiControl Ui;
    Ui.show();

    return app.exec();
}
