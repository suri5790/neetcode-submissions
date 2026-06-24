class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;int n=beginWord.size();
        for(auto &it:wordList){
            s.insert(it);
        }
        if(s.find(endWord)==s.end() ||endWord.size()>n)return 0;
       
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string cur=it.first;
            int minwords=it.second;
            if(cur==endWord)return minwords;
            for(int i=0;i<n;i++){
                char x=cur[i];
                for(char c='a';c<='z';c++){
                    cur[i]=c;
                    if(s.find(cur)!=s.end()){
                        q.push({cur,minwords+1});
                        s.erase(cur);
                    }
                }
                cur[i]=x;
            }
        }
        return 0;
    }
};
