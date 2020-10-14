function selectionSortTS(inputArr: number[]): number[] {
  const arrLength = inputArr.length

  for (let i = 0; i < arrLength; i++) {
    let lowestIdx: number = i

    // find the lowest
    for (let j = i + 1; j < arrLength; j++) {
      if (inputArr[lowestIdx] > inputArr[j]) {
        lowestIdx = j
      }
    }

    if (lowestIdx !== i) {
      // swap array value
      let temp: number = inputArr[i]
      inputArr[i] = inputArr[lowestIdx]
      inputArr[lowestIdx] = temp
    }
  }
  return inputArr
}
const arrExampleTS: number[] = [1, 5, 2, 4, 6, 3]
console.log(selectionSort(arrExample)) // [1, 2, 3, 4, 5, 6]