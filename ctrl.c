#include<stdio.h>
#inculde<signal.h>
#include<unistd.h>
void oh(int sig){
  printf("-OH!-I GOT SIGNAL %d\n",sig);
  signal(SIGINT,oh);
 //signal(SIGINT, SIG_DFL);
}
int main(){
 //signal(SIGINT,SIG_DFL);
  signal(SIGINT,oh);
  while(1){
    printf("Hello World!!\n");
    sleep(1);
  }
}