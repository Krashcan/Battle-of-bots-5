#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> x;
vector<int> y;



int availableMoves(int arr[10][10],int p);
void after(int pid,int board[10][10],vector<int>& Move);
void Frontier(int pid,int board[10][10],vector<int>& Move);

void count(int state,int pid,int board[10][10],vector<int>& Count);
void Brain(int board[10][10],vector<int>& b,int pid);
int main() {
	int board[10][10];
	int i,j;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin>>board[i][j];
		}
	}
	int pid;
	cin>>pid;
	int state=availableMoves(board,pid);
	/*int size=x.size();
	int r= rand()%size + 0;
	*/
	vector<int> move;
	for(int i=0;i<x.size();i++){
		move.push_back(0);
	}
	count(state,pid,board,move);
	Frontier(pid,board,move);
	Brain(board,move,pid);
	/*
	for(int i=0;i<move.size();i++){
		cout<<x[i]<<" "<<y[i]<<" "<<move[i]<<endl;
	}
	*/
	int r=0;
	int me=-100000000;
	int z=-1000;
	for(int i=0;i<move.size();i++){
		if(move[i]>me){
			me=move[i];
			r=i;
			z=-1000;
		}
		else if(move[i]==me){
			z=i;
		}
	}
	if(z>=0)
		cout<<x[z]<<" "<<y[z]<<endl;
	cout<<x[r]<<" "<<y[r];
	return 0;
}

int availableMoves(int board[10][10],int pid){
	int state=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(board[i][j]==3){
				x.push_back(i);
				y.push_back(j);
				
			}
			if(board[i][j]==1||board[i][j]==2)
				state++;
		}
	}
	return state;
}

