class Solution {
public:
    bool isValid(vector<int>& tasks, vector<int>& workers, int pills, int strength, int& mid){
        multiset<int> mst(workers.begin(),workers.begin()+mid); //mid
        //mid
        int pillUsed = 0;

        //mid+ (mid*mid)
        for(int i = mid-1;i>=0;i--){ //mid
            int taskToComplete = tasks[i];
            auto it = prev(mst.end());
            if(*it>=taskToComplete){
                mst.erase(it); //logmid
            }else if(pillUsed>=pills){
                return false;
            }else{
                auto weakWorker = mst.lower_bound(taskToComplete-strength); //mid
                if(weakWorker==mst.end()){
                    return false;
                }
                mst.erase(weakWorker); //logmid
                pillUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(),tasks.end()); //nlogn
        sort(workers.begin(),workers.end(),greater()); //mlogm

         // T.C: nlogn + mlogm + (logn * (logn+ (logn * logn)));
        int start = 0;
        int end = min(m,n);
        int res = 0;
        while(start<=end){  //logn
            int mid = start + (end-start)/2;

            if(isValid(tasks,workers,pills,strength,mid)){
                res = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }

        return res;
    }
};