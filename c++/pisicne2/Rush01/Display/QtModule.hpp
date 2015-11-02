#ifndef QT_MODULE_HPP
# define QT_MODULE_HPP

# include <QApplication>
# include <QObject>
# include <QGroupBox>
# include <QLabel>
# include <QProgressBar>
# include <QVBoxLayout>
# include <string>
# include "DisplayData.hpp"

class QtModule : public QGroupBox, public DisplayData
{
private:
	QtModule(void);
	QtModule(QtModule const & src);
	QtModule & operator=(QtModule const & src);

	std::vector<QLabel *> 	_label;
	std::string				_name;
	QVBoxLayout * 			_layout;
	QProgressBar * 			_progressBar;

	void	printBar(IMonitorModule * mod);

public:
	QtModule(std::string name);
	~QtModule(void);

	void	update(void);
};

#endif // QT_MODULE_HPP
