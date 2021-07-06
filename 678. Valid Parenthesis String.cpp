class Solution {
public:
    // O(n) time complecity
    bool checkValidString(string s) {
        // use of two stack as there are two options -> ( or *
        stack<int>open;
        stack<int>cache;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                if(!open.empty()){
                    open.pop();
                }
                else if(!cache.empty()){
                    cache.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else{
                cache.push(i);
            }
        }
        
        while(!open.empty() and !cache.empty()){
            if(open.top()>cache.top()){
                return false;
            }
            open.pop();
            cache.pop();
        }
        return open.empty();
    }
};
