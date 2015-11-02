#include "DisplayData.hpp"
#include "NameInfo.hpp"
#include "OsInfo.hpp"
#include "DateTime.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"

DisplayData::DisplayData() : _usedRam(0), _freeRam(1), _usedCpu(0), _freeCpu(1)
{
	_modulesNames.push_back(NAME_INFO_MOD);
	_modulesNames.push_back(OS_INFO_MOD);
	_modulesNames.push_back(DATE_TIME_MOD);
	_modulesNames.push_back(CPU_MOD);
	_modulesNames.push_back(RAM_MOD);

	_modules[NAME_INFO_MOD] = new NameInfo();
	_modules[OS_INFO_MOD] = new OsInfo();
	_modules[DATE_TIME_MOD] = new DateTime();
	_modules[CPU_MOD] = new Cpu();
	_modules[RAM_MOD] = new Ram();
}

void		DisplayData::retrieveResources(IMonitorModule * mod)
{
	Ram * ram = reinterpret_cast<Ram*>(mod);
	Cpu * cpu = reinterpret_cast<Cpu*>(mod);

	if (!ram && !cpu)
		return ;

	if (ram)
	{
		_usedRam = ram->getUsed();
		_freeRam = ram->getFree();
	}
	// else
	// {
	// 	_usedCpu = cpu->getUsed();
	// 	_freeCpu = cpu->getFree();
	// }
}

DisplayData::~DisplayData()
{
}
