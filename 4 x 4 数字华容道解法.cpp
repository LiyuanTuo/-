#include<iostream>
#include<cstring>
#include<windows.h>
#include<queue>
#include<unordered_map>
#pragma GCC optimize(2)
using namespace std;
int ans;
short endmap[5][5] = { {0,0,0,0,0},{0,1,2,3,4},{0,5,6,7,8},{0,9,10,11,12},{0,13,14,15,0} };
short dir[5][3] = { {0,0,0}, {0,1,0} ,{0,0,1},   {0,-1,0}   ,{0,0,-1} };
short biao[17][3];
short biaoend[17][3];
long long fac[16];
string direct[4] = { "��","��","��","��" };
struct Node
{
	short mat[5][5];
	short x, y;
	short flag;
	vector<string> step;
	bool operator()(Node& a, Node& b) {
		double sa = 0, sb = 0;
		if (a.flag == 1) {
			for (int i = 1; i <= 4; i++)
			{
				for (int j = 1; j <= 4; j++)
				{
					short loc = biaoend[a.mat[i][j]][1] + biaoend[a.mat[i][j]][2];
					if (loc == 2)sa += (abs(i - biaoend[a.mat[i][j]][1]) + abs(j - biaoend[a.mat[i][j]][2])) * 1.47;
					else if (loc == 3)sa += (abs(i - biaoend[a.mat[i][j]][1]) + abs(j - biaoend[a.mat[i][j]][2])) * 1.35;
					else if (loc == 4)sa += (abs(i - biaoend[a.mat[i][j]][1]) + abs(j - biaoend[a.mat[i][j]][2])) * 1.20;
					else if (loc == 5)sa += (abs(i - biaoend[a.mat[i][j]][1]) + abs(j - biaoend[a.mat[i][j]][2])) * 1.10;
					else if (loc == 6)sa += (abs(i - biaoend[a.mat[i][j]][1]) + abs(j - biaoend[a.mat[i][j]][2])) * 1.05;
					else if (loc == 7)sa += (abs(i - biaoend[a.mat[i][j]][1]) + abs(j - biaoend[a.mat[i][j]][2])) * 0.9;
					else sa += (abs(i - biaoend[a.mat[i][j]][1]) + abs(j - biaoend[a.mat[i][j]][2])) * 0.5;

					short loc2 = biaoend[b.mat[i][j]][1] + biaoend[b.mat[i][j]][2];
					if (loc2 == 2)sb += (abs(i - biaoend[b.mat[i][j]][1]) + abs(j - biaoend[b.mat[i][j]][2])) * 1.47;
					else if (loc2 == 3)sb += (abs(i - biaoend[b.mat[i][j]][1]) + abs(j - biaoend[b.mat[i][j]][2])) * 1.35;
					else if (loc2 == 4)sb += (abs(i - biaoend[b.mat[i][j]][1]) + abs(j - biaoend[b.mat[i][j]][2])) * 1.20;
					else if (loc2 == 5)sb += (abs(i - biaoend[b.mat[i][j]][1]) + abs(j - biaoend[b.mat[i][j]][2])) * 1.10;
					else if (loc2 == 6)sb += (abs(i - biaoend[b.mat[i][j]][1]) + abs(j - biaoend[b.mat[i][j]][2])) * 1.05;
					else if (loc2 == 7)sb += (abs(i - biaoend[b.mat[i][j]][1]) + abs(j - biaoend[b.mat[i][j]][2])) * 0.9;
					else sb += (abs(i - biaoend[b.mat[i][j]][1]) + abs(j - biaoend[b.mat[i][j]][2])) * 0.5;
				}
			}
			return sa * 0.87 + a.step.size() > sb * 0.87+ b.step.size();
		}//ϵ������1.4 �������貽�����  ϵ��С��1�ٶȾͺ�����
		else
		{
			for (int i = 1; i <= 4; i++)
			{
				for (int j = 1; j <= 4; j++) {
					short loc = biao[a.mat[i][j]][1] + biao[a.mat[i][j]][2];
					if (loc == 2)sa += (abs(i - biao[a.mat[i][j]][1]) + abs(j - biao[a.mat[i][j]][2])) * 1.47;
					else if (loc == 3)sa += (abs(i - biao[a.mat[i][j]][1]) + abs(j - biao[a.mat[i][j]][2])) * 1.35;
					else if (loc == 4)sa += (abs(i - biao[a.mat[i][j]][1]) + abs(j - biao[a.mat[i][j]][2])) * 1.20;
					else if (loc == 5)sa += (abs(i - biao[a.mat[i][j]][1]) + abs(j - biao[a.mat[i][j]][2])) * 1.10;
					else if (loc == 6)sa += (abs(i - biao[a.mat[i][j]][1]) + abs(j - biao[a.mat[i][j]][2])) * 1.05;
					else if (loc == 7)sa += (abs(i - biao[a.mat[i][j]][1]) + abs(j - biao[a.mat[i][j]][2])) * 0.9;
					else sa += (abs(i - biao[a.mat[i][j]][1]) + abs(j - biao[a.mat[i][j]][2])) * 0.5;

					short loc2 = biao[b.mat[i][j]][1] + biao[b.mat[i][j]][2];
					if (loc2 == 2)sb += (abs(i - biao[b.mat[i][j]][1]) + abs(j - biao[b.mat[i][j]][2])) * 1.47;
					else if (loc2 == 3)sb += (abs(i - biao[b.mat[i][j]][1]) + abs(j - biao[b.mat[i][j]][2])) * 1.35;
					else if (loc2 == 4)sb += (abs(i - biao[b.mat[i][j]][1]) + abs(j - biao[b.mat[i][j]][2])) * 1.20;
					else if (loc2 == 5)sb += (abs(i - biao[b.mat[i][j]][1]) + abs(j - biao[b.mat[i][j]][2])) * 1.10;
					else if (loc2 == 6)sb += (abs(i - biao[b.mat[i][j]][1]) + abs(j - biao[b.mat[i][j]][2])) * 1.05;
					else if (loc2 == 7)sb += (abs(i - biao[b.mat[i][j]][1]) + abs(j - biao[b.mat[i][j]][2])) * 0.9;
					else sb += (abs(i - biao[b.mat[i][j]][1]) + abs(j - biao[b.mat[i][j]][2])) * 0.5;
				}
			}
			return sa * 0.87 + a.step.size() > sb * 0.87+ b.step.size();
		}//ϵ������1.5 �������貽�����  ϵ��С��1�����ٶȾͺ�����
	}
}start, endg, cur, nex;
priority_queue<Node, vector<Node>, Node> Q;
priority_queue<Node, vector<Node>, Node> P;
unordered_map<long long, vector<string>>b;
unordered_map<long long, short>a;

