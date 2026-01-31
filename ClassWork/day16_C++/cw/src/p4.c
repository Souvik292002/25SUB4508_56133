#include <pthread.h>
#include <stdio.h>

typedef unsigned long long ULL;

ULL sumOdd = 0;
ULL sumEven = 0;

void* foo() {
    sleep(5);
    for(ULL i=0;i<190000;)
        {
            printf("\ni=%lld",i);
            i++;
        }

    printf("Thread is running.\n");
    return NULL;
}



void sumofEven(void **vargs)
{
	ULL i;
    ULL start=vargs[0];
    ULL end=vargs[1];
    printf("\n{EVEN}: %ld",pthread_self());
    printf("\nStart=%lld\nend=%lld\n",start,end);
	for(i=start;i<=end;i++)
	{
		if((i & 1) == 0)
		{
			sumEven += i;
            printf("\n[even]: %lld",i);
			sleep(1);
		}
	}
}
void sumofOdd(void **vargs)
{
	ULL i;
    ULL start=vargs[0];
    ULL end=vargs[1];
    printf("\n{ODD}: %ld",pthread_self());
    printf("\nStart=%lld\nend=%lld\n",start,end);
	for(i=start;i<=end;i++)
	{
		if((i & 1) != 0)
		{
			sumOdd += i;
			printf("\n[odd]: %lld",i);
            sleep(1);
		}
	}
}

int main() {
    pthread_t thread1,thread2;
   // ULL start=0;
   // ULL end=1900000000;
    ULL vargs[2] = {0,10};

    //sumofEven(start,end);
    //sumofOdd(start,end);
    pthread_create(&thread1, NULL, sumofEven, (void *)vargs);
    pthread_create(&thread2, NULL, sumofOdd, (void *)vargs);
    
    //sleep(2);
    //foo();
    // Wait for thread to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nSum of Even=%lld\nSum of Odd=%lld",sumEven, sumOdd);
    printf("\nThis is main thread");
    
    
    printf("\nThis is main thread after join of thread\n");

    return 0;
}