class Solution {
public:
    bool canEat(int mid,vector<int>& piles,int h){
        long long totalTime = 0;
        for(double ele: piles){
            totalTime+=ceil(ele/(double)mid);
        }

        return totalTime<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end =  *max_element(piles.begin(),piles.end());// will think later;
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;

            if(canEat(mid,piles,h)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid +1;
            }
        }

        return ans;


    }
};