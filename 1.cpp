// quan li sinh vien
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
void InsertFirst(node &a, int x){
	node tmp=makeNode(x);
	if(a==NULL){
		a=tmp;
	}
	else{
	tmp->next=a;
	a=tmp;	
	}
}
void InsertLast(node &a, int x){
	node tmp=makeNode (x);
	if(a==NULL){
		a=tmp;
	}
	else {
		node p=a;
		while(p->next != NULL){
			p=p->next;
		}
		p->next=tmp;
	}
}
//void DeleteFirst(node &a){
//	if(a==NULL){
//		return;
//	}
//	a=a->next;
//}
//void DeleteLast(node &a){
//	if(a==NULL){
//		return;
//	}
//	node truoc=NULL, sau=a;
//	while(a->next != NULL){	
//		truoc=sau;
//		sau=sau->next;
//	}
//	if(truoc==NULL){
//		a=NULL;
//	}
//	else{
//		truoc->next=NULL;
//	}
//}
void Delete(node &a, int pos){
	int n=Size(a);
	if(pos <=0 || pos > n+1){
		return;
	}
//	if(pos == 1){
//		DeleteFirst(a); return;
//	}
//	if(pos == n+1){
//		DeleteLast(a); return;
//	}
	node truoc=NULL, sau=a;
	for(int i=1; i<pos; i++){
		truoc=sau;
		sau=sau->next;
	}
	if(truoc==NULL){
		a=a->next;
	}
	else{
		truoc->next=sau->next;
	}
}
ll Sum (node a){
	ll s=0;
	node p=a;
	while(p != NULL){
		s+=p->data;
		p=p->next;
	}
	return s;
}
int main() {
	node head=NULL;
	int n; cin >> n;
	for(int  i=1; i<=n;i++){
		int x; cin >> x;
		InsertLast(head, x);
	}
	string s;
	while(cin >> s){
		int x; int pos;
		if(s[0]=='i'){
			cin >> x;
			InsertLast(head, x);
		}
		else if(s[0]=='d'){
			cin >> pos;
			Delete(head, pos);
		}
		else if(s[0]=='s'){
			cout << Sum(head) << endl;
		}
		else if(s[0]=='0'){
			int tmp; cin>> tmp;
			if(tmp==0) break;
		}
	}
	return 0;
}
/*
6
1 1 1 1 1 1
i 4
s
i 6
i 12
i 1
s
d 1
s
list 3.9
*/
