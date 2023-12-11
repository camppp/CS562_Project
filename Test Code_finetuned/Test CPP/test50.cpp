#include <QSortFilterProxyModel>
#include <QString>

class UserLocationsProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    UserLocationsProxyModel(QObject *parent = nullptr) : QSortFilterProxyModel(parent) {}

protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override
    {
        QVariant leftData = sourceModel()->data(left);
        QVariant rightData = sourceModel()->data(right);

        if (leftData.canConvert<QString>() && rightData.canConvert<QString>())
        {
            QString leftString = leftData.toString();
            QString rightString = rightData.toString();

            // Sort by user's name
            return QString::localeAwareCompare(leftString, rightString) < 0;
        }

        return QSortFilterProxyModel::lessThan(left, right);
    }

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override
    {
        QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
        QVariant data = sourceModel()->data(index);

        if (data.canConvert<QString>())
        {
            QString stringData = data.toString();

            // Filter by user's location
            if (stringData.contains("location"))
                return true;
        }

        return QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
    }
};


connect(sourceModel, &QAbstractItemModel::rowsInserted, this, &QSortFilterProxyModel::invalidate);
connect(sourceModel, &QAbstractItemModel::rowsRemoved, this, &QSortFilterProxyModel::invalidate);
connect(sourceModel, &QAbstractItemModel::dataChanged, this, &QSortFilterProxyModel::invalidate);