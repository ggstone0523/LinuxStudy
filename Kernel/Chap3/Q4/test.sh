#!/bin/bash

s=$1
e=$2

if [[ -z "$s" || -z "$e" ]]; then
	echo "Usage: $0 start end"
	exit 1
fi

for ((i=s; i<=e; i++)); do
	./task.sh $i &
done
