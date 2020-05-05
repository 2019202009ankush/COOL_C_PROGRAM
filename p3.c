#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argcount, char** arg)
{
	int pid = 0;
	DIR* directory = opendir("/proc");
	struct dirent *dir;
	int proid,parentid,sessionid,pgrp;
	char state;
	char filename[100000];
	 char arg_list[1024];
int fileopen;
int fileopen2;
ssize_t bytesRead,bytesWritten;
if(argcount == 1)
{
                //	int p = atoi(dir->d_name);
		       //	char fileprocess[100000];
		        dir=readdir(directory);
			char buffer[100000];
			mode_t mode=S_IRUSR|S_IWUSR|S_IXUSR|S_IXUSR|S_IRGRP|S_IROTH|S_IXOTH;
			//sprintf(fileprocess,"/proc/%d/stat",p);
			fileopen = open("/proc/dir->d_name/stat",O_RDONLY);
			if(fileopen==-1) printf("unable to open /proc\n");
			fileopen2=open("/home/ankush/Desktop/m.txt",O_WRONLY|O_EXCL|O_CREAT,mode);
			if(fileopen2==-1) printf("unable to open /m.txt\n");
			while((bytesRead=read(fileopen,&buffer,100000))>0)
			{
 		       	bytesWritten=write(fileopen2,&buffer,(ssize_t)bytesRead);
                         }
			//length = read(fd, arg_list, sizeof (arg_list));
			//printf("%s\n",buffer);
 			close (fileopen);
                        close (fileopen2);
			}
			//fscanf(file,"%d\n",&proid);
			//fscanf(file,"%s\n",filename);
			//printf("file name = %s\n",filename);
			//fscanf(file,"%c",&state);
			//printf("State = %c\n",state);
			//fscanf(file,"%d",&parentid);
			//printf("Parent processid = %d\n",parentid);
			//fscanf(file,"%d",&pgrp);
			//fscanf(file,"%d",&sessionid);
			//printf("Sessionid = %d\n",sessionid);
	 closedir(directory);


}


/*if(argcount == 2)
{
	pid = atoi(arg[1]);
	while((dir= readdir(directory)) != NULL )
	{
		if((atoi(dir->d_name)) != 0)
		{
		   if((atoi(dir->d_name)) == pid)
		     {
			int p = atoi(dir->d_name);
			char fileprocess[100000];
			sprintf(fileprocess,"/proc/%d/stat",pid);
			FILE *file = fopen(fileprocess,"r");
			fscanf(file,"%d\n",&proid);
			fscanf(file,"%s\n",filename);
			printf("file name = %s\n",filename);
			fscanf(file,"%c",&state);
			printf("State = %c\n",state);
			fscanf(file,"%d",&parentid);
			printf("Parent processid = %d\n",parentid);
			fscanf(file,"%d",&pgrp);
			fscanf(file,"%d",&sessionid);
			printf("Sessionid = %d\n",sessionid);
		     }
		}
	}
	 closedir(directory);
}

*///	DIR* filedir = opendir("/proc/*/fd");
//}


