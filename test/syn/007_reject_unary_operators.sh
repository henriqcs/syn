#!/bin/sh
read -d '' INPUTS <<- 'EOM'
	-N(20)
	N(20)*
	(N(1)+)+(N(2))
	(+)
	++
	N(1)+-N(2)
EOM

for i in $INPUTS; do
	echo "$i" | ./syn && exit 1
done
exit 0
