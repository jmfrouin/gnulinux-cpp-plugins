#ifndef _PLUGIN_FACTORY_INITIALIZER_H_
#define _PLUGIN_FACTORY_INITIALIZER_H_

//STL
#include <iostream>
#include <string>

#include "plugin_factory_manager.h"

namespace Plugin
{
	template <typename T>
	class PluginFactoryInitializer
	{
		public:
			PluginFactoryInitializer()
			{
				T* factory = new T();
				PluginFactoryManager::instance()->factories[factory->getName()] = factory;
				std::cout << "Plugins: " << factory->getName() << " registered" << std::endl;
			}
	};
} 	//namespace Plugin
#endif 	//_PLUGIN_FACTORY_INITIALIZER_H_
