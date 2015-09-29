#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QDialog>

class QTreeWidgetItem;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void OnTreeItemClicked(QTreeWidgetItem* item, int column);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
