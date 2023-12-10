// CustomProxyModel.h
#ifndef CUSTOMPROXYMODEL_H
#define CUSTOMPROXYMODEL_H

#include <QSortFilterProxyModel>

class CustomProxyModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    explicit CustomProxyModel(QObject *parent = nullptr);

protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override {
        // Implement custom sorting logic based on specific criteria
        // Example: Sort alphabetically based on location names
        QVariant leftData = sourceModel()->data(left);
        QVariant rightData = sourceModel()->data(right);
        return QString::localeAwareCompare(leftData.toString(), rightData.toString()) < 0;
    }

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override {
        // Implement custom filtering logic based on user-defined conditions
        // Example: Filter based on location type
        QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
        QVariant locationType = sourceModel()->data(index, LocationTypeRole);
        return locationType.toString() == "Restaurant";  // Filter for restaurants
    }
};

#endif // CUSTOMPROXYMODEL_H
