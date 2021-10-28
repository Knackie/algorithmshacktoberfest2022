/** 
 * @function cutRod Function that determines the maximum value obtainable by cutting 
 * the rods into different pieces.
 * @param {Array} price : An array containing prices of the rod at lengths 1 to n.
 * @param {Number} n : The length of the given rod 
 * @returns {Number} The maximum anount obtainable by cutting the rod into 
 * different pieces.
*/
function cutRod(price, n) {
    let val = new Array(n + 1);
    val[0] = 0;

    // Build the table val[] in
    // bottom up manner and return
    // the last entry from the table
    for (let i = 1; i <= n; i++) {
        let max_val = Number.MIN_VALUE;
        for (let j = 0; j < i; j++)
            max_val = Math.max(max_val, price[j] + val[i - j - 1]);
        val[i] = max_val;
    }

    return val[n];
}

// driver code
let arr = [1, 5, 8, 9, 10, 17, 17, 20];
let size = arr.length;
console.log("Cutting Rod Problem: ");
console.log("Highest amount that can be obtained = " + cutRod(arr, size));