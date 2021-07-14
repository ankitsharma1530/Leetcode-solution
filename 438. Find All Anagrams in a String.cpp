class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(s.length()<p.length()){
            return res;
        }
        vector<int>a(26,0),b(26,0);
        // first we traversed upto the length of the P
        // we count each occurence of the character in the both strings
        for(int i=0;i<p.length();i++){
            a[s[i]-'a']++;
            b[p[i]-'a']++;
        }
        
        // if their map got matched then the 0th index will be the first ans
        if(a==b){
            res.push_back(0);
        }
        
        // then we traverse for rest of the string
        // decrement the left most charcter of the window
        // and incrementing the rifht most charcter which gonna add in the window
        for(int i=p.length();i<s.length();i++){
            a[s[i]-'a']++;
            a[s[i-p.length()]-'a']--;
            if(a==b){
                // if pattern macthes with this window
                // just push the starting point of the window
                res.push_back(i-p.length()+1);
            }
        }
        return res;
    }
};438. Find All Anagrams in a String
