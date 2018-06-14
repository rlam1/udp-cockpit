# FindAllegro
# -----------
# Copyright (c) 2018 Rodolfo Lam. All Rights Reserved.
#
# Finds the Allegro 5 Library... or at least tries.
#
# This will define the following variables::
#
#   Allegro_FOUND         - True if the system has the Allegro library
#   Allegro_VERSION       - The version of the Allegro library which was found
#
# and the following imported targets::
#
#   Allegro::Allegro   - The Allegro 5 library
#   Allegro::<c>       - The requested Allegro Add-on

find_package(PkgConfig REQUIRED)
pkg_search_module(PC_Allegro QUIET allegro-5)

set(Allegro_FOUND ${PC_Allegro_FOUND})

find_path(Allegro_INCLUDE_DIR
	NAMES allegro5.h allegro.h
	PATHS ${PC_Allegro_INCLUDE_DIRS}
	PATH_SUFFIXES allegro5
)
find_library(Allegro_LIBRARY
	NAMES allegro
	PATH ${PC_Allegro_LIBRARY_DIRS}
)
set(Allegro_VERSION ${PC_ALLEGRO_VERSION})

if(Allegro_FOUND)
	set(Allegro_LIBRARIES ${Allegro_LIBRARY})
	set(Allegro_INCLUDE_DIRS ${Allegro_INCLUDE_DIR})
	set(Allegro_DEFINITIONS ${PC_Allegro_CFLAGS_OTHER})
endif()

if(Allegro_FOUND AND NOT TARGET Allegro::Allegro)
	add_library(Allegro::Allegro UNKNOWN IMPORTED)
	set_target_properties(Allegro::Allegro PROPERTIES
		IMPORTED_LOCATION "${Allegro_LIBRARIES}" 
		INTERFACE_COMPILE_OPTIONS "${Allegro_DEFINITIONS}"
		INTERFACE_INCLUDE_DIRECTORIES "${Allegro_INCLUDE_DIRS}"
	)
endif()

# Seatch Allegro Add-Ons and include them in the variables
# will set Allegro_FOUND to 0 if any Add-on is not found.
foreach(component ${Allegro_FIND_COMPONENTS})
	pkg_search_module(PC_Allegro_${component} QUIET allegro_${component}-5)
	if("${PC_Allegro_${component}_FOUND}")
		find_path(Allegro_${component}_INCLUDE_DIR
			NAMES allegro_${component}.h
			PATHS "${PC_Allegro_${component}_INCLUDE_DIRS}"
			PATH_SUFFIXES allegro5
		)
		
		find_library(Allegro_${component}_LIBRARY
			NAMES allegro_${component} allegro_${component}-5
			PATH "${PC_Allegro_${component}_LIBRARY_DIRS}"
		)
		
		set(Allegro_${component}_FOUND "${PC_Allegro_${component}_FOUND}")
		
		if(Allegro_${component}_FOUND AND NOT TARGET Allegro::${component})
			add_library(Allegro::${component} UNKNOWN IMPORTED)
			set_target_properties(Allegro::${component} PROPERTIES
				IMPORTED_LOCATION "${Allegro_${component}_LIBRARY}" 
				INTERFACE_COMPILE_OPTIONS "${PC_Allegro_${component}_CFLAGS_OTHER}"
				INTERFACE_INCLUDE_DIRECTORIES "${Allegro_${component}_INCLUDE_DIR}"
			)
		endif()
		
		mark_as_advanced(Allegro_${component}_INCLUDE_DIR Allegro_${component}_LIBRARY)
	else()
		message([FATAL_ERROR] "The Allegro ${component} Add-On was not found!")
		break()
	endif()
endforeach()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Allegro
	FOUND_VAR Allegro_FOUND
	REQUIRED_VARS
		Allegro_LIBRARY
		Allegro_INCLUDE_DIR
	VERSION_VAR Allegro_VERSION
	HANDLE_COMPONENTS
)

mark_as_advanced(Allegro_FOUND Allegro_INCLUDE_DIR Allegro_VERSION Allegro_LIBRARY)
