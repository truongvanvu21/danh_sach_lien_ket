#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node{
	int data;
	struct Node *next;
};
typedef Node* node;
node makeNode(int x){
	node tmp=new Node();
	tmp->data=x;
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
//chen dau
void InsertHead	(node &a, int x){
	node tmp=makeNode(x);
	if(a==NULL){
		a=tmp;
	}
	else{
		tmp->next=a;
		a=tmp;	
	}
}
//delete all cac gia tri bang x                                                                                
void DeleteData(node &a, int x){
	for(node p=a; p != NULL; p=p->next){
		for(node q=p->next; q != NULL; q=q->next){
			if(q->data ==x){
				p->next=q->next;	
			}
		}
	}
}
// hien thi danh sach tren 1 hang
void ShowList(node a){
	node p=a;
	while(p !=NULL){
		cout << p->data << " ";
		p=p->next;
	}
	cout <<  endl;
}
//nghich dao danh sach lien ket danh sach lien ket
void Reveser(node &a){
	node prev=NULL;
	node cur=a;
	node next=NULL;
	while(cur != NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	a=prev;
}
//sap xep theo thu tu tang dan
void Sort(node a){
	for(node p=a;p != NULL;p=p->next){
		for(node q=p->next; q != NULL; q=q->next){
			if(q->data < p->data) {
				swap(q->data, p->data);
			}
		}
	}
}
// xoa tat ca cac gia  tri trung nhau
void DeleteAll(node &a){
	node truoc=a;
	node sau=a->next;
	while(sau != NULL){
		if(truoc->data == sau->data){
			truoc->next = sau->next;
		}
		truoc=sau;
		sau=sau->next;
	}	
}
int  Count(node a){
	int cnt=0;
	node p=a;
	while(p != NULL){
		cnt++;
		p=p->next;
	}
	return cnt;
}
void CreateList(node &a,string s){
	stringstream ss(s);
	string tmp;
	while(ss >>tmp){
		int x=stoi(s);
		InsertHead(a, x);
	}
}
int main() {
	node head=NULL;
	string s;
	while(cin >> s){
		int x;
		if(s=="ins"){
			cin >> x;
			InsertHead(head, x);
			Sort(head);
		}
		else if(s=="del"){
			cin >> x;
			DeleteData(head, x);
		}
		else if(s=="dir"){
			ShowList(head);
		}
		else if(s=="rvs"){
			Reveser(head);
		}
		else if(s=="ord"){
			Sort(head);
		}
		else if(s=="dup"){
			DeleteAll(head);
		}
		else if(s=="cnt"){
			cout << Count(head) << endl;
		}
		else if(s=="end"){
			break;
		}
		else {
			stringstream ss(s);
			int tmp;
			ss >> tmp;
			InsertHead(head, tmp);
		}
	}	
	return 0;
}
/*
1 2 4 5 3 6 4 8 9 2 5 6
dir
rvs
dir
ord
dir
del 2
dir
ins 2
dup
dir
cnt
*/
