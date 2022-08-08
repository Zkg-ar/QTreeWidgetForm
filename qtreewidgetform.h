#ifndef QTREEWIDGETFORM_H
#define QTREEWIDGETFORM_H


#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QTextCodec>
#include "qtreewidgetdatabase.h"
#include <QByteArray>

class QTreeWidgetForm : public QWidget
{
    Q_OBJECT
public:
    QTreeWidgetForm();
    QWidget *window;
    QHBoxLayout *layout;
    QTreeWidget *treeWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label1;
    QLabel *label2;

private:
    void setDescribeOfElemnts();
    void insertInfoIntoQTreeWidget();

private slots:
    void set_text_to_line_edit();
    void set_text_to_text_edit();
    void set_text_to_text_edit_2();

};

#endif // QTREEWIDGETFORM_H
