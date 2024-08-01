#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    for (int i{}; i < nums.size(); i++)
    {
        for (int j{1}; j < nums.size(); j++)
        {
            if (i == j) continue;

            if (nums.at(i) + nums.at(j) == target)
            {
                return std::vector<int>{i, j};
            }
        }
    }

    return std::vector<int>{-1, -1};
}

struct TestData
{
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
    std::vector<int> result;
};

void test(std::vector<TestData>& data)
{
    for (auto& test : data)
    {
        test.result = twoSum(test.nums, test.target);

        std::cout << "Input:\nnums = [";
        for (const auto& num : test.nums)
        {
            std::cout << num << ", ";
        }
        std::cout << "], target = " << test.target << "\n";

        std::cout << "Output: [";
        for (const auto& num : test.result)
        {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;

        std::cout << "Expected: [";
        for (const auto& num : test.expected)
        {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;

        bool passed{true};

        for (int i{}; i < test.result.size(); i++)
        {
            if (test.result.at(i) != test.expected.at(i))
            {
                passed = false;
                break;
            }
        }

        std::cout << "Test: " << (passed ? "Passed\n" : "Failed\n") << std::endl;
    }
}

int main()
{
    std::vector<TestData> testData{
        {{3, 4, 5, 6}, 7, {0, 1}, {}},
        {{4,5,6}, 10, {0,2}, {}},
        {{5,5}, 10, {0,1}, {}}};

    test(testData);
}