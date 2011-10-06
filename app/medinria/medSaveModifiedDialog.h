#ifndef MEDSAVEMODIFIEDDIALOG_H
#define MEDSAVEMODIFIEDDIALOG_H

#include <QFileDialog>
#include <QTreeWidget>
#include <QTreeView>

#include <medCore/medDataIndex.h>
#include <medCore/medDataManager.h>

class QTreeWidget;
class QTreeWidgetItem;
class medSaveModifiedDialogPrivate;

class medSaveModifiedDialog: public QDialog
{
    Q_OBJECT
    
public:
  
    medSaveModifiedDialog(QWidget *parent);
    virtual ~medSaveModifiedDialog();

signals :

    void updateTree();

public slots:

    void Save();
    void updateCounter();
    void onUpdateTree();

private:
  
    medSaveModifiedDialogPrivate *d;
};







































#endif // MEDSAVEMODIFIEDDIALOG_H






