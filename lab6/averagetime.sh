#!/bin/bash
#Nathan Nayda
#ntn4jg@virginia.edu
#ntn4jg
#averagetime.sh
#10/20/2015

get_dictionaryname() {
read -r -p 'Enter the name of the dictionary file: ' -s "$1" && echo
}

get_gridname() {
read -r -p 'Enter the name of the grid file: ' -s "$1" && echo
}

get_dictionaryname DICT
get_gridname GRID

value1=`./a.out "$DICT" "$GRID" | tail -1`
value2=`./a.out "$DICT" "$GRID" | tail -1`
value3=`./a.out "$DICT" "$GRID" | tail -1`
value4=`./a.out "$DICT" "$GRID" | tail -1`
value5=`./a.out "$DICT" "$GRID" | tail -1`

 echo $((((value1+value2+value3+value4+value5)/5)))
