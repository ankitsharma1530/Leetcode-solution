class Solution {
public:
    // Refer to lee215
    //link-> https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/JavaC%2B%2BPython-Stack-Solution 
    
    // time complexity -> O(n)
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long res = 0;
        //vector to store number of subarrays to left and to right
        vector<int>left(n);
        vector<int>right(n);
        // stack that gonna used to find the above vector
        stack<pair<int,int>>s1,s2;
        
        //left
        for(int i=0;i<n;i++){
            int count = 1;
            // monotone condn
            while(!s1.empty() and s1.top().first>arr[i]){
                count+=s1.top().second;
                s1.pop();
            }
            s1.push(make_pair(arr[i],count));
            left[i] = count;
        }
        
        // right
        for (int i=n-1;i>=0;--i) {
            int count = 1;
            while(!s2.empty() && s2.top().first >= arr[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], count});
            right[i] = count;
        }
        
        for(int i=0;i<n;i++){
            // left[i] -> the number of subarrays upto a[i] for which a[i] is the min
            // right[i] -> no. of subarrys from a[i] for which a[i] is min
            res = (res+(long)arr[i]*left[i]*right[i])%1000000007;
        }
        return res;
    }
};
