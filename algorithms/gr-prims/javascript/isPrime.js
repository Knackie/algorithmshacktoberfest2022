// program to check if a number is prime or not

function isPrime(n) {
	let flag = true

	for (let i = 2; i <= n - 1; i++)
		if (n % i == 0) {
			flag = false
			break
		}

	if (flag) return true

	return false
}

console.log(isPrime(2)) // true
console.log(isPrime(4)) // false
console.log(isPrime(7)) // true
