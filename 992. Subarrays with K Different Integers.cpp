class Solution {
public:
    // We use a different problem to solve this. We find the number of substrings with atmost
    // K unique chars. 
    // substrings with exactly k = atmost unique (K) - atmost unique (K-1)
    // This diff only leaves the substrings with exactly k unique chars
    
    int dfs(vector<int>& nums,int k){
        if(k==0){
            return 0;
        }
        int i=0;
        int j=0;
        unordered_map<int,int>ump;
        int count = 0;
        int total = 0;
        while(j<nums.size()){
            ump[nums[j]]++;
            if(ump[nums[j]]==1){
                count++;
            }
            if(count>k){
                while(count>k){
                    ump[nums[i]]--;
                    if(ump[nums[i]]==0){
                        count--;
                    }
                    i++;
                }
            }
            total += (j-i)+1;
            j++;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return dfs(nums,k)-dfs(nums,k-1);        
    }
};
