#!/usr/bin/env bash
cnt=1
while true; do
		source code.sh > error.log 2>&1
		if [[ $? -eq 1 ]]
		then
				break
		else
				echo "the shell runs good"
		fi
		echo "run $cnt times"
		cnt=$[$cnt+1]
done
