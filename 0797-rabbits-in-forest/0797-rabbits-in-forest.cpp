class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>freq;
        for(auto ele: answers){
            freq[ele]++;
        }
        int ans = 0;
        for(auto P:freq){
            cout<<P.first<<"->"<<P.second<<endl;
            float numberOfSameRabit = P.first + 1;
            float totalMember = P.second;
            int groups = ceil(totalMember/numberOfSameRabit);
            int Rabits =  numberOfSameRabit * groups;
            cout<<Rabits<<endl;
            ans += Rabits;
        }

        return ans;
    }
};

