ines (15 sloc) 328 Bytes
#!/bin/bash

declare -a arr
echo "Enter the elements of the array: "
read -ra arr

n=${#arr[@]}

for((i=1;i<n;i++)); do
    k=${arr[$i]}
    j=$((i-1))
    while [[ $j -ge 0 && ${arr[$j]} -gt $k ]]; do
        arr[$((j+1))]=${arr[$j]}
        j=$((j-1))
    done
    arr[$((j+1))]=$k
done

echo -e "Array after sort:\n${arr[@]}"
