class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window approach
        int len = 0;
        vector<int> count(256,0); //count of characs
        int first = 0; //left bound of the window
        int second = 0; //right bound of the window

        while (second <s.size()){
            while (count[s[second]]){
                count[s[first]] = 0;
                first++;
            }
            count[s[second]] = 1;
            len = max(len, second-first+1);
            second++;
        }
        return len;
    }
};
