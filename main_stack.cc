#include <iostream>
#include <bits/stdc++.h>

#include "stack_problems/valid_parenthese.hpp"
#include "stack_problems/remove_outermost_parenthese.hpp"
#include "stack_problems/remove_adjacent_duplicates.hpp"
#include "stack_problems/clear_digits.hpp"
#include "stack_problems/stack_using_queue.hpp"
#include "stack_problems/queue_using_stack.hpp"

using namespace std;

void main_stack() {

    cout << "ValidParentheseSolution"<< endl;
    ValidParentheseSolution validParenthese{};
    string validParentheseTest[] = {"){", "(", "((", "()[", "()[]{}", "(]", "([])", "[{}{}()]"};
    for (auto& s : validParentheseTest) {
        cout.width(10); cout << left << s << ": "<< boolalpha << validParenthese.isValid(s) << endl;    
    }

    cout << "RemoveOutermostParentheseSolution"<< endl;
    string removeOutermostTest[] = {"", "()", "()()", "(()())(())", "(()())(())(()(()))"};
    RemoveOutermostParentheseSolution removeOutermostParenthese{};
    for (auto& s : removeOutermostTest) {
        cout.width(10); cout << s << "-->" << removeOutermostParenthese.removeOuterParentheses(s) << endl;
    }

    cout << "RemoveAdjacentDuplicatesSolution"<< endl;
    string removeAdjacentDuplicatesTest[] = {"", "a", "aa", "abba", "abbaca", "azxxzy"};
    RemoveAdjacentDuplicatesSolution removeAdjDupsSol;
    for (auto& s : removeAdjacentDuplicatesTest) {
        cout.width(10); cout << s << "-->" << removeAdjDupsSol.removeDuplicates(s) << endl;
    }

    cout << "ClearDigitsSolution"<< endl;
    string clearDigitsTest[] = {"1", "1ab2", "cb34", "abc"};
    ClearDigitsSolution clearDigitsSol;
    for (auto& s : clearDigitsTest) {
        cout.width(10); cout << s << "-->" << clearDigitsSol.clearDigits(s) << endl;
    }

    MyStack myStack{};
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    cout << myStack.top() << endl; // return 3

    myStack.pop(); // pop 3
    cout << myStack.top() << endl; // return 2

    myStack.pop(); // pop 2
    cout << boolalpha << myStack.empty() << endl; // return False 

    myStack.pop(); // pop 1
    cout << boolalpha << myStack.empty() << endl; // return True 
}