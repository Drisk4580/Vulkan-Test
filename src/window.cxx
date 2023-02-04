#include "window.h"

// Empty because why not.
window::window()
{

}
window::~window()
{

}

void window::window_instance()
{
	glfwInit();
	glfw_window_instance();
}

// TODO: Switch to XCB instead of GLFW
void window::glfw_window_instance()
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	this->vk_win = glfwCreateWindow(WIDTH, HEIGHT, "Window", nullptr, nullptr);
}

void window::windowLoop()
{
	while(!glfwWindowShouldClose(this->vk_win))
	{
		glfwPollEvents();
	}
	glfwDestroyWindow(this->vk_win);
}
