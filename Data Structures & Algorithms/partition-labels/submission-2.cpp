class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        vector<int>res;
        int maxi=m[s[0]];int l=0;
        if(maxi==0){res.push_back(1);l=1;}
        for(int i=1;i<s.size();i++){
            maxi=max(maxi,m[s[i]]);
            if(maxi==i){
                res.push_back(i-l+1);
                maxi=0;
                l=i+1;
            }
        }
        return res;
    }
};
