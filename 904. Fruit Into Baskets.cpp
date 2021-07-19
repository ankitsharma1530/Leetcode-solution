class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = 0;
        int i=0;
        int j=0;
        int n = fruits.size();
        unordered_map<int,int>ump; // value with index
        int count = 0;
        while(j<n){
            ump[fruits[j]]++;
            if(ump[fruits[j]]==1){
                count++;
            }
            if(count>2){
                ump[fruits[i]]--;
                if(ump[fruits[i]]==0){
                    count--;
                }
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};
