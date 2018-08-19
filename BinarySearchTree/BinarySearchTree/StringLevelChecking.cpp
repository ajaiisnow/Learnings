#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class string_level_checker
{
private:
    const char* const ptr_temp;
    const int nLength;

public:
    string_level_checker(const string& str) : ptr_temp(str.c_str()), nLength(str.length()){}
    bool check_level()
    {
        vector<char> stack;
        for(int i = 0; i < nLength; ++i)
        {
            switch (ptr_temp[i])
            {
                case '}':
                {
                    char ch = stack.back();
                    if (ch == '{')
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
                case ']':
                {
                    char ch = stack.back();
                    if (ch == '[')
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
                case ')':
                {
                    char ch = stack.back();
                    if (ch == '(')
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
                case '>':
                {
                    char ch = stack.back();
                    if (ch == '<')
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
                case '{':
                case '[':
                case '(':
                case '<':
                {
                    stack.push_back(ptr_temp[i]);
                    break;
                }
                default:
                {
                    // Do nothing
                    break;
                }
            }
        }
        return ((stack.size()) ?  false : true);
    }

};

vector<string> solution(vector<string>& A)
{
    vector<string> result_vector;
    vector<string>::iterator itrBegin = A.begin();
    vector<string>::iterator itrEnd = A.end();
    while (itrBegin != itrEnd)
    {
        string_level_checker obj(*itrBegin);
        result_vector.push_back((obj.check_level()) ? "YES" : "NO");
        ++itrBegin;
    }
    return result_vector;
}

//int main()
//{
//    vector<string> sample;
//    sample.push_back("{[}]");
//    sample.push_back("{<[]>}");
//    sample.push_back("[](){}");
//    sample.push_back("[]AbcdDEF{}<>");
//    sample.push_back("[]AbcdDEF{}<>{");
//    vector<string>&result = solution(sample);
//    sample.clear();
//    result.clear();
//}