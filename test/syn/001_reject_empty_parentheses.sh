#!/bin/sh
read -d '' INPUTS <<- 'EOM'
	()
EOM

for i in $INPUTS; do
	echo "$i" | ./syn && exit 1
done
exit 0
