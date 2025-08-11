# Interactive Guessing Game 🎯

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Library](https://img.shields.io/badge/graphics-Raylib%20%26%20RayGUI-orange.svg)](https://www.raylib.com/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Contributors](https://img.shields.io/badge/contributors-6-brightgreen.svg)](#-team)

An **interactive, self-learning guessing game** built in C with a GUI powered by **Raylib** and **RayGUI**. The game challenges players to think of an item (course, club, car, etc.), then narrows down guesses through yes/no questions. If the game guesses wrong, it learns from the player by adding new questions — becoming smarter over time.

## 📌 Features
- **Multiple Modes**: Course, Country, Programming Language, Football Club, Car, plus **Custom Mode Creation**
- **Dynamic Learning**: Learns new questions and answers for future sessions
- **Multiplayer Mode**: Compete with friends; highest score wins
- **Undo Functionality**: Go back to the previous question
- **Timer**: Tracks the time taken per round
- **Tree Printing**: Visualize the decision tree structure
- **GUI Enhancements**:  
  - Custom backgrounds and themes per mode  
  - Interactive buttons, emojis, and sound effects  
  - Volume control via settings  

## 🛠 Tech Stack
- **Language**: C  
- **Graphics**: [Raylib](https://www.raylib.com/) & [RayGUI](https://github.com/raysan5/raygui)  
- **Data Structure**: Binary Tree for decision-making  
- **File Handling**: Saves learned data between sessions  

## 📂 Project Structure
```
├── src/
│   ├── game.c
│   ├── play_game.c
│   ├── mode_and_construction.c
│   ├── extra.c
│   └── 5leha_3la_allah.h
├── assets/
│   ├── images/
│   ├── music/
│   └── data_files/
├── CMakeLists.txt
└── README.md
```

## 🚀 How to Run
1. **Install Dependencies**:  
   - [Raylib](https://www.raylib.com/)  
   - [RayGUI](https://github.com/raysan5/raygui)  
2. **Clone the Repository**
   ```bash
   git clone https://github.com/yourusername/guessing-game.git
   cd guessing-game
   ```
3. **Build the Project** (example with CMake)  
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ./guessing-game
   ```
4. **Run from CLI** or **Open in CLion** with external terminal enabled.

## 🎮 How to Play
1. Select **Solo** or **Multiplayer** mode.  
2. Choose a category (Course, Car, Country, Programming, Football Club, or Custom).  
3. Answer each question with **Yes**, **No**, or **Undo**.  
4. If the game guesses wrong, teach it a new question and answer.  
5. In multiplayer, points are awarded when the game fails to guess correctly.  

## 📸 Screenshots
*(Add GUI screenshots here)*

## 👥 Team
- **Abdulrahman Gomaa** – Overall supervision, testing, gameplay, video editing  
- **Hassan Ahmed** – File handling, tree construction, custom game feature, documentation  
- **Ahmed Zaytoun** – Multiplayer mode, stats system, timer  
- **Moataz Ashraf** – Undo feature, learning mechanism, programming language mode  
- **Ziad Mohamed** – GUI setup, CMake integration, tree printing  
- **Seif Haytham** – GUI linking, themes/music, emoji interaction, presentation  

## 📚 References
- [Raylib Cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)  
- [RayGUI Examples](https://github.com/raysan5/raygui/tree/master/examples)  
- [GeeksforGeeks – Binary Tree](https://www.geeksforgeeks.org/binary-tree-data-structure/)  
- YouTube tutorials and programming resources (full list in report)  
