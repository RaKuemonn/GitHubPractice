#pragma once

#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>



// string型からmapのkeyに変換し評価する
// 処理例
// "1,2" -> 1 2 -> map[1] = filename1 , map[2] = filename2
std::map<int, std::string> ScoredMapFromString(std::string input)
{
    std::map<int, std::string> map_temp;

    // algorithm
    replace(input.begin(), input.end(), ',', ' ');

    // 空白区切りの文字列から'map_temp'を作成する
    std::istringstream stream(input);
    int key;
    while (stream >> key)
    {
        // map に追加 (int key, string filename + key) 
        map_temp.emplace(key, "filename" + std::to_string(key));
    }


    return map_temp;
}


//  mapの要素をstringとして抽出する
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


// mapの動作確認
// ::::::::::::inputの要素が想定どうりに整理、代入されているか:::::::::::::::
// 処理例
// "1,2","filename1,filename2" -> O -> keyが昇順に整理、要素が代入されている
// "1,2","filename2,filename1" -> X -> このように要素は整理されない
void test_map_output(std::string input, std::string out)
{
    std::map<int, std::string> files = ScoredMapFromString(input);

    std::string output = ScoredMapToString(files);


    // 想定どうりかの判断
    // assert(想定の出力 == 実際の出力)
    //assert(out == output);


    // 手作りassert
    if (out != output)
    {
        std::cerr << "test_map_output() failed," << std::endl;

        // 入力
        std::cerr << "input:               \"" << input << "\"" << std::endl;
        // 期待された出力
        std::cerr << "expected output:     \"" << out << "\"" << std::endl;
        // 実際の出力
        std::cerr << "actual output:       \"" << output << "\"" << std::endl;

        abort();
    }
}