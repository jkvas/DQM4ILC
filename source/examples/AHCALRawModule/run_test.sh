export DQM4HEP_PLUGIN_DLL=/home/calice/Programs/DQM4HEP-AHCAL/lib/libDQM4ILC.so
dqm4hep_start_event_collector -c ahcal_event_collector -s LCIOStreamer &
dqm4hep_start_monitor_element_collector -c ahcal_me_collector &
dqm4hep_start_lcio_file_service -f /home/calice/TestFile_ChannelbyChannel.slcio -c ahcal_event_collector -r -t 100000 &
export DQM4HEP_PLUGIN_DLL=/home/calice/Programs/DQM4HEP-AHCAL/lib/libDQM4ILC.so:/home/calice/Programs/DQM4HEP-AHCAL/lib/libAHCALRawModule.so
dqm4hep_start_analysis_module -f /home/calice/Programs/DQM4HEP-AHCAL/DQM4ILC/source/examples/AHCALRawModule/lcioAHCALTests.xml
