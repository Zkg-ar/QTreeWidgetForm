#include "qtreewidgetform.h"

QTreeWidgetForm::QTreeWidgetForm()
{
    this->resize(400,250);
    window = new QWidget(this);
    treeWidget = new QTreeWidget();
    layout = new QHBoxLayout(window);
    gridLayout = new QGridLayout();
    textEdit = new QTextEdit();
    label1 = new QLabel();
    label2 = new QLabel();
    lineEdit = new QLineEdit();
    setDescribeOfElemnts();

}

void QTreeWidgetForm::setDescribeOfElemnts(){
    treeWidget->setFixedHeight(200);
    treeWidget->setFixedWidth(200);
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabel("?????? ???");
    layout->addWidget(treeWidget);
    label1->setText("????????????");
    gridLayout->addWidget(label1);
    gridLayout->addWidget(lineEdit);
    label2->setText("????????");
    gridLayout->addWidget(label2);
    textEdit->setFixedHeight(100);
    textEdit->setFixedWidth(150);
    gridLayout->addWidget(textEdit);
    layout->addLayout(gridLayout);

    insertInfoIntoQTreeWidget();

}
void QTreeWidgetForm::insertInfoIntoQTreeWidget(){


    QSqlQuery query("SELECT NAME FROM QTREEWIDGETTASKS");
    QSqlQuery query1;


    while(query.next()){
        QTreeWidgetItem *topLevelItems = new QTreeWidgetItem(treeWidget);
        topLevelItems->setText(0,query.value(0).toString());
        query1.prepare("SELECT SUBTASK_NAME FROM QTREEWIDGETBLOB WHERE TASK_ID = (SELECT ID FROM QTREEWIDGETTASKS WHERE NAME LIKE :str)");
        query1.bindValue(":str",query.value(0).toString());
        query1.exec();
        while(query1.next()){
            QTreeWidgetItem *child = new QTreeWidgetItem(topLevelItems);
            child->setText(0,query1.value(0).toString());
        }
    }
    QObject::connect(treeWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(set_text_to_line_edit()));

}
void QTreeWidgetForm::set_text_to_line_edit(){
    lineEdit->setText(treeWidget->currentItem()->text(0));
    set_text_to_text_edit();
    set_text_to_text_edit_2();
}
void QTreeWidgetForm :: set_text_to_text_edit(){
    QSqlQuery query;
    query.prepare("SELECT DESCRIBE FROM QTREEWIDGETTASKS  WHERE NAME LIKE :str");
    query.bindValue(":str",lineEdit->text());
    query.exec();
    while(query.next()){
        textEdit->setText(query.value(0).toString());
    }

}
void QTreeWidgetForm::set_text_to_text_edit_2(){
    QSqlQuery query;

    //    query.exec("blob get column = 2");

    //    while(query.next()){
    //        textEdit->setText(query.boundValue(0).toString());
    //    }
    //    query.prepare("SELECT DESCRIBE FROM QTREEWIDGETSUBTASKS  WHERE SUBTASK_NAME LIKE :str");
    query.prepare("SELECT DESCRIBE FROM QTREEWIDGETBLOB  WHERE SUBTASK_NAME LIKE :str");
    query.bindValue(":str",lineEdit->text());
    query.exec();
    while(query.next()){
        textEdit->setText(query.value(0).toString());
    }
}