void Brain(int board[10][10],vector<int>& move,int pid){
	for(int i=0;i<move.size();i++){
		int flag=1;
			if(board[0][0]==pid){
				flag=0;
				int m=x[i];
				int n=y[i];
				int turn=0;
				for(--m;m>=0;m--){
					if(board[m][y[i]]!=board[m+1][y[i]]){
						turn++;
					}
					if(board[m][y[i]]==0 || board[m][y[i]]==3 ) {flag=1;break;}
				}
				if(flag==0 &&  turn<=2){
					turn=0;
					for(--n;n>=0;n--){
						if(board[x[i]][n]!=board[x[i]][n+1]){
							turn++;
						}
						if(board[x[i]][n]==0 || board[x[i]][n]==3) {flag=1;break;}
					}
					if(flag==0 &&  turn<=2)move[i]+=10000;
					else if(y[i]==8) move[i]+=-10000 ;
					turn=0;
				}
				else if(x[i]==8) move[i]+=-10000 ;
			}
			if(board[0][9]==pid){
				
				flag=0;
				int m=x[i];
				int n=y[i];
				int turn=0;
				for(--m;m>=0;m--){
					
					if(board[m][y[i]]!=board[m+1][y[i]]){
						turn++;
						
					}
					if(board[m][y[i]]==0 || board[m][y[i]]==3 ) {flag=1;break;}
				}
				if(flag==0 &&  turn<=2){
					turn=0;
					for(++n;n<=9;n++){  
						if(board[x[i]][n]!=board[x[i]][n-1]){
							turn++;
						}
						if(board[x[i]][n]==0 || board[x[i]][n]==3) {flag=1;break;}
					}
					if(flag==0 &&  turn<=2)move[i]+=10000;
					else if(y[i]==1) move[i]+=-10000 ;
					turn=0;
				}
				else if(x[i]==8) move[i]+=-10000 ;
			}
			if(board[9][0]==pid){
				flag=0;
				int m=x[i];
				int n=y[i];
				int turn=0;
				for(++m;m>=0;m++){
					if(board[m][y[i]]!=board[m-1][y[i]]){
						turn++;
					}
					if(board[m][y[i]]==0 || board[m][y[i]]==3) {flag=1;break;}
				}
				if(flag==0 &&  turn<=2){
					turn=0;
					for(--n;n>=0;n--){
						if(board[x[i]][n]!=board[x[i]][n+1]){
							turn++;
						}
						if(board[x[i]][n]==0 || board[x[i]][n]==3) {flag=1;break;}
					}
					if(flag==0 &&  turn<=2)move[i]+=10000;
					else if(y[i]==8) move[i]+=-10000 ;
					turn=0;
				}
				else if(x[i]==1) move[i]+=-10000 ;
			}
			if(board[9][9]==pid){
				flag=0;
				int m=x[i];
				int n=y[i];
				int turn=0;
				for(++m;m>=0;m++){
					if(board[m][y[i]]!=board[m-1][y[i]]){
						turn++;
					}
					if(board[m][y[i]]==0 || board[m][y[i]]==3) {flag=1;break;}
				}
				if(flag==0 &&  turn<=2){
					turn=0;
					for(++n;n<=9;n++){
						if(board[x[i]][n]!=board[x[i]][n-1]){
							turn++;
						}
						if(board[x[i]][n]==0 || board[x[i]][n]==3) {flag=1;break;}
					}
					if(flag==0 &&  turn<=2)move[i]+=10000;
					else if(y[i]==1) move[i]+=-10000 ;
					turn=0;
				}
				else if(x[i]==1) move[i]+=-10000 ;
			}
			
			if(flag==1){
			if(x[i]==1 && y[i]==1){
				if(board[0][0]==0) move[i]+=-100000000;
				continue;
			}
			if(x[i]==1 && y[i]==8){
				if(board[0][9]==0) move[i]+=-100000000;
				continue;
			}
			if(x[i]==8 && y[i]==1){
				if(board[9][0]==0) move[i]+=-100000000;
				continue;
			}
			if(x[i]==8 && y[i]==8){
				
				if(board[9][9]==0) move[i]+=-100000000;
				continue;
			}
			else if(x[i]==1 || y[i]==1 || x[i]==8 || y[i]==8){
					if(x[i]==1){
						if(board[0][y[i]]==0 || board[0][y[i]]==3){
							move[i]+=-10;
							continue;
						}
						
						else if(y[i]==0 || y[i]==9) move[i]+=100;
						
					}
					if(y[i]==1){
						if(board[x[i]][0]==0 || board[x[i]][0]==3){
							move[i]+=-10;
							continue;
						}
						else if(x[i]==0 || x[i]==9) move[i]+=100;
					}
					if(x[i]==8){
						if(board[9][y[i]]==0 || board[9][y[i]]==3){
							move[i]+=-10;
							continue;
						}
						else if(y[i]==0 || y[i]==9)move[i]+=100;
					}	
					if(y[i]==8){
						if(board[x[i]][9]==0 || board[x[i]][9]==3){
							move[i]+=-10;
							continue;
						}
						else if(x[i]==0||x[i]==9) move[i]+=100;
					}
			}	
			
			else if(x[i]==2 || y[i]==7 || x[i]==7 || y[i]==2){
				
					if(move[i]>=2){
						if(x[i]==2 ){
							if(y[i]==0 || y[i]==9) move[i]+=50;
							
							else if(board[2][y[i]]==3){
								move[i]+=10;
								continue;
							}
						}
						if(y[i]==2){
							
							if(x[i]==0 || x[i]==9) move[i]+=50;
							
							else if(board[x[i]][2]==3){
								move[i]+=10;
								continue;
							}
						}
						if(x[i]==7){
							if(y[i]==0 || y[i]==9)move[i]+=50;
							
							else if(board[7][y[i]]==3){
								move[i]+=10;
								continue;
							}
							
						}	
						if(y[i]==7){
							if(x[i]==0||x[i]==9) move[i]+=50;
							else if(board[x[i]][7]==0 || board[x[i]][7]==3){
								move[i]+=10;
								continue;
							}
							
						}
					}	
			}		
			
			else if(x[i]==0 && y[i]==0){
				move[i]+=100;
				continue;
			}
			else if(x[i]==9 && y[i]==9){
				move[i]+=100;
				continue;
			}
			else if(x[i]==0 && y[i]==9){
				move[i]+=100;
				continue;
			}
			else if(x[i]==9 && y[i]==0){
				move[i]+=100;
				continue;
			}
			else if(x[i]==0 || y[i] ==0 || x[i]==9 || y[i]==9){
				move[i]+=50;
			}
			}
	}
	
}
void after(int pid,int board[10][10],vector<int>& Move){
	int Frontier;
	int i;
	int e=1;
	if(pid==2) e=2;
	for(i=0;i<x.size();i++){
		Frontier=0;
		if(board[x[i]+1][y[i]]==e){
			int m=x[i]+1;
			int temp=0;
			while(board[m][y[i]]==e){
				temp++;
				m++;
				if(m>9 || m<0) break;
			}
			m++;
			if(m<=9 && m>=0 && board[m][y[i]]==e){
				
				Frontier+=temp;
			} 
		}
		if(board[x[i]][y[i]+1]==e){
			int m=y[i]+1;
			int temp=0;
			while(board[x[i]][m]==e){
				temp++;
				m++;
				if(m>9 || m<0) break;
			}
			m++;
			if(m<=9 && m>=0 && board[x[i]][m]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]-1][y[i]]==e){
			int m=x[i]-1;
			int temp=0;
			while(board[m][y[i]]==e){
				temp++;
				m--;
				if(m>9 || m<0) break;
			}
			m--;
			if(m<=9 && m>=0 && board[m][y[i]]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]][y[i]-1]==e){
			int m=y[i]-1;
			int temp=0;
			while(board[x[i]][m]==e){
				temp++;
				m--;
				if(m>9 || m<0) break;
			}
			m--;
			if(m<=9 && m>=0 && board[x[i]][m]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]+1][y[i]+1]==e){
			int m=x[i]+1;
			int n=y[i]+1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				m++;
				n++;
				if(m>9||m<0||n>9||n<0) break;
			}
			m++;
			n++;
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]+1][y[i]-1]==e){
			int m=x[i]+1;
			int n=y[i]-1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				m++;
				n--;
				if(m>9||m<0||n>9||n<0) break;
			}
			m++;
			n--;
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]-1][y[i]+1]==e){
			int m=x[i]-1;
			int n=y[i]+1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				m--;
				n++;
				if(m>9||m<0||n>9||n<0) break;
			}
			m--;
			n++;
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]-1][y[i]-1]==e){
			int m=x[i]-1;
			int n=y[i]-1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				m--;
				n--;
				if(m>9||m<0||n>9||n<0) break;
			}
			m--;
			n--;
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		
		Move[i]-=Frontier;
		
	}
}
void Frontier(int pid,int board[10][10],vector<int>& Move){
	int Frontier =0;
	
	int i;
	int move;
	int e=1;
	if(pid==e) e=2;
	for(i=0;i<x.size();i++){
		Frontier=0;
		if(board[x[i]+1][y[i]]==pid){
			int m=x[i]+1;
			int temp=0;
			while(board[m][y[i]]==pid){
				temp++;
				m++;
				if(m>9 || m<0) break;
			}
			
			if(m<=9 && m>=0 && board[m][y[i]]==e){
				Frontier+=temp;
			} 
		}
		if(board[x[i]][y[i]+1]==pid){
			int m=y[i]+1;
			int temp=0;
			while(board[x[i]][m]==pid){
				temp++;
				m++;
				if(m>9 || m<0) break;
			}
			
			if(m<=9 && m>=0 && board[x[i]][m]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]-1][y[i]]==pid){
			int m=x[i]-1;
			int temp=0;
			while(board[m][y[i]]==pid){
				temp++;
				m--;
				if(m>9 || m<0) break;
			}
			
			if(m<=9 && m>=0 && board[m][y[i]]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]][y[i]-1]==pid){
			int m=y[i]-1;
			int temp=0;
			while(board[x[i]][m]==pid){
				temp++;
				m--;
				if(m>9 || m<0) break;
			}
			
			if(m<=9 && m>=0 && board[x[i]][m]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]+1][y[i]+1]==pid){
			int m=x[i]+1;
			int n=y[i]+1;
			int temp=0;
			while(board[m][n]==pid){
				temp++;
				m++;
				n++;
				if(m>9||m<0||n>9||n<0) break;
			}
			
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]+1][y[i]-1]==pid){
			int m=x[i]+1;
			int n=y[i]-1;
			int temp=0;
			while(board[m][n]==pid){
				temp++;
				m++;
				n--;
				if(m>9||m<0||n>9||n<0) break;
			}
			
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]-1][y[i]+1]==pid){
			int m=x[i]-1;
			int n=y[i]+1;
			int temp=0;
			while(board[m][n]==pid){
				temp++;
				m--;
				n++;
				if(m>9||m<0||n>9||n<0) break;
			}
			
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		if(board[x[i]-1][y[i]-1]==pid){
			int m=x[i]-1;
			int n=y[i]-1;
			int temp=0;
			while(board[m][n]==pid){
				temp++;
				m--;
				n--;
				if(m>9||m<0||n>9||n<0) break;
			}
			
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==e){
				Frontier+= temp;
			} 
		}
		
		Move[i]-=Frontier;
		
	}
	
}

