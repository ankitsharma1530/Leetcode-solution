class Solution {
public:
    // time complexity -> O(26*n)
    // sliding window
    int characterReplacement(string s, int k) {
        // we will make a sliding window and we will count the occurence of each                 // character in that window . 
        // eg -> S = "ababa"  --> ump[a] = 3 and ump[b] = 2
        // now greedily we can think that if we make the string having all characters 
        // as "a" -> then it will cost us 2 updates
        //  if we make the string having all characters as "b" -> cost 3 updates
        
        
        // hence we will always try to make the every character of string equal to most         // ocurring element in the window.
        int left = 0;
        int right = 0;
        int len_ans = 0;
        unordered_map<char,int>ump;
        int n = s.length();
        while(right<n){
            ump[s[right]]++;
            int max_occur = -1;
            
            // finding the maximum occuring character in the current window
            for(auto& x:ump){
                max_occur = max(max_occur,x.second);
            }
            if((right-left+1)-max_occur>k){
                // if this is the faulty case then update the window
                // and find the maximum_updated value of most occuring character
                while((right-left+1)-max_occur>k){
                    ump[s[left]]--;
                    for(auto& x:ump){
                        max_occur = max(max_occur,x.second);
                    }
                    left++;
                }
            }
            len_ans = max(len_ans,right-left+1);
            right++;
        }
        return len_ans;
    }
};
