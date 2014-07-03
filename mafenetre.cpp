#include "MaFenetre.h"

MaFenetre::MaFenetre()
{

    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

#ifdef Q_OS_SYMBIAN
    infoLabel = new QLabel(tr("<i>Choose a menu option</i>"));
#else
    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
#endif
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);
    createActions();
    createMenus();

    setWindowTitle(tr("Do It Yourself"));
    setMinimumSize(160, 160);
    resize(1024, 800);
}

void MaFenetre::createActions(){

    newProjectAct = new QAction(tr("&Project"), this);
    newProjectAct->setShortcuts(QKeySequence::New);
    newProjectAct->setStatusTip(tr("Create a new project"));
    connect(newProjectAct, SIGNAL(triggered()), this, SLOT(newProjectFunc()));

    newPageAct = new QAction(tr("&Page"), this);
    newPageAct->setStatusTip(tr("Create a new file"));
    connect(newPageAct, SIGNAL(triggered()), this, SLOT(newPageFunc()));

    openProjectAct = new QAction(tr("&Project"), this);
    openProjectAct->setShortcuts(QKeySequence::Open);
    openProjectAct->setStatusTip(tr("Create a new file"));
    connect(openProjectAct, SIGNAL(triggered()), this, SLOT(openProjectFunc()));

    openFileAct = new QAction(tr("&File"), this);
    openFileAct->setStatusTip(tr("Create a new file"));
    connect(openFileAct, SIGNAL(triggered()), this, SLOT(openFileFunc()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFunc()));

    saveAsAct = new QAction(tr("&Save As"), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save As"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAsFunc()));

    exportAct = new QAction(tr("&Export"), this);
    exportAct->setStatusTip(tr("Export"));
    connect(exportAct, SIGNAL(triggered()), this, SLOT(exportFunc()));

    helpAct = new QAction(tr("&Help"), this);
    helpAct->setStatusTip(tr("Help"));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(helpFunc()));

    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setStatusTip(tr("Quit"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(quitFunc()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redoFunc()));

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undoFunc()));

}

void MaFenetre::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *newMenu = fileMenu->addMenu("New");
    newMenu->addAction(newProjectAct);
    newMenu->addAction(newPageAct);

    QMenu *openMenu = fileMenu->addMenu("Open");
    openMenu->addAction(openProjectAct);
    openMenu->addAction(openFileAct);

    fileMenu->addSeparator();

    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);

    fileMenu->addSeparator();

    fileMenu->addAction(exportAct);
    fileMenu->addAction(helpAct);
    fileMenu->addAction(quitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(redoAct);
    editMenu->addAction(undoAct);
}
void MaFenetre::contextMenuEvent(QContextMenuEvent *event){
    QMenu menu(this);
    menu.addAction(newPageAct);
    menu.exec(event->globalPos());
}

void MaFenetre::newProjectFunc(){

}
void MaFenetre::newPageFunc(){}
void MaFenetre::openProjectFunc(){}
void MaFenetre::openFileFunc(){}
void MaFenetre::saveFunc(){}
void MaFenetre::saveAsFunc(){}
void MaFenetre::exportFunc(){}
void MaFenetre::helpFunc(){}
void MaFenetre::quitFunc(){}
void MaFenetre::redoFunc(){}
void MaFenetre::undoFunc(){}

