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

//��蕶�Ɖ𓚂�ۑ�����֐�
void savefile(const vector<string>& stringVector, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const string& str : stringVector) {
            outputFile << str << endl;
        }
        outputFile.close();
    }
}

//��蕶�Ɖ𓚂�ǂݎ��֐�
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

//�t�@�C���̒��g����������֐�
void clean(const string& filename) {
    ofstream outputFile(filename, ios::trunc);
    if (outputFile.is_open()) {
        outputFile.close();
        cout << "�t�@�C���̒��g���������܂����B" << endl;
    }
    else {
    }
}
int score = 0;
int score2 = 0;
int timescore = 0;

//���͂��ꂽ�������S�Đ����Ȃ�true�A����ȊO��false���o�͂���
bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

//���ԍ��������_����10�I�яo�肷��
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
            //�񓚎��Ԃ̌v���J�n
            auto start = chrono::high_resolution_clock::now();
            time_t nowtime = time(nullptr);
            string answer;

            while (true) {
                system("cls");
                cout << "��" << i << "��!\n";
                cout << vA[number[i]] << endl;
                //�J���}��؂�ŏ�����Ă���I������4�ɕ�����
                regex rx(",");
                sregex_token_iterator it(vB[number[i]].begin(), vB[number[i]].end(), rx, -1);
                sregex_token_iterator end;
                cout << "1. " << *it++ << endl;
                cout << "2. " << *it++ << endl;
                cout << "3. " << *it++ << endl;
                cout << "4. " << *it++ << endl;

                cout << endl << "��\n";
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
            //�񓚎��Ԃ̌v���I��
            auto end1 = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::duration<double>>(end1 - start);

            //�񓚎��Ԃ�15�b�ȓ���
            if (duration.count() < 15) {
                //�������ǂ���
                if (answer == vC[number[i]]) {
                    //5�b�ȓ��ɐ������Ă��邩
                    if (duration.count() < 5) {
                        getchar();
                        cout << "�����I 10pt�ɉ����ă{�[�i�X+5pt�I" << endl;
                        cout << endl << "�񓚎���: \n" << duration.count() << "�b\n" << endl;
                        score += 15;
                        score2 += 1;
                        timescore += duration.count();
                        j += 1;
                        getchar();
                    }
                    else {
                        getchar();
                        cout << "�����I 10pt�l���I\n" << endl;
                        cout << endl << "�񓚎���: \n" << duration.count() << "�b\n" << endl;
                        score += 10;
                        score2 += 1;
                        timescore += duration.count();
                        j += 1;
                        getchar();
                    }
                }
                else {
                    getchar();
                    cout << "�s�����I�|�C���g�l���Ȃ炸...\n" << endl;
                    timescore += duration.count();
                    j += 1;
                    getchar();
                }
            }
            else {
                getchar();
                cout << "���Ԑ؂�I\n" << endl;
                timescore += 15;
                getchar();
            }
            system("cls");
        }
    }
    else {
        cout << "��萔��10��ɒB���Ă��܂���B����ǉ����Ă��������B";
        getchar();
        while(1){}
    }
   
}

//�݂�Ȃ̌��ʂ��L�^����N���X
class Person {
public:
    string name;
    int v1;
    int v2;
    int v3;

    Person(const  string& n, int v1 = 0, int v2 = 0, int v3 = 0)
        : name(n), v1(v1), v2(v2), v3(v3) {}
};

//�݂�Ȃ̌��ʂ��֐��ɋL�^����
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

//�݂�Ȃ̋L�^���t�@�C������ǂݎ��
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