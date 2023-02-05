#include "sys.h"
#include "debug.h"
#include <iostream>
#include <thread>
#include <stdexcept>
#include <cstdlib>

// All the required resources
#include "window.h"
#include "vulkan_app.h"

int main()
{
	// Use libcwd/aicxx to debug the Application
  Debug(NAMESPACE_DEBUG::init());
  Dout(dc::notice, "Entering main()");
	vulkan_sim::vulkan* vulkan_engine = new vulkan_sim::vulkan();

	try
	{
		window* vulkan_win = new window();
		vulkan_win->window_instance();
		vulkan_engine->start_vulkan();
		vulkan_win->windowLoop();
		vulkan_engine->cleanEngine();
	}
	catch (const std::exception& e)
	{
		DoutFatal(dc::core, e.what());
	}
	return EXIT_SUCCESS;
}
