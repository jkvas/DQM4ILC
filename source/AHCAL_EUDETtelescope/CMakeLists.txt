#######################################################
# cmake file for building DQM4ILC examples
# @author Eté Rémi , IPNL
# modified by A. Irles DESY
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SHARED_LIBRARY( AHCAL_EUDETtelescope GeomCorrelations/Correlations.cc )

TARGET_LINK_LIBRARIES( AHCAL_EUDETtelescope ${PROJECT_NAME} )

INSTALL( 
	TARGETS AHCAL_EUDETtelescope
	LIBRARY DESTINATION lib 
)


