#include <iostream>
#include <vector>

int minCostTicketUtil(int idx, int currCost, const std::vector<int>& days, const int& daily, const int& weekly, const int& monthly) {
    std::cout << "idx=" << idx << " currCost=" << currCost << std::endl;
    if (idx >= days.size()) {
        return currCost;
    }
    int dailyIdx = idx + 1, weeklyIdx = idx, monthlyIdx = idx;
    for (int i = idx; i < days.size(); i++) {
        if (days[i] < days[idx] + 7) {
            weeklyIdx = i + 1;
        }
        if (days[i] < days[idx] + 30) {
            monthlyIdx = i + 1;
        }
    }
    std::cout << "dailyIdx=" << dailyIdx << " weeklyIdx=" << weeklyIdx << " monthlyIdx=" << monthlyIdx << std::endl;
    return std::min(minCostTicketUtil(dailyIdx, currCost + daily, days, daily, weekly, monthly), 
           std::min(minCostTicketUtil(weeklyIdx, currCost + weekly, days, daily, weekly, monthly), 
                    minCostTicketUtil(monthly, currCost + monthly, days, daily, weekly, monthly)));
}

int minCostTicket(const std::vector<int>& days, const int& daily, const int& weekly, const int& monthly) {
    return minCostTicketUtil(0, 0, days, daily, weekly, monthly);
}


int main() {
    //std::vector<int> days = {1,4,6,7,8,20};
    std::vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    std::cout << minCostTicket(days, 2, 7, 15) << std::endl;
    return 0;
}