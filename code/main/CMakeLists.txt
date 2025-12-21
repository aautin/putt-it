add_executable(${PROJECT_NAME})

set(SRCS main.cpp)
set(HDRS )

target_include_directories(${PROJECT_NAME} PRIVATE ${HDRS})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2)
target_sources(${PROJECT_NAME} PRIVATE ${SRCS})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)