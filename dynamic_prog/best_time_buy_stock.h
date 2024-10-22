/*
This is solution for the leetcode problem:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY
 */
#include <bits/stdc++.h>
#include <vector>


class BestTimeBuyStock {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPrice = prices[0]; // Keep track of the minimum price seen so far
        int maxProfit = 0; // Maximum profit we can achieve

        for (uint i = 1; i < prices.size(); ++i) {
            // Update the minimum price if the current price is lower
            minPrice = std::min(minPrice, prices[i]);

            // Calculate the profit if we sell on the current day and update max profit if it's better
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;

    } 
};