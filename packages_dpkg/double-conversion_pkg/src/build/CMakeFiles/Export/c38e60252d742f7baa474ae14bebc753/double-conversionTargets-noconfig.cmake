#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "double-conversion::double-conversion" for configuration ""
set_property(TARGET double-conversion::double-conversion APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(double-conversion::double-conversion PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib64/libdouble-conversion.so.3.3.0"
  IMPORTED_SONAME_NOCONFIG "libdouble-conversion.so.3"
  )

list(APPEND _cmake_import_check_targets double-conversion::double-conversion )
list(APPEND _cmake_import_check_files_for_double-conversion::double-conversion "${_IMPORT_PREFIX}/lib64/libdouble-conversion.so.3.3.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
