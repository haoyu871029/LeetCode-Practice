#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buy_price = INT_MAX;
    int max_profit = 0;
    for(int i=0; i<n; i++){
        buy_price = min(buy_price, prices[i]); //之前的買入最低價 vs 今天的買入價格
        max_profit = max(max_profit, prices[i] - buy_price); //之前的最高利潤 vs 今天賣可能會有的最高利潤
    }
    return max_profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl; //expect 5
    return 0;
}

//Compile: g++ -std=c++11 121.cpp -o 121
//Run: ./121