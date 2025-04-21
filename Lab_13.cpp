
// You are Arya's trusted assistant. She gives you a list of gem prices for the upcoming days and the fixed transaction fee. 
// Your task is to help her calculate the maximum profit she can earn if she trades optimally.#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int cash = 0;
    int hold = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    int fee;
    cin >> fee;
    cout << maxProfit(prices, fee) << endl;
    return 0;
}
