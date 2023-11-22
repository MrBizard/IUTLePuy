#include "ModelView.h"

ModelView::ModelView(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    m_model.setHorizontalHeaderLabels(QStringList{ "Nom", "Rouge", "Vert", "Bleu" });

    QStandardItem* rootItem = m_model.invisibleRootItem();

    rootItem->setChild(0, 0, new QStandardItem{ QIcon{ ":/Icones/Red.png" }, "Rouge" });
    rootItem->setChild(0, 1, new QStandardItem{ "255" });
    rootItem->setChild(0, 2, new QStandardItem{ "0" });
    rootItem->setChild(0, 3, new QStandardItem{ "0" });

    rootItem->child(0, 0)->setChild(0, 0, new QStandardItem{ QIcon{ ":/Icones/Orange.png" }, "Orange" });
    rootItem->child(0, 0)->setChild(0, 1, new QStandardItem{ "255" });
    rootItem->child(0, 0)->setChild(0, 2, new QStandardItem{ "127" });
    rootItem->child(0, 0)->setChild(0, 3, new QStandardItem{ "0" });

    rootItem->child(0, 0)->setChild(1, 0, new QStandardItem{ QIcon{ ":/Icones/Yellow.png" }, "Jaune" });
    rootItem->child(0, 0)->setChild(1, 1, new QStandardItem{ "255" });
    rootItem->child(0, 0)->setChild(1, 2, new QStandardItem{ "255" });
    rootItem->child(0, 0)->setChild(1, 3, new QStandardItem{ "0" });

    rootItem->appendRow(QList < QStandardItem* > {new QStandardItem{ QIcon{ ":/Icones/Green.png" }, "Vert" }, new QStandardItem{ "0" }, new QStandardItem{ "255" }, new QStandardItem{ "0" }});
    rootItem->child(1)->appendRow(QList < QStandardItem* > {new QStandardItem{ QIcon{ ":/Icones/GreenYellow.png" }, "Vert - Jaune" }, new QStandardItem{ "127" }, new QStandardItem{ "255" }, new QStandardItem{ "0" }});

    rootItem->appendRow(QList < QStandardItem* > {new QStandardItem{ QIcon{ ":/Icones/Blue.png" }, "Bleu" }, new QStandardItem{ "0" }, new QStandardItem{ "0" }, new QStandardItem{ "255" }});

    ui.listView->setModel(&m_model);
    ui.tableView->setModel(&m_model);
    ui.treeView->setModel(&m_model);
    ui.columnView->setModel(&m_model);
}

ModelView::~ModelView()
{

}
