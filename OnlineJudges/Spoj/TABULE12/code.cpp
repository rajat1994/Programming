#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
int posx,posy;
int buracox[4],buracoy[4];
bool flag;

void simula(){
	switch(x){
	
		case 1:
			posx += 1;
			posy += 2;
			break;
		case 2:
			posx += 2;
			posy += 1;
			break;
		case 3:
			posx += 2;
			posy -= 1;
			break;
		case 4:
			posx += 1;
			posy -= 2;
			break;
		case 5:
			posx -= 1;
			posy -= 2;
			break;
		case 6:
			posx -= 2;
			posy -= 1;
			break;
		case 7:
			posx -= 2;
			posy += 1;
			break;
		case 8:
			posx -= 1;
			posy += 2;
			break;
	}

	for(int i = 0; i < 4; i++)
		if(posx == buracox[i] && posy == buracoy[i])
			flag = true;
}

int main() {
	
	buracox[0] = 1; buracoy[0] = 3;
	buracox[1] = 2; buracoy[1] = 3;
	buracox[2]= 2; buracoy[2] = 5;
	buracox[3] = 5; buracoy[3] = 4;

	flag = false;
	posx = 4, posy = 3; 	
	
	scanf("%d",&n);
	int passos = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		if(!flag) passos++;
		simula();
	} 

	printf("%d\n",passos);
	return 0; 
}
