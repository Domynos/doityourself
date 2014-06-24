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
    void newFile();
    void open();
    void save();

private:
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QMenu *editMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QLabel *infoLabel;
};

#endif
