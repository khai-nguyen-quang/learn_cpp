/*
This is solution for the leetcode problem : 
https://leetcode.com/problems/climbing-stairs/description/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY
*/
class ClimbingStairs {
public:
    int climbStairs(int n) {
        int* memo = new int[n+1]{};

        climbStairs(n, memo);
        int  result =  memo[n];
        
        delete[] memo;
        return result;
    }

private: 
    int climbStairs(int n, int memo[] ) {
        if (n == 0) {
            memo[n] = 0; 
        } else if (n == 1) {
            // There is only 1 way to move 1 step
            memo[n] = 1;
        } else if (n == 2 ) {

            // there are 2 ways to move 2 steps
            // 1 + 1
            // 2
            memo[n] = 2;
        } else if (memo[n] == 0) {
            memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo); 
        } 

        return memo[n];
    }
};