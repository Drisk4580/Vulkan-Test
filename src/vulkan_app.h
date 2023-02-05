#pragma once

#include "sys.h"
#include "debug.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <cstring>
#include <vector>

#define WIDTH 800
#define HEIGHT 600

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

namespace vulkan_sim {
class vulkan
{
private:
	VkInstance m_vk_instance;
	void create_vulkan_instance();
	bool check_validation_layer_support();
	const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
	};
	std::vector<const char*> get_required_extensions();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);


public:
	void start_vulkan();
	void cleanEngine();
	vulkan();
	~vulkan();
};

} // vulkan_sim
