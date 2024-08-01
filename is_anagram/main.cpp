#include <iostream>
#include <unordered_map>
#include <vector>

bool isAnagram(std::string s, std::string t) 
{
    if (s.length() != t.length())
    {
        return false;
    }

    std::unordered_map<char, int> map1;
    std::unordered_map<char, int> map2;

    for (int i{}; i < s.length(); i++)
    {
        map1[s[i]]++;
        map2[t[i]]++;
    }

    for (int i{}; i < map1.size(); i++)
    {
        if (map1[i] != map2[i])
        {
            return false;
        }
    }

        return true;
}

struct TestData
{
    std::string s{};
    std::string t{};
    bool isAnagram{false};
    bool testResult{false};
};

void test(std::vector<TestData>& data)
{
    for (auto& test: data)
    {
        test.testResult = isAnagram(test.s, test.t);
        std::cout << "Input: s = " << test.s << ", t = " << test.t << std::endl;
        std::cout << "Output: " << (test.testResult ? "True" : "False") << "\nTest: " << (test.testResult == test.isAnagram ? "Passed\n" : "Failed\n") << std::endl;
    }
}

int main()
{
    std::vector<TestData> data {{"racecar", "carrace", true},
                                {"jar", "jam", false},
                                {"bbcc", "ccbc", false}};

    test(data);
}