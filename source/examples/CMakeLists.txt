#######################################################
# cmake file for building DQM4ILC examples
# @author Eté Rémi , IPNL
# modified by A. Irles DESY
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SHARED_LIBRARY( CaloHitModule CaloHitModule/CaloHitModule.cc )
ADD_SHARED_LIBRARY( AHCALRawModule4Channels AHCALRawModule/4Channels/AHCALRawModuleChannel.cc )
ADD_SHARED_LIBRARY( AHCALRawModuleT0 AHCALRawModule/T0/AHCALRawModuleT0.cc )
ADD_SHARED_LIBRARY( AHCALRawModuleGlobal AHCALRawModule/Global/AHCALRawModuleGlobal.cc )
ADD_SHARED_LIBRARY( BIFandAHCALcorrelations AHCALRawModule/BIF/BIFandAHCALcorrelations.cc )
ADD_SHARED_LIBRARY( Testbeam AHCALRawModule/TestbeamMay2016_3HBU/Testbeam.cc )
#ADD_SHARED_LIBRARY( Testbeam AHCALRawModule/TestbeamMay2016_PowerPulsing/Testbeam.cc )

TARGET_LINK_LIBRARIES( CaloHitModule ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( AHCALRawModule4Channels ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( AHCALRawModuleT0 ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( AHCALRawModuleGlobal ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( BIFandAHCALcorrelations ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( Testbeam ${PROJECT_NAME} )


INSTALL( 
	TARGETS CaloHitModule AHCALRawModule4Channels AHCALRawModuleT0 AHCALRawModuleGlobal BIFandAHCALcorrelations Testbeam
	LIBRARY DESTINATION  lib 
)


