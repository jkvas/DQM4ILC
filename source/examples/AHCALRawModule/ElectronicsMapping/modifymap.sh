#!/bin/bash
CHIP1=241
CHIP1=245
CHIP1=121
CHIP1=117
CHIP1=249
CHIP1=233
CHIP1=225
CHIP1=217
CHIP1=213
CHIP1=205
CHIP1=221
CHIP1=201
CHIP1=209
CHIP1=229

LAYER=2
for i in `seq 2 15`; 
do  
    echo $i
    CHIP1=241 
    CHIP2=242 
    CHIP3=243 
    CHIP4=244
    if [ $i -eq "3" ]
    then  
	CHIP1=245
	CHIP2=246
	CHIP3=247
	CHIP4=248
    fi
    if [ $i -eq "4" ]
    then  
	CHIP1=121
	CHIP2=122
	CHIP3=123
	CHIP4=124
    fi
    if [ $i -eq "5" ]
    then  
	CHIP1=117
	CHIP2=118
	CHIP3=119
	CHIP4=120
    fi
    if [ $i -eq "6" ]
    then  
	CHIP1=249
	CHIP2=250
	CHIP3=251
	CHIP4=252
    fi
    if [ $i -eq "7" ]
    then  
	CHIP1=233
	CHIP2=234
	CHIP3=235
	CHIP4=236
    fi
    if [ $i -eq "8" ]
    then  
	CHIP1=225
	CHIP2=226
	CHIP3=227
	CHIP4=228
    fi
    if [ $i -eq "9" ]
    then  
	CHIP1=217
	CHIP2=218
	CHIP3=219
	CHIP4=220
    fi
    if [ $i -eq "10" ]
    then  
	CHIP1=213
	CHIP2=214
	CHIP3=215
	CHIP4=216
    fi
    if [ $i -eq "11" ]
    then  
	CHIP1=205
	CHIP2=206
	CHIP3=207
	CHIP4=208
    fi
    if [ $i -eq "12" ]
    then  
	CHIP1=221
	CHIP2=222
	CHIP3=223
	CHIP4=224
    fi
    if [ $i -eq "13" ]
    then  
	CHIP1=201
	CHIP2=202
	CHIP3=203
	CHIP4=204
    fi
    if [ $i -eq "14" ]
    then  
	CHIP1=209
	CHIP2=210
	CHIP3=211
	CHIP4=212
    fi
    if [ $i -eq "15" ]
    then  
	CHIP1=229
	CHIP2=230
	CHIP3=231
	CHIP4=232
    fi

    echo $CHIP1 $CHIP2 $CHIP3 $CHIP4


    /bin/cp -f $PWD/geometry_layer1.txt $PWD/geometry_layer$LAYER.txt
    sed -i "s/237/$CHIP1/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/238/$CHIP2/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/239/$CHIP3/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/240/$CHIP4/g" $PWD/geometry_layer$LAYER.txt
    sed -i "s/k=\"1\"/k=\"$LAYER\"/g" $PWD/geometry_layer$LAYER.txt
    let LAYER=LAYER+1
done
