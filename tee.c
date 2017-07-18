/**
* @brief: this tee.c used general open/write/close. realize tee(1)
*
* @param: the file(if not exixt) you want write(use general input)
*
* @return: 0 is success
*
* @log: yulong -20170718 first edit
**/
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define buffer_size 1024
int main(int argc, char *argv[])
{	
    int InputFd, OutputFd;

//	if(argc == )
	printf("%d, %s\n", argc, argv[0]);
}       
