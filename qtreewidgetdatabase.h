#ifndef QTREEWIDGETDATABASE_H
#define QTREEWIDGETDATABASE_H


#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QStringList>
#include <QTreeWidgetItem>


class QTreeWidgetDatabase
{
public:
    QTreeWidgetDatabase();


    QSqlDatabase db1;
    QSqlDatabase* db;

private:
    void get_information();
};

#endif // QTREEWIDGETDATABASE_H
