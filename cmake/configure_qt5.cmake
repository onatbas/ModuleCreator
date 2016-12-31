find_package(Qt5Widgets)

include_directories(${Qt5Widgets_INCLUDE_DIRS})

set (QT5_LINK_TARGETS Qt5::Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#deploy with qt dlls.
#link against QT5_LINK_TARGETS
