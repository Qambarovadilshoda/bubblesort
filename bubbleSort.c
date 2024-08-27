 #include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void sort_characters(char *arr,int n)
{
    for(int i = 0; i < n - 1;i++){
        for(int j = 0; j < n - i - 1;j++){
            if(arr[j] > arr[j + 1]){
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;                              
            }
        }
    }
}
int main()
{
char*arr = calloc(100,sizeof(char));
int ind = 0;
int key = open("num.txt",O_RDONLY);
if(key == -1){
    printf("\n");   
    return 1;
}
int charactersRead;
while((charactersRead = read(key,&arr[ind],1)) != 0){
    if(charactersRead == -1){
        printf("\n");
        return 1;
    }
 ind++;
}
close(key);
sort_characters(arr,ind);

int outputKey = open("sorted.txt",O_WRONLY);
if(outputKey == -1){
    printf("\n");
    return 1;
}
for(int i = 1;i < ind; i++){
    if(arr[i] == ','){
        continue;
    write(outputKey,",",1);
    write(outputKey,&arr[i],1);
    }
    write(outputKey,&arr[i],1);
    write(outputKey,",",1);
    printf("%c",arr[i]);
    printf(",");
}
close(outputKey);
printf("Tartiblangan raqamlar sorted.txt fayliga yozildi.\n");
return 0;
}