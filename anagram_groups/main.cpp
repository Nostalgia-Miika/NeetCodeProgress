#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{
    std::unordered_map<std::string, std::vector<std::string>> ans;

        for (auto& s : strs) {
            std::vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

            std::string key;
            for (int i : count) {
                key += "#" + std::to_string(i);
            }

            ans[key].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        for (auto& pair : ans) {
            result.push_back(pair.second);
        }

        return result;
    
}

struct TestData
{
    std::vector<std::string> input;
    std::vector<std::vector<std::string>> expected;
    std::vector<std::vector<std::string>> output{};
};

void test(std::vector<TestData>& testData)
{
    for (auto& data :  testData)
    {
        data.output = groupAnagrams(data.input);

        std::cout << "\nInput: strs = [";
        for (auto& str : data.input)
        {
            std::cout << "\"" << str << "\",";
        }
        std::cout << "]" << std::endl;

        std::cout << "Output: [";
        for (auto& vStr : data.output)
        {
            std::cout << "[";
            for (auto &str : vStr)
            {
                std::cout << "\"" << str << "\",";
            }
            std::cout << "],";
        }
        std::cout << "]" << std::endl;

        std::cout << "Expected: [";
        for (auto& vStr : data.expected)
        {
            std::cout << "[";
            for (auto &str : vStr)
            {
                std::cout << "\"" << str << "\",";
            }
            std::cout << "],";
        }
        std::cout << "]\n" << std::endl;
    }
}

int main()
{
    std::vector<TestData> testData{{{"act","pots","tops","cat","stop","hat"}, {{"hat"},{"act", "cat"},{"stop", "pots", "tops"}},{}},
                                    {{"x"},{{"x"}},{}},
                                    {{""},{{""}},{}}};

    test(testData);
    return 0;
}