function kadane(arr) {
  let max = 0;
  let maxSoFar = 0;
  for (let i = 0; i < arr.length; i++) {
    maxSoFar = Math.max(0, maxSoFar + arr[i]);
    max = Math.max(max, maxSoFar);
  }
  return max;
}

const arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
console.log(kadane(arr));