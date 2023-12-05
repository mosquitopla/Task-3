#include "task.h"

Task createTask() {
    Task newTask;
    std::cout << "Enter title: ";
    std::cin.ignore();
    std::cin.getline(newTask.title, sizeof(newTask.title));

    std::cout << "Enter description: ";
    std::getline(std::cin, newTask.description);

    std::cout << "Enter priority: ";
    std::cin >> newTask.priority;

    std::cout << "Enter time: ";
    std::cin >> newTask.date;

    return newTask;
}

void deleteTask(Task tasks[], int& taskCount) {
    if (taskCount > 0) {
        int index;
        std::cout << "Enter the task number to delete: ";
        std::cin >> index;

        if (index >= 1 && index <= taskCount) {
            for (int i = index - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            std::cout << "Task deleted.\n";
        }
        else {
            std::cout << "Invalid task number.\n";
        }
    }
    else {
        std::cout << "Task list is empty.\n";
    }
}

void editTask(Task tasks[], int taskCount) {
    if (taskCount > 0) {
        int index;
        std::cout << "Enter the task number to edit: ";
        std::cin >> index;

        if (index >= 1 && index <= taskCount) {
            tasks[index - 1] = createTask();
            std::cout << "Task edited.\n";
        }
        else {
            std::cout << "Invalid task number.\n";
        }
    }
    else {
        std::cout << "Task list is empty.\n";
    }
}

void searchTasks(const Task tasks[], int taskCount) {
    if (taskCount > 0) {
        std::cout << "Enter the search parameter (title, priority, description, date): ";
        std::string searchParam;
        std::cin.ignore();
        std::getline(std::cin, searchParam);

        bool found = false;
        for (int i = 0; i < taskCount; ++i) {
            if (searchTask(tasks[i], searchParam)) {
                displayTask(tasks[i]);
                found = true;
            }
        }

        if (!found) {
            std::cout << "No tasks found for the specified parameter.\n";
        }
    }
    else {
        std::cout << "Task list is empty.\n";
    }
}

void displayTasks(const Task tasks[], int taskCount) {
    if (taskCount > 0) {
        
        std::cout << "Enter sorting parameter (1 for priority, 2 for date and time): ";
        int sortingOption;
        std::cin >> sortingOption;

        for (int i = 0; i < taskCount - 1; ++i) {
            for (int j = 0; j < taskCount - i - 1; ++j) {
                if ((sortingOption == 1 && sortByPriority(tasks[j], tasks[j + 1])) ||
                    (sortingOption == 2 && sortByDate(tasks[j], tasks[j + 1]))) {
                    std::swap(tasks[j], tasks[j + 1]);
                }
            }
        }

        for (int i = 0; i < taskCount; ++i) {
            displayTask(tasks[i]);
        }
    }
    else {
        std::cout << "Task list is empty.\n";
    }
}

bool searchTask(const Task& task, const std::string& searchParam) {
    if (searchParam == task.title ||
        std::to_string(task.priority) == searchParam ||
        searchParam == task.description ||
        searchParam == task.date) {
        std::cout << "Match found:\n";
        std::cout << "Title: " << task.title << "\n";
        std::cout << "Priority: " << task.priority << "\n";
        std::cout << "Description: " << task.description << "\n";
        std::cout << "Date: " << task.date << "\n";
        std::cout << "\n";
        return true;
    }
    return false;
}

void displayTask(const Task& task) {
    std::cout << "Title: " << task.title << '\n';
    std::cout << "Priority: " << task.priority << '\n';
    std::cout << "Description: " << task.description << '\n';
    std::cout << "Time: " << task.date << '\n';
    
}