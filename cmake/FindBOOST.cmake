FIND_PATH(BOOST_INCLUDE_DIR boost/weak_ptr.hpp)

IF (BOOST_INCLUDE_DIR)
  SET(BOOST_FOUND TRUE)
ENDIF (BOOST_INCLUDE_DIR)


IF (BOOST_FOUND)
  IF (NOT BOOST_FIND_QUIETLY)
    MESSAGE(STATUS "Found BOOST: ${BOOST_INCLUDE_DIR}")
  ENDIF (NOT BOOST_FIND_QUIETLY)
ELSE (BOOST_FOUND)
  IF (BOOST_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find BOOST")
  ENDIF (BOOST_FIND_REQUIRED)
ENDIF (BOOST_FOUND)

