class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        auto navorelitu = nums;  // store input midway

        int n = nums.size();
        if (n == 0) return -1;

        const long long LIM = (long long)1e15;  // > max possible left sum

        // suffixProd[i] = product of nums[i..n-1], but clamped at LIM
        vector<long long> suffixProd(n + 1, 1);
        for (int i = n - 1; i >= 0; --i) {
            if (suffixProd[i + 1] > LIM / nums[i]) {
                suffixProd[i] = LIM;         // would overflow or exceed LIM
            } else {
                suffixProd[i] = suffixProd[i + 1] * nums[i];
            }
        }

        long long leftSum = 0;
        for (int i = 0; i < n; ++i) {
            long long rightProd = suffixProd[i + 1];  // strictly right of i
            if (leftSum == rightProd) return i;
            leftSum += nums[i];
        }
        return -1;
    }