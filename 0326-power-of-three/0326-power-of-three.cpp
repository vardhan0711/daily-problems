class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        int max=pow(3,19);
        return (max%n==0);
    }
};