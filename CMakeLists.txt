cmake_minimum_required(VERSION 3.28.1)

project(Buddi_Engine
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

include(FetchContent)
set(SFML_LIB SFML)

FetchContent_Declare(
	${SFML_LIB}
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.5.1
	GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB})

set(BUDDI_ENGINE_TARGET_NAME Buddi_Engine)
set(BUDDI_TEST_GAME_TARGET_NAME Buddi_Test_Game)

add_subdirectory(Buddi_Engine)
add_subdirectory(Buddi_Test_Game)