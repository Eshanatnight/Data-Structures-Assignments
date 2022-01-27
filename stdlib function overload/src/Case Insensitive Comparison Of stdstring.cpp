#include <iostream>
#include <string>




bool case_insensitive_equal(const std::string& s1, const std::string& s2)
{
    if(s1.length() != s2. length())
        return false;
    for(int i = 0; i < s1.length(); ++i)
        if(std::toupper(s1[i]) != std::toupper(s2[i])) //tolower would do as well
            return false;
    return true;
}


bool operator== (const std::string& s1, const std::string& s2)
{
    if(s1.length() != s2. length())
        return false;
    for(int i = 0; i < s1.length(); ++i)
        if(std::toupper(s1[i]) != std::toupper(s2[i])) //tolower would do as well
            return false;
    return true;
}

int main()
{
    std::string str1("Alice"), str2("AlICd");
    std::cout << case_insensitive_equal(str1, str2) << std::endl;


}