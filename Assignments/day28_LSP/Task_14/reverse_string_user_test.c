#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/syscall.h>
 #include <errno.h>
 #include <string.h>

 #define SYS_reverse_string 548

 int main() {
 	char *input = NULL;
 	char *output = NULL;
 	size_t buffer_size = 256;

 	input = (char *)malloc(buffer_size);
 	output = (char *)malloc(buffer_size);

 	if (input == NULL || output == NULL) {
     	perror("Memory allocation failed");
     	return 1;
 	}

 	printf("Enter a string: ");
 	fgets(input, buffer_size, stdin);

 	if (syscall(SYS_reverse_string, input, output) < 0) {
     	perror("System call failed");
     	free(input);
     	free(output);
     	return 1;
 	}

 	printf("Reversed string from kernel: %s\n", output);

 	free(input);
 	free(output);

 	return 0;
 }
