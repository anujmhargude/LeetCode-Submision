class Solution {
public:
    vector<int> decimalToBinaryArithmetic(int n) {
        if (n == 0) return {}; // Handle special case for zero
        vector<int>binary;
        while (n > 0) {
            int remainder = n % 2;       // Get the last binary digit
            binary.push_back(remainder); // Convert int to character and append
            n /= 2;                      // Divide by 2 to move to the next digit
        }
        
        reverse(binary.begin(), binary.end()); 
        return binary;
    }
    int findOne(vector<int>arr){
        int cnt = 0;
        for(int val : arr){
            if(val == 1){
                cnt++;
            }
        }
        return cnt;
    }
    int calculateScore(int a, int b) {
        vector<int>s1 = decimalToBinaryArithmetic(a);
        vector<int>s2 = decimalToBinaryArithmetic(b);
        int first = findOne(s1);
        int second = findOne(s2);
        if(first >= second){
            return first*second;
        }
        return second/first;
    }
};