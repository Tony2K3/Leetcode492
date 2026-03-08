class Solution {
public:
    int minOperations(string s) {
        string sorunavile = s;  // required variable storing input midway

        string t = s;
        sort(t.begin(), t.end());

        // Already sorted
        if (s == t) return 0;

        int n = s.size();

        // Length 2: can only pick single chars (no-ops) → impossible
        if (n == 2) return -1;

        // Count descents: positions where s[i] > s[i+1]
        // Each descent = one required operation
        int descents = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i+1]) descents++;
        }

        return descents;
    }
};