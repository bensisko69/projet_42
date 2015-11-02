#ifndef DISPLAY_DATA_HPP
# define DISPLAY_DATA_HPP

# include <map>
# include <vector>
# include <string>

# define NAME_INFO_MOD		"name_info"
# define OS_INFO_MOD		"os_info"
# define DATE_TIME_MOD		"date_time"
# define CPU_MOD			"cpu"
# define RAM_MOD			"ram"
# define NB_MOD				5
# define USED_RES_INDEX		1
# define FREE_RES_INDEX		2
# define WIN_WIDTH			1500
# define WIN_HEIGHT			300
# define CYAN				1

class IMonitorModule;

class DisplayData
{
private:
	DisplayData(DisplayData const & src);
	DisplayData & operator=(DisplayData const & src);

protected:
	typedef std::vector<std::string>::const_iterator	mod_iterator;
	typedef std::vector<std::string>					mod_data;

	DisplayData(void);

	void		retrieveResources(IMonitorModule * mod);

	std::map<std::string, IMonitorModule*>			_modules;
	std::vector<std::string>						_modulesNames;
	int64_t											_usedRam;
	int64_t											_freeRam;
	int64_t											_usedCpu;
	int64_t											_freeCpu;

public:
	virtual ~DisplayData(void);

};

#endif // DISPLAY_DATA_HPP
