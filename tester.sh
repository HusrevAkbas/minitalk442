#! /bin/bash
PID=memcheck
S1=-SIGUSR1
S2=-SIGUSR2
WORD=0111001101110101011001000110111101101111 #sudoo
EXIT=0110010101111000011010010111010000000000 #exit
MAX=40
i=0
WORDCOUNT=2000 #25000
WORDI=0
#send word
# echo "sudo"
# while [ $WORDI -lt $WORDCOUNT ]
# do
# 	true $(( i=0 ))
# 	while [ $i -lt $MAX ]
# 	do
# 		if [ ${WORD:i:1} -eq 1 ]
# 		then
# 			pkill $S1 $PID
# 		else
# 			pkill $S2 $PID
# 		fi
# 		true $(( i=i+1 ))
# 	done
# echo "wordsent $WORDI"
# true $(( WORDI=WORDI+1 ))
# done
#send exit
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
sleep 2
i=0
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