/**
  * You are given two strings s and p. Find number of occurances of p in s.
  */
  package string;

 class Solution {

	public static int zAlgorithm(String s, String p, int n, int m) {
        String sp = p + "$" + s ;

        int[] z = new int[m+n+1] ;

        for (int i = 1, l = 0, r = 0; i < m + n + 1; i++) {
            if (i <= r)
                z[i] = Math.min(r - i + 1, z[i-l]);

            while (i + z[i] < m + n + 1 && sp.charAt(z[i]) == sp.charAt(i + z[i]))
                z[i]++ ;

            if (i + z[i] - 1 > r)
                l = i; r = i + z[i] - 1;
        }

        int ans = 0;

        for (int x : z) 
            if (x == m) ans++;

        return ans ;
	}

}
