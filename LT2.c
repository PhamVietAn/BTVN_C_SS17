#include <stdio.h>
#include <string.h>
#include <ctype.h>

void addArr(char *arr, int size);

void countText(char *arr, int size);

void countNum(char *arr, int size);

void countSpecial(char *arr, int size);

int main(){
    int choice;
    char arr[100];
    do{
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai va in ra\n");
        printf("4. Dem so luong chu so va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
        case 1:
            printf("1. Nhap vao chuoi.\n");
            fflush(stdin);
            addArr(arr, sizeof(arr));
            break;
        
        case 2:
            printf("2. In ra chuoi.\n");
            printf("Chuoi hien tai: %s", arr);
            break;

        case 3:
            printf("3. Dem so luong chu cai va in ra.\n");
            countText(arr, strlen(arr));
            break;

        case 4:
            printf("4. Dem so luong chu so va in ra.\n");
            countNum(arr, strlen(arr));
            break;

        case 5: 
            printf("5. Dem so luong ky tu dac biet trong chuoi va in ra.\n");
            countSpecial(arr, strlen(arr));
            break;

        default:
            printf("Lua chon khong hop le, vui long chon lai.\n");
            break;
        }

    }while(choice!=6);
}

void addArr(char *arr, int size){
    printf("Nhap vao chuoi ky tu: ");
    fgets(arr, size, stdin);
    int length = strlen(arr);
    if(length>0 && arr[length-1]=='\n'){
        arr[length-1] = '\0';
    }
}

void countText(char *arr, int size){
    int countText = 0;
    size = strlen(arr);
    for(int i=0; i<size; i++){
        if(isalpha(arr[i])){
            countText++;
        }
    }
    printf("So chu cai: %d\n", countText);
}

void countNum(char *arr, int size){
    int countNum = 0;
    size = strlen(arr);
    for(int i=0; i<size; i++){
        if(isdigit(arr[i])){
            countNum++;
        }
    }
    printf("So chu so: %d\n", countNum);
}

void countSpecial(char *arr, int size){
    int countSpecial = 0;
    size = strlen(arr);
    for(int i=0; i<size; i++){
        if(!isalpha(arr[i]) && !isdigit(arr[i]) && !isspace(arr[i])){
            countSpecial++;
        } 
    }
    printf("So ky tu dac biet: %d\n", countSpecial);
}
