#pragma once
#include <iostream>
#include <string>

struct Task {
    char title[100];
    std::string description;
    int priority;
    std::string date;
};

Task createTask();
void deleteTask(Task tasks[], int& taskCount);
void editTask(Task tasks[], int taskCount);
void searchTasks(const Task tasks[], int taskCount);
void displayTasks(const Task tasks[], int taskCount);
bool searchTask(const Task& task, const std::string& searchParam);
void displayTask(const Task& task);
bool sortByPriority(const Task& task1, const Task& task2);
bool sortByDate(const Task& task1, const Task& task2);