const primeFactor = num => {
  for (let i = 2; i <= num; i++) {
    if (num % i == 0) {
      while (num % i == 0) {
        console.log(i)
        num /= i;
      }
    }
  }
}

var num = 10005;
primeFactor(num);
