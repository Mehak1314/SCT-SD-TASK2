# 🎮 Number Guessing Game (Qt C++)

A fun and simple **Number Guessing Game** built with **Qt C++ Widgets**.  
The program randomly selects a number between **1 and 100**, and the user must guess it.  
Each guess is compared to the secret number and the app provides hints:  

- 🔽 **Too low** → Guess a higher number  
- 🔼 **Too high** → Guess a lower number  
- ✅ **Correct** → You win! 🎉  

---

## ✨ Features
- 🎲 **Random number generation** using `QRandomGenerator`  
- 🖥️ **Interactive GUI** with input field, button, and feedback label  
- ⚡ **Instant feedback** (too high / too low / correct)  
- 🗂️ Entire game implemented in **one file (`main.cpp`)**  
- 🎯 Minimal and beginner-friendly Qt project  

---

## 🖼️ Interface
- **Input box** → Enter your guess  
- **Check button** → Submit your guess  
- **Feedback label** → Displays hints and results  

---

## 📄 Code Overview
- `QApplication` → Starts the Qt app  
- `QWidget` → Main window  
- `QLineEdit` → For entering guesses  
- `QPushButton` → To check the guess  
- `QLabel` → Shows feedback  
- `QVBoxLayout` → Simple vertical layout  
- `QRandomGenerator` → Creates the secret number  

---

## 🛠️ Tech Stack
- **Language**: C++  
- **Framework**: Qt (Qt5 or Qt6 supported)  
- **GUI Widgets**: QLabel, QLineEdit, QPushButton, QVBoxLayout  

---

## 📄 Example Code Snippet
```cpp
int secretNumber = QRandomGenerator::global()->bounded(1, 101);
QObject::connect(checkButton, &QPushButton::clicked, [&]() {
    bool ok;
    int guess = input->text().toInt(&ok);
    if (!ok) { feedback->setText("❌ Enter a valid number."); return; }
    if (guess < secretNumber) feedback->setText("Too low!");
    else if (guess > secretNumber) feedback->setText("Too high!");
    else feedback->setText("🎉 Correct!");
});
