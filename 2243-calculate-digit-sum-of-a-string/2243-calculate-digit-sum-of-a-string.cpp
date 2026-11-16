class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string next = "";
            for(int i = 0;i < s.size();i+=k){
                string group = s.substr(i,k);
                int sum = 0;
                for(char c : group){
                    sum += c - '0';
                }
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};