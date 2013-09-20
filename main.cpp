#include <plugin_factory_manager.h>
#include <plugin_interface.h>

#include <string>
#include <iostream>
#include <cstdlib>

int main()
{
	Plugin::PluginFactoryManager::instance()->loadPlugins("plugs");
	Plugin::Plugin* plug1 = Plugin::PluginFactoryManager::instance()->createObject("Plugin1");
	Plugin::Plugin* plug2 = Plugin::PluginFactoryManager::instance()->createObject("Plugin2");
	Plugin::Plugin* plug3 = Plugin::PluginFactoryManager::instance()->createObject("Plugin3");

	if (plug1)
		plug1->action();

	if (plug2)
		plug2->action();

	if (plug3)
		plug3->action();
	return EXIT_SUCCESS;
}
