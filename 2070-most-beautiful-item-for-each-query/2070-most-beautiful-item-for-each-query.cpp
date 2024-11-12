class Solution {
public:
    int index(int base,vector<vector<int>>& items,vector<int>&v){
        int inc = base,base_val = items[base][0];
        int max_val = items[base][1];
        while(inc < items.size() && items[inc][0] == base_val){
            max_val = max(v[inc],max_val);
            inc++;
        }
        int dec = base;
        while(dec >= 0 && items[dec][0] == base_val){
            max_val = max(v[dec],max_val);
            dec--;
        }
        return max_val;
    }
    int getindex(vector<vector<int>>& items,int val){
        //apply binay search and give the index of item whose item[i][1] <= val
        int l = 0 , h = items.size()-1;
        while(h >= l){
            int mid = (h+l)/2;
            if(items[mid][0] == val){
                return mid;
            }
            else if(items[mid][0] > val){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return getindex(items,val-1);
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int>v(1,items[0][1]);
        for(int i = 1 ; i < items.size() ; i++){
            v.emplace_back(max(v[v.size()-1] , items[i][1]));
        }
        for(int i = 0 ; i < queries.size() ; i++){
            if(queries[i] < items[0][0]){
                queries[i] = 0;
            }
            else if(queries[i] > items[items.size()-1][0]){
                queries[i] = index(items.size()-1,items,v);
            }
            else{
                int ii = getindex(items,queries[i]);
                queries[i]= index(ii,items,v);
            }
        }
        return queries;
        
    }
};