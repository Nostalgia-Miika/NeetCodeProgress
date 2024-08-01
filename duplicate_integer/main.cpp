#include <iostream>
#include <vector>
#include <unordered_set>

bool hasDuplicate(std::vector<int> &nums)
{
    std::unordered_set<int> map;

    for (const auto& num : nums)
    {
        if (map.find(num) != map.end())
        {
            return true;
        }
        map.insert(num);
    }
    return false;
}

void print(const std::string& message, const std::vector<int>& input)
{
    std::cout << message << " = [";
    for (const auto &num : input)
    {
        std::cout << num << ", ";
    }
    std::cout << "]" << std::endl;
}
int main()
{
    std::vector<int> input0{1, 2 , 3, 3};
    std::vector<int> input1{1, 2, 3, 4};

    print("Input0", input0);
    std::cout << "Output: " << (hasDuplicate(input0) ? "true" : "false") << std::endl;

    print("Input1", input1);
    std::cout << "Output: " << (hasDuplicate(input1) ? "true" : "false") << std::endl;

    return 0;
}