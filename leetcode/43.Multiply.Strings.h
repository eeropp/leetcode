#pragma once

#include "stdafx.h"

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string ret(num1.size() + num2.size(), '0');
		for (size_t i1 = 0; i1 < num1.size(); ++i1) {
			for (size_t i2 = 0; i2 < num2.size(); ++i2) {
				char c1 = num1[num1.size() - i1 - 1];
				char c2 = num2[num2.size() - i2 - 1];
				char& cr = ret[ret.size() - i1 - i2 - 1];

				char mh = mul(c1, c2);
				char ah = add(cr, c1);

				for (size_t i = i1 + i2 + 1; i < ret.size() && mh != '0'; ++i) {
					mh = add(ret[ret.size() - i - 1], mh);
				}

				for (size_t i = i1 + i2 + 1; i < ret.size() && ah != '0'; ++i) {
					ah = add(ret[ret.size() - i - 1], ah);
				}
			}
		}
		int pos = ret.find_first_not_of('0');
		if (pos == -1)
			return "0";
		return ret.substr(pos);
	}

	char mul(char& c1, const char c2) {
		int m = (c1 - '0') * (c2 - '0');
		c1 = m % 10 + '0';
		return m / 10 + '0';
	}

	char add(char& c1, const char c2) {
		int m = (c1 - '0') + (c2 - '0');
		c1 = m % 10 + '0';
		return m / 10 + '0';
	}
};