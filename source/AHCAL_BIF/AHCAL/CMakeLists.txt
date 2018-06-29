#######################################################
# cmake file for building DQM4ILC examples
# @author Eté Rémi , IPNL
# modified by A. Irles DESY
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SHARED_LIBRARY( AHCAL_15Layers Layers/AHCAL_15Layers.cc )
ADD_SHARED_LIBRARY( AHCAL_40Layers Layers/AHCAL_40Layers.cc )
ADD_SHARED_LIBRARY( AHCAL_96Layers Layers/AHCAL_96Layers.cc )
ADD_SHARED_LIBRARY( AHCAL_15Channels Channels/Testbeam.cc )

TARGET_LINK_LIBRARIES( AHCAL_15Layers ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( AHCAL_40Layers ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( AHCAL_96Layers ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( AHCAL_15Channels ${PROJECT_NAME} )

INSTALL( 
	TARGETS AHCAL_15Layers AHCAL_15Channels AHCAL_40Layers AHCAL_96Layers 
	LIBRARY DESTINATION lib 
)


