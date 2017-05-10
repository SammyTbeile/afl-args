#include <stdio.h>
#include <string.h>

#define BUF_LEN 1024
#define SMALL_BUF_LEN 5
#define MOD_BASE 1000
#define DIV 2
#define REF_VAL (MOD_BASE - (MOD_BASE / DIV))

#define DEBUG

int f(char* str) {
    int sum = 0;
    int len = strlen( str );
    int i;
    for (i = 0; i < len; i++) {
        sum += str[i];
    }
	printf("Sum %d\n", sum);

    return sum % MOD_BASE;
}

int main(int argc, char* argv[])
{
    if (argc == 2) {
    	char str[BUF_LEN];
		int i =0;
#ifdef DEBUG
		FILE *fd = fopen("debug.txt", "a");
#endif
		for(; i < argc; i++){
#ifdef DEBUG
			fwrite(argv[i],1, strlen(argv[i]), fd);
			fwrite(" ", 1,1 ,fd);
#endif		
			char * pointer;
			if((pointer = strstr(argv[i], "%%")) != NULL){
				if (*pointer == '%'){
					printf("Didn't replace :(");	
					return 0;
				}
			}
			if((pointer = strstr(argv[i], "=")) != NULL) {
				printf("Pointer: %s\n", pointer);
			
			strncpy(str, pointer+1, strlen(pointer)-1);
//            if ( fgets( str, BUF_LEN, file ) != NULL) {
            if ( f(str) >= REF_VAL ) {
            	char buf[SMALL_BUF_LEN];
                strcpy( buf, str );
            }
        }
		}
   
#ifdef DEBUG
			fwrite("\n",1, strlen("\n"), fd);
            fclose( fd);
#endif
    }
    return 0;
}
