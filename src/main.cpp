#include "aiws/gui/main_window.hpp"

#include <QApplication>
#include <QCoreApplication>
#include <QMessageBox>
#include <QString>
#include <QWidget>

//asks the user to confirm exit and quits on yes
void confirm_exit(QWidget* parent)
{
    const QMessageBox::StandardButton answer = QMessageBox::question(
        parent,
        QStringLiteral("Exit"),
        QStringLiteral("Quit the application?"),
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::No);

    if (answer == QMessageBox::Yes)
    {
        QCoreApplication::quit();
    }
}

//creates the application window registers the exit callback and runs the loop
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    aiws::gui::MainWindow window;
    window.set_exit_callback(&confirm_exit);
    window.show();

    return app.exec();
}
