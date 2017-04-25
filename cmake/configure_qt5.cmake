find_package(Qt5Widgets)
find_package(Qt5Script)

include_directories(${Qt5Widgets_INCLUDE_DIRS})

set (QT5_LINK_TARGETS Qt5::Widgets Qt5::Script)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#deploy with qt dlls.
#link against QT5_LINK_TARGETS
