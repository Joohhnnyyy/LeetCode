class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0 , res = 0;
        unordered_map<char , int> freq;

        for(int high = 0 ; high < s.size() ; high++){
            freq[s[high]]++;
            while( freq.size() < (high - low + 1)){
                freq[s[low]]--;
                if(freq[s[low]] == 0) freq.erase(s[low]);
                low++;
            }
            int len = high -low + 1;
            res = max( res , len);
        }
        return res;
    }
};