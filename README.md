# 🐈 Cat Framework

> "Simplify. Evaluate. Move forward."

Cat Framework is a modern C++ framework for building autonomous systems based on the MAPE-K loop (Monitor, Analyze, Plan, Execute, Knowledge). It offers a modular architecture, a powerful CLI, and ready-to-use examples to accelerate your development.

---

## 🚀 Installation

```bash
# Clone the repository
$ git clone https://github.com/your-user/cat-framework.git
$ cd cat-framework

# Install dependencies and the framework (requires sudo)
$ ./install.sh
```

---

## 🐱 Starting a New Project

With the CLI installed, create a new project with ready-to-use examples:

```bash
$ catcli init my-project
$ cd my-project
```

This will generate a directory structure with examples for each framework component.

---

## 🔨 Build and Run

Easily build and run your project:

```bash
$ catcli build   # Builds the project (generates ./dist/app)
$ catcli run     # Builds and runs the project
```

You can also compile manually:
```bash
$ g++ -g -std=c++17 main.cpp -o app -Icore -Lbuild -lcat
$ ./app
```

---

## 📂 Generated Project Structure

```
my-project/
├── main.cpp
├── behavior/
│   ├── executor.action.hpp
│   ├── monitor.action.hpp
│   └── planner.action.hpp
├── constraints/
│   └── default.constraint.hpp
├── mapek/
│   └── default.mapek.hpp
├── models/
│   └── fan.model.hpp
├── modules/
│   └── default.module.hpp
└── strategy/
    └── default.strategyset.hpp
```

---

## 📖 Basic Tutorial

### 1. Modify the Monitor
Open `behavior/monitor.action.hpp` and implement your monitoring logic.

### 2. Create a New Module
Create a new file in `modules/` and register your module in `main.cpp`.

### 3. Add Strategies
Implement strategies in `strategy/` and link them to the Planner.

### 4. Compile and Run
```bash
$ catcli run
```

---

## 🛠️ Advanced Concepts
- Use smart pointers (`std::shared_ptr`) to handle models and strategies.
- The MAPE-K loop runs in a separate thread for high performance.
- Add constraints in `constraints/` for custom decision logic.

---

## ❌ Uninstall

```bash
$ ./uninstall.sh
```

---

## 💬 Feedback
Feel free to open issues or contribute! :3

---

**Cat Framework** © 2025 — Wendril Avila