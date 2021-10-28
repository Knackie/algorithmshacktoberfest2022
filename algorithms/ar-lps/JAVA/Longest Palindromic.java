import java.util.Scanner;

class LongestPalindromicSubstring {
  private static String findLongestPalindromicSubstring(String input) {
    if(input.isEmpty()) {
      return "";
    }
    int n = input.length();
    int longestSoFar = 0, startIndex = 0, endIndex = 0;
    boolean[][] palindrom = new boolean[n][n];
  
    for(int j = 0; j < n; j++) {
      palindrom[j][j] = true;
      for(int i = 0; i < j; i++) {
        if(input.charAt(i) == input.charAt(j) && (j-i <= 2 || palindrom[i+1][j-1])) {
          palindrom[i][j] = true;
          if(j-i+1 > longestSoFar) {
            longestSoFar = j-i+1;
            startIndex = i;
            endIndex = j;
          }  
        }
      }
    }
    return input.substring(startIndex, endIndex+1);
  }
  public static void main(String[] args) {
    Scanner keyboard = new Scanner(System.in);
    String input = keyboard.next();
    System.out.println(findLongestPalindromicSubstring(input));
  }
}