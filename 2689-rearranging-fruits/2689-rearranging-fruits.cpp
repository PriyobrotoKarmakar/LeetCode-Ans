class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       unordered_map<int,int>mp1,mp2;
       unordered_set<int>s;
       vector<int>a1,a2;
       long long ans=0;

       for(auto &x:basket1) mp1[x]++;
       for(auto &x:basket2) mp2[x]++;

       for(auto&x:mp1){
        int z=(mp2.count(x.first))?mp2[x.first]:0;
         s.insert(x.first);
        if((x.second+z)&1) {
            // cout<<x.first;
            return -1;
        }
        if(x.second==z) continue;
        if(z>x.second){
            for(int i=1;i<=(z-x.second)/2;i++) a2.push_back(x.first);
        }
        else{
            for(int i=1;i<=(x.second-z)/2;i++) a1.push_back(x.first);
        }
       }

       for(auto&x:mp2){
        if(s.find(x.first)!=s.end()) continue;
       if((x.second)&1) {
            // cout<<x.first;
            return -1;
        }
            for(int i=1;i<=(x.second)/2;i++) a2.push_back(x.first);
       }
       
       if(a1.size()==0) return 0;

       sort(a1.begin(),a1.end());
       sort(a2.begin(),a2.end());

    //    for(auto&x:a1) cout<<x<<" ";
    //    cout<<endl;
    //    for(auto&x:a2) cout<<x<<" ";
    //      cout<<endl;

        int mini=min(*min_element(basket1.begin(),basket1.end()),*min_element(basket2.begin(),basket2.end()));
        int i=0,j=a1.size()-1;
        
        while(j>=0){
            if(2*mini<min(a1[i],a2[j])){
                ans+=(2*mini);
            }
            else{
                ans+=(min(a1[i],a2[j]));
            }
            // cout<<ans<<" ";
            i++;
            j--;
        }
            
       return ans;
    }
};