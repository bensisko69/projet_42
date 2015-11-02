#ifndef NAME_INFO_HPP
#define NAME_INFO_HPP
# include <iostream>
# include "IMonitorModule.hpp"
# include <vector>
# include <unistd.h>
# include "ModulInfo.hpp"

class NameInfo: public IMonitorModule, public ModulInfo
{
	public:
		NameInfo(void);
		virtual ~NameInfo(void);
		Infos	const	&retriveInfo(void);
	private:
		NameInfo(NameInfo const &src);
		NameInfo &operator=(NameInfo const &rhs);
};


#endif // NAME_INFO_HPP
