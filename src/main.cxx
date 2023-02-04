#include "sys.h"
#include "debug.h"
#include <iostream>
#include <thread>
#include <stdexcept>
#include <cstdlib>

#include "window.h"

int main()
{
	// Use libcwd/aicxx to debug the Application
    Debug(NAMESPACE_DEBUG::init());
    Dout(dc::notice, "Entering main()");
	try
	{
		window* vulkan_win = new window();
		vulkan_win->window_instance();
		vulkan_win->windowLoop();
	}
	catch (const std::exception& e)
	{
		DoutFatal(dc::core, e.what());
	}
	return EXIT_SUCCESS;
}
