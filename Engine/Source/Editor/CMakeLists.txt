
set(EDITOR_SOURCES
	"EditorApplication.cpp"
	"main.cpp")

set(RUNTIME_LIBS
	SotolEngine-Core
)

add_executable(SotolEditor ${EDITOR_SOURCES})
target_include_directories(SotolEditor PUBLIC "${PROJECT_SOURCE_DIR}/Engine/Source/Runtime")
target_link_libraries(SotolEditor PUBLIC ${RUNTIME_LIBS} fmt::fmt)
set_property(TARGET SotolEditor PROPERTY CXX_STANDARD 20)
set_target_properties(SotolEditor PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Engine/Binaries"
	ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Engine/Binaries"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Engine/Binaries")