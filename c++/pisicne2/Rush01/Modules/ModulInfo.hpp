# ifndef MODUL_INFO_HPP
# define MODUL_INFO_HPP
# include <vector>
# include <string>
# include <iostream>

class ModulInfo{
	public:
		ModulInfo(unsigned int size);
		~ModulInfo(void);
		ModulInfo(void);
		void	aff(void);
		std::string		changeChar(char *src);
		std::string		changeChar(int src);
	protected:
		typedef std::vector<std::string> Infos;

		ModulInfo(ModulInfo const &src);
		ModulInfo &operator=(ModulInfo const &rhs);
		Infos	_vector;
};

#endif // MODUL_INFO_HPP
