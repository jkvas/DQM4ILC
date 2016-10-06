#######################################################
# cmake file for building DQM4ILC package
# @author Eté Rémi , IPNL
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SUBDIRECTORY( common )

IF( BUILD_EXAMPLES )
  ADD_SUBDIRECTORY( examples )
ENDIF()

IF( BUILD_AHCAL )
  ADD_SUBDIRECTORY( AHCAL_BIF )
  IF( BUILD_EUDET )
    ADD_SUBDIRECTORY( AHCAL_EUDETtelescope )
  ENDIF()
ENDIF()

IF( BUILD_EUDET )
  ADD_SUBDIRECTORY( EUDETtelescope )
ENDIF()

