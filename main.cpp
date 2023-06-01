#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    // Create the main window
    QWidget window;
    window.setWindowTitle("Simple Qt Application");

    // Create a label
    QLabel label("Hello, World!");

    // Create a button
    QPushButton button("Click me!");

    int counter;

    // Connect button click event to update the label
    QObject::connect(&button, &QPushButton::clicked, [&label, &counter]() {
        counter++;
        auto message = QString::fromStdString("Button Clicked: " + to_string(counter) + " times");
        label.setText(message);
        qDebug() << message;
    });

    // Create a layout and add the label and button
    QVBoxLayout layout;
    layout.addWidget(&label);
    layout.addWidget(&button);

    // Set the layout on the window
    window.setLayout(&layout);

    // Show the window
    window.show();

    return application.exec();
}
