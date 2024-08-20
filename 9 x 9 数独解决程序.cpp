#include<Windows.h>
#include<iostream>
#include<bitset>
using namespace std;
short a[10][10];
bitset<10>f[10][10];
long long cnt;
void dfs()
{
	bitset<10>now[10][10];
	short temp[10][10];
	bool flag1 = 1, flag2 = 1;
	short minx, miny, minc = 100;
	while (flag1) {
		flag1 = 0;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++) {
				if (a[i][j] == 0)
				{
					if (f[i][j] == 0)
					{
						return;
					}
					else if (f[i][j].count() == 1)
					{
						flag1 = 1;
						for (int k = 1; k <= 9; k++)
						{
							if (f[i][j][k])
							{
								a[i][j] = k;
								for (int r = 1; r <= 9; r++)
								{
									f[i][r][k] = 0;
									f[r][j][k] = 0;
								}
								short tempx = (i - 1) / 3 + 1;
								short tempy = (j - 1) / 3 + 1;
								for (int r = tempx * 3 - 2; r <= tempx * 3; r++)
								{
									for (int s = tempy * 3 - 2; s <= tempy * 3; s++)
									{
										f[r][s][k] = 0;
									}
								}
								break;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (!a[i][j])
			{
				flag2 = 0;
				if (f[i][j].count() <= minc)
				{
					minx = i; miny = j; minc = f[i][j].count();
				}
			}
		}
	}
	if (flag2)
	{
		cnt++;
		cout << "第 " << cnt << " 种方案\n";
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	memcpy(now, f, sizeof(f));
	memcpy(temp, a, sizeof(a));
	for (int k = 1; k <= 9; k++)
	{
		if (f[minx][miny][k])
		{
			a[minx][miny] = k;
			for (int r = 1; r <= 9; r++)
			{
				f[r][miny][k] = 0;
				f[minx][r][k] = 0;
			}
			short tempx = (minx - 1) / 3 + 1;
			short tempy = (miny - 1) / 3 + 1;
			for (int r = tempx * 3 - 2; r <= tempx * 3; r++)
			{
				for (int s = tempy * 3 - 2; s <= tempy * 3; s++)
				{
					f[r][s][k] = 0;
				}
			}
			dfs();
			memcpy(a, temp, sizeof(temp));
			memcpy(f, now, sizeof(now));
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << "此程序用于解决9 x 9 的数独，支持多解，并能算出所有的解 (注意，如果您输入的数独存在多解，方案数可能会多达上百种)，请将需要解决的数独输入，并以 0 代表尚未填写的空格，例如：\n8 0 0 0 0 0 0 0 0 \n0 0 3 6 0 0 0 0 0\n0 7 0 0 9 0 2 0 0\n0 5 0 0 0 7 0 0 0\n0 0 0 0 4 5 7 0 0\n0 0 0 1 0 0 0 3 0\n0 0 1 0 0 0 0 6 8\n0 0 8 5 0 0 0 1 0\n0 9 0 0 0 0 4 0 0";
	cout << "\n\n请输入：\n";
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			f[i][j] = ~f[i][j];
			f[i][j][0] = 0;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++) {
			cin >> a[i][j];
			if (a[i][j])
			{
				for (int r = 1; r <= 9; r++)
				{
					f[r][j][a[i][j]] = 0;
					f[i][r][a[i][j]] = 0;
				}
				short tempx = (i - 1) / 3 + 1;
				short tempy = (j - 1) / 3 + 1;
				for (int r = tempx * 3 - 2; r <= tempx * 3; r++)
				{
					for (int s = tempy * 3 - 2; s <= tempy * 3; s++)
					{
						f[r][s][a[i][j]] = 0;
					}
				}
			}
		}
	}
	cout << endl;
	dfs();
	cout << "共 " << cnt << "种方案";
	Sleep(2000000);
}