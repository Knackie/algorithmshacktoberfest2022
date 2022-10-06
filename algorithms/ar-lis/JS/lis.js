let arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
let Ln = arr.length-1;
let LIS = []

for(let i = 0; i<=Ln; i++){
    LIS[i] = 1;
}

for(let i =1; i<=Ln; i++){
    for(let j=0; j <= i; j++){
        if(arr[j] < arr[i] && LIS[i] < LIS[j]+1 ){
            LIS[i] = LIS[j]+1; 
        }
    }
}

console.log(`Max Length is ${Math.max.apply(null,LIS)}`)