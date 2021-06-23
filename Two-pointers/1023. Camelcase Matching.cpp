class Solution {
public:
    bool solve(string& a, string& b){
        int ind = 0;
        for(auto& x:a){
//We are only allowed to add lower case characters, Upper case must match with pattern
            if(isupper(x) and b[ind]!=x){
                return false;
            }
            else if(b[ind]==x){
                ind++;
            }
        }
        return ind==b.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>res;
        for(auto x:queries){
            if(solve(x,pattern))
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};
