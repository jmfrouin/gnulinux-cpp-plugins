#include <plugin_factory_initializer.h>
#include "plugin3.h"

#include <iostream>

namespace Plugin
{
	void Plugin3::action() 
	{
		std::cout << "Plugin3 : action()" << std::endl;
	}

	class Plugin3Factory : public PluginFactory
	{
		public:
			//From PluginFactory interface
			std::string getName()
			{ return "Plugin3"; }
			
			Plugin* createInstance()
			{ return new Plugin3;}
	};

	PluginFactoryInitializer<Plugin3Factory> plugin3FactoryInitialisazer;

}	// namespace Plugin
