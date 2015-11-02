#include "DateTime.hpp"

DateTime::DateTime(void): ModulInfo(2)
{
	retriveInfo();
}

DateTime::~DateTime(void)
{

}

DateTime::Infos const		&DateTime::retriveInfo(void)
{
	time_t	now = time(0);
	_vector[0] = "--------- Date and times ---------";
	_vector[1] = "Date and time: " + changeChar(ctime(&now));
	return _vector;
}
