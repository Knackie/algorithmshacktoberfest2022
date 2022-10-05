
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), k / 2);
    vector<double> medians;
    for (int i=k; ; i++) {

        // Push the current median.
        medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);

        // If all done, return.
        if (i == nums.size())
            return medians;
            
        // Insert nums[i].
        window.insert(nums[i]);
        if (nums[i] < *mid)
            mid--;

        // Erase nums[i-k].
        if (nums[i-k] <= *mid)
            mid++;
        window.erase(window.lower_bound(nums[i-k]));
    }
}