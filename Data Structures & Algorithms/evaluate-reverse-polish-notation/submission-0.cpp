class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &it:tokens){
            if(it=="+"||it=="-"||it=="*"||it=="/"){
                int x=st.top();st.pop();
                int y=st.top();st.pop();
                if(it=="+")st.push(x+y);
                if(it=="-")st.push(y-x);
                if(it=="*")st.push(y*x);
                if(it=="/")st.push(y/x);
            }
            else st.push(stoi(it));
        }
  
        return st.top();
    }
};
