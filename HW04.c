#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>//delay
#include <string.h>
char Name[10][20],NameSearch[20],PVPName[10][20],ChName[20];
int ID[10],PVPID[10],ChID;
int Math[10],PVPMath[10],ChMath;
int Physics[10],PVPPhysics[10],ChPhysics;
int English[10],PVPEnglish[10],ChEnglish;
float AVG[10],PVPAVG[10],ChAVG;
int People;
int Key=0;

void WelcomeScreen(){//Print desk 
	printf("          .ooOOoo.\n");
	printf("         o8888888o\n");
	printf("        88\"  *  \"88\n");
	printf("        (|  o o  |)\n");
	printf("         0\\  ^  //0\n");
	printf("           ) = (\n");
	printf("          /     \\\n");
	printf("         (       )\n");
	printf("        (         )\n");
	printf("       (           )\n");
	printf("      (             )\n");
	printf("     (               )\n");
	printf("    (                 )\n");
	printf("     (               )\n");
	printf("      (             )\n");
	printf("       (           )\n");
	printf("        (         )\n");
	printf("         (       )\n");
	printf("          '-----'\n");
}
void List(){//Print Function List 
	printf("----------[Grade System]----------\n");
	printf("| A. Enter Student's Grades      |\n");
	printf("| B. Display Student's Grades    |\n");
	printf("| C. Searh For Student's Grades  |\n");
	printf("| D. Grade Ranking               |\n");
	printf("| E. Exit System                 |\n");
	printf("----------------------------------\n\n");
	printf("Enter your option:\n");
} 
int FunctionA(){
	int loop,i;
	printf("總共有多少學生 (5-10) 位 : ");
	scanf("%d",&People);
	while(People<5 || People>10){//檢查輸入 
		printf("人數不對悠 只能 5-10 個人 : ");
		scanf("%d",&People);
	}

	for(loop=0;loop<People;loop++){
		printf("第 %d 個學生的姓名 : ",loop+1);
		scanf("%s",&Name[loop]);
		
		printf("%s 的學號 (6位整數) : ",Name[loop]);
		scanf("%d",&ID[loop]);
		while(ID[loop]<0 || ID[loop]>999999){//檢查輸入 
			printf("學號不在範圍內，請重新輸入 : ");
			scanf("%d",&ID[loop]);
		}
		
		printf("%s 的數學成績 : ",Name[loop]);
		scanf("%d",&Math[loop]);
		while(Math[loop]<0 || Math[loop]>100){//檢查輸入 
			printf("成績不在範圍內，請重新輸入 : ");
			scanf("%d",&Math[loop]);
		}
		
		printf("%s 的物理成績 : ",Name[loop]);
		scanf("%d",&Physics[loop]);
		while(Physics[loop]<0 || Physics[loop]>100){//檢查輸入 
			printf("成績不在範圍內，請重新輸入 : ");
			scanf("%d",&Physics[loop]);
		}
		
		printf("%s 的英文成績 : ",Name[loop]);
		scanf("%d",&English[loop]);
		while(English[loop]<0 || English[loop]>100){//檢查輸入 
			printf("成績不在範圍內，請重新輸入 : ");
			scanf("%d",&English[loop]);
		}
		
		AVG[loop]=(Math[loop]+Physics[loop]+English[loop])/3;
		
	}
	printf("成績輸入完畢......");
	
	for(loop=0;loop<People;loop++){//另開一個陣列儲存資料 
		strcpy(PVPName[loop],Name[loop]);
		PVPID[loop]=ID[loop];
		PVPMath[loop]=Math[loop];
		PVPPhysics[loop]=Physics[loop];
		PVPEnglish[loop]=English[loop];
		PVPAVG[loop]=AVG[loop];
	}
	
	for(loop=0;loop<People;loop++){//將另一個陣列的資料用來比較大小 
		for(i=0;i<People-1;i++){
			if(PVPAVG[i]<PVPAVG[i+1]){
				strcpy(ChName,PVPName[i+1]);
				ChID=PVPID[i+1];
				ChMath=PVPMath[i+1];
				ChPhysics=PVPPhysics[i+1];
				ChEnglish=PVPEnglish[i+1];
				ChAVG=PVPAVG[i+1];
				
				strcpy(PVPName[i+1],PVPName[i]);
				PVPID[i+1]=PVPID[i];
				PVPMath[i+1]=PVPMath[i];
				PVPPhysics[i+1]=PVPPhysics[i];
				PVPEnglish[i+1]=PVPEnglish[i];
				PVPAVG[i+1]=PVPAVG[i];
				
				strcpy(PVPName[i],ChName);
				PVPID[i]=ChID;
				PVPMath[i]=ChMath;
				PVPPhysics[i]=ChPhysics;
				PVPEnglish[i]=ChEnglish;
				PVPAVG[i]=ChAVG;
			}
		}
	}
	
	Sleep(1500);
}
int FunctionB(){
	int loop;
	printf("Name	ID	   M.G.  P.G.  E.G.  AVG\n");
	for(loop=0;loop<People;loop++){
		printf("%s	",Name[loop]);
		printf("%d	",ID[loop]);
		printf("%d	",Math[loop]);
		printf("%d	",Physics[loop]);
		printf("%d	",English[loop]);
		printf("%f \n",AVG[loop]);
	}
	getch();
}
int FunctionC(){
	int loop,Check=0;
	printf("要尋找的學生姓名 : ");
	scanf("%s",&NameSearch);
	for(loop=0;loop<People;loop++){
		if(strcmp(NameSearch,Name[loop])==0){
			printf("%s	",Name[loop]);
			printf("%d	",ID[loop]);
			printf("%d	",Math[loop]);
			printf("%d	",Physics[loop]);
			printf("%d	",English[loop]);
			printf("%f \n",AVG[loop]); 
		}
		else{
			Check++;	
		}
		
		
	}
	if(Check==People){
		printf("找不到，");	
	}	
	printf("按下任意按鍵退出");	
	getch();
	
}
int FunctionD(){
	
	int loop;
	printf("Rank Name ID M.G P.G E.G\n");
	for(loop=0;loop<People;loop++){
		printf("%s	",PVPName[loop]);
		printf("%d	",PVPID[loop]);
		printf("%d	",PVPMath[loop]);
		printf("%d	",PVPPhysics[loop]);
		printf("%d	",PVPEnglish[loop]);
		printf("%f \n",PVPAVG[loop]);
	}
	printf("\n\n按下任意按鍵退出");	
	getch();
}
int FunctionE(){
	printf("Continue?(Y/N) : ");
		Key=getch();
		
		while(Key != 78 && Key != 89 && Key != 110 && Key != 121){ 
			system("cls");
			printf("Can you not read? It's just Y or N, dude: ");
			Key=getch();
		}
		
		if( Key== 78 || Key == 110){
			
			return 0;
		}
		system("cls");
}
int main(void){
	int KeyCount=3,Key,FunctionKeyIn;
	WelcomeScreen();
	
	do{//Key In 
		printf("Enter the password (%d tries left): ", KeyCount);
		scanf("%d",&Key);
		printf("\n");
		KeyCount--;
		if(KeyCount==-1){
			system("cls");
			printf("Can't even remember the password? Just quit already.");
			return 0;
		}
	}while(Key!=2025);
	
	system("cls");
	printf("----------Welcome E3B34----------");
	Sleep(1500);//Delay
	system("cls");
	
	do{//infinite loop
		system("cls");
		List();
		FunctionKeyIn=getch();
		system("cls");
		while(FunctionKeyIn!=65 && FunctionKeyIn!=66 && FunctionKeyIn!=67 && FunctionKeyIn!=68 && FunctionKeyIn!=69 && FunctionKeyIn!=97 && FunctionKeyIn!=98 && FunctionKeyIn!=99 && FunctionKeyIn!=100 && FunctionKeyIn!=101){
			List();
			printf("\nDamn it, stop choosing crap that's not even listed.\n");
			FunctionKeyIn=getch();
			system("cls");
		}
		switch(FunctionKeyIn){
			case 65:
			case 97:
				FunctionA();
				break;
			case 66:
			case 98:
				FunctionB();
				break;
			case 67:
			case 99:
				FunctionC();
				break;
			case 68:
			case 100:
				FunctionD();
				break;
			case 69:
			case 101:
				FunctionE();
				break;
		}
		
	}while(1);
} 
//其實剛開始寫的時候就覺得有點難，還看了一下兩年前的我寫的程式，結果兩年前那個根本跑不動，超白癡的， 至少這次終於進步點了，程式如果你[正常使用]不亂案的話基本上都沒啥問題。然後我到這次才發現Commit要五次他媽的我每次都直接全部寫完一次交上去，又要重修了草 