void count(int state,int pid,int board[10][10],vector<int>& Count){
	
	
	int i;
	
	int e=1;
	if(pid==e) e=2;
	for(i=0;i<x.size();i++){
		
		if(board[x[i]+1][y[i]]==e){
			int m=x[i]+1;
			int temp=0;
			while(board[m][y[i]]==e){
				temp++;
				if((m==5 && y[i]==5)||(m==5 && y[i]==4)||(m==4 && y[i]==5)||(m==4 && y[i]==4)) {
					
					if(state<=20)  {
						Count[i]+=100000; 
					}
				}
				m++;
				if(m>9 || m<0) break;
			}
			if(m<=9 && m>=0 && board[m][y[i]]==pid){
				Count[i]+=temp;
			} 
		}
		if(board[x[i]][y[i]+1]==e){
			int m=y[i]+1;
			int temp=0;
			while(board[x[i]][m]==e){
				temp++;
				if((m==5 && x[i]==5)||(m==5 && x[i]==4)||(m==4 && x[i]==5)||(m==4 && x[i]==4)) {
					if(state<=20)  {
						Count[i]=100000; 
						return;
						
					}
				}
				m++;
				if(m>9 || m<0) break;
			}
			if(m<=9 && m>=0 && board[x[i]][m]==pid){
				Count[i]+=temp;
			} 
		}
		if(board[x[i]-1][y[i]]==e){
			int m=x[i]-1;
			int temp=0;
			while(board[m][y[i]]==e){
				temp++;
				if((m==5 && y[i]==5)||(m==5 && y[i]==4)||(m==4 && y[i]==5)||(m==4 && y[i]==4)) {
				
					if(state<=20)  {
						Count[i]=100000; 
						return;
						
					}
				}
				m--;
				if(m>9 || m<0) break;
			}
			if(m<=9 && m>=0 && board[m][y[i]]==pid){
				Count[i]+=temp;
			} 
		}
		if(board[x[i]][y[i]-1]==e){
			int m=y[i]-1;
			int temp=0;
			while(board[x[i]][m]==e){
				temp++;
				if((m==5 && x[i]==5)||(m==5 && x[i]==4)||(m==4 && x[i]==5)||(m==4 && x[i]==4)) {
					if(state<=20)  {
						Count[i]=100000; 
						return;
						
					}
				}
				m--;
				if(m>9 || m<0) break;
			}
			if(m<=9 && m>=0 && board[x[i]][m]==pid){
				Count[i]+=temp;
			} 
		}
		if(board[x[i]+1][y[i]+1]==e){
			int m=x[i]+1;
			int n=y[i]+1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				if((m==4 && n==4)||(m==4 && n==5)||(m==5 && n==4)||(m==5 && n==5)) {
					if(state<=20)  {
						Count[i]=100000; 
						return;
						
					}
				}
				m++;
				n++;
				if(m>9||m<0||n>9||n<0) break;
			}
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==pid){
				Count[i]+=temp;
			}
		}
		if(board[x[i]+1][y[i]-1]==e){
			int m=x[i]+1;
			int n=y[i]-1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				if((m==5 && n==5)||(m==5 && n==4)||(m==4 && n==5)||(m==4 && n==4)) {
					if(state<=20)  {
						Count[i]=100000; 
						
						
					}
				}
				m++;
				n--;
				if(m>9||m<0||n>9||n<0) break;
			}
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==pid){
				Count[i]+=temp;
			}
		}
		if(board[x[i]-1][y[i]+1]==e){
			int m=x[i]-1;
			int n=y[i]+1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				if((m==5 && n==5)||(m==5 && n==4)||(m==4 && n==5)||(m==4 && n==4)) {
					if(state<=20)  {
						Count[i]=100000; 
						return;
						
					}
				}
				m--;
				n++;
				if(m>9||m<0||n>9||n<0) break;
			}
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==pid){
				Count[i]+=temp;
			}
		}
		if(board[x[i]-1][y[i]-1]==e){
			int m=x[i]-1;
			int n=y[i]-1;
			int temp=0;
			while(board[m][n]==e){
				temp++;
				if((m==5 && n==5)||(m==5 && n==4)||(m==4 && n==5)||(m==4 && n==4)) {
					if(state<=20)  {
						Count[i]=100000; 
						return;
						
					}
				}
				m--;
				n--;
				if(m>9||m<0||n>9||n<0) break;
			}
			if(m<=9 && m>=0 && n>=0 && n<=9 && board[m][n]==pid){
				Count[i]+=temp;
			}
		}
		
		
	}
	
}
