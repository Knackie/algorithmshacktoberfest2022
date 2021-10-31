import java.util.Scanner;

class Main {
  /**
  *Using Dynamic Programming
  *@param int //Amount of value
  *@param int[] //Number values to add to amount
  **/
  public static int coinChange(int n, int[] coins){
    int[] ways = new int[n+1];
    ways[0] = 1;
    for(int i=0; i<coins.length; i++){
      for(int j=1; j<n+1; j++){
        if(j >= coins[i]){
          ways[j] += ways[j-coins[i]];
        }
      }
    }
    return ways[n];
  }

  public static void main(String[] args) {
    int value;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter change -> ");
    value = sc.nextInt();
    System.out.print("Amount of coins -> ");
    int[] coins = new int[sc.nextInt()];
    System.out.println("Coin values: ");
    for(int i=0; i < coins.length; i++){
      int coin = sc.nextInt();
      coins[i] = coin;
    }
    System.out.print("Total combinations: ");
    System.out.println(coinChange(value, coins));
  }
}