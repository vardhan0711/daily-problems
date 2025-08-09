class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>pq;
        int sum=0;
        for(int i:piles){
            pq.push(i);
            sum+=i;
        }
        for(int i=1;i<=k;i++){
            int temp=pq.top();
            pq.pop();
            int remove=temp/2;
            sum-=(remove);
            temp-=(remove);
            pq.push(temp);
        }
        return sum;
    }
};