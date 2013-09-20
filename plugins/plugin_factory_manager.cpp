#include <dlfcn.h>	///In order to load dyn lib
#include <dirent.h>	///For path manipulation
#include <iostream>

#include "plugin_interface.h"
#include "plugin_factory_manager.h"

namespace Plugin
{

	PluginFactoryManager* PluginFactoryManager::singleton = 0;

	PluginFactoryManager::~PluginFactoryManager()
	{
		std::map<std::string, PluginFactory*>::iterator _it = factories.begin();
		std::cout << "All plugins registered are : " << std::endl;
		while(_it != factories.end())
		{
			std::cout << _it->second << ", ";
		}
		std::cout << std::endl;
	}

	PluginFactoryManager* PluginFactoryManager::instance()
	{
		if (singleton == 0)
		{	
			singleton = new PluginFactoryManager();
		}
		return singleton;
	}

	void PluginFactoryManager::loadPlugins(const std::string& path)
	{
		struct dirent** namelist;
		int n = scandir(path.c_str(), &namelist, 0, alphasort);
		while (n-- > 0)
		{
			std::string tmp = path + "/" + namelist[n]->d_name;
			if (tmp.length() > 8)
			{
				void* handler = dlopen (tmp.c_str(), RTLD_NOW);
				if (handler != 0)
				{
					std::cout << tmp.c_str() << " loaded ! " << std::endl;
				}
				else
				{
					std::cerr << dlerror() << std::endl;
				}
			}
		}
	}

	Plugin* PluginFactoryManager::createObject(const std::string& name)
	{
		if (factories.find(name) != factories.end())
		{
			PluginFactory* fact = factories[name];
			return fact->createInstance();
		}
		return 0;
	}
} //namespace Plugin

