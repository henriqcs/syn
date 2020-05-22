#!/bin/sh
read -d '' INPUTS <<- 'EOM'
	((N(1))
	((N(1)))+((N(2))))
	(N(1))+((V(0))+N(2)
	(N(1))+((V(0))+N(2)))
	((N(100)/(N(200))-(N(300)))
	((N(100)/(N(200))-(N(300)))))
EOM

for i in $INPUTS; do
	echo "$i" | ./syn && exit 1
done
exit 0
