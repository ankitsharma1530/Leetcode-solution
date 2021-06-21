class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int curr = 0;
        int total = 0;
        unordered_map<int,int>ump;
        ump[0]=1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            curr+=nums[i];
            total+=ump[curr-goal];
            ump[curr]++;
        }
        return total;
    }
};
