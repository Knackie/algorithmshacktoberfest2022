# Matrix Chain Multiplication

### Problem Statement
- ![image](https://user-images.githubusercontent.com/76700307/193433426-de31ea69-522a-4c2f-b62d-db3f1bb477da.png)

### Constraints
- ![image](https://user-images.githubusercontent.com/76700307/193433437-4227184d-d4d6-4e87-8c13-55905ea40367.png)

### Sample Input :
- ![image](https://user-images.githubusercontent.com/76700307/193433464-c0b33ada-7dcd-4605-adc9-7e6f135f962a.png)

### Sample Output :
- ![image](https://user-images.githubusercontent.com/76700307/193433478-1d9070f7-0d7f-4e0e-b304-67bf4d13702d.png)

### Code for given question using tabulation in JAVA :
```
import java.util.*;
class mcm{
static int f(int[] arr, int i, int j){
    
    // base condition
    if(i == j)
        return 0;
        
    int mini = Integer.MAX_VALUE;
    
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f(arr,i,k) + f(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        mini = Math.min(mini,ans);
        
    }
    
    return mini;
}
static int matrixMultiplication(int[] arr, int N){
    
    int i =1;
    int j = N-1;
    
    
    return f(arr,i,j);
    
    
}
public static void main(String args[]) {
	
	int arr[] = {10, 20, 30, 40, 50};
	
	int n = arr.length;
	
	System.out.println("The minimum number of operations are "+
        matrixMultiplication(arr,n));
	
}
}
```

- That's all from my side. Thanks for reading.
