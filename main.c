#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int rand_gen() {
	
}

int main() {
	umask(0000);
	
	int arr[10];
	int x;
	
	printf("generating numbers\n");
	for (x = 0; x < 10; x++) {
		arr[x] = rand_gen();
		printf("%d: %d\n", x, ar[x]");
	}
	
	fd = open("arr_data", O_CREATE | O_RDWR, 0644);
	write(fd, arr, sizeof(arr));
	
	int copy[10];
	read(fd, copy, sizeof(copy));
	
	printf("reading numbers\n");
	for (x = 0; x < 10; x++) {
		printf("%d: %d\n", x, copy[x]");
	}
	
	return 0;
}
