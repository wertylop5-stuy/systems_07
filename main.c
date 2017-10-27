#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int rand_gen() {
	char rand_num[];
	read("/dev/random", (int)rand_num, sizeof(rand_num));
	return rand_num;
}

int main() {
	rand_gen();

	return 0;
}
