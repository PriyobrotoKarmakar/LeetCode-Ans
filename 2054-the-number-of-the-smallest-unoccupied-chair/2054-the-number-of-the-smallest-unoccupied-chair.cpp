class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Add index to each friend for identification
        vector<pair<int, int>> arrival, departure;
        for (int i = 0; i < n; ++i) {
            arrival.push_back({times[i][0], i});  // {arrival time, friend index}
            departure.push_back({times[i][1], i});  // {departure time, friend index}
        }

        // Sort the friends based on arrival and departure times
        sort(arrival.begin(), arrival.end());  // Sort by arrival time
        sort(departure.begin(), departure.end());  // Sort by departure time

        // Min-heap to store available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // Initially, all chairs are available
        }

        // Min-heap to track when each friend leaves and which chair they occupied
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

        // To keep track of departure times, friend index, and chair number
        vector<int> chairAssigned(n, -1);  // This will store which chair is assigned to which friend

        int departureIdx = 0;  // Index for tracking which friends leave
        for (int i = 0; i < n; ++i) {
            // Free up chairs that are now available (departure times <= current arrival time)
            while (departureIdx < n && departure[departureIdx].first <= arrival[i].first) {
                int chairToFree = chairAssigned[departure[departureIdx].second];
                availableChairs.push(chairToFree);  // Return the chair to available pool
                departureIdx++;
            }

            // Assign the smallest available chair to the current friend
            int currentFriend = arrival[i].second;
            int assignedChair = availableChairs.top();
            availableChairs.pop();  // Remove the chair from available chairs
            chairAssigned[currentFriend] = assignedChair;  // Assign the chair to this friend

            // If this is the target friend, return the chair number
            if (currentFriend == targetFriend) {
                return assignedChair;
            }
        }
        
        return -1;  // Should never reach here since targetFriend is guaranteed to exist
    }
};
