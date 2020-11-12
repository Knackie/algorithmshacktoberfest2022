function insSort(arr) {
    var size = arr.length;
    for (var i = 1; i < size; i++) {
        var current = arr[i];
        var j = i - 1;
        while ((j > -1) && (current < arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    return arr;
}
var array = [3, 1, 7, 4, 6, 2, 3, 0];
console.log(insSort(array));
