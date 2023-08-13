class Solution {
public:
    vector<string> topKFrequent(vector<string>& w, int k) {
        map<string,int>msc;
        for(int i=0;i<w.size();i++)
        {
            msc[w[i]]+=1;
        }
        
        map<int,vector<string>>m;
        map<string,int>::iterator it;
        
        for(it=msc.begin();it!=msc.end();it++)
        {
            m[it->second].emplace_back(it->first);
        }
        
        
        
        vector<string>ans; 
        
        map<int,vector<string>>::iterator mit;
        for(mit = m.begin();mit!=m.end();mit++)
        {
            sort(mit->second.begin(),mit->second.end());
        }
        mit--;
        while(1)
        {
            for(int i=0;i<mit->second.size();i++)
            {
                ans.emplace_back(mit->second[i]);
            }
            
            if(mit==m.begin())
            {
                break;
            }
            mit--;
        }
        vector<string>fans;
        int i=0;
        while(k>0)
        {
            fans.emplace_back(ans[i]);
            i++;
            k--;
        }
        return fans;    

    }
};