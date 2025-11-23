// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
//  2025-11-23
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
// KMP算法效率O(m+n)
// KMP就是把输入字符串的每一个子串，计算首尾相等的长度然后存起来，匹配的时候遇到不一样的值，则只挪动过的长度
// KMP按照next数组会跳过一部分被模式串匹配的主串，保证被跳过这部分不存在更优解是因为：
// 假设匹配失败的点位m，则会根据next[m-1]来挪动模式串
// 首先，因为匹配失败而挪动模式串，匹配失败点m之前是模式串的一部分，长度必然小于模式串。
// 所以在匹配的过程中，如果存在比根据next[m-1]计算出的模式串头位置更好更靠左的点，
// 则这样匹配到next[m-1]时，next[m-1]该有的值一定是大于已存储的点的。但在构建next[m-1]时，已经找到next[m-1]的值，故结论不成立