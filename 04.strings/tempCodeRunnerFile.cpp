    cout << "result: " << s.strStr("aabaabaaf", "aabaaf") << endl;
    cout << "result: " << s.strStr("abcabc", "abc") << endl;
    cout << "result: " << s.strStr("dabcabc", "abc") << endl; // 用haystack来做kmp会出现漏解，因为start是needle而非haystack
    cout << "result: " << s.strStr("leetcode", "leeto") << endl;