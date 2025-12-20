project(PuttIt-Tests)

add_executable(${PROJECT_NAME})

add_test(
	NAME ${PROJECT_NAME}
	COMMAND $<TARGET_FILE:${PROJECT_NAME}>
)

set(SRCS main.cpp SDLTests.cpp)
set(HDRS )

target_include_directories(${PROJECT_NAME} PRIVATE ${HDRS})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 gtest::gtest)
target_sources(${PROJECT_NAME} PRIVATE ${SRCS})