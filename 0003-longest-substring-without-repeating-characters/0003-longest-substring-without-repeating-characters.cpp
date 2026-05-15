class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int maxlen=0;
        int left =0;
        for (int right =0;right<s.length();right++){
            while(set.contains(s[right])){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            maxlen= max(maxlen, right-left+1);
            
        }
        return maxlen;
    }
};