#ifndef DATE_TIME_HPP
# define DATE_TIME_HPP
# include "IMonitorModule.hpp"
# include <ctime>
# include <iostream>
# include <vector>
# include "ModulInfo.hpp"

class DateTime: public IMonitorModule, public ModulInfo{
	public:
		DateTime(void);
		virtual ~DateTime(void);
		Infos const		&retriveInfo(void);

	private:
		DateTime(DateTime const &);
		DateTime &operator=(DateTime const &rhs);
};


#endif // DATE_TIME_HPP
