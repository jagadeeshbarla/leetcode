class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        map<string,int>m;
        
        string temp = "";
        for(int i = 0 ; i < 10 ; i++)
        {
            temp+=s[i];
        }
        m[temp]+=1;
        for(int i = 10; i < s.length() ; i++)
        {
            temp.erase(0,1);
            temp+=s[i];
            m[temp]+=1;
        }
        
        map<string,int>::iterator itr;
        for(itr = m.begin() ; itr != m.end() ;itr++)
        {
            //cout<<itr->first <<" "<<itr->second<<endl;
            if(itr->second > 1)
            {
                ans.emplace_back(itr->first);
            }
        }
        return ans;
    }
};