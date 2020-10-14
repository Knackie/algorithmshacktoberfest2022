class LongestPalindromicSubstring {
public:
    string lps(string s) {
        ios::sync_with_stdio(0);
        int mx = 1;
        int st = 0;
        int len = s.length();
        for (int i = 1 ; i < len ; i++) {
            int l = i - 1;
            int h = i;
            while (l >= 0 && h < len && s[l] == s[h]) {
                if (h - l + 1 > mx) {
                    mx = h - l + 1;
                    st = l;
                }
                l--;
                h++;
            }
            l = i - 1;
            h = i + 1;
            while (l >= 0 && h < len && s[l] == s[h]) {
                if (h - l + 2 > mx) {
                    st = l;
                    mx = h - l + 1;
                }
                l--;
                h++;
            }
        }
        return s.substr(st, mx);
    }
};