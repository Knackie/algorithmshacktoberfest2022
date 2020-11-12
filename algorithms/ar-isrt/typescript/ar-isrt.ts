function insSort(arr:Array<number>):Array<number>{
    let size = arr.length
    for (let i = 1; i < size; i++) {
        let current = arr[i];
        let j = i-1; 
        while ((j > -1) && (current < arr[j])) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    return arr
}

let array = [3,1,7,4,6,2,3,0]
console.log(insSort(array))