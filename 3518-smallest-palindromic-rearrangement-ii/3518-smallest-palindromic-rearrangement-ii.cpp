class Solution {
    private:
    const long long INF = 1e9;
    long long calc_perms(const vector<int>& freqs) {
        long long res = 1;
        int total = 0;
        for (int f : freqs) {
            if (f == 0) continue;
            total += f;
            res *= nCr(total, f);
            if (res > INF) return INF; 
        }
        return res;
    }
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;
        
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * n / i;
            if (res > INF) return INF; 
            n--;
        }
        return res;
    }
public:
    string smallestPalindrome(string s, int k) {
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        char odd = '?';
        vector<int> freqs(26, 0);
        int half_len = 0;
        
        for (auto it : mp) {
            if (it.second % 2 != 0) {
                odd = it.first;
            }
            freqs[it.first - 'a'] = it.second / 2;
            half_len += it.second / 2;
        }

        if (calc_perms(freqs) < k) {
            return ""; 
        }

        string a = "";
        for (int i = 0; i < half_len; i++) {
            for (int c = 0; c < 26; c++) {
                if (freqs[c] > 0) {
                    freqs[c]--; 
                    long long p = calc_perms(freqs); 
                    
                    if (k <= p) {
                        a += (char)('a' + c);
                        break; 
                    } else {
                        k -= p; 
                        freqs[c]++;
                    }
                }
            }
        }

        string b = a;
        if (odd != '?') {
            b += odd;
        }
        reverse(a.begin(), a.end());
        
        return b + a;
    }
};