long long ran(short f[5][5]) {
	bool g[16] = {};
	long long num = 0;
	short cnt = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < f[i][j]; k++)
			{
				if (!g[k])cnt++;
			}
			g[f[i][j]] = 1;
			num += cnt * fac[16 - (i - 1) * 4 - j];
			cnt = 0;
		}
	}
	return num;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fac[1] = fac[0] = 1;
	for (int i = 2; i <= 15; i++) {
		fac[i] = i * fac[i - 1];
	}
	cout << "�˳������ڽ�� 4 x 4 ���ֻ��ݵ���������������Ҫ��������ֻ��ݵ��ĳ�ʼ״̬������ 0 ��ʾ���ֻ��ݵ��еĿո����磺\n13 5 4 3\n6  2 0 9\n7 11 12 8\n15 1 10 14\n���Իس����������ո� 0 ������4 x 4�����е�����λ��)\n   ��������  ����ո���ƶ�����\n\n��Ȼ����ȫ�������һ��\n";

	cout << 13 << endl << 5 << endl << 4 << endl << 3 << endl << 6 << endl << 2 << endl << 0 << endl << 9 << endl << 7 << endl << 11 << endl << 12 << endl << 8 << endl << 15 << endl << 1 << endl << 10 << endl << 14 << endl << "Ҳ�ǿ��Ե�  �����룺" << endl;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			biaoend[(i - 1) * 4 + j][1] = i;
			biaoend[(i - 1) * 4 + j][2] = j;

			cin >> start.mat[i][j];
			biao[start.mat[i][j]][1] = i;
			biao[start.mat[i][j]][2] = j;

			if (start.mat[i][j] == 0) {
				start.x = i; start.y = j;
			}
			endg.mat[i][j] = endmap[i][j];
		}
	}
	biaoend[0][1] = biaoend[0][2] = 4;
	cout << "\n" << "���ڼ����У� �����㷨ˮƽ���ޣ�����Ҫ����һ�ᣬ��ͨ�� 50S �����ǿ��Գ������\n(�𰸲���֤�����Ž⣬��ͨ���ǽӽ����Ž�ķ���)\n\n";
	a[ran(start.mat)] = 1;
	start.flag = 1;
	P.push(start);
	if (a.count(ran(endg.mat)))
	{
		cout << "\n" << "�Ѿ���ԭ��";
		Sleep(2000000);
	}
	else
	{
		a[ran(endg.mat)] = 2;
		endg.flag = 2;
		endg.x = endg.y = 4;
		Q.push(endg);
		for (short s = 1; !Q.empty() && !P.empty(); s = (s + 1) % 2)
		{
			if (s & 1) {
				cur = nex = P.top(); P.pop();
				for (int i = 1; i <= 4; i++)
				{
					int tempx = cur.x + dir[i][1]; int tempy = cur.y + dir[i][2];
					if (tempx > 0 && tempx <= 4 && tempy > 0 && tempy <= 4)
					{
						swap(cur.mat[cur.x][cur.y], cur.mat[tempx][tempy]);
						long long tempr = ran(cur.mat);
						if (a.count(tempr))
						{
							if (a[tempr] == 2) {
								ans++;
								cout << "���� " << ans << ": ��" << cur.step.size() + 1 + (b[tempr]).size() << "�� ";
								for (string j : cur.step) {
									cout << j << " ";
								}
								cout << direct[i - 1] << " ";
								for (int j = 1; j <= b[tempr].size(); j++)
								{
									cout << b[tempr].at(b[tempr].size() - j) << " ";
								}
								cout << endl;
								if (ans == 5)
								{
									cout << "\n\n��չʾ5��";
									Sleep(2000000);
								}
								cout << "\n";
								a[tempr] = 3;
								a[ran(nex.mat)] = 3;
								cur = nex;
								continue;
							}
							cur = nex;
						}
						else
						{
							cur.x = tempx; cur.y = tempy;
							cur.step.push_back(direct[i - 1]);
							a[tempr] = 1;

							for (string j : cur.step)
							{
								b[tempr].push_back(j);
							}
							P.push(cur);
							cur = nex;
						}
					}
				}
			}
			else
			{
				cur = nex = Q.top(); Q.pop();
				for (int i = 1; i <= 4; i++) {
					int tempx = cur.x + dir[i][1]; int tempy = cur.y + dir[i][2];
					if (tempx > 0 && tempx <= 4 && tempy > 0 && tempy <= 4)
					{
						swap(cur.mat[cur.x][cur.y], cur.mat[tempx][tempy]);
						long long tempr = ran(cur.mat);
						if (a.count(tempr))
						{
							if (a[tempr] == 1) {
								ans++;
								cout << "���� " << ans << ": ��" << cur.step.size() + 1 + b[tempr].size() << "�� ";
								for (string j : b[tempr]) {
									cout << j << " ";
								}
								cout << direct[(i - 1 + 2) % 4] << " ";
								for (int j = 1; j <= cur.step.size(); j++) {
									cout << cur.step.at(cur.step.size() - j) << " ";
								}
								cout << endl;
								if (ans == 5)
								{
									cout << "\n\n��չʾ5��";
									Sleep(2000000);
								}
								cout << "\n";
								a[ran(nex.mat)] = 3;
								a[tempr] = 3;
								cur = nex;
								continue;
							}
							cur = nex;
						}
						else
						{
							cur.x = tempx; cur.y = tempy;
							cur.step.push_back(direct[(i - 1 + 2) % 4]);
							a[tempr] = 2;
							for (string j : cur.step)
							{
								b[tempr].push_back(j);
							}
							Q.push(cur);
							cur = nex;
						}
					}
				}
			}
		}
	}
}