#include <stdio.h>
#include <string.h>

char* commonSuffix(const char* str1, const char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = len1 - 1;
    int j = len2 - 1;
    while(i >= 0 && j >= 0 && str1[i] == str2[j]){
        i--;
        j--;
    }
    return (char*)(str1 + i + 1);
}

int main(){
    const char* str1 = "Yello";
    const char* str2 = "Hello";
    const char* res = commonSuffix(str1, str2);
    printf("%s", res);

    return 0;
}