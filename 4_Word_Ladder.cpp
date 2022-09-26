https://leetcode.com/problems/word-ladder/


// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        unordered_set<string>dict(wl.begin(),wl.end());
        queue<string>q;
        q.push(bw);
        dict.erase(bw);
        int ladder=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string word=q.front();
                q.pop();
                if(word==ew)return ladder;
                for(int i=0;i<word.length();i++){
                    char ch=word[i];
                    for(int j=0;j<26;j++){
                        word[i]='a'+j;
                        if(dict.find(word)!=dict.end()){
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i]=ch;
                }
            }
            ladder++;
        }
        return 0;
    }
};