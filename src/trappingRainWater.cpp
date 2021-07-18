// Proposed solution for "Trapping Rain Water" problem
// Pedro Casanova
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int globalMaximum = 0, globalMaximumIndex = 0, localMaximum = 0, totalWater = 0;
        for (unsigned int i = 0; i < height.size(); i++)
        {
            if (height[i] > globalMaximum)
            {
                globalMaximum = height[i];
                globalMaximumIndex = i;
            }
        }
        for (int i = 0; i < globalMaximumIndex; i++)
        {
            if (height[i] > localMaximum) localMaximum = height[i];
            totalWater = totalWater + (localMaximum - height[i]);
        }
        localMaximum = 0;
        for (int i = height.size() - 1; i > globalMaximumIndex; i--)
        {
            if (height[i] > localMaximum) localMaximum = height[i];
            totalWater = totalWater + (localMaximum - height[i]);
        }
        return totalWater;
    }
};

int main() {
	vector <int> height;
	height = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution inst;
	cout << inst.trap(height);
	return 0;
}
