#include "vulkan_app.h"

vulkan_sim::vulkan::vulkan()															// Empty for later code
{
	Debug(NAMESPACE_DEBUG::init());
}
vulkan_sim::vulkan::~vulkan()
{
}

void vulkan_sim::vulkan::start_vulkan()
{
	Dout(dc::notice, "Vulkan Starting");
	create_vulkan_instance();
}

void vulkan_sim::vulkan::create_vulkan_instance()
{
	if (enableValidationLayers && !check_validation_layer_support()) {
    DoutFatal(dc::core|error_cf, "Validation layers enabled but not supported.");
  }
	else
	{
		Dout(dc::notice, "Validation layers enabled.");
	}
	// WHAT THE HECK IS THIS
	VkApplicationInfo engine_info{};
	engine_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  engine_info.pApplicationName = "Vulkan Test";
  engine_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	engine_info.pEngineName = "SimEngine";
  engine_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  engine_info.apiVersion = VK_API_VERSION_1_3;

	VkInstanceCreateInfo createInfo{};																									// Create Vulkan Info
	if (enableValidationLayers) {																												// Add Vulkan layer support i dont know
    createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
    createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else
	{
    createInfo.enabledLayerCount = 0;
	}
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &engine_info;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	auto extensions = get_required_extensions();
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();

	// This code should never fail
	if (vkCreateInstance(&createInfo, nullptr, &this->m_vk_instance) != VK_SUCCESS)
	{
    DoutFatal(dc::core|error_cf, "Could not create a Vulkan Instance");
	}

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	// TODO: Major refacoring
	// std::vector<VkExtensionProperties> extensions(extensionCount);
	// vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
}

bool vulkan_sim::vulkan::check_validation_layer_support() {
  uint32_t layerCount;
  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
	for (const char* layerName : this->validationLayers)
	{
    bool layerFound = false;

    for (const auto& layerProperties : availableLayers)
		{
      if (strcmp(layerName, layerProperties.layerName) == 0)
			{
        layerFound = true;
        break;
      }
		}
		if (!layerFound)
		{
      return false;
    }
	}

	return true;
}

void vulkan_sim::vulkan::cleanEngine()
{
	vkDestroyInstance(this->m_vk_instance, nullptr);
}

std::vector<const char*> vulkan_sim::vulkan::get_required_extensions()
{
  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

  if (enableValidationLayers)
	{
      extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
  }

  return extensions;
}
