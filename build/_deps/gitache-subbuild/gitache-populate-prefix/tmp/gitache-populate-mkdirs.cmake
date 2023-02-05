# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-src"
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-build"
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix"
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/tmp"
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp"
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src"
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
