add_executable(${BUDDI_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Application.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/Framework/Application.h
)

target_include_directories(${BUDDI_TARGET_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${BUDDI_TARGET_NAME} PUBLIC sfml-audio)


add_custom_command(TARGET ${BUDDI_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-graphics>
	$<TARGET_FILE_DIR:${BUDDI_TARGET_NAME}>
)

add_custom_command(TARGET ${BUDDI_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-window>
	$<TARGET_FILE_DIR:${BUDDI_TARGET_NAME}>
)

add_custom_command(TARGET ${BUDDI_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-system>
	$<TARGET_FILE_DIR:${BUDDI_TARGET_NAME}>
)

add_custom_command(TARGET ${BUDDI_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-audio>
	$<TARGET_FILE_DIR:${BUDDI_TARGET_NAME}>
)
