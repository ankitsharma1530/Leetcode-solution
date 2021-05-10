class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        int size = pushed.size();
        stack<int>s;
        int i = 0;
        while(j<size)
        {
            s.push(pushed[j]);
            while(!s.empty() && i<size && s.top()==popped[i])
            {
                s.pop();
                i++;
            }
            j++;
        }
        return i==size;
    }
};
