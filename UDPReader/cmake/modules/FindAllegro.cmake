# FindAllegro
# -----------
# Copyright (c) 2018 Rodolfo Lam. All Rights Reserved.
#
# Finds the Allegro 5 Library... or at least tries.
#
# This will define the following variables::
#
#   Allegro_FOUND    - True if the system has the Foo library
#   Allegro_VERSION  - The version of the Foo library which was found
#
# and the following imported targets::
#
#   Allegro::AllegroMain   - The Allegro 5 library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_Allegro QUIET IMPORTED_TARGET allegro-5)

find_path(Allegro_INCLUDE_DIR
	NAMES ./allegro5/allegro5.h ./allegro5/allegro.h
	PATHS ${PC_Allegro_INCLUDE_DIRS}
	PATH_SUFFIXES 
)

find_library(Allegro_LIBRARY
	NAMES allegro
	PATH ${PC_Allegro_LIBRARY_DIRS}
)

set(Allegro_VERSION ${PC_ALLEGRO_VERSION})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Allegro
	FOUND_VAR Allegro_FOUND
	REQUIRED_VARS
		Allegro_LIBRARY
		Allegro_INCLUDE_DIR
	VERSION_VAR Allegro_VERSION
)
