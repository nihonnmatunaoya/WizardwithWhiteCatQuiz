#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<algorithm>
#include "header.h"
#include< cstdlib >
using namespace std;

int main() {
	Person loadperson = loaddata("persondata.txt");
	while(1){
		string str1;
		while (true) {
			system("cls");
			cout << "魔法使いwith白猫のクイズ \n" << endl;
			cout << "実行したい操作の番号を入力してください。 \n" << endl << endl;
			cout << "1. ゲームスタート \n";
			cout << "2. ルール説明を見る \n";
			cout << "3. みんなの結果を見る \n";
			cin >> str1;
			if (isNumber(str1)) {
				int str2 = stoi(str1);
				if (str2 == 1 || str2 == 2 || str2 == 3 || str2 == 987654321) {
					break;
				}
				else {
				}
			}
			else {

			}
		}
		int a = stoi(str1);

		if (a == 3) {
			 system("cls");
			 
			getchar();
			
			cout << endl << "みんなの結果\n" << endl << endl << endl << endl;
			for (const auto& person : people) {
				cout << "名前: " << person.name << "　　スコア: " << person.v1 << "　　正答数: " <<person.v2 << "　　回答時間: " << person.v3 << endl;
			}
			cout <<endl<<endl << "タイトルに戻りたい場合はEnterを入力してください。 \n";
			
			getchar();


		}
		else if (a == 2) {
			 system("cls");
			getchar();
			cout << "ルール説明\n" << endl << endl << endl;
			cout << "今から4択クイズが出題されます。正解で10pt、不正解で0pt、獲得します。\n" << endl;
			cout << "また、制限時間は10秒で5秒以内に正解するとボーナスポイントを5pt獲得することができます。\n" << endl << endl << endl;
			cout << "回答方法は答えの数字を入力した後にEnterキーを押してください。\n" << endl;
			cout << "出題ジャンルは選択することができます。\n" << endl;
			cout << "また、難易度はランダムです。\n" << endl << endl << endl;
			cout << "タイトルに戻りたい場合はEnterを入力してください。 \n";
			getchar();

		}
		else if (a == 1) {
			system("cls");
			getchar();
			cout << endl << endl << endl;
			cout << "ゲームを開始します\n" << endl;
			getchar();
			string x;
			while (true) {
				system("cls");
				cout << endl << endl << endl << "出題ジャンルを選択してください\n" << endl << endl;
				cout << "1. 芸能\n" << endl;
				cout << "2. 雑学\n" << endl;
				cout << "3. スポーツ\n" << endl;
				cout << "4. ニュース\n" << endl;
				cin >> x;

				if (isNumber(x)) {
					int str3 = stoi(x);
					if (str3 >= 1 && str3 <= 4) {
						break;
					}
					else {
					}
				}
				else {

				}
			}
			int y = stoi(x);
			system("cls");
			getchar();
			cout << endl << endl << endl << "では、始めますEnterを押してください。\n" << endl << endl;
			getchar();
			score == 0;
			if (y == 1) {
				Q(A1, B1, C1,"data1-1.txt", "data1-2.txt", "data1-3.txt");
			}
			else if (y == 2) {
				Q(A2, B2, C2, "data2-1.txt", "data2-2.txt", "data2-3.txt");

			}
			else if (y == 3) {
				Q(A3, B3, C3, "data3-1.txt", "data3-2.txt", "data3-3.txt");
			}
			else if (y == 4) {
				Q(A4, B4, C4, "data4-1.txt", "data4-2.txt", "data4-3.txt");
			}
			int score3 = score2*10;
			system("cls");
			cout << endl << endl << "終了！！\n" << endl << endl;
			getchar();
			cout << "あなたの得点は...\n";
			getchar();
			cout << score << "/150点！\n" << endl << endl;
			cout << "正解数:" << score2 << "/10問   正答率:" << score3 << "%\n";
			cout << "合計タイム:" << timescore << "秒\n";
			getchar();

			system("cls");
			cout << endl << endl << "点数を記録します\n";
			cout << "名前を入力してください\n";
			string name;
			cin >> name;
			Person person(name,score,score2,timescore);
			savedata(person, "persondata.txt");
			people.push_back(Person(person));
			getchar();
		}
		else if (a == 987654321) {
			cout << "製作者用のメニューです。";
			
				while (true) {
					string genre;
					system("cls");
					cout << "追加したいジャンルを答えてください\n";
					cout << "1. 芸能 2.雑学 3. スポーツ 4. ニュース\n";
					cout << endl << "問題と解答をリセットする場合は9を押してください\n" << endl;
					cout <<endl<<endl<<endl << "終了する場合は0\n";
					
					cin >> genre;
					if (isNumber(genre)) {
						int genre1 = stoi(genre);
						if ((genre1 >= 0 && genre1 <= 4) || genre1 == 9) {
							if (genre1 == 1) {
								int Q = 0;
								while (Q == 0) {
									system("cls");
									loadfile(A1, "data1-1.txt");
									cout << "問題文\n";
									string question;
									cin >> question;
									A1.push_back(question);

									loadfile(B1, "data1-2.txt");
									cout << "選択肢\n" << endl;
									cout << "xxx,xxx,xxx,xxxのようにコンマで区切って選択肢を4つ入力してください。\n";
									string answer1;
									cin >> answer1;
									B1.push_back(answer1);

									loadfile(C1, "data1-3.txt");
									cout << "答えの番号を入力(1-4)\n";
									string correct;
									cin >> correct;
									C1.push_back(correct);

									int size1 = A1.size();
									cout << "問題数\n" << size1 << endl;
									cout << "続ける場合は1,カテゴリ選択に戻るには0" << endl;
									int AA1;
									cin >> AA1;
									savefile(A1, "data1-1.txt");
									savefile(B1, "data1-2.txt");
									savefile(C1, "data1-3.txt");

									if (AA1 == 0) {
										Q += 1;
									}
								}
							}
							else if (genre1 == 2) {
								int Q = 0;
								while (Q == 0) {
									system("cls");
									loadfile(A2, "data2-1.txt");
									cout << "問題文\n";
									string question;
									cin >> question;
									A2.push_back(question);

									loadfile(B2, "data2-2.txt");
									cout << "選択肢\n" << endl;
									cout << "xxx xxx xxx xxxのように空白を開けて選択肢を4つ入力してください。\n";
									string answer1;
									cin >> answer1;
									B2.push_back(answer1);

									loadfile(C2, "data2-3.txt");
									cout << "答えの番号を入力(1-4)\n";
									string correct;
									cin >> correct;
									C2.push_back(correct);

									int size2 = A2.size();
									cout << "問題数\n" << size2 << endl;
									cout << "続ける場合は1,カテゴリ選択に戻るには0" << endl;
									int AA1;
									cin >> AA1;
									savefile(A2, "data2-1.txt");
									savefile(B2, "data2-2.txt");
									savefile(C2, "data2-3.txt");

									if (AA1 == 0) {
										Q += 1;
									}
								}
							}
							else if (genre1 == 3) {
								int Q = 0;
								while (Q == 0) {
									system("cls");
									loadfile(A3, "data3-1.txt");
									cout << "問題文\n";
									string question;
									cin >> question;
									A3.push_back(question);

									loadfile(B3, "data3-2.txt");
									cout << "選択肢\n" << endl;
									cout << "xxx xxx xxx xxxのように空白を開けて選択肢を4つ入力してください。\n";
									string answer1;
									cin >> answer1;
									B3.push_back(answer1);

									loadfile(C3, "data3-3.txt");
									cout << "答えの番号を入力(1-4)\n";
									string correct;
									cin >> correct;
									C3.push_back(correct);

									int size3 = A3.size();
									cout << "問題数\n" << size3 << endl;
									cout << "続ける場合は1,カテゴリ選択に戻るには0" << endl;
									int AA1;
									cin >> AA1;
									savefile(A3, "data3-1.txt");
									savefile(B3, "data3-2.txt");
									savefile(C3, "data3-3.txt");

									if (AA1 == 0) {
										Q += 1;
									}
								}
							}
							else if (genre1 == 4) {
								int Q = 0;
								while (Q == 0) {
									system("cls");
									loadfile(A4, "data4-1.txt");
									cout << "問題文\n";
									string question;
									cin >> question;
									A4.push_back(question);

									loadfile(B4, "data4-2.txt");
									cout << "選択肢\n" << endl;
									cout << "xxx xxx xxx xxxのように空白を開けて選択肢を4つ入力してください。\n";
									string answer1;
									cin >> answer1;
									B4.push_back(answer1);

									loadfile(C4, "data4-3.txt");
									cout << "答えの番号を入力(1-4)\n";
									string correct;
									cin >> correct;
									C4.push_back(correct);

									int size4 = A4.size();
									cout << "問題数\n" << size4 << endl;
									cout << "続ける場合は1,カテゴリ選択に戻るには0" << endl;
									int AA1;
									cin >> AA1;
									savefile(A4, "data4-1.txt");
									savefile(B4, "data4-2.txt");
									savefile(C4, "data4-3.txt");

									if (AA1 == 0) {
										Q += 1;
									}
								}
							}
							else if (genre1 == 9) {
								cout << "本当に消去してもよろしいですか?(戻ることはありません)\n" << endl;
								cout << "消去する場合は1を,キャンセルする場合は0を押してください\n" << endl;
								string str99;
								cin >> str99;
								int str9 = stoi(str99);
								if (str9 == 1) {
									getchar();
									clean("data1-1.txt");
									clean("data1-2.txt");
									clean("data1-3.txt");
									clean("data2-1.txt");
									clean("data2-2.txt");
									clean("data2-3.txt");
									clean("data3-1.txt");
									clean("data3-2.txt");
									clean("data3-3.txt");
									clean("data4-1.txt");
									clean("data4-2.txt");
									clean("data4-3.txt");
									cout << "消去されました\n";
									getchar();
								}
								if (str9 == 0) {
									getchar();
									cout << "キャンセルしました\n";
									getchar();
								}
							}
							else if(genre1==0){
								break;
							}
						}
						else {

						}
					}
					else {
					}
					
					
					
				}
			
		}
	}
}


