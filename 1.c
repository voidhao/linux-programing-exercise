#include <stdio.h>
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int xor = m ^ n;
    int count = 0;
    while (xor != 0) {
        count += xor & 1;
        xor >>= 1;
    }
    printf("%d\n", count);
}
