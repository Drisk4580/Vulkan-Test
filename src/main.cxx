#include "sys.h"
#include "debug.h"
#include <iostream>
#include <thread>
#include "window.h"

#include <vulkan/vulkan.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

int main()
{
    Debug(NAMESPACE_DEBUG::init());
    Dout(dc::notice, "Entering main()");

    std::thread thr1([](){
        Debug(NAMESPACE_DEBUG::init_thread("Thread1"));
        Dout(dc::warning, "Starting Multi-threading");
    });

    thr1.join();
	window* base_window = new window();

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    Dout(dc::notice, extensionCount << " extensions supported\n");

	base_window->initialize_vk_window();

	base_window->clean_vk_engine();
    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    return 0;
}
