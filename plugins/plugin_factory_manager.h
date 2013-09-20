#ifndef _PLUGIN_FACTORY_MANAGER_H_
#define _PLUGIN_FACTORY_MANAGER_H_

//STL
#include <map>

#include "plugin_factory.h"

namespace Plugin
{
	/**
	 * @brief 
	 */
	class PluginFactoryManager
	{
		public:
			///Grab the singleton instance
			static PluginFactoryManager* instance();	
			void loadPlugins (const std::string& path);
			Plugin* createObject (const std::string& name);
		
		public:
			std::map<std::string, PluginFactory*> factories;

		private:
			~PluginFactoryManager();
			///The singleton itself
			static PluginFactoryManager* singleton;
	};

} 	//namespace Plugin
#endif 	//_PLUGIN_FACTORY_MANAGER_H_
