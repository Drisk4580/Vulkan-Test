# Vulkan-Test
My vulkan learning progress

# Because Github keeps messing this up:

Create a 'external' directory ```cd``` into it and type: 
	git submodule add https://github.com/glfw/glfw
  git submodule add https://github.com/g-truc/glm

#### Report Any Errors. THiS WILL NOT WORK ON WINDOWS OR WAYLAND(yet)
###### To build:
	cmake -S . -GNinja -B build -DCMAKE_BUILD_TYPE=Debug
	ninja -C build
