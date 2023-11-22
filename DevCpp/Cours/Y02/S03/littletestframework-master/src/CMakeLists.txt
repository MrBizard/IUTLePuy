# CMakeList.txt : projet CMake pour LittleTestFramework, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.15)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (LittleTestFramework "LittleTestFramework.cpp"  "test.h" )

find_package(Doxygen)

option(BUILD_DOCUMENTATION "Create and install the HTML documentation of LittleTestFramework API" ${DOXYGEN_FOUND})

if(${DOXYGEN_FOUND})
	add_custom_target(doc ALL
	                  COMMAND ${DOXYGEN_EXECUTABLE} doxyfile.dox
					  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
					  COMMENT "Generating API documentation with Doxygen"
					  VERBATIM
	)
endif()

install(FILES "test.h" DESTINATION "src")
install(DIRECTORY doc/html DESTINATION "doc")