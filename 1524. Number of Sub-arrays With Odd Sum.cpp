class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // time complexity -> O(n)
        int odd = 0;
        int even = 1; // for sum to be ZERo as we initialise ump[0]=1
        int ans = 0;
        int sum =0;
        for(auto x:arr){
            sum+=x;
            if(sum&1){
                ans = (ans+even)%1000000007;
                odd++;
            }
            else{
                ans = (ans+odd)%1000000007;
                even++;
            }
        }
        return ans;
    }
};
