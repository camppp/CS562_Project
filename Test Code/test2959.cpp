#include <Windows.h>
#include <wrl.h>
#include <windows.ui.notifications.h>
#include <windows.data.xml.dom.h>

using namespace Windows::UI::Notifications;
using namespace Windows::Data::Xml::Dom;
using namespace Microsoft::WRL;

class NotificationManager {
public:
    void showToastNotification(const std::wstring& message) {
        ComPtr<IToastNotifier> notifier;
        ToastNotificationManager::CreateToastNotifier(&notifier);

        ComPtr<IXmlDocument> toastXml;
        hstring xml = L"<toast><visual><binding template='ToastText01'><text id='1'>" + message + L"</text></binding></visual></toast>";
        HRESULT hr = Windows::Data::Xml::Dom::XmlDocument::LoadFromXml(xml, &toastXml);
        if (SUCCEEDED(hr)) {
            ToastNotification toast(toastXml.Get());
            notifier->Show(toast.Get());
        }
    }

    void showToastNotificationWithAction(const std::wstring& message, const std::wstring& action) {
        ComPtr<IToastNotifier> notifier;
        ToastNotificationManager::CreateToastNotifier(&notifier);

        ComPtr<IXmlDocument> toastXml;
        hstring xml = L"<toast><visual><binding template='ToastText01'><text id='1'>" + message + L"</text></binding></visual><actions><action content='" + action + L"' arguments='" + action + L"'/></actions></toast>";
        HRESULT hr = Windows::Data::Xml::Dom::XmlDocument::LoadFromXml(xml, &toastXml);
        if (SUCCEEDED(hr)) {
            ToastNotification toast(toastXml.Get());
            notifier->Show(toast.Get());
        }
    }
};
