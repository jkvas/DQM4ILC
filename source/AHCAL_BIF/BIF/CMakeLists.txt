#######################################################
# cmake file for building DQM4ILC examples
# @author Eté Rémi , IPNL
# modified by A. Irles DESY
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SHARED_LIBRARY( BIF_FindOffset FindOffset/FindOffset.cc )
ADD_SHARED_LIBRARY( BIF_AHCAL_Correlation PlotCorrelations/TimeCorrelation.cc )

TARGET_LINK_LIBRARIES( BIF_FindOffset ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( BIF_AHCAL_Correlation ${PROJECT_NAME} )

INSTALL( 
	TARGETS BIF_FindOffset BIF_AHCAL_Correlation
	LIBRARY DESTINATION lib 
)


