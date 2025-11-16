#include <stdio.h>
#include <stdint.h>

int a();
int b();

// 전역 변수로 리턴 주소 저장
void *saved_return_addr = NULL;

int main()
{
    printf("main 시작\n");
    a();

    // 실행 되지 않음
    printf("main 종료\n");
    return 0;
}

int b()
{
    printf("b 함수 실행됨!\n");
    return 0;
}

int a()
{
    // 인라인 어셈블리로 정확한 리턴 주소 얻기
    __asm__ volatile (
        "movq 8(%%rbp), %0" 
        : "=r" (saved_return_addr)
    );
    
    printf("a 함수 실행\n");
    printf("리턴 주소: %p\n", saved_return_addr);
    printf("b 함수 주소: %p\n", b);
    
    // 리턴 주소를 직접 조작
    __asm__ volatile (
        "movq %0, 8(%%rbp)"
        :
        : "r" (b)
    );
    
    printf("리턴 주소를 b 함수로 변경했습니다\n");
    
    return 0;
}
