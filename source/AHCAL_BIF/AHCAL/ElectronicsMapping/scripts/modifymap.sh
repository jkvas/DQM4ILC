#!/bin/bash

# You need to provide one layer xml file: geometry_layer1.txt
# and the chip ID of all asic-1 id for the different layers

CHIP1_2=241
CHIP1_3=245
CHIP1_4=121
CHIP1_5=117
CHIP1_6=249
CHIP1_7=233
CHIP1_8=225
CHIP1_9=217
CHIP1_10=213
CHIP1_11=205
CHIP1_12=221
CHIP1_13=201
CHIP1_14=209
CHIP1_15=229

LAYER=2

for i in `seq 2 15`; 
do  
    CHIP1=$((CHIP1_$i))
    CHIP2=$((CHIP1+1))
    CHIP3=$((CHIP1+2))
    CHIP4=$((CHIP1+3))
    echo $CHIP1 $CHIP2 $CHIP3 $CHIP4

    /bin/cp -f $PWD/geometry_layer1.txt $PWD/geometry_layer$LAYER.txt
    sed -i "s/237/$CHIP1/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/238/$CHIP2/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/239/$CHIP3/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/240/$CHIP4/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/k=\"1\"/k=\"$LAYER\"/g" $PWD/geometry_layer$LAYER.txt
    let LAYER=LAYER+1
done

for i in `seq 1 15`;

do
if [ $i -lt 10 ] 
    then cat geometry_layer$i.txt > map.xml
fi
if [ $i -gt 9 ]
    then cat geometry_layer$i.txt > map.xml
fi

done
