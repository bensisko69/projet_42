#include "QtWindow.hpp"
#include "DisplayData.hpp"

QtWindow::QtWindow(QWidget *parent) : QWidget(parent)
{
	setFixedSize(WIN_WIDTH, WIN_HEIGHT);

	setWindowTitle(QString::fromUtf8("42 GkRellM - Graphical Mode"));
}

QtWindow::~QtWindow(void)
{
}
