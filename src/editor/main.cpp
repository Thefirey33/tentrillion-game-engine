#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
	// General testing window for the Ten-Trillion.

	QApplication app(argc, argv);
	QLabel label("Testing Window.");

	label.show();
	return QApplication::exec();
}