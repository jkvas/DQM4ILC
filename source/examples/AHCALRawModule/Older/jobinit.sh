source /home/calice/Programs/ilcinstall-v01-17-09/v01-17-09/init_ilcsoft.sh
export LD_LIBRARY_PATH=/home/calice/Programs/DQM4HEP-AHCAL/lib:$LD_LIBRARY_PATH
export PATH=/home/calice/Programs/DQM4HEP-AHCAL/bin:$PATH
export DIM_DNS_NODE=localhost

./home/calice/Programs/DQM4HEP-AHCAL/bin/dqm4hep_start_job_interface
