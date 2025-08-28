#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string& s1, string& s2)
{
    return s1 + s2 < s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    nums.resize(numbers.size());
    for (int i = 0; i < numbers.size(); ++i)
    {
        nums[i] = to_string(numbers[i]);
    }
    
    sort(nums.begin(), nums.end(), compare);
    
    while (nums.size() != 0)
    {
        answer += nums[nums.size() - 1];
        nums.pop_back();
    }
    
    return (answer[0] == '0' ? "0" : answer);
}