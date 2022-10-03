function change(coins, i, amount) {
  if (amount === 0) {
    return 1;
  }
  if (amount < 0) {
    return 0;
  }
  if (i <= 0) {
    return 0;
  }

  return (
    change(coins, i - 1, coins[i - 1]) + change(coins, i, amount - coins[i - 1])
  );
}
let coinArr = [1, 2, 3];
console.log(change(coinArr, coinArr.length, 4));
