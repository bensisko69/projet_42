#include "QtModule.hpp"
#include "IMonitorModule.hpp"
#include "Ram.hpp"
#include "Cpu.hpp"

QtModule::QtModule(std::string name) : _name(name)
{
	setFixedSize(WIN_WIDTH / NB_MOD - 14, WIN_HEIGHT - 60);

	_layout = new QVBoxLayout(this);
	_progressBar = new QProgressBar();
}

void	QtModule::printBar(IMonitorModule * mod)
{
	retrieveResources(mod);

	if (_name == RAM_MOD)
		_progressBar->setValue(_usedRam * 100 / (_usedRam + _freeRam));
	else
		_progressBar->setValue(_usedCpu * 100 / (_usedCpu + _freeCpu));
	_progressBar->setTextVisible(true);
	_layout->addWidget(_progressBar);
}

void	QtModule::update(void)
{
	int i = 1;
	mod_data data = _modules[_name]->retriveInfo();
	for (mod_iterator it_data = data.begin(); it_data != data.end(); it_data++)
	{
		if (i == 1)
			setTitle(it_data->c_str());
		else
		{
			QLabel * lab = new QLabel(it_data->c_str());
			lab->setWordWrap(true);
			_layout->addWidget(lab);
		}
		if (_name == RAM_MOD || _name == CPU_MOD)
			printBar(_modules[_name]);
		i++;
	}
}

QtModule::~QtModule(void)
{
	delete _layout;
	delete _progressBar;
}
