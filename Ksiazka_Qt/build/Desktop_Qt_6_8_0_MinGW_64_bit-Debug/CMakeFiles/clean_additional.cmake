# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ksiazka_Qt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ksiazka_Qt_autogen.dir\\ParseCache.txt"
  "Ksiazka_Qt_autogen"
  )
endif()
