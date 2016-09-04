#pragma once

#include "stdafx.h"

using namespace std;

class Solution 
{
public:

	int coinChange(vector<int>& coins, int amount) 
	{
		if (amount == 0)
			return 0;

		vector<int> dp(amount, numeric_limits<int>::max());

		for (int i = 0; i < amount; ++i)
		{
			int cMin = numeric_limits<int>::max();
			for (int j = 0; static_cast<size_t>(j) < coins.size(); ++j)
			{
				int idx = i + 1 - coins[j] - 1;
				if (idx >= 0)
				{
					if (dp[idx] != numeric_limits<int>::max())
					{
						if (dp[idx] + 1 < cMin)
							cMin = dp[idx] + 1;
					}
				}
				else if (i + 1 == coins[j])
				{
					cMin = 1;
				}
			}
			dp[i] = cMin;
		}
		
		return dp[amount - 1] == numeric_limits<int>::max() ? -1 : dp[amount - 1];
	}
};