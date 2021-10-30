function linearSearch(arr, item) {
    // Go through all the elements of arr to look for item.
    for (var i = 0; i < arr.length; i++) {
      if (arr[i] === item) { 
        console.log(i);
      }
    }
    console.log(null);
}

const arr = [1,23,5,9,10];
linearSearch(arr, 20);
