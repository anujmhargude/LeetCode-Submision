class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>res;
        string f;
        string s;
        for(int i = 0;i < s1.length();i++){
            if(s1[i] != s2[i]){
                f.push_back(s1[i]);
                s.push_back(s2[i]);
            }
            else if(f != "" && s != ""){
                res.push_back({f,s});
                f = "";
                s = "";   
            }
        }
        if(f != "" && s != ""){
            res.push_back({f,s});
        }
        return res;
    }
};