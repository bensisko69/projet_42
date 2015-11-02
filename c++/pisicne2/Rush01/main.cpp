#include <QApplication>
#include <QPushButton>
#include "DisplayManager.hpp"

int main(int argc, char *argv[])
{
	srand(time(0));
	DisplayManager dm(argc, argv);
	return dm.exec();
}
