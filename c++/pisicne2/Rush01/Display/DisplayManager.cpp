#include "DisplayManager.hpp"
#include "NcursesDisplay.hpp"
#include "QtDisplay.hpp"

DisplayManager::DisplayManager(int argc, char *argv[])
{
	_nc = new NcursesDisplay();
	_qt = new QtDisplay(argc, argv);
	_current = _nc;
}

DisplayManager::~DisplayManager(void)
{
	delete _nc;
	delete _qt;
}

void	DisplayManager::switchDisplay(void)
{
	if (_current == _nc)
	{
		_current->hide();
		_current = _qt;
	}
	else
	{
		_current->hide();
		_current = _nc;
	}
}

int		DisplayManager::exec(void)
{
	int render;
	do
	{
		render = _current->show();
		if (render == 0)
			switchDisplay();
	} while (render != 1);
	return 0;
}
