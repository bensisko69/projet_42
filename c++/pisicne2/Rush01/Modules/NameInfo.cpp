#include "NameInfo.hpp"

NameInfo::NameInfo(void): ModulInfo(3)
{
	retriveInfo();
}

NameInfo::~NameInfo(void)
{

}

NameInfo::Infos	const	&NameInfo::retriveInfo(void)
{
	size_t	len = 256;
	char	name[256];
	_vector[0] = "--------- Host Name and Username ---------";
	if (gethostname(name, len) == 0)
		_vector[1] = "Host name: " + changeChar(name);
	if (getlogin_r(name, len) == 0)
		_vector[2] = "User name: " + changeChar(name);
	return _vector;
}