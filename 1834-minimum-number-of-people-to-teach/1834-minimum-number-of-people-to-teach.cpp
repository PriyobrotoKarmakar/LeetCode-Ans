// Build a list of pairs (a, b) who cannot communicate.
// For each luage L in 1..n:
// Count how many people in the problematic pairs don’t know L.
// Track the minimum of that count.
// Return that minimum.

class Solution {

    bool check(vector<int> a, vector<int> b){
        unordered_set<int> ss;
        for(auto x: a)ss.insert(x);
        for(auto y: b){
            // if (find(B.begin(), B.end(), x) != B.end())           // better 
            if(ss.find(y) != ss.end()) return true;                  //mil gya common
        }
        return false;
    }

public:
    int minimumTeachings(int n, vector<vector<int>>& lan, vector<vector<int>>& friendS) {
        int m = lan.size();
        unordered_set<int> s;
        // Step 1: Find friendships that cannot communicate
        for(auto &x : friendS){
            int a = x[0]-1 , b = x[1]-1;
            if(check(lan[a],lan[b]) == false){                      //cant communicate
                s.insert(a); s.insert(b);
            }
        }

        if(s.empty()) return 0;                                     //sb cimmunite kr skte no need t teach any1



        //step2: Each lang8age k liye check kro k use SET s k kitne log NHI bol skte hai,
        //       each language jo jo b minimun ho vo hmaraanswer, hme utne logo k vo language sikhani h
        //       since given single language sikhani h sbko in question !!
        int ans = INT_MAX;
        for(int l = 1; l <= n; l++){
            int cnt = 0;
            for(int person : s){
                if(find(lan[person].begin(), lan[person].end(), l) == lan[person].end())         // l lan nhi bol skte
                    cnt++;
            }
            ans = min(ans, cnt);
        }

        return ans;
    }
};