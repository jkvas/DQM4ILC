
# Starting the individual processes
source dns_script.sh &

dqm4hep_start_event_collector -c ahcal_event_collector -s LCIOStreamer &

dqm4hep_start_monitor_element_collector -c ahcal_me_collector &

dqm4hep_start_run_control_server -r AHCALRunControl &
dqm4hep_start_run_control_interface -r AHCALRunControl &

dqm4hep_start_dqm_monitor_gui  &

#dqm4hep_start_lcio_file_service -f /home/calice/TestFile_ChannelbyChannel.slcio -c ahcal_event_collector -r -t 10
#dqm4hep_start_analysis_module -f /home/calice/Programs/DQM4HEP-AHCAL/DQM4ILC/source/examples/AHCALRawModule/lcioAHCALTests.xml
