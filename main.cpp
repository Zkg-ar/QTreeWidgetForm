#include <QApplication>
#include "qtreewidgetform.h"
#include "qtreewidgetdatabase.h"


int main(int argc, char *argv[]){

    QApplication a(argc,argv);


     QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QTreeWidgetDatabase *database = new QTreeWidgetDatabase();
    QTreeWidgetForm obj;
    obj.show();


    return a.exec();
}
