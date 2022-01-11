#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double a[][N]){
	int i,j;
	for(i=0;i<N;i++){
		cout << "Row " << i+1 << ": ";
		for(j=0;j<N;j++){
			cin >> a[i][j];
		}
		
	}
}
void showMatrix(const bool b[][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(b[i][j]==true) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}
}
void findLocalMax(const double a[][N], bool b[][N]){
	int x,y;
	for(x=0;x<N;x++){
		for(y=0;y<N;y++){
			if(a[x][y]<a[x][y+1] || a[x][y]<a[x][y-1] || a[x][y]<a[x+1][y] || a[x][y]<a[x-1][y]) 
				b[x][y]=0;
			else b[x][y]=1;
			b[0][y]=0;
			b[N-1][y]=0;			
		}
		b[x][0]=0;
		b[x][N-1]=0;
	}
}	