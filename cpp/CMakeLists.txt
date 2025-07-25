cmake_minimum_required(VERSION 3.31.0-rc2)
project(GIK VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.14.2/mingw73_32")

find_package(Qt5 COMPONENTS Core Gui Widgets LinguistTools REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(HEADERS
    src/mainwindow.hpp
)

set(SOURCES
    main.cpp
    src/mainwindow.cpp
)

set(SRC
    src
    res
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${Qt5Widgets_INCLUDE_DIRS} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

if (WIN32)
    # Создаём файл ресурсов (app.rc)
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/app.rc "1 24 \"${CMAKE_CURRENT_SOURCE_DIR}/manifest.xml\"\n")

    # Добавляем ресурсы к приложению
    target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/app.rc)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE ON)
