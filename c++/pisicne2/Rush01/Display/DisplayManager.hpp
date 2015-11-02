#ifndef DISPLAY_MANAGER_HPP
# define DISPLAY_MANAGER_HPP

class IMonitorDisplay;

class DisplayManager
{
private:
	DisplayManager(DisplayManager const & src);
	DisplayManager & operator=(DisplayManager const & src);

	IMonitorDisplay	*						_nc;
	IMonitorDisplay	*						_qt;
	IMonitorDisplay	*						_current;

public:
	DisplayManager(int argc, char *argv[]);
	~DisplayManager(void);

	int		exec(void);
	void	switchDisplay(void);

};

#endif // DISPLAY_MANAGER_HPP
