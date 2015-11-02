# include "ModulInfo.hpp"
# include <sstream>

ModulInfo::ModulInfo(unsigned int size)
{
	_vector.resize(size);
}
ModulInfo::~ModulInfo(void)
{

}

ModulInfo::ModulInfo(void)
{
	
}

std::string		ModulInfo::changeChar(char *src)
{
	std::stringstream strm;
	strm << src;
	return strm.str();
}

std::string		ModulInfo::changeChar(int nbr)
{
	std::stringstream strm;
	strm << nbr;
	return strm.str();

}

void	ModulInfo::aff(void)
{
	Infos::iterator	it = _vector.begin();

	for (int i = 0;it != _vector.end(); it++)
		std::cout << it[i] << std::endl;
}