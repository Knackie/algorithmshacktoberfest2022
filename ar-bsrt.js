function bubbleSort(values){
    let n = values.length
    for( i =0; i < n -1; i++){
      for(j =0; j < n -1; j++){
        if(values[j] > values[j+1]){
          let temp = values[j]
          values[j] = values[j+1];
          values[j+1] = temp;
        }
      }
    }
      for(l = 0; l < n; l++)
        {
          console.log(values[l])
        }
}
let hello  = [10, 21,2,4,78]
bubbleSort(hello)