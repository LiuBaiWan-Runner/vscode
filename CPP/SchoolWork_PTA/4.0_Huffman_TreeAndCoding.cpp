#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string letter = "abcdefghijklmnopqrstuvwxyz";
string code[26];
int ans;
string Code;


struct HufTree {
	int Weight;
	char name;
	HufTree* lChild, * rChild;
};

struct cmp {
	bool operator ()(const HufTree T1, const HufTree T2) {
		if(T1.Weight != T2.Weight){
			return T1.Weight > T2.Weight;
		}
		else{
			return (int)T1.name<(int)T2.name;
		}
	}
};
priority_queue<HufTree, vector<HufTree>, cmp> q;

void Traverse(HufTree* T);

int main()
{
	int n, W[26];
	string let;
	cin >> n;
	cin >> let;
	for (int i = 0; i < n; i++)
		cin >> W[i], q.push({ W[i], let[i], NULL, NULL });

	HufTree* L, * R,*T;
	HufTree a, b;
	while (!q.empty())
	{
		b = q.top(), q.pop();
		L = new HufTree();
		L->Weight = b.Weight, L->name = b.name;
		L->lChild = b.lChild, L->rChild = b.rChild;

		if (!q.empty())
		{
			a = q.top(), q.pop();
			R = new HufTree();
			R->Weight = a.Weight, R->name = a.name;
			R->lChild = a.lChild, R->rChild = a.rChild;
		}
		
		else
			continue;
		if(R->Weight==L->Weight){
			swap(R,L);
		}
		q.push({ b.Weight + a.Weight, '-', L, R });
	}
	Traverse(L);
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << letter[i] << ":" << code[i] << endl;
	return 0;
}

void Traverse(HufTree* T)
{
	if (!T->lChild && !T->rChild)
	{
		code[T->name - 'a'] = Code;
		ans += T->Weight * Code.size();
		return;
	}
	Code.push_back('0');
	Traverse(T->lChild);
	Code.pop_back();

	Code.push_back('1');
	Traverse(T->rChild);
	Code.pop_back();
}
