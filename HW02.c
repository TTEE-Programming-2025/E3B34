#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
	int Keycount=4,Key,Function,FunctionKey=0,i,j,k; 
	
	do{//����J�@���K�X�A�����ܴN���s��J�A���즸�ƺ� 
		printf("��J�K�X(�Ѿl %d ��) : ",Keycount);
		scanf("%d",&Key);
		Keycount--;
		if(Keycount==0){
			return 0;
		}
	}while(Key!=2025);
	
	do{//�u���L�X�\��C 
		system("cls");
		printf("--------------------\n");
		printf("a. �L�X�����T����   \n");
		printf("b. ��ܭ��k��       \n");
		printf("c. ����             \n");	
		printf("�п�J�ﶵ : \n");
		printf("--------------------\n");
		Function=getch();
		system("cls");
		
		if(Function == 97 || Function == 65){//�\��A 
			printf("�п�J A-N�������r�� : ");
			FunctionKey=getch();
			while(65>FunctionKey || 78<FunctionKey && 97>FunctionKey || 110<FunctionKey){//�p�G��J���N�b�o��@����J��אּ�� 
				system("cls");
				printf("A �� N�AA �� N �n�ܡA�A�^�夣�n ? : ");
				FunctionKey=getch();
			}
			if(65<=FunctionKey && FunctionKey<=78){//�T�O�j�骺��J�ȬO�T�w�� 
				FunctionKey+=32; 
			} 
			for(i=97 ; i<=FunctionKey ; i++){//���h�j�� 
				printf("\n");
				for(k=0;k<FunctionKey-i;k++){//�Ů檺�j�� 
					printf("  ");
				}
				for(j=97;j<=i;j++){//�r���j�� 
					printf("%c ",j);
				}
				
			}
			printf("\n���U���N���~��...... ");
			Function=getch();
		}
		
		
		
		if(Function == 98 || Function == 66){//�\��B 
			printf("�п�J 1-9 �������Ʀr : ");
			FunctionKey=getch();
			while(49>FunctionKey || 57<FunctionKey){//�p�G��J���N�b�o��@����J��אּ�� 
				system("cls");
				printf("���N��J1-9�Ӥw�O���h�� : ");
				FunctionKey=getch();
			}
			for(i=1 ; i<=FunctionKey-48 ; i++){//�Q���ưj�� 
				printf("\n");
				for(j=1;j<=i;j++){//���ưj�� 
					printf("%d * %d = %d ",i,j,i*j);
				}
				
			}
			printf("\n���U���N���~��...... ");
			Function=getch();
		}
		
		
		
		if(Function == 99 || Function == 67){//�\��C 
			printf("Continue?(Y/N) : ");
			FunctionKey=getch();
			if(FunctionKey == 78 || FunctionKey == 110){//�O�_������ 
				break;
			}
			while(FunctionKey != 78 && FunctionKey != 89 && FunctionKey != 110 && FunctionKey != 121){//�p�G��J���N�b�o��@����J��אּ�� 
				system("cls");
				printf("�A�O�ݤ����r�O���OY��N��@�ӧA�]�����n���ڭ��� : ");
				FunctionKey=getch();
			}
		}
	}while(FunctionKey != 89 || FunctionKey != 121);
	
	system("cls");
	return 0;	
}

/*�o����~�]�S���ƻ�������A�N�O�y�L�߲Ӥ@�I�N�i�H�����F(�i��O�]���ڬO���ץJ�~�໡�X�o�ظܧa)�A�٦�*/ 

