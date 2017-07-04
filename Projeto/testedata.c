#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
   for(int i=0;i<5;i++){
	 struct tm *tm = localtime(&t);
    printf("%s\n", asctime(tm));
	sleep(1);
}

}
