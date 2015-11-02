# include "Ram.hpp"
# include <iostream>
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <sstream>
# include <iomanip>

static const int GIGA_BYTES = 1 << 30;
static const int MEGA_BYTES = 1 << 20;
static const int KILO_BYTES = 1 << 10;

Ram::Ram(void): ModulInfo(6),_usedMemory(0), _freeMemory(0)
{
	size_t size = sizeof(uint64_t);
	static int MEM_SIZE_MIB[] = { CTL_HW, HW_MEMSIZE };
	sysctl(MEM_SIZE_MIB, 2, &_availableMemory, &size, 0, 0);
}

Ram::~Ram(void)
{

}

int64_t			Ram::getUsed(void) const
{
	return this->_usedMemory;
}

int64_t			Ram::getFree(void) const
{
	return this->_freeMemory;
}

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

Ram::Infos	const	&Ram::retriveInfo(void)
{
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,(host_info64_t)&vm_stats, &count))
	{
		int64_t freeMemory = (int64_t)vm_stats.free_count * (int64_t)page_size;
		int64_t inactiveMemory = (int64_t)vm_stats.inactive_count * (int64_t)page_size;
		int64_t usedMemory = ((int64_t)vm_stats.active_count +
								 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
		_usedMemory = usedMemory;
		_freeMemory = freeMemory;
		_vector[0] = " --------- Ram memory ---------";
		_vector[1] = "Total Memory: " + byteFormatted(_availableMemory);
		_vector[2] = "Used memory: " + byteFormatted(_usedMemory);
		_vector[3] = "Free memory: " + byteFormatted(_freeMemory);
		_vector[4] = "Inactive memory: " + byteFormatted(inactiveMemory);
		_vector[5] = "Page size: " + byteFormatted(page_size);
	}
	return _vector;
}


