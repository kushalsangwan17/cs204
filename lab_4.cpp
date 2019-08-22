#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
ll mod=1e9+7;
//------------------------------------------------------------


struct node{
	int x;
	char opr;
	bool b;
};
struct etree{
	node data;
	etree * left;
	etree * right;
};

stack<node>st;
int priority(char p) ;
etree * make_tree(vector<node>v);
vector<node> intopost(vector<node>v);
int eval(etree * root);

int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		while(n--){
			string s="(";
			string tmps;
			cin>>tmps;
			s+=tmps;
			s+=')';
			int a=0,o=0;
			string curr="";
			vector<node> v;
			forl(i,0,s.si){
				if(s[i]>='0'&&s[i]<='9'){
					curr+=s[i];
				}
				else{
					if(!curr.si&&s[i]=='-'){
						curr+=s[i];
					}
					else if(curr.si==1&&curr[0]=='-'){
						curr+='1';
						//i-=2;
						s[i-1]='*';
						i-=2;
					}
					else {
						if(curr.si){
						node n;
						n.b=0;
						n.x=stoi(curr);
						v.pb(n);}
						curr="";
						node n;
						n.opr=s[i];
						n.b=1;
						v.pb(n);
					}
				}
			}
			if(curr.si){
				node n;
				n.b=0;
				n.x=stoi(curr);
				v.pb(n);
			}
			//for(int i=0;i<v.si;i++){
			//	if(v[i].b) cout<<v[i].opr<<endl;
			//	else cout<<v[i].x<<endl;
			//}
			vector<node> post=intopost(v);
			//forl(i,0,post.si){
			//	if(post[i].b) cout<<post[i].opr;
			//	else cout<<post[i].x;
			//}
			etree * root=make_tree(post);
			//cout<<root->right->left->data.x;
			cout<<eval(root)<<endl;
		}
	}
	return 0;
}

etree * make_tree(vector<node>v){
	stack<etree *> s;
	etree *t, *t1, *t2;
	forl(i,0,v.si){
		if(v[i].b){
			t=new etree;
			t->data=v[i];
			t1=s.top();
			s.pop();
			t2=s.top();
			s.pop();
			t->right=t1;
			t->left=t2;
			s.push(t);
		}
		else{
			t=new etree;
			t->data=v[i];
			t->left=NULL;
			t->right=NULL;
			s.push(t);
		}
	}
	return s.top();
}

vector<node> intopost(vector<node>v){
	vector<node> ans;
	forl(i,0,v.si){
		if(v[i].b){
			char c=v[i].opr;
			if(c=='('){
				st.push(v[i]);
			}
			else if(c==')'){
				while(st.top().opr!='('){
					ans.pb(st.top());
					st.pop();
				}
				st.pop();
			}
			else{
				while(st.top().opr!='('&&priority(c)<=priority(st.top().opr)){
					if(c=='^'&&st.top().opr=='^') break;
					ans.pb(st.top());
					st.pop();
				}
				//if(st.top().opr=='(') st.pop();
				st.push(v[i]);
			}
		}
		else{
			ans.pb(v[i]);
		}
	}
	return ans;
	
}
int eval(etree * root){
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL){
		return root->data.x;
	}
	int x=eval(root->left);
	int y=eval(root->right);
	if(root->data.opr=='+') return x+y;
	else if(root->data.opr=='-') return x-y;
	else if(root->data.opr=='*') return x*y;
	else if(root->data.opr=='/') return x/y;
	else return pow(x,y);
}

int priority(char p) 
{ 
    if(p == '^') 
    return 2; 
    else if(c == '*' || c == '/') 
    return 1; 
    else if(c == '+' || c == '-') 
    return 0; 
    else
    return -1; 
} 
