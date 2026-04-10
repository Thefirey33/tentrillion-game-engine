
#ifndef TEN_TRILLION_BASEGUIMANAGER_H
#define TEN_TRILLION_BASEGUIMANAGER_H
#include <QMainWindow>
#include <QtGlobal>

QT_BEGIN_NAMESPACE

class BaseGuiManager {
  protected:
	// QAppliction Ptr reference.
	QApplication *qApplicationPtr;

	// The QMainWindow root parent of all children.
	QMainWindow *qMainWindow;

  public:
	BaseGuiManager(QApplication *app);

	// This creates the menuBar needed by the TenTrillion.
	void createMenuBar();
};

QT_END_NAMESPACE

#endif // TEN_TRILLION_BASEGUIMANAGER_H
