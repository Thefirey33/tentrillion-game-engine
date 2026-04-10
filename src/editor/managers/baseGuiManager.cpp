
#include "managers/baseGuiManager.hpp"

#include <QApplication>
#include <QMenuBar>
#include <QPushButton>

BaseGuiManager::BaseGuiManager(QApplication *app) : qApplicationPtr(app) {
	// Create the Qt window needed for the TenTrillion to function. This is
	// where the editor functionality will be hold.

	this->qMainWindow = new QMainWindow();
	this->createMenuBar();

	qMainWindow->show();
}

void BaseGuiManager::createMenuBar() {
	auto *menuBar = new QMenuBar(qMainWindow);

	const auto menu = menuBar->addMenu("File");
	const auto menuAction = menu->addAction("Exit");

	QObject::connect(menuAction, &QAction::triggered, qApplicationPtr,
					 &QApplication::quit);

	qMainWindow->setMenuBar(menuBar);
}