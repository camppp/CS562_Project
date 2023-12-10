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

        void addTask(int taskId, const QString &description)
        {
            Task newTask;
            newTask.id = taskId;
            newTask.description = description;
            tasks_.append(newTask);
            emit taskAdded(taskId, description);
        }

        void deleteTask(int taskId)
        {
            for (int i = 0; i < tasks_.size(); ++i)
            {
                if (tasks_[i].id == taskId)
                {
                    tasks_.removeAt(i);
                    emit taskDeleted(taskId);
                    return;
                }
            }
        }

        QList<Task> getTasks() const
        {
            return tasks_;
        }

    signals:
        void taskAdded(int taskId, const QString &description);
        void taskDeleted(int taskId);

    private:
        QList<Task> tasks_;
    };
}
}
