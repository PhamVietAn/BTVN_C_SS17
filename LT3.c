#include <stdio.h>
#include <string.h>
#include <ctype.h>

void addString(char *str, int size);

void reverseString(char *str);

int countWords(char *str);

void compareStrings(char *str1, char *str2);

void upperCase(char *str);

void ketHopChuoi(char *str1, char *str2, int size);

int main(){
    int choice;
    char str1[100], str2[100];

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                printf("1. Nhap vao chuoi.\n");
                fflush(stdin);
                addString(str1, sizeof(str1));
                break;

            case 2:
                printf("2. In ra chuoi dao nguoc.\n");
                reverseString(str1);
                printf("Chuoi dao nguoc: %s\n", str1);
                break;

            case 3:
                printf("3. Dem so luong tu trong chuoi.\n");
                printf("So luong tu: %d\n", countWords(str1));
                break;

            case 4:
                printf("4. Nhap vao chuoi khac va so sanh.\n");
                fflush(stdin);
                addString(str2, sizeof(str2));
                compareStrings(str1, str2);
                break;

            case 5:
                printf("5. In hoa tat ca chu cai trong chuoi.\n");
                upperCase(str1);
                printf("Chuoi in hoa: %s\n", str1);
                break;

            case 6:
                printf("6. Nhap vao chuoi khac va them vao chuoi ban dau.\n");
                fflush(stdin);
                addString(str2, sizeof(str2));
                ketHopChuoi(str1, str2, sizeof(str1));
                printf("Chuoi sau khi them: %s\n", str1);
                break;

            default:
                printf("Lua chon khong hop le vui long chon lai.\n");
                break;
        }

    }while(choice != 7);

}

void addString(char *str, int size) {
    printf("Nhap vao chuoi ky tu: ");
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void reverseString(char *str){
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++){
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int countWords(char *str){
    int count = 0;
    int inWord = 0;
    while(*str){
        if(isspace(*str)){
            inWord = 0;
        }else if(!inWord){
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

void compareStrings(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 > len2){
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    }else if(len1 < len2){
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    }else{
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void upperCase(char *str){
    while(*str){
        *str = toupper(*str);
        str++;
    }
}

void ketHopChuoi(char *str1, char *str2, int size){
    strcat(str1, str2);

}
