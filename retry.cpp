#include <iostream>
#include <string>
#include <vector>

class Task
{
private:
    std::string name;
    int priority;
    bool completed;

public:
    Task(std::string a, int b, bool c)
    {
        name = a;
        priority = 1;
        if (b >= 1 && b <= 5)
        {
            priority = b;
        }
        completed = c;
    }

    void changeName(std::string newName)
    {
        if (!newName.empty())
        {
            name = newName;
        }
    }

    void completeTask()
    {
        completed = true;
    }

    bool isCompleted() const
    {
        return completed;
    }

    void updatePriority(int newPriority)
    {
        if (newPriority >= 1 && newPriority >= 5)
        {
            priority = newPriority;
        }
    }

    bool operator==(const Task &other) const
    {
        return name == other.name && priority == other.priority && completed == other.priority;
    }

    void getInfo() const
    {
        std::cout << "Task name: " << name << " | Priority: " << priority << " | " << (completed ? "Task completed" : "IN progress") << '\n';
    }
};

int main()
{
    std::cout << "=====================TASK MANAGER=====================" << '\n';
    std::vector<Task> tasks;
    tasks.push_back(Task("Task 1", 1, true));
    tasks.push_back(Task("Task 2", 2, false));
    tasks.push_back(Task("Task 123", 3, false));
    tasks.push_back(Task("Task 4", 99, true));
    tasks.push_back(Task("Task 5", 5, false));
    tasks.push_back(Task("Task ?", 32, true));
    tasks.push_back(Task("asdfjasdkjfhdasl", 0, false));

    tasks[2].changeName("Task 3");
    tasks[3].updatePriority(4);
    tasks[4].completeTask();
    tasks[5].changeName("Task 6");
    tasks[5].updatePriority(6);
    tasks[6].changeName("Task 7");
    tasks[6].updatePriority(7);

    for (int i = 0; i < tasks.size(); i++)
    {
        tasks[i].getInfo();
    }

    std::cout << "=======================================================" << '\n';

    return 0;
}