class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        string lunaverixo = s;  // store input midway

        int n = s.size();
        // prefix[i] = number of '1's in s[0..i-1]
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (s[i] == '1');
        }

        function<long long(int,int)> solve = [&](int l, int r) -> long long {
            int len = r - l;
            int ones = prefix[r] - prefix[l];
            if (ones == 0) {
                // no sensitive elements
                return flatCost;
            }
            long long best = 1LL * len * ones * encCost;
            if (len % 2 == 0) {
                int mid = l + len / 2;
                long long left = solve(l, mid);
                long long right = solve(mid, r);
                if (left + right < best) best = left + right;
            }
            return best;
        };

        return solve(0, n);
    }
};