#include <stdio.h>

int main(){
    int T, A, B;
    scanf("%d", &T);

    for(int t = 1; t <= T; ++t){
        scanf("%d%d", &A, &B);
        printf("Case #%d: %d + %d = %d\n", t, A, B, A + B);
    }

    return 0;
}