project("Putt-It-core")

add_library(${PROJECT_NAME})

set(SRCS conversion.cpp)
set(HDRS ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC ${HDRS})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
target_sources(${PROJECT_NAME} PRIVATE ${SRCS})