#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QRandomGenerator>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Number Guessing Game");
    window.resize(300, 150);

    // Generate random number between 1 and 100
    int secretNumber = QRandomGenerator::global()->bounded(1, 101);

    QLabel *prompt = new QLabel("Guess a number between 1 and 100:");
    QLineEdit *input = new QLineEdit();
    QPushButton *checkButton = new QPushButton("Check Guess");
    QLabel *feedback = new QLabel("");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(prompt);
    layout->addWidget(input);
    layout->addWidget(checkButton);
    layout->addWidget(feedback);

    QObject::connect(checkButton, &QPushButton::clicked, [&]() {
        bool ok;
        int guess = input->text().toInt(&ok);

        if (!ok) {
            feedback->setText("❌ Please enter a valid number.");
            return;
        }

        if (guess < secretNumber) {
            feedback->setText("Too low! Try again.");
        } else if (guess > secretNumber) {
            feedback->setText("Too high! Try again.");
        } else {
            feedback->setText("🎉 Correct! You guessed the number!");
        }
    });

    window.show();
    return app.exec();
}
