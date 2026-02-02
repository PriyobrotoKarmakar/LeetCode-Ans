using FlightStatus = tuple<int, int, int>;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> flightGraph(n);
        
        for (const auto& flight : flights) {
            flightGraph[flight[0]].push_back({flight[1], flight[2]});
        }

        priority_queue<FlightStatus, vector<FlightStatus>, greater<FlightStatus>> minPriceQueue;
        minPriceQueue.push({0, src, 0});

        vector<int> minStops(n, INT_MAX);

        while (!minPriceQueue.empty()) {
            auto [currentPrice, currentCity, currentStops] = minPriceQueue.top();
            minPriceQueue.pop();

            if (currentCity == dst) return currentPrice;

            if (currentStops > k) continue;

            if (currentStops >= minStops[currentCity]) continue;
            
            minStops[currentCity] = currentStops;

            for (auto& [nextCity, flightPrice] : flightGraph[currentCity]) {
                minPriceQueue.push({currentPrice + flightPrice, nextCity, currentStops + 1});
            }
        }

        return -1;
    }
};