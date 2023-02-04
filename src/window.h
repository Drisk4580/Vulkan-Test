#include "sys.h"
#include "debug.h"
#include <GLFW/glfw3.h>

#include <iostream>

#define WIDTH 800
#define HEIGHT 600

class window {
private:
	void glfw_window_instance();
	GLFWwindow* vk_win;
public:
	void window_instance();
	void windowLoop();
	window();
	~window();
};
