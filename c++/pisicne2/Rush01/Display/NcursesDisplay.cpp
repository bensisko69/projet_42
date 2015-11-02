#include "NcursesDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Ram.hpp"
#include "Cpu.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <sstream>

NcursesDisplay::NcursesDisplay() : _winheight(0), _winwidth(0)
{
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	endwin();
}

NcursesDisplay::~NcursesDisplay(void)
{
	endwin();
}

void	NcursesDisplay::printBar(std::string const & dataType, WINDOW * win, IMonitorModule * mod, std::string moduleName)
{
	std::ostringstream	usageMsg;
	int		perc;
	int					pos_y = 9;

	retrieveResources(mod);

	if (moduleName == RAM_MOD)
		perc = _usedRam * 50 / (_usedRam + _freeRam);
	else
		perc = _usedCpu * 50 / (_usedCpu + _freeCpu);

	usageMsg << dataType << " usage: [";
	mvwprintw(win, pos_y, 2, usageMsg.str().c_str());

	for (int p = 0; p < 50; p++)
	{
		if (p < perc)
			mvwaddch(win, pos_y, p + 17, '|');
		else
			mvwaddch(win, pos_y, p + 17, ' ');
	}
	mvwprintw(_windows[moduleName], pos_y, 67, "]");
}

void	NcursesDisplay::printModuleInfos(std::string moduleName)
{
	int i = 1;
	mod_data data = _modules[moduleName]->retriveInfo();
	for (mod_iterator it_data = data.begin(); it_data != data.end(); it_data++)
	{
		if (i == 1)
		{
			attron(COLOR_PAIR(CYAN));
			mvwprintw(_windows[moduleName], i, 2, it_data->c_str());
			attroff(COLOR_PAIR(CYAN));
		}
		else
			mvwprintw(_windows[moduleName], i + 1, 2, it_data->c_str());
		if (moduleName == RAM_MOD)
			printBar("Memory", _windows[moduleName], _modules[moduleName], moduleName);
		if (moduleName == CPU_MOD)
			printBar("CPU", _windows[moduleName], _modules[moduleName], moduleName);
		i++;
	}
	wrefresh(_windows[moduleName]);
}

void	NcursesDisplay::update(void)
{
	int x, y;
	getmaxyx(stdscr, y, x);
	if (x != _winwidth || y != _winheight)
	{
		_windows.clear();
		_winwidth = x;
		_winheight = y;
	}
	if (_windows.empty())
		initWindows();
	for (mod_iterator it = _modulesNames.begin(); it != _modulesNames.end(); it++)
		printModuleInfos(*it);
	refresh();
}

void	NcursesDisplay::initWindows()
{
	int	mod_height = _winheight / NB_MOD;
	int i = 0;

	for (mod_iterator it = _modulesNames.begin(); it != _modulesNames.end(); it++)
	{
		_windows[*it] = newwin(mod_height, _winwidth, i * mod_height, 0);
		box(_windows[*it], '|', '=');
		wbkgd(_windows[*it], COLOR_PAIR(1));
		wrefresh(_windows[*it]);
		i++;
	}
}

int		NcursesDisplay::exec()
{
	int ch;

	do
	{
		usleep(15000);
		ch = getch();
		// Switch display
		if (ch == 's')
			return 0;
		// Update output
		update();
	} while (ch != 'q' && ch != 'Q');
	return 1;
}

int		NcursesDisplay::show()
{
	return exec();
}

void	NcursesDisplay::hide() const
{
	endwin();
}
