const shellSort = (arr) => {
	let n = arr.length;

	for (let gap = Math.floor(n/2); gap > 0; gap = Math.floor(gap/2))	{
		for (let i = gap; i < n; i += 1)  {
			let temp = arr[i];
			
			let j;
			for (j = i; j >= gap && arr[j-gap] > temp; j-=gap)  {
				arr[j] = arr[j-gap];
			}

			arr[j] = temp;
		}
	}

	return arr;
}

const array = [1, 5, 6, 2, 0, 100, 15, 12, 19]

const preSorted = `Unsorted array = ${array}`
const sorted = `Sorted array = ${shellSort(array)}`

console.log(preSorted + "\n" + sorted);