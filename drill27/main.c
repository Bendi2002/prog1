#include <stdio.h>

void func1(char* p, int x){
	printf("p: %s, x: %d\n", p,x);
}

int main(){
	printf("Hello, World!\n");

	char* h = "Hello";
	char* w = "World!";

	printf("%s %s\n",h,w);

	func1("foo",7);

	return 0;
}