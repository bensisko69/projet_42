#ifndef CPU_HPP
# define CPU_HPP
# include <iostream>
# include <vector>
# include "IMonitorModule.hpp"
# include "ModulInfo.hpp"

struct cpusample {
	uint64_t totalSystemTime;
	uint64_t totalUserTime;
	uint64_t totalIdleTime;

};

class Cpu: public IMonitorModule, public ModulInfo
{
	public:
		Cpu(void);
		virtual ~Cpu(void);
		Infos	const	&retriveInfo(void);
		void 	sample(struct cpusample *sample);

	private:
		Cpu(Cpu const &src);
		Cpu &operator=(Cpu const &rhs);
		int64_t	_nCpu;
		std::string	_name;
};

#endif // CPU_HPP
