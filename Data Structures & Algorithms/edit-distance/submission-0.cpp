class Solution {
public:

    int f(int i,int j,string &w1, string &w2,vector<vector<int>>&v){
        if(i>=w1.size()||j>=w2.size()){
            if(j>=w2.size()){
                if(i<w1.size())return w1.size()-i;
                else return 0;
            }
            else if(i>=w1.size())return w2.size()-j;
        }    
        if(v[i][j]!=-1)return v[i][j];
        if(w1[i]==w2[j]){
            return v[i][j]=f(i+1,j+1,w1,w2,v);
        }
        else {
            return v[i][j]=min({1+f(i,j+1,w1,w2,v),1+f(i+1,j,w1,w2,v),1+f(i+1,j+1,w1,w2,v)});
        }
    }
    int minDistance(string w1, string w2) {
        vector<vector<int>>v(w1.size()+1,vector<int>(w2.size()+1,-1));
        return f(0,0,w1,w2,v);
    }
};