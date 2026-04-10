#include "managers/baseGuiManager.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	auto baseGuiManager = std::make_unique<BaseGuiManager>(&app);
	return QApplication::exec();
}