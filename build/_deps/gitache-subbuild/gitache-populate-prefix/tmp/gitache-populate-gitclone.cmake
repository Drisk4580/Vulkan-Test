# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitclone-lastrun.txt" AND EXISTS "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitinfo.txt" AND
  "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/luxcid/Vulkan-Test/build/_deps/gitache-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/luxcid/Vulkan-Test/build/_deps/gitache-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" 
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/CarloWood/gitache.git" "gitache-src"
    WORKING_DIRECTORY "/home/luxcid/Vulkan-Test/build/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/CarloWood/gitache.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" 
          checkout "bef7d0d52ef3587e310edd43a762f4cc16ef1708" --
  WORKING_DIRECTORY "/home/luxcid/Vulkan-Test/build/_deps/gitache-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'bef7d0d52ef3587e310edd43a762f4cc16ef1708'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/home/luxcid/Vulkan-Test/build/_deps/gitache-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/luxcid/Vulkan-Test/build/_deps/gitache-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitinfo.txt" "/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/luxcid/Vulkan-Test/build/_deps/gitache-subbuild/gitache-populate-prefix/src/gitache-populate-stamp/gitache-populate-gitclone-lastrun.txt'")
endif()