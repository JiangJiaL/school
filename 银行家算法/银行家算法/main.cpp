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
	 //ͳ�����İ�ȫ����
	cout << "������ÿ�����̵�״̬" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> finish[i];
	}
	for (int i = 0; i < n; i++) //i�������
	{
		int j = 0;
		for ( j = 0; j < m;) // j������Դ����
		{
			int k = 0;
			while (k < m)
			{
				if (P[i][j].need <= work[k] && finish[i] == 0 && j < m)  // m������Դ����
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
			cout << "����ȫ" << endl;
			return -1;
		}
	}
	return 0;
		
}

int Requ(vector<vector<RS>> &P, vector<int> & av, int n, int m)
{
	int job;
	vector<int> request(m);
	cout << "����������Դ�Ľ���" << endl;
	cin >> job;
	cout << "������̷�������Դ����" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> request[i];
	}
	for (int j = 0; j < m; j++)
	{
		if (av[j] < request[j])
		{
			cout << "�������㣬�ȴ�" << endl;
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
	int m; //������Դ�༯�ϵĸ���
	cout << "��������Դ�༯�ϵĸ���" << endl;
	cin >> m;
	int n;//������̸���
	cout << "��������̸���" << endl;
	cin >> n;
	vector<vector<RS>> P(n, vector<RS>(m));
	vector<int> av(m);
	vector<int>count; // ͳ�ư�ȫ����
	cout << "������Allocation" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> P[i][j].al;
		}
	}
	cout << "������Need" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> P[i][j].need;
		}
	}
	cout << "������Available" << endl;
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
		cout << "�Ƿ��н��̷�����Դ���� 0:��  1:û��" << endl;
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
				cout << "����ʧ��" << endl;
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