# To-Do List App (C++)

A simple command-line to-do list manager written in C++.  
Tasks are stored in a plain text file (`tasks`) and loaded at startup.  
The app allows you to add, list, remove, and view help for tasks.

---

## Features

- **Add** a new task
- **List** all current tasks
- **Remove** a task by its index
- **Help** screen with usage examples
- **Persistent storage**: tasks are saved to a file when you exit

---

## Usage

Compile and run the program:

```bash
g++ -std=c++11 -o todo todo.cpp
./todo
```

You will see a list of available commands and your current tasks.  
Enter commands at the prompt:

```
Enter your input:
```

---

## Commands

| Command         | Description                                       | Example                    |
|-----------------|---------------------------------------------------|----------------------------|
| `:help`         | Show detailed help with examples                  | `:help`                    |
| `:l`            | List all tasks (displays the current list)        | `:l`                       |
| `:i <task>`     | Insert a new task at the end of the list          | `:i Buy groceries`         |
| `:rm <number>`  | Remove the task with the given **1‑based** index  | `:rm 2`                    |
| `:e`            | Save tasks to file and exit the program           | `:e`                       |

> **Note:** The initial command list shows some commands with an asterisk (`*`), but they are fully functional.

---

## How It Works

1. **Startup**  
   - If the file `tasks` exists, its contents are read into memory.  
   - If it doesn't exist, the app starts with an empty list.  
   - The existing file is then removed (to be rewritten on exit).

2. **Interaction**  
   - You enter commands in a loop.  
   - The current task list is displayed after each command.

3. **Exit**  
   - When you enter `:e`, all tasks are written to `tasks` (overwriting any previous content) and the program terminates.

---

## Building

### Prerequisites
- A C++ compiler (e.g., `g++`, `clang++`)
- Standard C++ libraries

### Compilation
```bash
g++ -std=c++11 -o todo main.cpp
```
(Replace `main.cpp` with the name of your source file.)

---

## Limitations & Known Issues

- Task lines are limited to **198 characters** (due to `fscanf` buffer).
- Empty lines in the input file are skipped.
- The `:i` command does not trim extra spaces from the task description.
- Commands like `:help` and `:l` are recognized even if they appear as substrings (e.g., `abc:help` will trigger help).
- The file is deleted on startup; if the program crashes before saving, tasks are lost.

---

## Future Improvements

- Use `std::ifstream`/`std::ofstream` for file I/O instead of C‑style functions.
- Add proper command parsing (exact matching, trimming).
- Support task completion status (e.g., checkboxes).
- Allow editing of existing tasks.
- Add error handling for edge cases (e.g., invalid indices, empty tasks).

---

## License

This project is open‑source and available under the MIT License.

---

## Contributing

Feel free to fork, improve, and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.
