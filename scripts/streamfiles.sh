FILES=/home/calice/TB2016/Data_July2016/EMShower/20160804/3GeV_PowerPulsing/*
for f in $FILES
do 
    echo "Processing $f file"
    dqm4hep_start_lcio_file_service -v INFO -t 0 -c ahcal_event_collector -f $f
done
