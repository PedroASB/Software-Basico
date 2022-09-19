// gcc -no-pie main03.c process.c -o main03 && ./main03
// gcc -no-pie main03.c process.S -o main03-asm && ./main03-asm

int calc(int i, int j, int k, int l, int m, int n);

int process(int a, int b, int c, int d, int e, int f) {
    int r = calc(f, e, d, c, b, a);
    return r + a + b + c + d + e + f;
}