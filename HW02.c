#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
	int Keycount=4,Key,Function,FunctionKey=0,i,j,k; 
	
	do{//先輸入一次密碼，錯的話就重新輸入，直到次數滿 
		printf("輸入密碼(剩餘 %d 次) : ",Keycount);
		scanf("%d",&Key);
		Keycount--;
		if(Keycount==0){
			return 0;
		}
	}while(Key!=2025);
	
	do{//優先印出功能列 
		system("cls");
		printf("--------------------\n");
		printf("a. 印出直角三角形   \n");
		printf("b. 顯示乘法表       \n");
		printf("c. 結束             \n");	
		printf("請輸入選項 : \n");
		printf("--------------------\n");
		Function=getch();
		system("cls");
		
		if(Function == 97 || Function == 65){//功能A 
			printf("請輸入 A-N之間的字母 : ");
			FunctionKey=getch();
			while(65>FunctionKey || 78<FunctionKey && 97>FunctionKey || 110<FunctionKey){//如果輸入錯就在這邊一直輸入到對為止 
				system("cls");
				printf("A 到 N，A 到 N 好嗎，你英文不好 ? : ");
				FunctionKey=getch();
			}
			if(65<=FunctionKey && FunctionKey<=78){//確保迴圈的輸入值是固定的 
				FunctionKey+=32; 
			} 
			for(i=97 ; i<=FunctionKey ; i++){//頂層迴圈 
				printf("\n");
				for(k=0;k<FunctionKey-i;k++){//空格的迴圈 
					printf("  ");
				}
				for(j=97;j<=i;j++){//字母迴圈 
					printf("%c ",j);
				}
				
			}
			printf("\n按下任意鍵繼續...... ");
			Function=getch();
		}
		
		
		
		if(Function == 98 || Function == 66){//功能B 
			printf("請輸入 1-9 之間的數字 : ");
			FunctionKey=getch();
			while(49>FunctionKey || 57<FunctionKey){//如果輸入錯就在這邊一直輸入到對為止 
				system("cls");
				printf("不就輸入1-9而已是有多難 : ");
				FunctionKey=getch();
			}
			for(i=1 ; i<=FunctionKey-48 ; i++){//被乘數迴圈 
				printf("\n");
				for(j=1;j<=i;j++){//乘數迴圈 
					printf("%d * %d = %d ",i,j,i*j);
				}
				
			}
			printf("\n按下任意鍵繼續...... ");
			Function=getch();
		}
		
		
		
		if(Function == 99 || Function == 67){//功能C 
			printf("Continue?(Y/N) : ");
			FunctionKey=getch();
			if(FunctionKey == 78 || FunctionKey == 110){//是否為停止 
				break;
			}
			while(FunctionKey != 78 && FunctionKey != 89 && FunctionKey != 110 && FunctionKey != 121){//如果輸入錯就在這邊一直輸入到對為止 
				system("cls");
				printf("你是看不懂字是不是Y跟N選一個你也打不好給我重打 : ");
				FunctionKey=getch();
			}
		}
	}while(FunctionKey != 89 || FunctionKey != 121);
	
	system("cls");
	return 0;	
}

/*這次的~也沒有甚麼太難的，就是稍微心細一點就可以打完了(可能是因為我是重修仔才能說出這種話吧)，還行*/ 

