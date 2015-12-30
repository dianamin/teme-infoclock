/*
    https://leetcode.com/problems/3sum-closest/
*/

class Solution {
public:
    inline int modul(int x) {
        if (x < 0) return (-1) * x;
        return x;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sol = 0;
        bool unset = true;
        int j, k;

        int current_sum;
        int new_target;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            new_target = target - nums[i];

            j = i + 1;
            k = n - 1;

            while (j != k) {
                current_sum = nums[j] + nums[k];
                if (unset || modul(new_target - current_sum) <= modul(target - sol)) {
                    sol = current_sum + nums[i];
                    unset = false;
                }
                if (current_sum < new_target) j++;
                else k--;
            }
        }

        return sol;
    }
};
