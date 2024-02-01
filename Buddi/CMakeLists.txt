add_executable(${BUDDI_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-audio)

add_custom_command(
	TARGET ${BUDDI_TARGET_NAME}
)