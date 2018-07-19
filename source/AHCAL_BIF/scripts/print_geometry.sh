#!/bin/sh

for l in `seq -f "%02g" 1 48` 
do 
    echo "    <monitorElement ID=\"MIP_600_l${l}\" path=\"/Maps/MIP\" type=\"TH2I\"
		    name =\"MIP_600_l${l}\"
		    nBinsX=\"24\" minX=\"0.5\" maxX=\"24.5\" 
		    nBinsY=\"24\" minY=\"0.5\" maxY=\"24.5\" 
		    resetPolicy=\"EndOfRun\" drawOption=\"colz\"/>"
done

for l in `seq -f "%02g" 1 48` 
do 
    echo "    <monitorElement ID=\"Ped_600_l${l}\" path=\"/Maps/Ped\" type=\"TH2I\" 
		    name =\"Ped_600_l${l}\"
		    nBinsX=\"24\" minX=\"0.5\" maxX=\"24.5\" 
		    nBinsY=\"24\" minY=\"0.5\" maxY=\"24.5\" 
		    resetPolicy=\"EndOfRun\" drawOption=\"colz\"/>"
done

for l in `seq -f "%02g" 1 48` 
do 
    echo "    <monitorElement ID=\"MIP_600_l${l}\" path=\"/Maps/MIP\" type=\"TH2I\" name =\"MIP_600_l${l}\" nBinsX=\"24\" minX=\"0.5\" maxX=\"24.5\" nBinsY=\"24\" minY=\"0.5\" maxY=\"24.5\" resetPolicy=\"EndOfRun\" drawOption=\"colz\"/>"
done

for l in `seq -f "%02g" 1 48` 
do 
    echo "    <monitorElement ID=\"Ped_600_l${l}\" path=\"/Maps/Ped\" type=\"TH2I\" name =\"Ped_600_l${l}\" nBinsX=\"24\" minX=\"0.5\" maxX=\"24.5\" nBinsY=\"24\" minY=\"0.5\" maxY=\"24.5\" resetPolicy=\"EndOfRun\" drawOption=\"colz\"/>"
done

for l in `seq -f "%02g" 1 48` 
do 
    shortl=`expr "$l" + "0"`
    echo "    <monitorElement ID=\"TempAverage_${l}\" name=\"TempAverage_${l}\" path=\"/Temp/Average\" type=\"user\" ROOTClass=\"TGraph\" title=\"Temp (Average) on Layer ${shortl}\" resetPolicy=\"NoReset\" drawOption=\"alp\"/>"
done

for l in `seq -f "%02g" 1 48` 
do 
    shortl=`expr "$l" + "0"`
    echo "    <monitorElement ID=\"TempDIF_${l}\" name=\"TempDIF_${l}\" path=\"/Temp/DIF\" type=\"user\" ROOTClass=\"TGraph\" title=\"Temp (DIF) on Layer ${shortl}\" resetPolicy=\"NoReset\" drawOption=\"alp\"/>"
done

for l in `seq -f "%02g" 1 48` 
do 
    shortl=`expr "$l" + "0"`
    echo "    <monitorElement ID=\"TempPWR_${l}\" name=\"TempPWR_${l}\" path=\"/Temp/PWR\" type=\"user\" ROOTClass=\"TGraph\" title=\"Temp (PWR) on Layer ${shortl}\" resetPolicy=\"NoReset\" drawOption=\"alp\"/>"
done
