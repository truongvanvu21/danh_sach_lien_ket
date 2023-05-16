// quan li sinh vien
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node{
	string hoten;
	ll ddong;
	double hsl;
	struct Node *next;	
	
};

typedef struct Node* node;
node makeNode(string _hoten, ll _ddong, double _hsl){
	node tmp= new Node();
	tmp->hoten=_hoten;
	tmp->ddong=_ddong;
	tmp->hsl=_hsl;
	tmp->next=NULL;
	return tmp;
}
int Size(node a){
	int cnt=0;
	while(a != NULL){
		cnt++;
		a=a->next;
	}
	return cnt;
}
void InsertFirst(string _hoten, ll _ddong, double _hsl, node &a){
	node tmp= makeNode (_hoten, _ddong, _hsl);
	if(a==NULL){
		a=tmp;
	}
	else{
		tmp->next=a;
		a=tmp;
	}
}
void InsertLast(string _hoten, ll _ddong, double _hsl, node &a){
	node tmp= makeNode (_hoten, _ddong, _hsl);
	if(a==NULL){
		a=tmp;
	}
	else{
		node p=a;
		while(p->next != NULL){
			p=p->next;
		}
		p->next=tmp;
	}
}
double SumSalary(node a){
	double res=0;
	node p=a;
	while(p != NULL){
		res += p->hsl*1390000;
		p=p->next;
	}
	return res;
}
void ListPerson(node a, double _hsl){
	node p=a;
	while(p != NULL){
		if(p->hsl==_hsl){
			cout << p->hoten << " ";
		}
		p=p->next;
	}
	cout << endl;
}
int main() {
	node head=NULL;
	string s;
	while(cin >> s){
		string hoten;
		ll ddong;
		double hsl; 
		if(s=="insF"){
			cin >> hoten >> ddong >> hsl;
			InsertFirst(hoten, ddong, hsl, head);
		}
		else if(s=="insL"){
			cin >> hoten >> ddong >> hsl;
			InsertLast(hoten, ddong, hsl, head);
		}
		else if(s=="sum"){
			cout << fixed << setprecision(3) << SumSalary(head) << endl;
		}
		else if(s=="list"){
			cin >> hsl;
			ListPerson(head, hsl);
		}
		else if(s=="fin")break;
	}
	return 0;
}
/*
insF NguyenVanHung 0914236699 4.9
insL NguyenVanDung 0914236779 3.9
insF TranVanHung 0914234567 4.2
insL NguyenVanLinh 0914236788 3.9
sum
list 3.9
*/
