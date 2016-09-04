// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "322.Coin.Change.h"


int main()
{
	
	int t = -1;
	{
		vector<int> c = { 1 };
		t = Solution().coinChange(c, 0);
	}

	{
		vector<int> c = { 186, 419, 83, 408 };
		t = Solution().coinChange(c, 6249);
	}

	{
		vector<int> c = { 3, 7, 405, 436 };
		t = Solution().coinChange(c, 8839);
	}

    return 0;
}

