class Solution {
public:
    string processStr(string s) {
        string res = "";

        for(auto &c : s){
            if(c >= 'a'){
                res.push_back(c);
            }
            else{
                if(c == '*' && !res.empty()){
                    res.pop_back();
                } else if(c == '#') {
                    res += res;
                } else {
                    reverse(begin(res), end(res));
                }
            }
        }
        return res;
    }
};