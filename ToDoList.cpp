#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;
};

// Function to add a new task to the list
void addTask(vector<Task>& taskList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added successfully." << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << "[" << (i + 1) << "] ";
            cout << (taskList[i].completed ? "[Done] " : "[Pending] ");
            cout << taskList[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number. Task not marked as completed." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList.erase(taskList.begin() + (index - 1));
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task number. Task not removed." << endl;
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "\nTodo List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Consume the newline character left by previous input
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                addTask(taskList, description);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                cout << "Enter the task number to mark as completed: ";
                size_t index;
                cin >> index;
                markCompleted(taskList, index);
                break;
            }
            case 4: {
                cout << "Enter the task number to remove: ";
                size_t index;
                cin >> index;
                removeTask(taskList, index);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
