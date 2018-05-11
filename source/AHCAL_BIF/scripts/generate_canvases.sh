#!/bin/bash
#generated text should be placed in the <canvasView> tag
XSIZE=156; YSIZE=170; XOVERLAP=8; YOVERLAP=15; CANVASES=40; XCANVASES=8
echo " <canvasArea name=\"HITs\">"
for c in `seq 0 $((CANVASES-1))` ; do
    X=$(( (c % XCANVASES) * (XSIZE - XOVERLAP) ));    Y=$(( (c / XCANVASES) * (YSIZE - YOVERLAP) ));    L=`printf "%02d" $((c+1))`
    echo "<canvas x=\"${X}\" y=\"${Y}\" w=\"${XSIZE}\" h=\"${YSIZE}\"> <monitorElement collector=\"ahcal_me_collector\" module=\"myAHCAL_40Layers\" path=\"Maps/HIT\" name=\"HIT_600_l${L}\" /></canvas>"
done
echo "</canvasArea>"

echo " <canvasArea name=\"MIPs\">"
for c in `seq 0 $((CANVASES-1))` ; do
    X=$(( (c % XCANVASES) * (XSIZE - XOVERLAP) ));    Y=$(( (c / XCANVASES) * (YSIZE - YOVERLAP) ));    L=`printf "%02d" $((c+1))`
    echo "<canvas x=\"${X}\" y=\"${Y}\" w=\"${XSIZE}\" h=\"${YSIZE}\"> <monitorElement collector=\"ahcal_me_collector\" module=\"myAHCAL_40Layers\" path=\"Maps/MIP\" name=\"MIP_600_l${L}\" /></canvas>"
done
echo "</canvasArea>"

echo " <canvasArea name=\"Ped\">"
for c in `seq 0 $((CANVASES-1))` ; do
    X=$(( (c % XCANVASES) * (XSIZE - XOVERLAP) ));    Y=$(( (c / XCANVASES) * (YSIZE - YOVERLAP) ));    L=`printf "%02d" $((c+1))`
    echo "<canvas x=\"${X}\" y=\"${Y}\" w=\"${XSIZE}\" h=\"${YSIZE}\"> <monitorElement collector=\"ahcal_me_collector\" module=\"myAHCAL_40Layers\" path=\"Maps/Ped\" name=\"Ped_600_l${L}\" /></canvas>"
done
echo "</canvasArea>"

echo " <canvasArea name=\"Temp\">"
for c in `seq 0 $((CANVASES+7))` ; do
    X=$(( (c % XCANVASES) * (XSIZE - XOVERLAP) ));    Y=$(( (c / XCANVASES) * (YSIZE - YOVERLAP) ));    L=`printf "%02d" $((c))`
    echo "<canvas x=\"${X}\" y=\"${Y}\" w=\"${XSIZE}\" h=\"${YSIZE}\"> <monitorElement collector=\"ahcal_me_collector\" module=\"myAHCAL_40Layers\" path=\"Temp/Average\" name=\"TempAverage_${L}\" /></canvas>"
done
echo "</canvasArea>"

echo " <canvasArea name=\"PWR\">"
for c in `seq 0 $((CANVASES+7))` ; do
    X=$(( (c % XCANVASES) * (XSIZE - XOVERLAP) ));     Y=$(( (c / XCANVASES) * (YSIZE - YOVERLAP) ));     L=`printf "%02d" $((c))`
    echo "<canvas x=\"${X}\" y=\"${Y}\" w=\"${XSIZE}\" h=\"${YSIZE}\"> <monitorElement collector=\"ahcal_me_collector\" module=\"myAHCAL_40Layers\" path=\"Temp/PWR\" name=\"TempPWR_${L}\" /></canvas>"
done
echo "</canvasArea>"

echo " <canvasArea name=\"DIF\">"
for c in `seq 0 $((CANVASES+7))` ; do
    X=$(( (c % XCANVASES) * (XSIZE - XOVERLAP) ));     Y=$(( (c / XCANVASES) * (YSIZE - YOVERLAP) ));     L=`printf "%02d" $((c))`
    echo "<canvas x=\"${X}\" y=\"${Y}\" w=\"${XSIZE}\" h=\"${YSIZE}\"> <monitorElement collector=\"ahcal_me_collector\" module=\"myAHCAL_40Layers\" path=\"Temp/DIF\" name=\"TempDIF_${L}\" /></canvas>"
done
echo "</canvasArea>"

echo " <canvasArea name=\"Layer\">"
for c in `seq 0 $((CANVASES+7))` ; do
    X=$(( (c % XCANVASES) * (XSIZE - XOVERLAP) ));     Y=$(( (c / XCANVASES) * (YSIZE - YOVERLAP) ));     L=`printf "%02d" $((c))`
    echo "<canvas x=\"${X}\" y=\"${Y}\" w=\"${XSIZE}\" h=\"${YSIZE}\"> <monitorElement collector=\"ahcal_me_collector\" module=\"myAHCAL_40Layers\" path=\"Temp/Layer\" name=\"TempLayer_${L}\" /></canvas>"
done
echo "</canvasArea>"
