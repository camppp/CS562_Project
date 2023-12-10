#include <QMenu>
#include <QToolBar>
#include <QList>
#include <QAction>
#include <QDockWidget>
#include <QPoint>

class GUIManager {
public:
    void populateMenuAndToolBar(QMenu *menu, QToolBar *toolBar, QList<QAction*> actions) {
        // Add actions to menu and toolbar
        for (QAction *action : actions) {
            menu->addAction(action);
            toolBar->addAction(action);
        }
    }

    void createDockWidgets() {
        // Create dock widgets
        QDockWidget *dockWidget1 = new QDockWidget(this);
        dockWidget1->setWindowTitle("Dock Widget 1");
        dockWidget1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        dockWidget1->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);

        QDockWidget *dockWidget2 = new QDockWidget(this);
        dockWidget2->setWindowTitle("Dock Widget 2");
        dockWidget2->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
        dockWidget2->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);

        // Add dock widgets to main window
        addDockWidget(Qt::LeftDockWidgetArea, dockWidget1);
        addDockWidget(Qt::RightDockWidgetArea, dockWidget2);
    }

    void createConnections() {
        // Establish connections between UI elements
        connect(dockWidget1, &QDockWidget::visibilityChanged, this, &GUIManager::onDockWidgetVisibilityChanged);
        connect(dockWidget2, &QDockWidget::visibilityChanged, this, &GUIManager::onDockWidgetVisibilityChanged);
    }

    bool okToClearData() {
        // Check if it is safe to clear data
        if (dockWidget1->isVisible() || dockWidget2->isVisible()) {
            return false;
        }
        return true;
    }

    QPoint position() {
        // Return position of dock widget
        return dockWidget1->pos();
    }

private:
    QDockWidget *dockWidget1;
    QDockWidget *dockWidget2;

    void onDockWidgetVisibilityChanged(bool visible) {
        // Update dock widget visibility
        if (visible) {
            dockWidget1->show();
            dockWidget2->show();
        } else {
            dockWidget1->hide();
            dockWidget2->hide();
        }
    }
};
