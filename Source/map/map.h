#pragma once

#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>



// string�^����map��key�ɕϊ����]������
// ������
// "1,2" -> 1 2 -> map[1] = filename1 , map[2] = filename2
std::map<int, std::string> ScoredMapFromString(std::string input)
{
    std::map<int, std::string> map_temp;

    // algorithm
    replace(input.begin(), input.end(), ',', ' ');

    // �󔒋�؂�̕����񂩂�'map_temp'���쐬����
    std::istringstream stream(input);
    int key;
    while (stream >> key)
    {
        // map �ɒǉ� (int key, string filename + key) 
        map_temp.emplace(key, "filename" + std::to_string(key));
    }


    return map_temp;
}


//  map�̗v�f��string�Ƃ��Ē��o����
std::string ScoredMapToString(std::map<int, std::string> map_temp)
{
    std::ostringstream stream;
    for (auto itr = map_temp.begin(); itr != map_temp.end(); itr++)
    {
        if (itr != map_temp.begin()) stream << ",";
        stream << itr->second;
    }


    return stream.str();
}


// map�̓���m�F
// ::::::::::::input�̗v�f���z��ǂ���ɐ����A�������Ă��邩:::::::::::::::
// ������
// "1,2","filename1,filename2" -> O -> key�������ɐ����A�v�f���������Ă���
// "1,2","filename2,filename1" -> X -> ���̂悤�ɗv�f�͐�������Ȃ�
void test_map_output(std::string input, std::string out)
{
    std::map<int, std::string> files = ScoredMapFromString(input);

    std::string output = ScoredMapToString(files);


    // �z��ǂ��肩�̔��f
    // assert(�z��̏o�� == ���ۂ̏o��)
    //assert(out == output);


    // ����assert
    if (out != output)
    {
        std::cerr << "test_map_output() failed," << std::endl;

        // ����
        std::cerr << "input:               \"" << input << "\"" << std::endl;
        // ���҂��ꂽ�o��
        std::cerr << "expected output:     \"" << out << "\"" << std::endl;
        // ���ۂ̏o��
        std::cerr << "actual output:       \"" << output << "\"" << std::endl;

        abort();
    }
}