#include<iostream>
#include<vector>
#include<string>

using namespace std;
//dsfsdf
//12111543 안영샘
class Student
{ //클래스 스튜던트
public:
	int mid;
	int last;
	int quiz;
	int chu;
	int total;
	string hackjum;
	string name;
};
//asdfasdf
<<<<<<< HEAD
//asdfasdfasdfasdafsfsadf
vector<Student> arr; //student �������迭
=======

vector<Student> arr; //student 값전역배열
>>>>>>> origin/master

///
//

///

//
//

//
//
//


bool getchart = true; //다음키를 누르세요 중복방지


void display(Student st) //등수를 보여지는 부분이 조회와 전체에서 사용되므로 함수를 만듬
{
	cout << "-------------------" << endl;
	cout << "이름 : " << st.name << endl;
	cout << "중간고사 : " << st.mid << endl;
	cout << "기말고사 : " << st.last << endl;
	cout << "퀴즈점수 : " << st.quiz << endl;
	cout << "출석점수 : " << st.chu << endl;
	cout << "총점 : " << st.total << endl;
	cout << "학점 : " << st.hackjum << endl;
	int ct = 1;
	for (int i = 0; i < arr.size(); i++) //등수
	{
		if (arr[i].total > st.total)
			ct++;
	}
	cout << "석자 :" << ct << endl;
	cout << "다음화면으로 가려면 아무키나 누르세요!" << endl;
	cout.clear();
	getchar();
	if (getchart==true) //연속 다음키를 누르세요 방지
		getchar();
	getchart = false;
}

int main()
{

	while (1)
	{
		system("cls");
		cout << "---------------------" << endl;
		cout << "1. 학생자료 등록" << endl;
		cout << "2. 조회" << endl;
		cout << "3. 삭제" << endl;
		cout << "4. 전체출력" << endl;
		cout << "5. 석차별출력" << endl;
		cout << "0. 종료" << endl;
		cout << "---------------------" << endl;

		int select;
		cout << "입력:" << endl;
		cin >> select;
		getchart = true; //연속키 허용 
		if (select == 1)
		{
			Student tmp;
			
			cout << "이름 :";
			cin >> tmp.name;
			cout << "중간고사:";
			cin >> tmp.mid;
			cout << "기말고사:";
			cin >> tmp.last;
			cout << "퀴즈점수:";
			cin >> tmp.quiz;
			cout << "출석점수:";
			cin >> tmp.chu;
			cout << endl;
			
			tmp.total = tmp.mid + tmp.last + tmp.chu + tmp.quiz;
			
			if (tmp.total >= 95) tmp.hackjum = "A+";
			else if (tmp.total >= 90) tmp.hackjum = "A";
			else if (tmp.total >= 85) tmp.hackjum = "B+";
			else if (tmp.total >= 80) tmp.hackjum = "B";
			else if (tmp.total >= 75) tmp.hackjum = "C+";
			else if (tmp.total >= 70) tmp.hackjum = "C";
			else if (tmp.total >= 65) tmp.hackjum = "D+";
			else if (tmp.total >= 60) tmp.hackjum = "D";
			else tmp.hackjum = "F";

			arr.push_back(tmp);
		}
		else if (select == 2)
		{
			string sttmp;
			cout << "찾는 이름 입력:";
			cin >> sttmp;
			for (int i = 0; i < arr.size(); i++) //조회
			{
				if (sttmp == arr[i].name)
				{
					display(arr[i]);
					break;
				}
			}
		}
		else if (select == 3)
		{
			string sttmp;
			cout << "지울 이름 입력:";
			cin >> sttmp;
			for (int i = 0; i < arr.size(); i++)
			{
				if (sttmp == arr[i].name)
				{ //이름이 같은지 확인
					for (int j = i; j < arr.size() - 1; j++)
					{
						swap(arr[j], arr[j+1]); //순서가 바뀌면 안되므로 맨뒤로 보내서 삭제
					}
					arr.pop_back(); //맨뒤의자료삭제
					break;
				}
				
			}
		}
		else if (select == 4)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				display(arr[i]); //보여지기
			}
		}
		else if (select == 5)
		{
			cout << "------------------------------" << endl;
			for (int i = 1; i <= arr.size(); i++) 
			{
				int ct = 1; //등수 초기화
				for (int k = 0; k < arr.size(); k++) 
				{
					for (int j = 0; j < arr.size(); j++)
					{
						if (arr[j].total > arr[k].total)
							ct++; //등수 계산
					}
					if (ct == i)
					{ //for i 문에 해당하는 해당 등수면 출력 만약 3명이어도 2등까지 출력해야하므로 2명다 출력
						cout << "순위:" << i << "등 총점:" << arr[k].total << " 이름:" << arr[k].name << endl;
					}
					ct = 1;
				}

			}
			cout << "다음화면으로 가려면 아무키나 누르세요!" << endl;
			cout.clear();
			getchar();
			getchar();
			//ddsfdsfjkjkjknjhjh
		}
		else if (select == 0)
		{
			exit(1);///dfasdfasdfas
		}
	}

	return 0;
}
