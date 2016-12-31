cmake_minimum_required(VERSION 3.1)
project(ModuleEditor)
include(CTest)
enable_testing()

# sets
set (CMAKE_CXX_STANDARD 14)
set(MODULEEDITOR_SRC_FILES 
     ${CMAKE_CURRENT_SOURCE_DIR}/src/Editor.cxx
)
set(MODULEEDITOR_HDR_FILES 
     ${CMAKE_CURRENT_SOURCE_DIR}/include/ModuleEditor/Editor.hxx
     ${CMAKE_CURRENT_SOURCE_DIR}/include/ModuleEditor/module_editor.ui
)


# includes/include directories
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_qt5.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ModuleEditor)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# binaries/executables/libraries
add_executable(ModuleEditor main.cxx ${MODULEEDITOR_HDR_FILES} ${MODULEEDITOR_SRC_FILES}  )

# linker
target_link_libraries(ModuleEditor ${Boost_LIBRARIES} ${QT5_LINK_TARGETS} )
