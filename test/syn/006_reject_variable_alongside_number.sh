#!/bin/sh
read -d '' INPUTS <<- 'EOM'
	V(10)N(20)
	N(20)V(10)
EOM

for i in $INPUTS; do
	echo "$i" | ./syn && exit 1
done
exit 0
