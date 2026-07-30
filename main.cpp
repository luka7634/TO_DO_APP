#include <cstdio>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

void show_help(void);
void insert(std::string input, std::vector<std::string> &ToDoList);
const char *filename = "tasks";

int main(int argc, char *argv[]) {
  std::vector<std::string> ToDoList;
  bool fileExisted = true;

  FILE *input_file = fopen(filename, "r");
  if (!input_file) {
    fileExisted = false;
  } else {
    char line[200];
    while (fscanf(input_file, "%198[^\n]\n", line) == 1) {
      ToDoList.push_back(line);
    }
    fclose(input_file);
  }

  if (fileExisted) {
    if (remove(filename) != 0) {
      std::cerr << "Warning: Could not remove old file." << std::endl;
    } else {
      std::cout << "Old tasks file removed." << std::endl;
    }
  }
  // asterisk means is not implented
  std::vector<std::string> show_available_commands = {
      "* :i - Insert new task at the end of the file", "* :rm - Delete a task",
      ":l - List all tasks.", "* :help - Shows how to use all commands",
      "* :e - Exit"};

  fprintf(stdout, "====== TO-DO App ======\n");
  fprintf(stdout, "Commands:\n");
  for (int i = 0; i < show_available_commands.size(); i++) {
    std::cout << show_available_commands[i] << std::endl;
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  while (1) {
    std::cout << std::endl;

    std::cout << "====| List of tasks |====" << std::endl;

    for (int i = 0; i < ToDoList.size(); i++) {
      std::cout << i + 1 << " - " << ToDoList[i] << std::endl;
    }

    std::cout << "Enter your input: " << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::cout << std::endl;

    if (input.find(":help") != std::string::npos) {
      show_help();
    } else if (input.find(":l") != std::string::npos) {
      for (int i = 0; i < ToDoList.size(); i++) {
        std::cout << i + 1 << " - " << ToDoList[i] << std::endl;
      }
    } else if (input.find(":i") != std::string::npos) {
      std::string send = "";
      for (int i = 3; i < input.length(); i++)
        send += input[i];
      insert(send, ToDoList);
    } else if (input.rfind(":rm", 0) == 0) {
      std::stringstream ss(input);
      std::string cmd;
      int idx;
      ss >> cmd;       // reads ":rm"
      if (ss >> idx) { // tries to read an integer
        int vecIndex = idx - 1;
        if (vecIndex >= 0 && vecIndex < ToDoList.size()) {
          ToDoList.erase(ToDoList.begin() + vecIndex);
          std::cout << "Task " << idx << " removed.\n";
        } else {
          std::cout << "No task at index " << idx << ".\n";
        }
      } else {
        std::cout << "Please specify a task number, e.g. :rm 2\n";
      }
    } else if (input.find(":e") != std::string::npos) {
      FILE *output;
      if (!(output = fopen(filename, "w"))) {
        fprintf(stderr, "Can't create the output file.");
        return 1;
      }

      for (int i = 0; i < ToDoList.size(); i++) {
        fprintf(output, "%s\n", ToDoList[i].c_str());
      }
      fclose(output);
      return 0;
    }
  }

  return 0;
}

void insert(std::string input, std::vector<std::string> &ToDoList) {
  ToDoList.push_back(input);
}

void show_help(void) {
  std::cout << "=== HELP ===" << std::endl;

  std::vector<std::string> example_list = {
      "[ ] Do my homework.", "[ ] Clean my room.", "[ ] Do that job."};

  std::cout << std::endl;
  std::cout << ":help - Shows this help line" << std::endl << std::endl;

  std::cout << ":i - Insert a new task at the end of the file." << std::endl;
  std::cout << "Use example: " << std::endl;
  std::cout << "Example list: " << std::endl;
  for (int i = 0; i < example_list.size(); i++) {
    std::cout << i + 1 << " - " << example_list[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Enter your input: " << std::endl;
  std::cout << ":i [ ] Clean my shoes." << std::endl;
  std::cout << std::endl;
  example_list.push_back("[ ] Clean my shoes");
  for (int i = 0; i < example_list.size(); i++) {
    std::cout << i + 1 << " - " << example_list[i] << std::endl;
  }
  example_list.pop_back();
  std::cout << std::endl;

  std::cout << ":rm - Delete a task." << std::endl;
  std::cout << "Use example: " << std::endl << std::endl;
  std::cout << "Example list: " << std::endl;
  for (int i = 0; i < example_list.size(); i++) {
    std::cout << i + 1 << " - " << example_list[i] << std::endl;
  }
  std::cout << "Enter your input: " << std::endl;
  std::cout << ":rm 2" << std::endl;
  std::cout << "<<Being 2 the index of the note/task that you want to remove>>"
            << std::endl;
  std::cout << std::endl;

  // this will be the parch while i figure out how to remove an element from a
  // vector
  for (int i = 0; i < example_list.size(); i++) {
    if (i + 1 == 2)
      continue;
    //
    std::cout << i + 1 << " - " << example_list[i] << std::endl;
  }

  std::cout << std::endl;
  std::cout << ":e - Ends the program" << std::endl;
}
