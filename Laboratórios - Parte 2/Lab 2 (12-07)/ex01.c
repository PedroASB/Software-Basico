int a = 30;
int b = 45;
int c = -10;
int d = 25;

void ex01() {
    if (a > b) {
        c = -c;
        d = 2 * c;
    }

    if (b >= a) {
        c = (a + b) * c;
        d = 1024;
    }
}