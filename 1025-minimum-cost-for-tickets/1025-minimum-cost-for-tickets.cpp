#include <algorithm>
#include <bitset>
#include <cstring>
#include <vector>

class Solution {
public:
    static constexpr int MAX_DAYS = 365;
    std::bitset<MAX_DAYS + 1> travelDays;
    int memo[MAX_DAYS + 1];

    int calculateMinCost(int day, int startDay, const std::vector<int>& costs) {
        if (day < startDay) {
            return 0;
        }
        if (!travelDays[day]) {
            return calculateMinCost(day - 1, startDay, costs);
        }
        if (memo[day] != -1) {
            return memo[day];
        }
        memo[day] =
            std::min({costs[0] + calculateMinCost(day - 1, startDay, costs),
                      costs[1] + calculateMinCost(day - 7, startDay, costs),
                      costs[2] + calculateMinCost(day - 30, startDay, costs)});
        return memo[day];
    }

    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        std::memset(memo, -1, sizeof(memo));
        for (int day : days) {
            travelDays[day] = true;
        }
        return calculateMinCost(days.back(), days.front(), costs);
    }
};
