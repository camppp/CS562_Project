#include <Windows.h>
#include <Windows.UI.Notifications.h>

using namespace Windows::UI::Notifications;

class NotificationManager
{
public:
    void showToastNotification(String^ message)
    {
        ToastNotification^ notification = ref new ToastNotification(message);
        ToastNotificationManager::CreateToastNotifier()->Show(notification);
    }

    void showToastNotificationWithAction(String^ message, Action^ action)
    {
        ToastNotification^ notification = ref new ToastNotification(message);
        notification->Actions->Append(action);
        ToastNotificationManager::CreateToastNotifier()->Show(notification);
    }
};
