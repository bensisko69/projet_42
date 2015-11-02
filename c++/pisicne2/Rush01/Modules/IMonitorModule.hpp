#ifndef I_MONITOR_MODULE_HPP
# define I_MONITOR_MODULE_HPP
# include <vector>
class IMonitorModule
{
	public:
		IMonitorModule(void);
		virtual ~IMonitorModule(void) = 0;
		virtual std::vector<std::string> const		&retriveInfo(void) = 0;

	private:
		IMonitorModule(IMonitorModule const & src);
		IMonitorModule & operator=(IMonitorModule const & src);

};

#endif // I_MONITOR_MODULE_HPP
