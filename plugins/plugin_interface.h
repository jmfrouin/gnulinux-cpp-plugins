#ifndef _PLUGIN_INTERFACE_H_
#define _PLUGIN_INTERFACE_H_

namespace Plugin
{
	/**
	 * @brief Plugin Interface
	 */
	class Plugin
	{
		public:
			virtual void action() = 0;
	};

}	// namespace Plugin
#endif 	//_PLUGIN_INTERFACE_H_
