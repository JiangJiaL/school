#include<iostream>
#include <vector>
using namespace std;
struct RS{
	int need;
	int al;
};
void Print(vector<int> count, int n)
{
	for (int i = 0; i < n; i++)
	{
		
	   cout << count[i]<< ' ';
	}
	cout << endl;
}

int bank(vector<vector<RS>> &P, vector<int> &count, vector<int> av, int n, int m)
{
	vector<int> work = av;
	vector<int> finish(n);
	 //统计最后的安全序列
	cout << "请输入每个进程的状态" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> finish[i];
	}
	for (int i = 0; i < n; i++) //i代表进程
	{
		int j = 0;
		for ( j = 0; j < m;) // j代表资源类型
		{
			int k = 0;
			while (k < m)
			{
				if (P[i][j].need <= work[k] && finish[i] == 0 && j < m)  // m代表资源个数
				{
					if (k == (m - 1))
					{
						for (int s = 0; s < m; s++)
						{
							work[s] = work[s] + P[i][s].al;
						}
						finish[i] = 1;
						count.push_back(i);
						i = -1;
					}
					j++;
					k++;
					
				}
				else
				{
					break;
				}			
			}
			break;
		}
	}
	int i;
	for ( i = 0; i < n; i++)
	{
		if (finish[i] != 1)
		{
			cout << "不安全" << endl;
			return -1;
		}
	}
	return 0;
		
}

int Requ(vector<vector<RS>> &P, vector<int> & av, int n, int m)
{
	int job;
	vector<int> request(m);
	cout << "输入申请资源的进程" << endl;
	cin >> job;
	cout << "输入进程发出的资源请求" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> request[i];
	}
	for (int j = 0; j < m; j++)
	{
		if (av[j] < request[j])
		{
			cout << "请求不满足，等待" << endl;
			return -1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		P[job][i].al += request[i];
		P[job][i].need -= request[i];
		av[i] -= request[i];
	}
	return 0;
}

int main()
{
	int m; //代表资源类集合的个数
	cout << "请输入资源类集合的个数" << endl;
	cin >> m;
	int n;//代表进程个数
	cout << "请输入进程个数" << endl;
	cin >> n;
	vector<vector<RS>> P(n, vector<RS>(m));
	vector<int> av(m);
	vector<int>count; // 统计安全序列
	cout << "请输入Allocation" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> P[i][j].al;
		}
	}
	cout << "请输入Need" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> P[i][j].need;
		}
	}
	cout << "请输入Available" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> av[i];
	}
	//Print(P, n, m);
	if (bank(P,count,av, n, m) == 0)
	{
		Print(count, n);
	}
	while (1)
	{
		cout << "是否有进程发出资源请求 0:有  1:没有" << endl;
		int s;
		cin >> s;
		if (s == 0)
		{
			if (Requ(P, av, n, m) == 0)
			{
				if (bank(P, count, av, n, m) == 0)
				{
					Print(count, n);
				}
			}
			else
			{
				cout << "分配失败" << endl;
			}
		}
		else
		{
			break;
		}
	}
	system("pause");
	return 0;
}