#include<windows.h>
#include<stdio.h>

//name pipe of server
int main()
{
	HANDLE hPipe;
	OVERLAPPED ovi = {0};
	char buff[200];
	DWORD read_buff;
	//hPipe = CreateNamedPipe("\\\\DESKTOP-IBDDJHT\\pipe\\japan-pipe",
	//	                    PIPE_ACCESS_DUPLEX,
	//	                    PIPE_TYPE_BYTE,
	//	                    PIPE_UNLIMITED_INSTANCES,
	//	                    1024,
	//	                    1024,
	//	                    0,NULL);
	hPipe = CreateNamedPipe("\\\\.\\pipe\\japanpipe",
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_BYTE,
		PIPE_UNLIMITED_INSTANCES,
		1024,
		1024,
		0, NULL);
	Sleep(5000);
	printf("The name pipe is succcessfully created.\r\n");

	if (::ConnectNamedPipe(hPipe,&ovi))
	{
		printf("Connected to client successfully.\r\n");
		printf("Reading data...\r\n");
		if (ReadFile(hPipe,buff,200,&read_buff,NULL))
		{
			printf("Data read successfully\r\n");
			printf("Data:%s \r\n",buff);
		}
		else
		{
			printf("Failed to read...");
		}
	}

	return 0;
}