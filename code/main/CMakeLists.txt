add_executable(${PROJECT_NAME})

set(SRCS main.cpp)
set(HDRS )

target_include_directories(${PROJECT_NAME} PRIVATE ${HDRS})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image "Putt-It-core")
target_sources(${PROJECT_NAME} PRIVATE ${SRCS})

file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION .)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)