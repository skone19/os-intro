#!/bin/bash
typeset -i count=0;
for prov in *.tmp
do rm $prov
done
for ((count=1; count<$1+1; count++))
do
	touch $count.tmp

done
