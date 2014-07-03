#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QContextMenuEvent>
#include <QLabel>
#include <QVBoxLayout>

class MaFenetre : public QMainWindow
{
    Q_OBJECT

public:
    MaFenetre();

protected:
     void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void newProjectFunc();
    void newPageFunc();
    void openProjectFunc();
    void openFileFunc();
    void saveFunc();
    void saveAsFunc();
    void exportFunc();
    void helpFunc();
    void quitFunc();
    void redoFunc();
    void undoFunc();

private:
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QMenu *editMenu;
    QAction *newProjectAct;
    QAction *newPageAct;
    QAction *openProjectAct;
    QAction *openFileAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exportAct;
    QAction *helpAct;
    QAction *quitAct;
    QAction *redoAct;
    QAction *undoAct;
    QLabel *infoLabel;
};

#endif
