add_library(${BUDDI_ENGINE_TARGET_NAME} STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Application.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/Framework/Application.h

	${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Core.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/Framework/Core.h

	${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Scene.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/Framework/Scene.h

	${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Actor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/Framework/Actor.h

	${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Object.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/Framework/Object.h

	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/includes/EntryPoint.h
)

target_include_directories(${BUDDI_ENGINE_TARGET_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_link_libraries(${BUDDI_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${BUDDI_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${BUDDI_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${BUDDI_ENGINE_TARGET_NAME} PUBLIC sfml-audio)


add_custom_command(TARGET ${BUDDI_ENGINE_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-graphics>
	$<TARGET_FILE_DIR:${BUDDI_ENGINE_TARGET_NAME}>
)

add_custom_command(TARGET ${BUDDI_ENGINE_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-window>
	$<TARGET_FILE_DIR:${BUDDI_ENGINE_TARGET_NAME}>
)

add_custom_command(TARGET ${BUDDI_ENGINE_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-system>
	$<TARGET_FILE_DIR:${BUDDI_ENGINE_TARGET_NAME}>
)

add_custom_command(TARGET ${BUDDI_ENGINE_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:sfml-audio>
	$<TARGET_FILE_DIR:${BUDDI_ENGINE_TARGET_NAME}>
)

