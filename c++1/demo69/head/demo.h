#ifndef __DEMO_H_
#define __DEMO_H_

#include <string>

inline int sum(int a, int b)
{
    return a + b;
}

inline const std::string &shortString(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size() ? s1 : s2;
}

inline bool isShoter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

#endif // !__DEMO_H_