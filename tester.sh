#! /bin/bash
PID=memcheck
S1=-SIGUSR1
S2=-SIGUSR2
WORD=0111001101110101011001000110111100000000 #sudo
EXIT=0110010101111000011010010111010000000000 #exit
MAX=40
i=0
#send word
echo "sudo"
while [ $i -lt $MAX ]
do
	if [ ${WORD:i:1} -eq 1 ]
	then
		pkill $S1 $PID
	else
		pkill $S2 $PID
	fi
	true $(( i=i+1 ))
done
#send exit
sleep 2
i=0
echo "exit"
while [ $i -lt $MAX ]
do
	if [ ${EXIT:i:1} -eq 1 ]
	then
		pkill $S1 $PID
	else
		pkill $S2 $PID
	fi
	true $(( i=i+1 ))
done