cmake_minimum_required(VERSION 3.28.1)

project(Buddi_Engine
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

set(BUDDI_TARGET_NAME Buddi_Test)

add_subdirectory(Buddi)