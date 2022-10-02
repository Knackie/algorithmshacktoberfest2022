let input = [1,2,3,4]
input = shuffle(input)
var shuffleCount = 0;
function bogosort(arr:number[]){
    while (!iSsorted(arr)) {
        shuffleCount++;
        arr = shuffle(arr);
      }
    return {shuffleCount, arr} 
}

function iSsorted(array:number[]) {
    for (var i = 0; i < array.length - 1; i++) {
      if (array[i] <= array[i + 1]) {
        continue;
      } else {
        return false;
      }
    }
    return true
  }

function shuffle(arr:number[]) {
  return arr.sort(() => Math.random() - 0.5);
}

let solve = bogosort(input)
console.log(`Finished within ${solve.shuffleCount} | ${solve.arr.join(",")}`)