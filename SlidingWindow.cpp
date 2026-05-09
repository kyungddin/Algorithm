// 가변 슬라이딩 윈도우 템플릿
// 조건이 발동할때까지 오른쪽을 계속 키우다, 조건을 만족하면 왼쪽을 줄이기!

int left = 0;

for (int right = 0; right < n; right++) {
    // 1. 오른쪽 확장
    add(arr[right]);

    // 2. 조건 깨지면 왼쪽 줄이기
    while (condition_broken) {
        remove(arr[left]);
        left++;
    }

    // 3. 결과 갱신
    update_answer(left, right);
}
