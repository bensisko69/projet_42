#ifndef I_MONITOR_DISPLAY_HPP
# define I_MONITOR_DISPLAY_HPP

class IMonitorDisplay
{
private:
	IMonitorDisplay & operator=(IMonitorDisplay const & src);
	IMonitorDisplay(IMonitorDisplay const & src);
	virtual int exec(void) = 0;

protected:
	IMonitorDisplay(void);

public:
	virtual ~IMonitorDisplay(void) = 0;
	virtual int show(void) = 0;
	virtual void hide(void) const = 0;
};

#endif // I_MONITOR_DISPLAY_HPP
