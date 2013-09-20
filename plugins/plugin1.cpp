#include <plugin_factory_initializer.h>
#include "plugin1.h"

#include <iostream>

namespace Plugin
{
	void Plugin1::action() 
	{
		std::cout << "Plugin1 : action()" << std::endl;
	}

	class Plugin1Factory : public PluginFactory
	{
		public:
			//From PluginFactory interface
			std::string getName()
			{ return "Plugin1"; }
		
			Plugin* createInstance()
			{ return new Plugin1;}
	};

	PluginFactoryInitializer<Plugin1Factory> pluginInit;
}	// namespace Plugin
