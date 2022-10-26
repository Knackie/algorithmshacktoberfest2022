linear-search.sh

#!/bin/bash

# Delcare array
declare -a arr

echo "Enter space separated integers"
read -a arr

totalElements=${#arr[@]}

echo "Enter element to be searched for:"
read search

index=-1
for ((i = 0; i < totalElements; i++)); do
	if [ ${arr[i]} -eq $search ]; then
		index=$i
	fi
done

if [ $index -ne -1 ]; then
	echo "Element found at index $((index + 1))"
else
	echo "Element not found"
fi
