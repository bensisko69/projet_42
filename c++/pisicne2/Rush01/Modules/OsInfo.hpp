#ifndef OS_INFO_HPP
#define OS_INFO_HPP
# include <iostream>
# include <sys/utsname.h>
# include "IMonitorModule.hpp"
# include "ModulInfo.hpp"

class OsInfo: public IMonitorModule, public ModulInfo
{
	public:
		OsInfo(void);
		virtual ~OsInfo(void);
		Infos	const	&retriveInfo(void);

	private:
		OsInfo(OsInfo const &src);
		OsInfo &operator=(OsInfo const &rhs);
};

#endif // OS_INFO_HPP
