#include<iostream>
#include<vector>
#include<string>

using namespace std;

//12111543 �ȿ���
class Student
{ //Ŭ���� ��Ʃ��Ʈ
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
//asdfasdfasdfasdafsfsadf
vector<Student> arr; //student �������迭

///
//

///

//
//

//
//
//


bool getchart = true; //����Ű�� �������� �ߺ�����


void display(Student st) //����� �������� �κ��� ��ȸ�� ��ü���� ���ǹǷ� �Լ��� ����
{
	cout << "-------------------" << endl;
	cout << "�̸� : " << st.name << endl;
	cout << "�߰���� : " << st.mid << endl;
	cout << "�⸻��� : " << st.last << endl;
	cout << "�������� : " << st.quiz << endl;
	cout << "�⼮���� : " << st.chu << endl;
	cout << "���� : " << st.total << endl;
	cout << "���� : " << st.hackjum << endl;
	int ct = 1;
	for (int i = 0; i < arr.size(); i++) //���
	{
		if (arr[i].total > st.total)
			ct++;
	}
	cout << "���� :" << ct << endl;
	cout << "����ȭ������ ������ �ƹ�Ű�� ��������!" << endl;
	cout.clear();
	getchar();
	if (getchart==true) //���� ����Ű�� �������� ����
		getchar();
	getchart = false;
}

int main()
{

	while (1)
	{
		system("cls");
		cout << "---------------------" << endl;
		cout << "1. �л��ڷ� ���" << endl;
		cout << "2. ��ȸ" << endl;
		cout << "3. ����" << endl;
		cout << "4. ��ü���" << endl;
		cout << "5. ���������" << endl;
		cout << "0. ����" << endl;
		cout << "---------------------" << endl;

		int select;
		cout << "�Է�:" << endl;
		cin >> select;
		getchart = true; //����Ű ��� 
		if (select == 1)
		{
			Student tmp;
			
			cout << "�̸� :";
			cin >> tmp.name;
			cout << "�߰����:";
			cin >> tmp.mid;
			cout << "�⸻���:";
			cin >> tmp.last;
			cout << "��������:";
			cin >> tmp.quiz;
			cout << "�⼮����:";
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
			cout << "ã�� �̸� �Է�:";
			cin >> sttmp;
			for (int i = 0; i < arr.size(); i++) //��ȸ
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
			cout << "���� �̸� �Է�:";
			cin >> sttmp;
			for (int i = 0; i < arr.size(); i++)
			{
				if (sttmp == arr[i].name)
				{ //�̸��� ������ Ȯ��
					for (int j = i; j < arr.size() - 1; j++)
					{
						swap(arr[j], arr[j+1]); //������ �ٲ�� �ȵǹǷ� �ǵڷ� ������ ����
					}
					arr.pop_back(); //�ǵ����ڷ����
					break;
				}
				
			}
		}
		else if (select == 4)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				display(arr[i]); //��������
			}
		}
		else if (select == 5)
		{
			cout << "------------------------------" << endl;
			for (int i = 1; i <= arr.size(); i++) 
			{
				int ct = 1; //��� �ʱ�ȭ
				for (int k = 0; k < arr.size(); k++) 
				{
					for (int j = 0; j < arr.size(); j++)
					{
						if (arr[j].total > arr[k].total)
							ct++; //��� ���
					}
					if (ct == i)
					{ //for i ���� �ش��ϴ� �ش� ����� ��� ���� 3���̾ 2����� ����ؾ��ϹǷ� 2��� ���
						cout << "����:" << i << "�� ����:" << arr[k].total << " �̸�:" << arr[k].name << endl;
					}
					ct = 1;
				}

			}
			cout << "����ȭ������ ������ �ƹ�Ű�� ��������!" << endl;
			cout.clear();
			getchar();
			getchar();
			//ddsfdsfjkjkjknjhjh
		}
		else if (select == 0)
		{
			exit(1);
		}
	}

	return 0;
}