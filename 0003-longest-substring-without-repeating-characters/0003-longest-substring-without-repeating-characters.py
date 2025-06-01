class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        hashSet=set()
        left=0
        maxlength=0

        for right in range(len(s)):
            while s[right] in hashSet:
                hashSet.remove(s[left])
                left+=1
            hashSet.add(s[right])
           
            maxlength=max(maxlength, right-left+1)
        return maxlength

        