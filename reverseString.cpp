class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0, en = s.size()-1;
        while(st<en){
            char temp = s[st];
            s[st] = s[en];
            s[en] = temp;
            st++;en--;
        }
    }
};
