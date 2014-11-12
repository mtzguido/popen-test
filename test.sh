#!/bin/bash


echo "Verbose message to stderr" >&2
echo "These will be ignored" >&2

for i in $(seq 1 10); do
	echo "Tick $i"
	sleep 1
done

echo "Done!"
