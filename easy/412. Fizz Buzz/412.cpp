#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
    public:
        vector<string> fizzBuzz(int n);
};
 
vector<string> Solution::fizzBuzz(int n) {
    vector<string> ans;
    for (int i=1; i<=n; i++){
        if (i%15 == 0)
            ans.push_back("FizzBuzz");
        else if (i%3 == 0)
            ans.push_back("Fizz");
        else if (i%5 == 0)
            ans.push_back("Buzz");
        else
            ans.push_back(to_string(i));
    }
    return ans;
}

int main(){
    Solution sol;
    vector<string> ans = sol.fizzBuzz(15);
    for (string s :ans)
        cout << s << endl;
    return 0;
}

//Compile: g++ -std=c++11 412.cpp -o 412
//Run: ./412
