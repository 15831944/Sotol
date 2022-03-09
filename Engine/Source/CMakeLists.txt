

find_package(mimalloc CONFIG REQUIRED)

find_package(EASTL CONFIG REQUIRED)

find_package(fmt CONFIG REQUIRED)

find_package(glm CONFIG REQUIRED)

find_package(glad CONFIG REQUIRED)

find_package(glfw3 CONFIG REQUIRED)
message(WARNING "Include dirs: ${GLFW3_LIBRARIES}")



find_package(imgui CONFIG REQUIRED)


# link EASTL

add_subdirectory("Editor")
add_subdirectory("Runtime")
add_subdirectory("ThirdParty")

include_directories("Runtime")
include_directories("ThirdParty")