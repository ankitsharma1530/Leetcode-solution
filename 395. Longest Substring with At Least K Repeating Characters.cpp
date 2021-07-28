class Solution {
public:
    // time complexoty -> O(n^2)
    // check for the O(n) time complexity in future revision
    int longestSubstring(string s, int k) {
        if(s.length()==0){
            return 0;
        }
        if(k==0){
            return s.size();
        }
        // divide conquer
        unordered_map<char,int>ump;
        for(auto x:s){
            ump[x]++;
        }
        int i=0;
        int n = s.length();
        while(i<n){
            if(ump[s[i]]<k){
                break;
            }
            i++;
        }
        if(i==n){
            return n;
        }
        int left = longestSubstring(s.substr(0,i),k);
        int right = longestSubstring(s.substr(i+1),k);
        return max(left,right);
    }
};
