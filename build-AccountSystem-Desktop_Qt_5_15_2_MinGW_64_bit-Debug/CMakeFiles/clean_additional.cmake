# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AccountSystem_autogen"
  "CMakeFiles\\AccountSystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AccountSystem_autogen.dir\\ParseCache.txt"
  )
endif()
