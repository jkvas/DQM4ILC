#######################################################
# cmake file for building DQM4ILC examples
# @author Eté Rémi , IPNL
# modified by A. Irles DESY
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SHARED_LIBRARY( CaloHitModule CaloHitModule/CaloHitModule.cc )

TARGET_LINK_LIBRARIES( CaloHitModule ${PROJECT_NAME} )

INSTALL( 
	TARGETS CaloHitModule
	LIBRARY DESTINATION  lib 
)


