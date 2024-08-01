#include <iostream>
#include <vector>

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    return std::vector<int>{};
}

struct TestData
{
    std::vector<int> nums;
    int k;
    std::vector<int> output;
    std::vector<int> expected{};
};

void test(std::vector<TestData>& testData)
{
    for (auto& test : testData)
    {
        test.output = topKFrequent(test.nums, test.k);

        std::cout << "Input: nums = [";
        for (const auto& num : test.nums)
        {
            std::cout << num << ", ";
        }
        std::cout << "], k = " << test.k << std::endl;

        std::cout << "Output: [";
        for (const auto& num : test.output)
        {
            std::cout << num << ", ";
        }
        std::cout << "]\n";

        std::cout << "Expected: [";
        for (const auto& num : test.expected)
        {
            std::cout << num << ", ";
        }
        std::cout << "]\n\n";
    }
}

int main()
{
    std::vector<TestData> testData{{{1,2,2,3,3,3}, 2, {2,3}},
                                   {{7,7}, 1, {7}}};

    test(testData);
}