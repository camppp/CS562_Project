#include "CustomProxyModel.h"  // Include the header file for your custom proxy model

class UserLocationsDialog : public QDialog {
    Q_OBJECT

public:
    UserLocationsDialog(QWidget* parent = nullptr) : QDialog(parent) {
        // Assume _userLocationsModel is an instance of your custom model class representing user locations
        _userLocationsModel = new YourUserLocationsModel(this);

        // Assume _proxyModel is a member of UserLocationsDialog
        _proxyModel = new CustomProxyModel(this);
        _proxyModel->setSourceModel(_userLocationsModel);

        // Assume _userLocationsView is an instance of QListView (or any other view)
        _userLocationsView->setModel(_proxyModel);
    }

private:
    YourUserLocationsModel* _userLocationsModel;
    CustomProxyModel* _proxyModel;
    // Other members...
};
