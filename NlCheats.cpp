#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <fcntl.h>
#include "Constants.h"
using namespace std;

class NLCheats {
    static void saveListOfCheats(const std::string& path, const std::string& jsonName) {
        /*val pathToFolder = File(path)

        val listOfPairs = readFileAndFormVectorOfStrings(pathToFolder)
        val updatedListOfPairs = getUpdatedListOfPairsByDescriptionPath(listOfPairs)
        val listOfCheats = convertListOfPairsIntoListOfCheats(updatedListOfPairs)
        val listOfJsons = getListOfJsons(listOfCheats)
        putListOfJsonsIntoLocalFile(jsonName, listOfJsons)*/

        auto vectorOfStrings = readFileAndFormVectorOfStrings(path);
        for (auto element : vectorOfStrings)
            cout << "\n" + element;

        /*auto vectorOfPairs = convertVectorOfStringsIntoListOfPairs(vectorOfStrings);
        auto updatedVectorOfPairs = getUpdatedListOfPairsByDescriptionPath(vectorOfPairs);

        for (const auto& element : updatedVectorOfPairs) {
            cout << "\nЭлемент вектора:" << element.first;
        }*/
    }
    static void /*vector<string>*/ readFileAndFormVectorOfStrings(const std::string& path) {
        

        /*vector<string> vectorOfStrings;
        string element;
        // Объявление input file stream
        ifstream file;
        // Открываем file stream
        file.open(path);
        // Проверяем, был ли открыт файл
        if (!file) {
            cerr << "Unable to open file";
            exit(1);
        }
        // Читаем файл и добавляем его строки в вектор
        while (file >> element) {
            vectorOfStrings.push_back(element);
        }
        // Закрываем stream
        file.close();
        // Выводим размер вектора в консоли
        cout << "\nРазмер вектора: " << vectorOfStrings.size();
        // Возвращаем вектор строк
        return vectorOfStrings;*/

        /*std::ifstream f(path);
        std::wbuffer_convert<std::codecvt_utf8<wchar_t>> conv(f.rdbuf());
        std::wistream wf(&conv);

        #ifdef _WIN32
        _setmode(_fileno(stdout), _O_WTEXT);
        #else
        std::setlocale(LC_ALL, "");
        #endif
        for (wchar_t c; wf.get(c); )
            std::wcout << c ;

        /*system("pause");
        return 0;*/
    }
    static vector<pair<string, string>> convertVectorOfStringsIntoListOfPairs(vector<string> vectorOfStrings) {
        // Объявляем вектор пар, названий и описаний
        vector<pair<string, string>> vectorOfPairs;
        vector<string> vectorOfTitles;
        vector<string> vectorOfDescriptions;
        // Для каждого элемента, кратного двум, добавляем его в вектор названий
        // В противном случае добавляем его в список описаний
        for (int i = 0; i < vectorOfStrings.size(); ++i) {
            if (i % 2 == 0)
                vectorOfTitles.push_back(vectorOfStrings[i]);
            else vectorOfDescriptions.push_back(vectorOfStrings[i]);
        }
        // Резервируем размер вектора пар, равный размеру вектора названий
        // Формируем вектор пар из полученных векторов
        vectorOfPairs.reserve(vectorOfTitles.size());
        for (int j = 0; j < vectorOfTitles.size(); ++j) {
            vectorOfPairs.emplace_back(vectorOfTitles[j],
                            vectorOfDescriptions[j]
            );
        }
        // Возвращаем вектор пар
        return vectorOfPairs;
    }
    static vector<pair<string, string>> getUpdatedListOfPairsByDescriptionPath(vector<pair<string, string>> vectorOfPairs) {
        // Объявление input file stream
        ifstream file;
        // Объявляем обновлённый вектор пар
        vector<pair<string, string>> updatedVectorOfPairs;
        // Объявляем путь к папке с описаниями
        string pathToBaseAndDescription = CheatConstants::basePath + CheatConstants::pathToDescription;

        for (const auto& element : vectorOfPairs) {
            string line;
            string title;
            string description;

            cout << "\n" << element.first;
            cout << "\n" << element.second;
            string pathToFile = "\n" + pathToBaseAndDescription + element.second;
            cout << pathToFile;
            // Открываем file stream
            file.open(pathToFile);
            // Проверяем, был ли открыт файл
            if (!file) {
                cerr << "Unable to open file";
                exit(1);
            }
            title = element.first;
            while (file >> line) {
                description += line + "\n";
            }

            updatedVectorOfPairs.emplace_back(title, description);
            /*val bufferedReader = BufferedReader(
                    InputStreamReader(
                            FileInputStream(pathToFile),"Cp1251")
            )

            val title = it.first
            val description = bufferedReader.lines().collect(Collectors.joining("\n"))

            updatedListOfPairs.add(Pair(title, description))*/
        }

        return updatedVectorOfPairs;
    }
public:
    static void mainFunction() {
        string pathToBaseAndTitles = CheatConstants::basePath + CheatConstants::pathToTitles;
        string pathToBaseAndNLCheats = CheatConstants::basePath + CheatConstants::pathToNLCheats;
        // Первый вектор
        saveListOfCheats(pathToBaseAndTitles + "c1.txt",
                         pathToBaseAndNLCheats + "nl_cheats_#1.json");
        /*// Второй вектор
        saveListOfCheats(pathToBaseAndTitles + "c2.txt",
                         pathToBaseAndNLCheats + "nl_cheats_#2.json");
        // Третий вектор
        saveListOfCheats(pathToBaseAndTitles + "c3.txt",
                         pathToBaseAndNLCheats + "nl_cheats_#3.json");
        // Четвертый вектор
        saveListOfCheats(pathToBaseAndTitles + "c4.txt",
                         pathToBaseAndNLCheats + "nl_cheats_#4.json");
        // Пятый вектор
        saveListOfCheats(pathToBaseAndTitles + "c5.txt",
                         pathToBaseAndNLCheats + "nl_cheats_#5.json");
        // Шестой вектор
        saveListOfCheats(pathToBaseAndTitles + "c6.txt",
                         pathToBaseAndNLCheats + "nl_cheats_#6.json");*/
    }
};
