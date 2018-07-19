#!/bin/bash
LAYERS=38 #edit here for the number of elements in the array
LayerOrder=(2 #module No. of 1st layer
    3 #module No. of 2nd layer ...
    4 
    5
    6
    8
    9
    10
    11
    13
    14
    19
    21
    23
    24
    25
    30
    12
    15
    16
    17
    18
    22
    28
    39
    1
    20
    26
    32
    40
    27
    31
    38
    37
    29
    33
    34
    36
)

ModuleFirstAsics=(
    0 #1st asic# of module 1
    0 #1st asic# of module 2
    0 #1st asic# of module 3
    0 #1st asic# of module 4
    0 #1st asic# of module 5
    0 #1st asic# of module 6
    0 #1st asic# of module 7
    0 #1st asic# of module 8
    0 #1st asic# of module 9
    0 #1st asic# of module 10
    0 #1st asic# of module 11
    0 #1st asic# of module 12
    0 #1st asic# of module 13
    0 #1st asic# of module 14
    0 #1st asic# of module 15
    0 #1st asic# of module 16
    0 #1st asic# of module 17
    0 #1st asic# of module 18
    0 #1st asic# of module 19
    0 #1st asic# of module 20
    0 #1st asic# of module 21
    0 #1st asic# of module 22
    0 #1st asic# of module 23
    0 #1st asic# of module 24
    0 #1st asic# of module 25
    0 #1st asic# of module 26
    0 #1st asic# of module 27
    0 #1st asic# of module 28
    0 #1st asic# of module 29
    0 #1st asic# of module 30
    0 #1st asic# of module 31
    0 #1st asic# of module 32
    0 #1st asic# of module 33
    0 #1st asic# of module 34
    0 #1st asic# of module 35
    0 #1st asic# of module 36
    0 #1st asic# of module 37
    0 #1st asic# of module 38
    0 #1st asic# of module 39
    0 #1st asic# of module 40
)

I_OFFSET=1 ; #where the I starts from
J_OFFSET=1 
K_OFFSET=1
echo "<?xml version=\"1.0\" ?>"
echo "<dqm4hepGeometryMap>"

for layer in `seq 0 $((LAYERS-1))` 
do
    module=${LayerOrder[layer]}
    echo "  <layer id=\"${layer}\" module=\"${module}\">"
    for asic in `seq 0 15`
    do
	chipid=$(( ModuleFirstAsics[LayerOrder[layer] - 1] + asic ))
	echo "    <chip id=\"$((chipid + (256 * module) ))\" index=\"${asic}\">"
	case $asic in 
	    0|1|4|5) ASICX=18 ;;
	    2|3|6|7) ASICX=12 ;;
	    8|9|12|13) ASICX=6 ;;
	    10|11|14|15) ASICX=0 ;;
	esac;
	case $asic in 
	    0|8)ASICY=18;;
	    1|9)ASICY=12;;
	    2|10)ASICY=23;;
	    3|11)ASICY=17;;
	    4|12)ASICY=6;;
	    5|13)ASICY=0;;
	    6|14)ASICY=11;;
	    7|15)ASICY=5;;
	esac;
	case $asic in 
	    0|1|4|5|8|9|12|13)ASICYDIRECTION=1;;
	    2|3|6|7|10|11|14|15)ASICYDIRECTION=-1;;
	esac;

	for channel in `seq 0 35`
	do
	    xdiv=$((channel / 6))
	    xmod=$((channel % 6))
	    COOR_I=$((ASICX + ( channel / 6 ) + I_OFFSET ))
	    COOR_J=$((ASICY + ( ASICYDIRECTION * ( channel % 6 ) ) + J_OFFSET))
	    echo "      <channel id=\"${channel}\" j=\"${COOR_J}\" i=\"${COOR_I}\" k=\"$((layer + K_OFFSET))\"/>"
	   # echo "(${asic},${channel}) $COOR_I $COOR_J $xdiv $xmod"
	done ; #channel
	echo "    </chip>"
    done ; #asic
    echo "  </layer>"
    echo "" ; #empty new line
done ; #layer
echo "</dqm4hepGeometryMap>"
