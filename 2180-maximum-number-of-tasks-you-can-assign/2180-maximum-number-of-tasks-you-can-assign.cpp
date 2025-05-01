class Solution {
public:
    bool isValid(vector<int>& tasks, vector<int>& workers, int pills, int strength, int& mid){
        multiset<int> mst(workers.begin(),workers.begin()+mid);
        int pillUsed = 0;
        for(int i = mid-1;i>=0;i--){
            int taskToComplete = tasks[i];
            auto it = prev(mst.end());
            if(*it>=taskToComplete){
                mst.erase(it);
            }else if(pillUsed>=pills){
                return false;
            }else{
                auto weakWorker = mst.lower_bound(taskToComplete-strength);
                if(weakWorker==mst.end()){
                    return false;
                }
                mst.erase(weakWorker);
                pillUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater());


        int start = 0;
        int end = min(m,n);
        int res = 0;
        while(start<=end){
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