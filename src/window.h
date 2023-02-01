#include "sys.h"
#include "debug.h"
#include <iostream>
#include <string>

#include <vulkan/vulkan.h>
#include <xcb/xcb.h>
#include <glm/vec4.hpp>

typedef uint32_t xcb_window_t;

class window {
  public:
	window();
	xcb_window_t vk_window;
	xcb_connection_t *connection;
	std::string window_title;
	void initialize_vk_window();
	void clean_vk_engine();
  private:
	void vk_window_instance();
};
