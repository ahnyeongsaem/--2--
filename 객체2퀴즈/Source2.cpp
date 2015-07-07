#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> arr;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };


void display()
{
	cout << "  0 1 2 3 4 5 6 7"<<endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i << " ";
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == 1)
			{
				cout << "●";
			}
			else if (arr[i][j] == 2)
			{
				cout << "○";
			}
			else cout << "▒";
		}
		cout << endl;
	}
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		vector<int> tmp = *new vector<int>(8);
		arr.push_back(tmp);
	}
	while (1)
	{
		int x, y;
		do
		{
			cout << "검은돌을 입력하시오 x,y" << endl;
			cin >> x >> y;
		} while (!(x >= 0 && y >= 0 && x < 8 && y < 8 && arr[x][y] == 0));
		arr[x][y] = 1;
		for (int k = 0; k < 8; k++)
		{
			int cx = x, cy = y;

			while (cx >= 1 && cy >= 1 && cx < 7 && cy < 7)
			{
				cx += dx[k];
				cy += dy[k];
				if (arr[cx][cy] == 2)
				{
					while (1)
					{
						if (arr[cx][cy] == 2)
							break;
						arr[cx][cy] = 1;
						cx -= dx[k];
						cy -= dy[k];
					}
					break;
				}
			}
		}
		display();
		{
			cout << "하얀돌을 입력하시오 x,y" << endl;

			cin >> x >> y;

		} while (!(x >= 0 && y >= 0 && x < 8 && y < 8 && arr[x][y] == 0));
		arr[x][y] = 2;
		for (int k = 0; k < 8; k++)
		{
			int cx = x, cy = y;

			while (cx >= 1 && cy >= 1 && cx < 7 && cy < 7)
			{
				cx += dx[k];
				cy += dy[k];
				if (arr[cx][cy] == 1)
				{
					while (1)
					{
						if (arr[cx][cy] == 1)
							break;
						arr[cx][cy] = 2;
						cx -= dx[k];
						cy -= dy[k];
					}
					break;
				}
			}
		}
		display();
	}


	return 0;
}