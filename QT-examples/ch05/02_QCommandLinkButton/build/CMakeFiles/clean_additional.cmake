# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "02_QCommandLinkButton_autogen"
  "CMakeFiles/02_QCommandLinkButton_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/02_QCommandLinkButton_autogen.dir/ParseCache.txt"
  )
endif()
