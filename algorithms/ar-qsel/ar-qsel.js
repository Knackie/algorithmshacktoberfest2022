function quickSelect(arr, k) {
    if (k < 0 || k > arr.length - 1) {
        return null;
    }
    return quickSelectHelper(arr, 0, arr.length - 1, k);
}

function quickSelectHelper(arr, left, right, k) {
    if (left === right) {
        return arr[left];
    }
    const pivot = partition(arr, left, right);
    if (pivot === k) {
        return arr[pivot];
    } else if (pivot > k) {
        return quickSelectHelper(arr, left, pivot - 1, k);
    } else {
        return quickSelectHelper(arr, pivot + 1, right, k);
    }
}

function partition(arr, left, right) {
    const pivot = arr[right];
    let i = left;
    for (let j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, right);
    return i;
}

function swap(arr, i, j) {
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(quickSelect(arr, 5));
