#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEMORY 30000

int main(int argc, char *argv[]){

  if(argc != 2){
    printf("ファイルが指定されていないか，２つ以上指定されています\n");
    return -1;
  }

  FILE *fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("そのようなファイルはありません\n");
    return -1;
  }

  char src[1024*1024];
  char temp[500];

  while(fgets(temp, 500, fp) != NULL){
    //  for(int i=0; i<strlen(temp); i++){
    //    if(temp[i] == '\n'){
    //    }
    strcat(src, temp);
    }

  // printf("%s", src);

  unsigned char *mem = (unsigned char *)malloc(sizeof(unsigned char));
  memset(mem, 0,MEMORY);

  unsigned int pos = 0;

  for(int i = 0; i < strlen(src); i++){
    switch (src[i]){
    case '>':
      pos++;
      if(pos == sizeof(mem)) mem = (unsigned char *)realloc(mem, sizeof(unsigned char) * sizeof(mem));
      break;
    
    case '<':
      if(pos == 0){
        printf("ポインタの値を負にすることはできません\n");
        return -1;
      }
      pos--;
      break;

    case '+':
      mem[pos]++;
      break;
    
    case '-':
      mem[pos]--;
      break;

    case '.':
      putchar(mem[pos]);
      break;

    case ',':
      mem[pos] = getchar();
      break;

    case '[':
      if(mem[pos] == 0){
        int cnt = 1;
        while(cnt != 0){
          i++;
          if(i == strlen(src)){
            printf("対応する']'がありません\n");
            return -1;
          }
          if(src[i] == '[') cnt++;
          else if(src[i] == ']') cnt--;
        }
      }
      break;

    case ']':
      if(mem[pos] != 0){
        int cnt = 1;
        while(cnt != 0){
          i--;
          if(i < 0){
            printf("対応する'['がありません\n");
            return -1;
          }
          if(src[i] == ']') cnt++;
          else if(src[i] == '[') cnt--;
        }
      }
      break;

    default:
      break;
    }
  }
  free(mem);
  printf("\n処理が終了しました\n");
  return 0;
}