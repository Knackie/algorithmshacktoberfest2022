function heapify(arr, n, i) {
    let largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;

    if (left < n && arr[left] > arr[i]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        aux = arr[i];
        arr[i] = arr[largest];
        arr[largest] = aux;
        heapify(arr, n, largest);
    }
}

function heapsort(arr) {
    let n = arr.length;

    for (i = Math.floor(n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--) {
        aux = arr[i];
        arr[i] = arr[0];
        arr[0] = aux;
        heapify(arr, i, 0);
    }
}

let arr = [12, 11, 13, 5, 6, 7, 22];
heapsort(arr);

for (i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}
