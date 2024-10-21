class Solution {
    int max_size = 0;
    void fun(int index, string curr, string s, unordered_set<string>flag){
        if(index == s.size() ){
            if(flag.size() > max_size){
                max_size = flag.size();
            }
            return;
        }
        // Create a new entity 
        int index_1 = index;
        string new_curr = "";
        new_curr = s[index_1++];
        while(index_1 < s.size() && flag.find(new_curr) != flag.end()){
            new_curr += s[index_1++];
        }
        if(flag.find(new_curr) == flag.end()){
            flag.insert(new_curr);
            fun(index_1,new_curr,s,flag);
            flag.erase(new_curr);
        }
        if(index == 0){
            return;
        }
        // Append to curr
        flag.erase(curr);
        curr += s[index++];
        while(index < s.size() && flag.find(curr) != flag.end()){
            curr += s[index++];
        }
        if(flag.find(curr) == flag.end()){
            flag.insert(curr);
            fun(index,curr,s,flag);
            flag.erase(curr);
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>flag;
        fun(0,"",s,flag);
        return max_size;
    }
};