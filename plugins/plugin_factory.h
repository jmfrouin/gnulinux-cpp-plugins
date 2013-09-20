#ifndef _PLUGIN_FACTORY_H_
#define _PLUGIN_FACTORY_H_

//STL
#include <string>

#include "plugin_interface.h"

namespace Plugin
{
	/**
	 * @brief Plugin Factory Interface
	 */
	class PluginFactory
	{
		public:
			virtual std::string getName() = 0;
			virtual Plugin* createInstance() = 0; 
	};

} 	//namespace Plugin
#endif 	//_PLUGIN_FACTORY_H_
