#ifndef QT_WINDOW_HPP
# define QT_WINDOW_HPP

# include <QApplication>
# include <QObject>
# include <QWidget>

class QtModule;

class QtWindow : public QWidget
{
private:
	QtWindow(QtWindow const & src);
	QtWindow & operator=(QtWindow const & src);

public:
	QtWindow(QWidget *parent = 0);
	~QtWindow(void);
};

#endif // QT_WINDOW_HPP
