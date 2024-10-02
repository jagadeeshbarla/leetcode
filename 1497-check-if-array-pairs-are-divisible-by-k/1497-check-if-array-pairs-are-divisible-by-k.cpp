class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        map<int,int>m;
        for(int i = 0 ; i < arr.size() ; i++){
            int t = (arr[i]%k+k)%k;
            m[t]++;
        }
        map<int,int>::iterator itr;
        for(itr = m.begin() ; itr != m.end() ; itr++){
            int temp1 = itr->first;
            int temp2 = k - itr->first;
            if(temp1 == 0){
                if(m[temp1]%2 ==1){
                    return false;
                }
            }
            else if((m[temp1] != m [temp2])){
                return false;
            }
        }
        return true;
    }
};