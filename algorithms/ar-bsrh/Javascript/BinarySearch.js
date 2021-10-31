function binarySearch(arr,x){
    var l=0,r=arr.length-1;
    while(l<=r){
        var mid = Math.floor(l+(r-l)/2);
        if(arr[mid]===x){
            return mid;
        }
        else if(arr[mid]>x){
            r=mid-1;
        }
        else l=mid+1;
    }
    return -1;
}

function main(){
    var a = [1,2,3,4,5];
    if(binarySearch(a,4)===-1){
        console.log("Element not found.");
    }
    else {
        console.log(`Element found at ${binarySearch(a,4)}`)
    }
}

main();