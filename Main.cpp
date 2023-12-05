#include "task.h"

using namespace std;

int main()
{
    Task tasks[100];
    int taskCount = 0;

    while (true) {
        cout << "Enter 1 to add task\n";
        cout << "Enter 2 to delete task\n";
        cout << "Enter 3 to edit task\n";
        cout << "Enter 4 to search task\n";
        cout << "Enter 5 to display tasks list\n";

        int choice = 0;
        cin >> choice;

        switch (choice) {
        case 1:
            tasks[taskCount++] = createTask();
            break;
        case 2:
            deleteTask(tasks, taskCount);
            break;
        case 3:
            editTask(tasks, taskCount);
            break;
        case 4:
            searchTasks(tasks, taskCount);
            break;
        case 5:
            displayTasks(tasks, taskCount);
            break;
        }
    }
}