class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=0;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(ch == word[i])
            {
                index = i;
                break;
            }
        }
        index++;
        for(int i = 0 ; i < index/2; i++)
        {
            char temp = word[i];
            word[i] = word[index-i-1];
            word[index-i-1] =temp;
        }
        return word;
    }
};