#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


using namespace std;

vector<string> parseResult(ifstream &in) {
    vector<string> result;

    while (!in.eof()) {
        string curLexem;
        in >> curLexem;

        if (curLexem == "-") {
            in >> curLexem;
            result.push_back(curLexem);
        }
    }

    return result;
}

string getFrequent(const vector<string> &wholeResult) {
    map<string, size_t> resultCount;

    for (const auto &i : wholeResult) {
        auto a = resultCount.find(i);

        if (a != resultCount.end()) {
            a->second++;
        } else {
            resultCount.emplace(i, 1);
        }
    }

    pair<string, size_t> maxFrequency(*resultCount.begin());

    for (const auto &i : resultCount) {
        if (i.second > maxFrequency.second) {
            maxFrequency = i;
        }
    }

    return maxFrequency.first;
}

int main() {
    string resourceFile = "car1.png";
//    string resourceFile = "car2.png";
//    string resourceFile = "car_video.mp4";

    string tmpFile = "resultTmp";

    string command = "sh ./script.sh " + resourceFile + " " + tmpFile;
    system(command.data());

    ifstream fileResult(tmpFile);
    vector<string> wholeResult = parseResult(fileResult);
    fileResult.close();

    cout << "Распознанный номер: " << getFrequent(wholeResult) << endl;

    return 0;
}
