class Solution {
public:
    int dist(int x,int y){
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,vector<int>>>maxH;
        for(int i = 0 ; i < points.size() ; i++){
            maxH.push(make_pair(dist(points[i][0],points[i][1]) , points[i] ) );
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        
        vector<vector<int>>ans;
        while(!maxH.empty()){
            ans.emplace_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};