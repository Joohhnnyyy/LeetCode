class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        string s = "balloon";
        for(int i = 0 ; i < s.size() ; i++){
            need[s[i]]++;
        }
        for(int i = 0 ; i < text.size() ; i++){
            have[text[i]]++;
        }
        int ans = INT_MAX;
        for(auto i : need){
            char c = i.first;
            int f_need = i.second;
            int f_have = have[c];
            ans = min(ans , f_have/f_need);
        }
        return (ans == INT_MAX ? 0 : ans  );
    }
};