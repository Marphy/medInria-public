#ifndef medDatabaseProxyModel_h__
#define medDatabaseProxyModel_h__


#include "medSqlExport.h"

#include <QSortFilterProxyModel>
#include <QVector>
#include <QtCore>


/**
 * Proxy model that sits between a model and a view and filters + sorts items
 */
class MEDSQL_EXPORT medDatabaseProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    medDatabaseProxyModel(QObject *parent = 0);
    ~medDatabaseProxyModel();

    void setFilterRegExpWithColumn(const QRegExp &regExp, int column);

    void clearAllFilters();

protected slots:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;
    bool customFilterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;
private:
    mutable bool isCheckingChild;
    mutable bool isCheckingParent;
    QHash<int,QRegExp> filterVector;
    mutable int currentKey;
    mutable QRegExp currentValue;
};
#endif // medDatabaseProxyModel_h__
