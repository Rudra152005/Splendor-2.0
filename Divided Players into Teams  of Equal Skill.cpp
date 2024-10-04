#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>    

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Sort the array to easily form teams
        sort(skill.begin(), skill.end());
        
        // Calculate the target sum for each team
        int n = skill.size();
        int totalSum = accumulate(skill.begin(), skill.end(), 0);
        if (totalSum % (n / 2) != 0) {
            return -1;
        }
        
        int targetSum = totalSum / (n / 2);  
        
        long long totalChemistry = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (skill[left] + skill[right] != targetSum) {
                return -1;  
            }
            totalChemistry += (long long)skill[left] * skill[right];
            
            left++;
            right--;
        }
        
        // Return the total chemistry
        return totalChemistry;
    }
};
int main() {
    Solution solution;
    vector<int> skill1 = {3, 2, 5, 1, 3, 4};
    cout << "Output 1: " << solution.dividePlayers(skill1) << endl;  
    vector<int> skill2 = {3, 4};
    cout << "Output 2: " << solution.dividePlayers(skill2) << endl;  
    vector<int> skill3 = {1, 1, 2, 3};
    cout << "Output 3: " << solution.dividePlayers(skill3) << endl;  
    return 0;
}
