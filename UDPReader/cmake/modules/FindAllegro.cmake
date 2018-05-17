# FindAllegro
# -----------
#
# Finds the Allegro 5 Library... or at least tries.
#
# This will define the following variables::
#
#   ALLLEGRO_FOUND    - True if the system has the Foo library
#   ALLEGRO_VERSION  - The version of the Foo library which was found
#
# and the following imported targets::
#
#   Allegro::AllegroMain   - The Allegro 5 library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_ALLEGRO QUIET IMPORTED_TARGET allegro-5)

find_path(ALLEGRO_INCLUDE_DIR
	NAMES ./allegro5/allegro5.h ./allegro5/allegro.h
	PATHS ${PC_ALLEGRO_INCLUDE_DIRS}
	PATH_SUFFIXES 
)

find_library(ALLEGRO_LIBRARY
	NAMES allegro
	PATH ${PC_ALLEGRO_LIBRARY_DIRS}
)

set(ALLEGRO_VERSION ${PC_ALLEGRO_VERSION})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ALLEGRO
	FOUND_VAR ALLEGRO_FOUND
	REQUIRED_VARS
		ALLEGRO_LIBRARY
		ALLEGRO_INCLUDE_DIR
	VERSION_VAR ALLEGRO_VERSION
)