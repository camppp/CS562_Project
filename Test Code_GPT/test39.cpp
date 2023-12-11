#include <QSortFilterProxyModel>
#include <QModelIndex>

class CustomProxyModel : public QSortFilterProxyModel {
public:
    CustomProxyModel(QObject* parent = nullptr) : QSortFilterProxyModel(parent) {}

protected:
    bool lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const override {
        // Custom sorting based on alphabetical order
        QVariant leftData = sourceModel()->data(source_left);
        QVariant rightData = sourceModel()->data(source_right);

        return QString::localeAwareCompare(leftData.toString(), rightData.toString()) < 0;
    }

    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override {
        // Custom filtering based on location type (assuming role 0 represents location type)
        QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
        QVariant locationType = sourceModel()->data(index);

        // Filter based on location type (modify the condition as per your requirement)
        return locationType.toString() == "Office";
    }
};
