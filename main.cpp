
#include <iostream>
#include <map>
#include <string>
#include "Source/map/map.h"

int main()
{

    char charactor = 'A';

    int number = charactor;

    std::cout << "�����@�@�@:" << charactor << std::endl;
    std::cout << "�����ԍ��H:" << number << std::endl;

    // map�̐錾�ƎQ��,���
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


    // �e�X�g�֐�
    test_map_output("1,2", "filename5,filename2");
    

    std::getchar();

    return 0;
}