const QuickSort = (list)=>{
    
    const length = list.length;
    const pivot = list[length-1];
    const left = [];
    const right = []

    if(list.length <= 1) return list ;
    
    for(let i = 0 ; i < length-1 ; i++){

        if(list[i] < pivot){
            left.push(list[i]);
        }

        else{
            right.push(list[i])
        }
    }

    return [...QuickSort(left) , pivot , ...QuickSort(right)];
} 