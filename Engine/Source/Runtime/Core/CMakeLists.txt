# Source/Core

set(SOTOL_CORE_SOURCES
	"Application/Application.cpp"
	"Application/Window.cpp"
	"Application/Log.cpp")

set(SOTOL_CORE_LIBS
	EASTL)

add_library(SotolEngine-Core ${SOTOL_CORE_SOURCES})
target_link_libraries(SotolEngine-Core PRIVATE ${SOTOL_CORE_LIBS})
set_property(TARGET SotolEngine-Core PROPERTY CXX_STANDARD 20)
set_target_properties(SotolEngine-Core PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Engine/Binaries"
	ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Engine/Binaries"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Engine/Binaries")