#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){   
    int FunctionMode=0;
    int code;
    char ch;
    
    printf( 
        "---------------\n"
        "               \n"
        "EEEEEEEEEEEEEEE\n"
        "333333333333333\n"
        "BBBBBBBBBBBBBBB\n"
        "333333333333333\n"
        "444444444444444\n"
        "               \n"
        "IIIIIIIIIIIIIII\n"
        "SSSSSSSSSSSSSSS\n"
        "               \n"
        "AAAAAAAAAAAAAAA\n"
        "               \n"
        "LLLLLLLLLLLLLLL\n"
        "OOOOOOOOOOOOOOO\n"
        "SSSSSSSSSSSSSSS\n"
        "EEEEEEEEEEEEEEE\n"
        "RRRRRRRRRRRRRRR\n"
        "               \n"
        "---------------\n"
        "               \n"
        "Press Any Key TO Continue.....\n"
    );// 個人風格畫面  
    
    while(1){
        system("PAUSE");
        system("CLS");
        printf("--------------------\n"
               "A-Z     Uppercase\n"
               "a-z     Lowercase\n"
               "0-9     Digit\n"
               "Other   Name\n"
               "--------------------\n"
               );
               
        ch=getch();//輸入
        system("CLS");
        if(65<=ch && ch<=90){//A-Z
            printf("Uppercase\n""Press Any Key TO Continue.....\n");
        }
        else if(97<=ch && ch<=122){//a-z
            printf("Lowercase\n""Press Any Key TO Continue.....\n");
        }
        else if(48<=ch && ch<=57){//0-9
            printf("Digit\n""Press Any Key TO Continue.....\n");
        }
        else{//其他
            printf("E3B34\n""Press Any Key TO Continue.....\n");
        }
    
    }
        
    return 0;
}
