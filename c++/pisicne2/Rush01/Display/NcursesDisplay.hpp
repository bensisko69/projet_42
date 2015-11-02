#ifndef NCURSES_DISPLAY_HPP
# define NCURSES_DISPLAY_HPP

# include <ncurses.h>
# include "IMonitorDisplay.hpp"
# include "DisplayData.hpp"

class NcursesDisplay : public IMonitorDisplay, public DisplayData
{
private:
	NcursesDisplay & operator=(NcursesDisplay const & src);
	NcursesDisplay(NcursesDisplay const & src);

	void	update(void);
	int		exec(void);
	void	draw_borders(WINDOW * screen) const;
	void	printModuleInfos(std::string moduleName);
	void	printBar(std::string const & dataType, WINDOW * win, IMonitorModule * mod, std::string moduleName);

	int									_winheight;
	int									_winwidth;
	std::map<std::string, WINDOW *>		_windows;

public:
	NcursesDisplay(void);
	~NcursesDisplay(void);

	void	initWindows(void);

	int show(void);
	void hide(void) const;
};

#endif // NCURSES_DISPLAY_HPP
