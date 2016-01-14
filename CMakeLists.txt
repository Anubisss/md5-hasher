cmake_minimum_required(VERSION 2.8)

SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM})

SET( BIN md5-hasher )
SET( PROJECT_ROOT "${CMAKE_SOURCE_DIR}/" )

IF(UNIX AND NOT APPLE)
    SET(LINUX ON)
ENDIF(UNIX AND NOT APPLE)

IF(WIN32)
	MESSAGE(SEND_ERROR "WINDOWS is unsupported yet ;)")
ENDIF(WIN32)

#--------------------------------------------------------------------
# Set source files.
#--------------------------------------------------------------------
AUX_SOURCE_DIRECTORY( ${PROJECT_ROOT}/src/md5 SOURCES )
AUX_SOURCE_DIRECTORY( ${PROJECT_ROOT}/src/main SOURCES_MAIN )

SET(PROJECT_SOURCES
	${SOURCES}
	${SOURCES_MAIN}
)

#--------------------------------------------------------------------
# Compile
#--------------------------------------------------------------------
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g3 -std=c++11")

INCLUDE_DIRECTORIES(
    ${PROJECT_ROOT}/src/md5/
)

ADD_EXECUTABLE( ${BIN} ${PROJECT_SOURCES} )

TARGET_LINK_LIBRARIES( ${BIN}
    ${CMAKE_THREAD_LIBS_INIT}
)

SET_TARGET_PROPERTIES(${BIN}
	PROPERTIES 
	VERSION ${MAJOR_VERSION}
	SOVERSION ${MINOR_VERSION}
)
