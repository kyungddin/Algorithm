```cpp
void dfs(...)
{
    if (종료조건)
    {
        // 정답 처리
        return;
    }

    for (후보들)
    {
        if (선택할 수 없음)
            continue;

        // 1. 선택

        // 2. 다음 단계
        dfs(...);

        // 3. 선택 취소
    }
}
```
