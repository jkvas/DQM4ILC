# default stuff
sudo apt-get update
sudo apt-get update && sudo apt-get install build-essential

#root prerequisites
sudo apt-get install git dpkg-dev make g++ gcc binutils libx11-dev libxpm-dev \
libxft-dev libxext-dev

sudo apt-get install gfortran libssl-dev libpcre3-dev \
xlibmesa-glu-dev libglew1.5-dev libftgl-dev \
libmysqlclient-dev libfftw3-dev cfitsio-dev \
graphviz-dev libavahi-compat-libdnssd-dev \
libldap2-dev python-dev libxml2-dev libkrb5-dev \
libgsl0-dev libqt4-dev

#other basics
sudo apt-get install python-dev libbz2-dev g++-4.8 \
git openssl perl python subversion

#java
sudo apt-get install default-jdk
sudo apt-get install default-jre

#more basics
sudo apt-get install freeglut3-dev
sudo apt-get install libncurses5-dev
sudo apt-get install libxrender-dev

#cmake 3.1 (for eudaq)
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:george-edison55/cmake-3.x
sudo apt-get update
sudo apt-get install cmake
sudo apt-get upgrade
sudo apt-get install cmake-qt-gui

#install ilcsoft
cd /home/calice/Desktop
git clone https://github.com/CALICETB/ILCSoftInstall
cd ILCSoftInstall
mkdir build
cd build
cmake ..
