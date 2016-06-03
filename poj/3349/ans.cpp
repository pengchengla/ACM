#include <stdio.h>
#include <string.h>

const int prime=999983;

struct Snowflake{
	int v[6];
	Snowflake *next;

	Snowflake(){
		next = NULL;
	}
};

struct Entry{
	Snowflake *pEntry;

	Entry(){
		pEntry = NULL;
	}
};

Entry hashData[prime + 1];

int GetHashCode(const Snowflake &flake){
	int s = 0;
	for( int i = 0; i < 6; i++){
		s += flake.v[i] % prime;
		s %= prime;
	}
	return s;
}

bool FlakeSame(const Snowflake &flake1,const Snowflake &flake2){
	int v[12] = {0};
	memcpy(v, flake1.v, sizeof(flake1.v));
	memcpy(v+6, flake1.v, sizeof(flake1.v));
	
	int i,j,k;
	for(i = 0; i < 6; i++){
		for( j = i, k = 0; k < 6; k++, j++)
			if(v[j] != flake2.v[k])
				break;
		if( k == 6)
			return true;
	}
	//reverse
	for( i = 0, j = 11; i < 6; i++, j--){
		int tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}
	for(i = 0; i < 6; i++){
		for( j = i, k = 0; k < 6; k++, j++)
			if(v[j] != flake2.v[k])
				break;
		if( k == 6)
			return true;
	}
	return false;

}

bool InsertIntoHash(Snowflake &flake){
	int id = GetHashCode(flake);
	if(hashData[id].pEntry == NULL){
		hashData[id].pEntry = &flake;
		return true;
	}
	else{
		Snowflake *p = hashData[id].pEntry;
		Snowflake *previous;
		while(p){
			if(FlakeSame(*p, flake))
				return false;
			previous = p;
			p = p->next;
		}
		previous->next = &flake;
		return true;
	}
}

Snowflake snowflakes[100001];
int nflakes;

int main(){
    scanf("%d", &nflakes);
	bool duplicate = false;
	for(int i = 0; i < nflakes; i++){
		for(int p=0;p<6;p++)
			scanf("%d",snowflakes[i].v+p);
		if(!duplicate)
			if(!InsertIntoHash(snowflakes[i]))
				duplicate = true;
	}
	if(duplicate)	printf("Twin snowflakes found.\n");
	else	printf("No two snowflakes are alike.\n");
	return 0;
}
