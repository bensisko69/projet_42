# include "OsInfo.hpp"
# include <sstream>

OsInfo::OsInfo(void): ModulInfo(5)
{
	retriveInfo();
}

OsInfo::~OsInfo(void)
{

}

OsInfo::Infos	const	&OsInfo::retriveInfo(void)
{
	struct utsname	_buf;
	if (uname(&_buf) == 0)
	{
		_vector[0] = "--------- Os info ---------";
		_vector[1] = "System name: " + changeChar(_buf.sysname);
		_vector[2] = "Host name: " + changeChar(_buf.nodename);
		_vector[3] = "System version: " + changeChar(+_buf.version);
		_vector[4] = "Architecture: " + changeChar(+_buf.machine);
	}
	return _vector;
}