#include "sys.h"
#include "debug.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace vulkan_sim {
class vulkan
{
private:
	VkInstance m_vk_instance;
	void create_vulkan_instance();

public:
	void start_vulkan();
	void cleanEngine();
	vulkan();
	~vulkan();
};

} // vulkan_sim
