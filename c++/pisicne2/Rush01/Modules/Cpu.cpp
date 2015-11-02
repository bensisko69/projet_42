#include "Cpu.hpp"
#include <sys/sysctl.h>
#include <sstream>
#include <iomanip>

static const int GIGA_BYTES = 1 << 30;
static const int MEGA_BYTES = 1 << 20;
static const int KILO_BYTES = 1 << 10;

template <class T>
std::string byteFormatted(const T & t) {
	std::ostringstream oss;
	oss << std::fixed;
	if (t > GIGA_BYTES) {
		oss << std::setprecision(2) << static_cast<double>(t) / GIGA_BYTES << " GB";
	}
	else if (t > MEGA_BYTES) {
		oss << std::setprecision(2) << static_cast<double>(t) / MEGA_BYTES << " MB";
	}
	else if (t > KILO_BYTES) {
		oss << std::setprecision(2) << static_cast<double>(t) / KILO_BYTES << " KB";
	}
	else {
		oss << t << " B";
	}
	return oss.str();
}

Cpu::Cpu(void): ModulInfo(3)
{
	retriveInfo();
	char buff[256];
	size_t size = sizeof(uint64_t);
	static int N_CPU_MIB[] = { CTL_HW, HW_NCPU };
	sysctl(N_CPU_MIB, 2, &_nCpu, &size, 0, 0);
	size = sizeof(buff);
	sysctlbyname("machdep.cpu.brand_string", &buff, &size, 0, 0);
	_name = buff;
}

Cpu::~Cpu(void)
{

}

Cpu::Infos	const	&Cpu::retriveInfo(void)
{
	_vector[0] = "--------- Cpu ---------";
	_vector[1] = "name of CPU: " + _name;
	_vector[2] = "number of cores: " + changeChar(_nCpu);
	return _vector;
}

