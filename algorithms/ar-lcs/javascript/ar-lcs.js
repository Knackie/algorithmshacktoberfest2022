
function lcs(a, b){
    var m = a.length, n = b.length, i, j, l = [];
    for(i = 0; i <= m; i++){
        l[i] = [];
        for(j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                l[i][j] = 0;
            }else if(a[i-1] == b[j-1]){
                l[i][j] = l[i-1][j-1] + 1;
            }else{
                l[i][j] = Math.max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    return l[m][n];
}

let a = [1,2,3,4,5,6,7,8,9,0];
let b = [2,4,6,7,9,10];

console.log(lcs(a, b));