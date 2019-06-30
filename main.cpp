#include <iostream>
#include <fstream>
#define NUM 30000

int main(int argc,char *argv[]){
  FILE *f;
  char c[NUM];
  unsigned char b[NUM];
  int cp=0,cl=0,bp=0,l=0;
  int i;
  if(argc != 2 || (f=fopen(argv[1],"r")) == NULL){
  std::cout << "error!" << std::endl;
  return -1;
  }
  for(cl = 0; (c[cl]=fgetc(f)) != EOF && cl < NUM; cl++);
  for(i = 0; i < NUM; i++) b[i] = 0;
  for(; cp < cl; cp++){
    switch(c[cp]){
      case '>':
        bp++;
        break;
      case '<':
        bp--;
        break;
      case '+':
        b[bp]++;
        break;
      case '-':
        b[bp]--;
        break;
      case '.':
        putchar(b[bp]);
        break;
      case ',':
        b[bp] = getchar();
        break;
      case '[':
        if(b[bp] == 0){
          for(cp++; l > 0 || c[cp] != ']'; cp++){
            if(c[cp] == '[')l ++;
            if(c[cp ]== ']') l--;
          }
        }
        break;
      case ']':
        if(b[bp]!=0){
          for(cp--; l>0 || c[cp] != '['; cp--){
            if(c[cp] == '[') l--;
            if(c[cp] == ']') l++;
            cp--;
          }
        }
        break;
      default:
        break;
    }
  }
  fclose(f);
  std::cout << "execution end" << std::endl;
  return 0;
}