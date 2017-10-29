#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

/*
#include<time.h>
#include<stdlib.h>
*/

int rand_gen() {
	int rand_file = open("/dev/random", O_RDONLY);
	if (rand_file == -1) {
		printf("%d: %s\n", errno, strerror(errno));
	}
	int rand;
	read(rand_file, &rand, sizeof(rand));
	close(rand_file);
	return rand;
}

int main() {
	//rand_gen();
  umask(0000);
	//srand(time(NULL));

	char file_name[] = "arr_data";

	int arr[10];
	int copy[10];
	int x, len, fd;

	printf("generating numbers\n");
	for (x = 0; x < 10; x++) {
		arr[x] = rand_gen();
		//arr[x] = rand();
		printf("%d: %d\n", x, arr[x]);
	}

	//write the numbers to the file
	fd = open(file_name, O_CREAT | O_WRONLY, 0644);
	len = write(fd, arr, sizeof(arr));
	close(fd);

	printf("bytes written: %d\n", len);
	if (len < 0) {
		printf("%d: %s\n", errno, strerror(errno));
	}


	//now read it back
	fd = open(file_name, O_RDONLY);
	len = read(fd, copy, sizeof(copy));
	close(fd);

	printf("bytes read: %d\n", len);
	if (len < 0) {
		printf("%d: %s\n", errno, strerror(errno));
	}

	printf("reading numbers\n");
	for (x = 0; x < 10; x++) {
		printf("%d: %d\n", x, copy[x]);
	}


	return 0;
}
