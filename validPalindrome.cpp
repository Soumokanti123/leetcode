class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, en = s.size()-1;
        int cnt = 0;
        while(start < en){
            if(s[start] == s[en]){
                start++;
                en--;
            }
            else{
                cnt++;
                en--;
            }
            
            if(cnt > 1)break;
        }
        
        start = 0;
        en = s.size()-1;
        int c = 0;
        while(start < en){
            if(s[start] == s[en]){
                start++;
                en--;
            }
            else{
                c++;
                start++;
            }
            if(c > 1)break;
        }
        if(cnt <= 1 or c <= 1)return true;
            return false;
    }
};
