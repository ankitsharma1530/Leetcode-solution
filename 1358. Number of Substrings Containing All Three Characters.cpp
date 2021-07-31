class Solution {
public:
    // this is not a easy slinding window
    int numberOfSubstrings(string s) {
        unordered_map<char,int>ump;
        int res = 0;
        int i=0;
        int j=0;
        int n = s.length();
        while(j<n){
            ump[s[j]]++;
            if(ump['a']>0 and ump['b']>0 and ump['c']>0){
                while(ump['a']>0 and ump['b']>0 and ump['c']>0){
                    ump[s[i]]--;
                    i++;
                }
            }
            // logic
/*
 see , we will count how many times a index contribute in a substring
 as "aaabc" so ith=0(it contribute in one substring i.e aaabc), 
        ith=1 (it contribute in two substring-> aaabc, aabc)
        ith=2 (it contribute in three aaabc, aabc, abc)
        
    s = "abcabc"
    ith =0 for 'a' -> it occur one time in "abc"
    ith = 1 for 'b' -> it occure 2 time in "abc","bca"
    ith =2 for 'c' -> it occur 3 time in "abc","bca","cba"
    .
    .
    .
    .
    and so on
*/
            res+=i;
            j++;
        }
        return res;
    }
};
