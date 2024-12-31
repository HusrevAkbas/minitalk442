#! /bin/bash
PID=memcheck
S1=-SIGUSR1
S2=-SIGUSR2
WORD=001100000111001101110101011001000110111100000000 #sudo
EXIT=001100000110010101111000011010010111010000000000 #exit
MAX=48
i=0
#send word

while [ $i -lt $MAX ]
do
	sleep 0.00001
	if [ ${WORD:i:1} -eq 1 ]
	then
		pkill $S1 $PID
		echo "$S1 $PID"
	else
		pkill $S2 $PID
		echo "$S2 $PID"
	fi
	true $(( i=i+1 ))
done
#send exit
sleep 5
i=0
while [ $i -lt $MAX ]
do
	sleep 0.00001
	if [ ${EXIT:i:1} -eq 1 ]
	then
		pkill $S1 $PID
		echo "$S1 $PID"
	else
		pkill $S2 $PID
		echo "$S2 $PID"
	fi
	true $(( i=i+1 ))
done