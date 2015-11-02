#ifndef QT_DISPLAY_HPP
# define QT_DISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "DisplayData.hpp"
# include <vector>

class QApplication;
class QGridLayout;
class QtWindow;
class QtModule;

class QtDisplay : public IMonitorDisplay, public DisplayData
{
private:
	typedef std::vector<QtModule *>::const_iterator iterator;

	QtDisplay(void);
	QtDisplay & operator=(QtDisplay const & src);
	QtDisplay(QtDisplay const & src);

	QtWindow *					_mainWindow;
	QApplication *				_app;
	QGridLayout *				_layout;

	int							exec(void);
	void						deleteMods(void);
	void 						clearLayout(void);

	std::map<std::string, QtModule *>	_windows;
	std::vector<QtModule *>	_mods;

protected:
	void						update(void);

public:
	QtDisplay(int argc, char *argv[]);
	~QtDisplay(void);

	int							show(void);
	void						hide(void) const;
};

#endif // QT_DISPLAY_HPP
