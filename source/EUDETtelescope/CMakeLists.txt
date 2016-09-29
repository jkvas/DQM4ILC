#######################################################
# cmake file for building DQM4ILC examples
# @author Eté Rémi , IPNL
# modified by A. Irles DESY
# Copyright (c) CNRS / IPNL
#######################################################


ADD_SHARED_LIBRARY( EUDETtelescopeHotPixels hotpixels/EUDETtelescopeHotPixels.cc )
ADD_SHARED_LIBRARY( EUDETtelescopeHitMaps hitmaps/EUDETtelescopeHitMaps.cc )

TARGET_LINK_LIBRARIES( EUDETtelescopeHotPixels ${PROJECT_NAME} )
TARGET_LINK_LIBRARIES( EUDETtelescopeHitMaps ${PROJECT_NAME} )

INSTALL(
        TARGETS EUDETtelescopeHotPixels EUDETtelescopeHitMaps
        LIBRARY DESTINATION  lib
)




