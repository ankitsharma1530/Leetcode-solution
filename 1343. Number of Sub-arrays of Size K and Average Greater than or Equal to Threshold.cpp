class Solution {
public:
    // Time complexity -> O(n)
    // same logic as maximum number in given window
    
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int c = 0;
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if(sum/k>=threshold){
            c++;
        }
        for(int i=k;i<n;i++){
            sum-=arr[i-k];
            sum+=arr[i];
            if(sum/k>=threshold){
                c++;
            }
        }
        return c;
    }
};
