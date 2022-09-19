char str[] = "BEBAMUITOCAFE";

void process() {
    char *ptr = str;

    // 'a' = 97, 'A' = 65
    while (*ptr) {
        *ptr += 32;
        ptr++;
    }
}