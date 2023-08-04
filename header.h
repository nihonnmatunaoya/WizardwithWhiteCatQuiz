#ifndef defineheader
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<regex>
#include<thread>
#include<chrono>
#include<cstdlib>
#define defineheader
using namespace std;

vector<string> A1;
vector<string> B1;
vector<string> C1;
vector<string> A2;
vector<string> B2;
vector<string> C2;
vector<string> A3;
vector<string> B3;
vector<string> C3;

vector<string> A4;
vector<string> B4;
vector<string> C4;

//問題文と解答を保存する関数
void savefile(const vector<string>& stringVector, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const string& str : stringVector) {
            outputFile << str << endl;
        }
        outputFile.close();
    }
}

//問題文と解答を読み取る関数
void loadfile(vector<string>& stringVector, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        stringVector.clear(); 
        string line;
        while (getline(inputFile, line)) {
            stringVector.push_back(line);
        }
        inputFile.close();
    }
    else {
    }
}

//ファイルの中身を消去する関数
void clean(const string& filename) {
    ofstream outputFile(filename, ios::trunc);
    if (outputFile.is_open()) {
        outputFile.close();
        cout << "ファイルの中身を消去しました。" << endl;
    }
    else {
    }
}
int score = 0;
int score2 = 0;
int timescore = 0;

//入力された文字が全て数字ならtrue、それ以外はfalseを出力する
bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

//問題番号をランダムに10個選び出題する
void Q(vector<string>& vA, vector<string>& vB, vector<string>& vC, const string& filename, const string& filename2, const string& filename3) {
    loadfile(vA, filename);
    loadfile(vB, filename2);
    loadfile(vC, filename3);
    system("cls");

    int size = static_cast<int>(vA.size());
    vector<int> number;
    size -= 1;
    if (size >= 9) {
        if (number.empty()) {
            for (int i = 0; i <= size; ++i) {
                number.push_back(i);
            }
            random_device engine;
            mt19937 g(engine());
            shuffle(number.begin(), number.end(), g);
        }
        int i = 0;
        int j = 0;
        while (i++ < 10) {
            //回答時間の計測開始
            auto start = chrono::high_resolution_clock::now();
            time_t nowtime = time(nullptr);
            string answer;

            while (true) {
                system("cls");
                cout << "第" << i << "問!\n";
                cout << vA[number[i]] << endl;
                //カンマ区切りで書かれている選択肢を4つに分ける
                regex rx(",");
                sregex_token_iterator it(vB[number[i]].begin(), vB[number[i]].end(), rx, -1);
                sregex_token_iterator end;
                cout << "1. " << *it++ << endl;
                cout << "2. " << *it++ << endl;
                cout << "3. " << *it++ << endl;
                cout << "4. " << *it++ << endl;

                cout << endl << "回答\n";
                cin >> answer;
                if (isNumber(answer)) {
                    int answer2 = stoi(answer);
                    if (answer2 >= 1 && answer2 <= 4) {
                        break;
                    }
                    else {
                    }
                }
                else {

                }
            }
            //回答時間の計測終了
            auto end1 = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::duration<double>>(end1 - start);

            //回答時間が15秒以内か
            if (duration.count() < 15) {
                //正解かどうか
                if (answer == vC[number[i]]) {
                    //5秒以内に正解しているか
                    if (duration.count() < 5) {
                        getchar();
                        cout << "正解！ 10ptに加えてボーナス+5pt！" << endl;
                        cout << endl << "回答時間: \n" << duration.count() << "秒\n" << endl;
                        score += 15;
                        score2 += 1;
                        timescore += duration.count();
                        j += 1;
                        getchar();
                    }
                    else {
                        getchar();
                        cout << "正解！ 10pt獲得！\n" << endl;
                        cout << endl << "回答時間: \n" << duration.count() << "秒\n" << endl;
                        score += 10;
                        score2 += 1;
                        timescore += duration.count();
                        j += 1;
                        getchar();
                    }
                }
                else {
                    getchar();
                    cout << "不正解！ポイント獲得ならず...\n" << endl;
                    timescore += duration.count();
                    j += 1;
                    getchar();
                }
            }
            else {
                getchar();
                cout << "時間切れ！\n" << endl;
                timescore += 15;
                getchar();
            }
            system("cls");
        }
    }
    else {
        cout << "問題数が10問に達していません。問題を追加してください。";
        getchar();
        while(1){}
    }
   
}

//みんなの結果を記録するクラス
class Person {
public:
    string name;
    int v1;
    int v2;
    int v3;

    Person(const  string& n, int v1 = 0, int v2 = 0, int v3 = 0)
        : name(n), v1(v1), v2(v2), v3(v3) {}
};

//みんなの結果を関数に記録する
void savedata(const Person& person, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << person.name << " " << person.v1 << " " << person.v2 << " " << person.v3<<endl;
        file.close();
    }
    else {
    }
}
vector<Person> people;
int Psize = people.size();

//みんなの記録をファイルから読み取る
Person loaddata(const string& filename) {
    string name;
    int v1, v2, v3;
    ifstream file(filename);
    if (file.is_open()) {
        while (file >> name >> v1 >> v2 >> v3) {
            people.push_back(Person(name, v1, v2, v3));
        }
        file.close();
        return Person(name, v1, v2, v3);
    }
    else {
    }
}
#endif