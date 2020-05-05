#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#define BUF_SIZE 1024
int main(int argc, char * argv[])
{
  int fp,fq;
  //int pid = 0;
  DIR* directory = opendir("/proc");
  struct dirent *dir;
  int proid,parentid,sessionid,pgrp;
  ssize_t bytesRead,bytesWritten;
  char buffer[BUF_SIZE];
  mode_t mode=S_IRUSR|S_IWUSR|S_IXUSR|S_IXUSR|S_IRGRP|S_IROTH|S_IXOTH;
  dir= readdir(directory);
  char s[]="/proc/";
  char *s1=dir->d_name;
  char s3[]="/stat";
  strcat(s,s1);
  strcat(s,s3);
  printf("%s",s1);
  fp=open(s,O_RDONLY);
  if(fp==-1){
	  perror("The source file cannot be opened in rw");
     return 1;
}
fq=open("/home/ankush/Desktop/mmmmm.txt",O_WRONLY|O_EXCL|O_CREAT,mode);
if(fq==-1)
{
	perror("File could not be opened");
	return 2;
}
while((bytesRead=read(fp,&buffer,BUF_SIZE))>0){
	bytesWritten=write(fq,&buffer,(ssize_t)bytesRead);
}
close(fp);
close(fq);
return 0;
}

