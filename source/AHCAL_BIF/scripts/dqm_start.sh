
# Starting the individual processes
dns &
#source dns_script.sh &

dqm4hep_start_run_control_server -v ALL -r AHCALRunControl & 

dqm4hep_start_run_control_interface -v ALL -r AHCALRunControl 
#--settings-file Runcontrol_Detector_center.xml &

export DQM4HEP_PLUGIN_DLL=/home/calice/TB2018/DQM4ILC/lib/libAHCAL_40Layers.so
dqm4hep_start_event_collector -v WARN -c ahcal_event_collector &

dqm4hep_start_monitor_element_collector -v WARN -c ahcal_me_collector &
dqm4hep_start_dqm_monitor_gui -v WARN -f /home/calice/TB2018/scripts/test_canvases1.xml &
dqm4hep_start_analysis_module -v WARN -f /home/calice/TB2018/scripts/lcioTestbeam201805.xml &




#dqm4hep_start_run_control_interface -v WARN -r AHCALRunControl --settings-file Runcontrol_Detector_corner.xml &

#dqm4hep_start_dqm_monitor_gui -v WARN --import-file DQM_Monitoring_canvases.xml &
#--import-file DQM_2017July.xml& 
#dqm4hep_start_dqm_monitor_gui -v WARN &

sleep 2;

#dqm4hep_start_analysis_module -v ALL -f /home/calice/TB2018/scripts/lcioTestbeam201805.xml &

#start the analysis modules
#dqm4hep_start_analysis_module -v WARN -f ../DQM4HEP/DQM4ILC/source/AHCAL_BIF/AHCAL/Layers/lcioTestbeam201707.xml&
#sleep 5
#dqm4hep_start_analysis_module -v WARN -f ~/TB2017/DQM4HEP/DQM4ILC/source/AHCAL_BIF/AHCAL/Channels/lcio15channelsX4.xml&

#dqm4hep_start_analysis_module -v WARN -f ~/TB2017/DQM4HEP/DQM4ILC/source/AHCAL_EUDETtelescope/GeomCorrelations/lcioTelescopeCorrelations.xml&


#dqm4hep_start_lcio_file_service -f /home/calice/TestFile_ChannelbyChannel.slcio -c ahcal_event_collector -r -t 10
#dqm4hep_start_analysis_module -f /home/calice/Programs/DQM4HEP-AHCAL/DQM4ILC/source/examples/AHCALRawModule/lcioAHCALTests.xml
 
