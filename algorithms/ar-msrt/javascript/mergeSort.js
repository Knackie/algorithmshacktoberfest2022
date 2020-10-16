const mergeSort = (nums) => {
    if(nums.length<2){
        return nums;
    }
  
const length = nums.length;
const middle = Math.floor(length/2);
const left = nums.slice(0,middle);
const right = nums.slice(middle,length);
console.log(middle);
return stitch (mergeSort(left) , mergeSort(right));
  
};

const stitch = (left , right) =>{
    const results = [];
    while(left.length && right.length){
        if(left[0] <= right[0]){
            results.push(left.shift());
        }
        else{
            results.push(right.shift());
        }
    }
  return results.concat(left,right);
}