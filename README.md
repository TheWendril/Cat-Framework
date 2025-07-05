# 🐾 Cat Framework

> "Always make the simple as possible, evaluate, forward"

Cat Framework é um framework C++ moderno para construção de sistemas autônomos baseados no ciclo MAPE-K (Monitor, Analyze, Plan, Execute, Knowledge). Ele oferece uma arquitetura modular, CLI poderosa e exemplos prontos para acelerar seu desenvolvimento.

---

## 🚀 Instalação

```bash
# Clone o repositório
$ git clone https://github.com/seu-usuario/cat-framework.git
$ cd cat-framework

# Instale as dependências e o framework (requer sudo)
$ ./install.sh
```

---

## 🐱 Iniciando um novo projeto

Com a CLI instalada, crie um novo projeto com exemplos prontos:

```bash
$ catcli init meu-projeto
$ cd meu-projeto
```

Isso irá gerar uma estrutura de diretórios com exemplos de cada componente do framework.

---

## 🔨 Build e Execução

Compile e execute seu projeto facilmente:

```bash
$ catcli build   # Compila o projeto (gera ./dist/app)
$ catcli run     # Compila e executa o projeto
```

Você também pode compilar manualmente:
```bash
$ g++ -g -std=c++17 main.cpp -o app -Icore -Lbuild -lcat
$ ./app
```

---

## 📂 Estrutura de Projeto Gerada

```
meu-projeto/
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

## 📖 Tutorial Básico

### 1. Modifique o Monitor
Abra `behavior/monitor.action.hpp` e implemente sua lógica de monitoramento.

### 2. Crie um novo Módulo
Crie um novo arquivo em `modules/` e registre seu módulo no `main.cpp`.

### 3. Adicione Estratégias
Implemente estratégias em `strategy/` e vincule-as ao Planner.

### 4. Compile and Run
```bash
$ catcli run
```

---

## 🛠️ Advanced Concepts
- Use smart pointers (`std::shared_ptr`) para manipular modelos e estratégias.
- O loop MAPE-K roda em thread separada para alta performance.
- Adicione constraints em `constraints/` para lógica de decisão customizada.

---

## ❌ Uninstall

```bash
$ ./uninstall.sh
```

---

## 💬 Feedback
Fique à vontade para abrir issues ou contribuir! :3

---

**Cat Framework** © 2025 — Feito com carinho por Wendril Avila