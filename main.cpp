
#include <iostream>
#include <map>
#include <string>
#include "Source/map/map.h"

int main()
{

    char charactor = 'A';

    int number = charactor;

    std::cout << "文字　　　:" << charactor << std::endl;
    std::cout << "文字番号？:" << number << std::endl;

    // mapの宣言と参照,代入
    {
        std::map<int, std::string> files;

        files[1] = "filename1";
        files.emplace(100, "filename100");
        files.emplace(2, "filename2");

        for (auto i = files.begin(); i != files.end(); ++i)
        {
            std::cout << i->first << " = " << i->second << std::endl;
        }
    }


    // テスト関数
    test_map_output("1,2", "filename5,filename2");
    

    std::getchar();

    return 0;
}