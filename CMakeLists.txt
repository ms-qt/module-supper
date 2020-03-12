cmake_minimum_required(VERSION 3.5)
project(module-supper LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)

find_package(Qt5 COMPONENTS Core REQUIRED)

if (UNIX)
    SET(LIBRARY_OUTPUT_PATH /usr/local/lib)
endif (UNIX)

if (WIN32)
    SET(LIBRARY_OUTPUT_PATH D:/Local/libs/lib)
endif ()


# 库类型
# SHARED STATIC
set(LIB_TYPE SHARED)

# 1 可独立执行程序   0 非独立执行程序
set(APPLICATION 0)


find_package(Qt5 COMPONENTS Core REQUIRED)

set(SRC
        module/supper/IModule.h
        module/supper/IData.h
        )


if (APPLICATION)
    add_library(${PROJECT_NAME}
            ${SRC}
            )
else ()
    add_library(${PROJECT_NAME} ${LIB_TYPE}
            ${SRC}
            )
endif ()


target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)
target_compile_definitions(${PROJECT_NAME} PRIVATE MODULESUPPER_LIBRARY)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY module DESTINATION include FILES_MATCHING PATTERN "*.h")
install(EXPORT ${PROJECT_NAME} NAMESPACE bdlbsc DESTINATION lib/cmake/module/supper)