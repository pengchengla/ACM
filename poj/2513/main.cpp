#include <iostream>
#include <string>
#define MIN 251000
#define MAX 510000 
using namespace std;

struct node {
    int  flag;
    node *next[26];
}*root;

int n,tot,odd,_hash[MAX],pa[MAX];
char kind1[MIN][11],kind2[MIN][11];

node *CreateNode(){
    node *p;
    p = (node *) malloc (sizeof(node));
    p->flag = 0;
    for (int i = 0; i < 26; ++i)
        p->next[i] = NULL;
    return p;
}

int Insert(char *str) {
    int i = 0,k;
    node *p = root;
    while (str[i]){
        k = str[i++] - 'a';
        if (p->next[k] == NULL)
            p->next[k] = CreateNode();
        p = p->next[k];
    }
    if (p->flag == 0) p->flag = tot++;
    return p->flag;     
}

int GetPa(int n){
    int r = n,x = n,q;
    while (r != pa[r]) r = pa[r];
    while (x != r) 
        q = pa[x],pa[x] = r,x = q;
    return r;
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
    int i,j,k,fir,sec; 
    i = tot = 1;
    root = CreateNode();
    memset(_hash,0,sizeof(_hash));
	while(cin>>kind1[i]>>kind2[i]){
        k = Insert(kind1[i]);
        _hash[k]++;
        k = Insert(kind2[i]);
        _hash[k]++;
        i++;
    }
    
    n = i,odd = 0;
    for (i = 1; i < tot; ++i)     
        if (_hash[i] % 2 == 1) odd++;
    if (odd != 0 && odd != 2 ) {
		cout<<"Impossible"<<endl;
        return 0;
    }
    
	//判连通
    for (i = 1; i < tot; ++i) pa[i] = i;
    for (i = 1; i < n; ++i){
        k = Insert(kind1[i]);
        fir = GetPa(k);
        k = Insert(kind2[i]);
        sec = GetPa(k);
        pa[fir] = sec;
    }
        
    fir = GetPa(1);
    for (i = 2; i < tot; ++i) {
        sec = GetPa(i);
        if (sec != fir) {
			cout<<"Impossible"<<endl;
            return 0;
        }
    }
	cout<<"Possible"<<endl;
}
