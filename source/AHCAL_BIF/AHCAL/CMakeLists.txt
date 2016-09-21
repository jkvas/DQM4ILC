#######################################################
# cmake file for building DQM4ILC examples
# @author Eté Rémi , IPNL
# modified by A. Irles DESY
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SHARED_LIBRARY( AHCAL_15Layers Layers/AHCAL_15Layers.cc )
ADD_SHARED_LIBRARY( AHCAL_15Channels Channels/Testbeam.cc )

TARGET_LINK_LIBRARIES( AHCAL_15Layers ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( AHCAL_15Channels ${PROJECT_NAME} )

INSTALL( 
	TARGETS AHCAL_15Layers AHCAL_15Channels
	LIBRARY DESTINATION lib 
)


