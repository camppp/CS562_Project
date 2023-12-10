#include <QObject>
#include <QList>
#include "task.h"

namespace LeechCraft
{
namespace DBusManager
{
    class Tasks : public QObject
    {
        Q_OBJECT

    public:
        Tasks(QObject *parent = nullptr);

        void addTask(int taskId, const QString &description);
        void deleteTask(int taskId);
        QList<Task> getTasks() const;

    signals:
        void taskAdded(int taskId, const QString &description);
        void taskDeleted(int taskId);

    private:
        QList<Task> tasks_;
    };
}
}

Tasks::Tasks(QObject *parent) : QObject(parent)
{
}

void Tasks::addTask(int taskId, const QString &description)
{
    tasks_.append(Task(taskId, description));
    emit taskAdded(taskId, description);
}

void Tasks::deleteTask(int taskId)
{
    for (int i = 0; i < tasks_.size(); ++i) {
        if (tasks_[i].id == taskId) {
            tasks_.removeAt(i);
            emit taskDeleted(taskId);
            return;
        }
    }
}

QList<Task> Tasks::getTasks() const
{
    return tasks_;
}
