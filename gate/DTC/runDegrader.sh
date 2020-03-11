#!/bin/bash

#for i in `seq -w 1 1 330`; do
#   tsp /build/gate/Gate-8.2reducedRootOutput-install/bin/Gate -a "'[energy,230] [degraderthickness,$i]'" Main_chip.mac
#   echo "Running PROTON degrader thickness = $i mm"
#done

for i in `seq -w 160 1 160`; do
   # tsp /build/gate/Gate-8.2reducedRootOutput-install/bin/Gate -a "'[energy,917] [degraderthickness,$i]'" Main_He_chip.mac
   ~/gate/Gate-8.2custom-install/bin/Gate -a "'[energy,917] [degraderthickness,$i]'" Main_He_chip.mac
   echo "Running HELIUM degrader thickness = $i mm"
done
