#include <plugin_factory_initializer.h>
#include "plugin2.h"

#include <iostream>

namespace Plugin
{
	void Plugin2::action() 
	{
		std::cout << "Plugin2 : action()" << std::endl;
	}

	class Plugin2Factory : public PluginFactory
	{
		public:
			//From PluginFactory interface
			std::string getName()
			{ return "Plugin2"; }
			
			Plugin* createInstance()
			{ return new Plugin2;}
	};

	PluginFactoryInitializer<Plugin2Factory> plugin2FactoryInitialisazer;

}	// namespace Plugin
