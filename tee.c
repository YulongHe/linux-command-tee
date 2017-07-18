/**
* @brief: this tee.c used general open/write/close. realize tee(1)
*		  read from standard input and write to standard output and files.
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
#include<stdio.h>
#include<stdlib.h>

#define buffer_size 1024
int main(int argc, char *argv[])
{	
    int InputFd, OutputFd;
	int OpenFlags = O_CREAT | O_WRONLY;
	char *file; //new file name
	int FilePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	int numread, numwrite; //count num of read/write buffer
	char buffer[buffer_size]; //save standard input

	if((argc != 2) && (argc != 3))
	{
		printf("Please input a right param!\n");
	}
	//printf("%d, %s", argc, argv[1]);

	if(argc == 2) //creat a new file
	{
		OpenFlags |= O_TRUNC;
		file = argv[1];
	}
	else if((argc == 3) && (strcmp(argv[1], "-a") == 0)) //append to file
	{
		OpenFlags |= O_APPEND;
		file = argv[2];
		printf("this file will append!\n");
	}
	else
		printf("Unknown argument!\n");

	OutputFd = open(file, OpenFlags, FilePerms); //open file ready to write
	if(OutputFd == -1) //open file error
		printf("open file error!\n");
	while((numread = read(STDIN_FILENO, buffer, buffer_size))>0) //read standard input and sae string to buffer
	{
		numwrite = write(OutputFd, buffer, numread);//write buffer to file
		if(numwrite != numread)
			printf("Fatal error,couldn't write whole buffer to file\n");
		write(STDOUT_FILENO, buffer, numread);//write to standard output
	}

	if(close(OutputFd) == -1)
		printf("close OutFd error!\n");
	
	exit(0);
}       
