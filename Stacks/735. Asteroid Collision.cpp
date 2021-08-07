class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto x:asteroids){
            if(st.empty()){
                st.push(x);
            }
            else{
                if(x<0){
                    if(st.top()>0){
                        if(abs(x)<st.top()){
                            continue;
                        }
                        else{
                            bool f = true;
                            while(!st.empty() and st.top()>0 and f){
                                if(st.top()<abs(x)){
                                    st.pop();
                                }
                                else if(st.top()==abs(x)){
                                    f=false;
                                    st.pop();
                                }
                                else if(st.top()>abs(x)){
                                    f = false;
                                }
                            }
                            if(f)
                                st.push(x);
                        }
                    }
                    else{
                        st.push(x);
                    }
                }
                else{
                    st.push(x);
                }
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
