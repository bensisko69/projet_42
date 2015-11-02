#ifndef RAM_HPP
# define RAM_HPP
# include "IMonitorModule.hpp"
# include "ModulInfo.hpp"

class Ram: public IMonitorModule, public ModulInfo
{
	public:
		Ram(void);
		virtual ~Ram(void);
		Infos		const	&retriveInfo(void);
		int64_t					getFree(void) const;
		int64_t					getUsed(void) const;

	private:
		Ram(Ram const &src);
		Ram &operator=(Ram const &rhs);
		int64_t		_usedMemory;
		int64_t		_freeMemory;
		uint64_t	_availableMemory;
};

#endif // RAM_HPP
