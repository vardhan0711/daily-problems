class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res=numBottles;
        int remaining=0;
        while(numBottles>=numExchange){
            remaining=numBottles%numExchange;
            numBottles/=numExchange;
            res+=numBottles;
            numBottles+=remaining;
        }
        return res;
    }
};