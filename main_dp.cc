#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "dynamic_prog/climbing_stairs.h"
#include "dynamic_prog/best_time_buy_stock.h"
#include "dynamic_prog/pascal_triangle.h"
#include "dynamic_prog/palindromic_string.h"
#include "dynamic_prog/generate_parenthese.h"

using namespace std;

void printListOfVector(vector<vector<int>>& listVector) {
    for (auto& v : listVector) {
            std::cout << "[";
            for (auto& e: v) {
                std::cout << e << " ";
            }
            std::cout << "], ";
        }
        std::cout << std::endl;
}
void printVectorOfString(vector<string>&& listString) {
    for (auto str : listString) {
        std::cout << str << std::endl;
    }
}

int main_dynamic_prog() {

    ClimbingStairs solClimbingStair{};
    std::cout << solClimbingStair.climbStairs(4) << std::endl;

    std::vector<int> prices = {7,1,5,3,6,4, 10 ,11, 15 , 8};
    // std::vector<int> prices = {3,1,2};
      
    BestTimeBuyStock solBuyStock{};
    std::cout << solBuyStock.maxProfit(prices) << std::endl;

    PascalTriangle solPascal;
    vector<vector<int>> printPascal = solPascal.generate(6);
    printListOfVector(printPascal);


    PalindromicString solPalString{};
    string testInput = "busislnescsicxpvvysuqgcudefrfjbwwjcchtgqyajdfwvkypfwshnihjdztgmyuuljxgvhdiwphrweyfkbnjgerkmifbirubhseuhrugwrabnjafnbdfjnufdstjbkuwtnpflffaqmjbhssjlnqftgjiglvvequhapasarlkcvbmkwnkuvwktbgfoaxteprobdwswcdyddyvrehvmxrrjiiidatidlpihkbmmruysmhhsncmfdanafdrfpdtfgkglcqpwrrtvacuicohspkounojuziittugpqjyhhkwfnflozbispehrtrnizowrlzcuollagxwtznjwzcumvedjwokueuqktvvouwnsmpxqvvpuwprezrbobrpnwaccwljchdguubjulyilzvmandjjleitweybqkjttschrjjlebnmponvlktzzcdtuybugggcqffkcffpamauvxfbonjrobgpvlyzveiwemmtdvbjciaytvesnocnjrwodtcokgcuoiicxapmrzpkfphjniuvzjrhbnqndfshoduejyktebgdabidxlkstepuwvtrtgbxaeheylicvhrxddijshcvdadxzsccmainyfpfdhqdanfccqkzlmhsfilvoybqojlvbcixjzqpbngdvesuokbxhkomsiqfyukvspqthlzxdnlwthrgaxhtpjzhrugqbfokrdcyurivmzgtynoqfjbafboselxnfupnpqlryvlcxeksirvufepfwczosrrjpudbwqxwldgjyfjhzlzcojxyqjyxxiqvfhjdwtgoqbyeocffnyxhyyiqspnvrpxmrtcnviukrjvpavervvztoxajriuvxqveqsrttjqepvvahywuzwtmgyrzduxfqspeipimyoxmkadrvrdyefekjxcmsmzmtbugyckcbjsrymszftjyllfmoeoylzeahnrxlxpnlvlvzltwnmldi";
    std::cout << solPalString.longestPalindrome(testInput) << std::endl;

    GenerateParenthese solGenParenthese{};
    printVectorOfString(solGenParenthese.generateParenthesis(4));
    return 0;
}