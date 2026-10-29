class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                mp[nums[i]]++;
            }
        }
        int ans = -1, maxFreq = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > maxFreq) {
                maxFreq = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};

