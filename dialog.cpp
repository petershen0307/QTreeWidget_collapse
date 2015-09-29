#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QTreeWidgetItem* pTreeItem = ui->treeWidget->topLevelItem(0)->child(0);
    pTreeItem->setData(0, Qt::UserRole, QVariant::fromValue(0));
    pTreeItem = ui->treeWidget->topLevelItem(0)->child(1);
    pTreeItem->setData(0, Qt::UserRole, QVariant::fromValue(1));
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(OnTreeItemClicked(QTreeWidgetItem*, int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::OnTreeItemClicked(QTreeWidgetItem* item, int column)
{
    Q_UNUSED(column);
    int itemIndex = qvariant_cast<int>(item->data(0, Qt::UserRole));
    switch (itemIndex)
    {
        case 0:
        {
            ui->label->setVisible(true);
            ui->label_2->setVisible(false);
            break;
        }
        case 1:
        {
            ui->label->setVisible(false);
            ui->label_2->setVisible(true);
            break;
        }
        default:
        {
            Q_ASSERT(false);
        }
    }
}
