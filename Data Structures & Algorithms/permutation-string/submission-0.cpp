class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int>m1;
        for(auto &it:s1){
            m1[it]++;
        }
        int maxi=m1.size();int lo=0;
        unordered_map<int,int>m2;
        int curmaxi=0;
        for(int i=0;i<s2.length();i++){
            m2[s2[i]]++;
            if(m1.find(s2[i])==m1.end()){
                m2.clear();
                curmaxi=0;
                lo=i+1;
                continue;
            }
            else if(m2[s2[i]]==m1[s2[i]]){
                curmaxi++;
                if(curmaxi==maxi)return true;
            }
            else if(m2[s2[i]]>m1[s2[i]]){
                while(m2[s2[i]]>m1[s2[i]]){
                    if(m2[s2[lo]]==m1[s2[lo]])curmaxi--;
                    m2[s2[lo]]--;
                    lo++;
                }
            }
            else continue;

        }
        return false;
    }
};










