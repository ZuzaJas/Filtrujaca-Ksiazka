# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ksiazka_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ksiazka_autogen.dir\\ParseCache.txt"
  "Ksiazka_autogen"
  )
endif()
