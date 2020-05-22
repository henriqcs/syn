#!/bin/sh
read -d '' INPUTS <<- 'EOM'
	N(123)
	N(57)
EOM

for i in $INPUTS; do
	! echo "$i" | ./syn && exit 1
done
exit 0
