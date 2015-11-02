#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include "QtDisplay.hpp"
#include "QtWindow.hpp"
#include "QtModule.hpp"
#include <iostream>
#include <unistd.h>

QtDisplay::QtDisplay(int argc, char *argv[])
{
	_app = new QApplication(argc, argv);
}

QtDisplay::~QtDisplay(void)
{
	delete _app;
}

void QtDisplay::deleteMods(void)
{
	while (!_mods.empty())
	{
		delete _mods.back();
		_mods.pop_back();
	}
}

void QtDisplay::clearLayout(void)
{
	if (_layout)
	{
		while(_layout->count() > 0)
		{
			QLayoutItem *item = _layout->takeAt(0);
			delete item->widget();
			delete item;
		}
	}
}

void QtDisplay::update(void)
{
	int i = 0;
	int	mod_width = WIN_WIDTH / NB_MOD;

	deleteMods();
	for (mod_iterator it = _modulesNames.begin(); it != _modulesNames.end(); it++)
	{
		_mods.push_back(new QtModule(*it));
		_layout->addWidget(_mods.back(), 0, i * mod_width);
		_mods.back()->update();
		i++;
	}
	_app->processEvents();
}

int QtDisplay::exec(void)
{
	for (;;)
	{
		usleep(15000);
		update();
	}
	clearLayout();
	return 0;
}

int QtDisplay::show(void)
{
	_mainWindow = new QtWindow();
	_layout = new QGridLayout();

	_mainWindow->setLayout(_layout);
	_mainWindow->show();

	return exec();
}

void QtDisplay::hide() const
{
	delete _mainWindow;
	delete _layout;
}
