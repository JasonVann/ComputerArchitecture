// 2014-08-15
// Start studying Computer System: A progrmmer's Perspective
// Restarted on 2016-10-1

#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;
//typedef double *byte_pointer;

void test_exchange();

void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void inplace_swap(int *x, int *y){
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

int main()
{
    write(1, "hello, world\n", 13);

    int pid = fork();
    printf("pid, %d\n", pid);
    
    printf("Hello, world\n");
    int i = 200 * 300 * 400 * 500;
    printf("i is %i\n",i);
    double d =  4 * 500;
    printf("d is %f\n", d);
    int ival = 12345;
    show_int(ival);
    
    show_pointer(&ival);
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));

    int x = 100;
    int y = 200;
    inplace_swap(&x, &y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("x^x^y: %d\n", x^x^y);

    int a = 5;
    int b = 6;
    printf("a-b: %u\n", (a-b));
    //int c = (int) (1 * pow(2, 31));
    int c = -2147483648;
    c = -c;
    // ?? Why doesn't this overflow
    printf("-Int_Min is %d\n", 2147473648);

    test_exchange();
    return 0;
}

int tmult_ok(int x, int y)
{
  int p = x * y;
  return !x || p/x == y;
}

int exchange(int *xp, int y)
{
  int x = *xp;
  *xp = y;
  return x;
}

void test_exchange()
{
  int a = 4;
  int b = exchange(&a, 3);
  printf("a = %d, b = %d\n", a, b); // 3, 4
}

int var_ele(int n, int A[n][n], int i, int j)
{
    return A[i][j];

}
