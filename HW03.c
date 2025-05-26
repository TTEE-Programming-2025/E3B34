#include <stdio.h>
#include <stdlib.h>
#include <time.h>//random number
#include <conio.h>
#include <unistd.h>//delay

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
	printf("----------[Booking System]----------\n");
	printf("| A. Available seats               |\n");
	printf("| B. Arrange for you               |\n");
	printf("| C. Choose by yourself            |\n");
	printf("| D. Exit                          |\n");
	printf("------------------------------------\n\n");
	printf("Enter your option:\n");
} 
int main(void) {//Main 
	int Row,Column,KeyCount=2,FunctionKeyIn=0,Key,RandomSeatCount;
	int i,j,k;
	char Seats[9][9];
	
	for(Row=0;Row<9;Row++){//Seats Reset
		for(Column=0;Column<9;Column++){
			Seats[Row][Column]='-';
		}
	}
	
	srand(time(NULL));
	RandomSeatCount=0;
	
	while(RandomSeatCount<10){//Set Random Seat
		Row = rand()%9;
		Column = rand()%9;
		if(Seats[Row][Column]=='-'){
			Seats[Row][Column]='*';
			RandomSeatCount++; 
		}
	}
	
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
	
	while(1){//infinite loop
		List();
		FunctionKeyIn=getch();
		system("cls");
		while(FunctionKeyIn!=65 &&FunctionKeyIn!=66 &&FunctionKeyIn!=67 &&FunctionKeyIn!=68 &&FunctionKeyIn!=97 &&FunctionKeyIn!=98 &&FunctionKeyIn!=99 &&FunctionKeyIn!=100){
			List();
			printf("\nDamn it, stop choosing crap that's not even listed.\n");
			FunctionKeyIn=getch();
			system("cls");
		}
		
		if(FunctionKeyIn==65 || FunctionKeyIn==97){//Function A
			printf("Here are the current available seats:\n\n");
			printf(" 123456789\n");
			
			for(i=8;i>=0;i--){//Srint seats
				printf("%d",i+1);
				for(j=0;j<9;j++){
					printf("%c",Seats[i][j]);
				}
				printf("\n");
			}
			
			printf("Press any key to continue.\n");
			getch();
			system("cls");	
		}
		
		else if(FunctionKeyIn==66 || FunctionKeyIn==98){//Function B
			printf("How many people are booking? (1-4): ");
			Key=getch();
			system("cls");
			while(Key<'1' || Key>'4'){
				printf("It's 1 to 4 people, is that too hard to understand?");
				Key=getch();
				system("cls");
			} 
			switch(Key){
				case '1'://1 person
					do{
						Row = rand()%9;
						Column = rand()%9;
					}while(Seats[Row][Column]=='*');
					Seats[Row][Column]='@';
					break;
				case '2'://2 person
					do{
						Row = rand()%8;
						Column = rand()%8;
					}while(Seats[Row][Column]=='*' || Seats[Row][Column+1]=='*');
					Seats[Row][Column]='@';
					Seats[Row][Column+1]='@';
					break;
				case '3'://3 person
					do{
						Row = rand()%7;
						Column = rand()%7;
					}while(Seats[Row][Column]=='*' || Seats[Row][Column+1]=='*' || Seats[Row][Column+2]=='*');
					Seats[Row][Column]='@';
					Seats[Row][Column+1]='@';
					Seats[Row][Column+2]='@';
					break;
					break;
				case '4'://4 person
					printf("Do you want 4 people in one damn row or 2 by 2? (1 or 2)");
					Key=getch();
					system("cls");
					while(Key!='1' && Key!='2'){
						printf("It's literally choosing between 1 and 2, come on.");
						Key=getch();
						system("cls");
					}
					if(Key=='1'){//4 people in 1 row
						do{
							Row = rand()%6;
							Column = rand()%6;
						}while(Seats[Row][Column]=='*' || Seats[Row][Column+1]=='*' || Seats[Row][Column+2]=='*' || Seats[Row][Column+3]=='*');
						Seats[Row][Column]='@';
						Seats[Row][Column+1]='@';
						Seats[Row][Column+2]='@';
						Seats[Row][Column+3]='@';
					}
					else if(Key=='2'){//2 by 2
						do{
							Row = rand()%8;
							Column = rand()%8;
						}while(Seats[Row][Column]=='*' || Seats[Row][Column+1]=='*' || Seats[Row+1][Column]=='*' || Seats[Row+1][Column+1]=='*');
						Seats[Row][Column]='@';
						Seats[Row][Column+1]='@';
						Seats[Row+1][Column]='@';
						Seats[Row+1][Column+1]='@';
					}
					break; 
			}
			printf("Here's what the system picked for you. Happy now? (Y/N)\n");
			for(i=8;i>=0;i--){//print seats
				printf("%d",i+1);
				for(j=0;j<9;j++){
					printf("%c",Seats[i][j]);
				}
				printf("\n");
			}
			Key=getch();
			system("cls");
			while(Key!=78 && Key!=89 && Key!=110 && Key!=121 ){//others key in
				system("cls");
				printf("Is picking Yes or No too much to ask?");
				Key=getch();				
			}
			if(Key=='Y' || Key=='y'){//happy
				for(i=0;i<9;i++){
					for(j=0;j<9;j++){
						if(Seats[i][j]=='@'){
							Seats[i][j]='*';//pick success
						}
					}
				}
			}
			else if(Key=='N' || Key=='n'){//unhappy
				for(i=0;i<9;i++){
					for(j=0;j<9;j++){
						if(Seats[i][j]=='@'){
							Seats[i][j]='-';
						}
					}
				}
			}
			system("cls");
				
		}
		
		else if(FunctionKeyIn==67 || FunctionKeyIn==99){//Function C 
			printf("Manual seat selection\n\n");
			do{
				printf("Which row? : \n");
				Row=getche();
				while(Row<'1' || Row >'9'){
					system("cls");
					printf("That row doesn¡¦t even exist. Try again:\n");
					Row=getche();
				}
				Row-='0';//Row - ascii code
				printf("Row %d. Which column? : \n", Row);
				Column=getche();
				while(Column<'1' || Column >'9'){
					system("cls");
					printf("No such seat. Which column? :\n");
					Column=getche();
				}
				Column-='0';//Column - ascii code
				if(Seats[Row-1][Column-1]=='*'){
					printf("\nSomeone's already sitting there. Try again.\n");
				}
				else{
					Seats[Row-1][Column-1]='@';
					printf("Here's the seat you picked:\n\n");
					printf(" 123456789\n");
					for(i=8;i>=0;i--){
						printf("%d",i+1);
						for(j=0;j<9;j++){
							printf("%c",Seats[i][j]);
						}
						printf("\n");
					}
				}
				printf("\nPress a number to keep choosing, anything else to go back to main menu.\n");
				Key=getch();
				Seats[Row-1][Column-1]='*';
				system("cls");	
			}while('0'<=Key && Key<='9');
				
		}			
		
		else if(FunctionKeyIn==68 || FunctionKeyIn==100){//Function D 
			printf("Continue?(Y/N) : ");
			Key=getch();
			if( Key== 78 || Key == 110){
				break;
			}
			while(Key != 78 && Key != 89 && Key != 110 && Key != 121){ 
				system("cls");
				printf("Can you not read? It's just Y or N, dude: ");
				Key=getch();
			}
			system("cls");
		}
	}	
}

//This assignment wasn¡¦t much harder than the previous ones, but dealing with random values was a bit annoying. There are a lot of functions too. I could¡¦ve written separate functions to handle most of them, but¡K I was kinda too lazy to refactor. So yeah¡Xit was alright, I guess?

