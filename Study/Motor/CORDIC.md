COordinate Rotation DIgital Computer

- 삼각함수, 역삼각함수, 로그, 지수, 제곱근 연산을 효율적으로 수행하는 알고리즘
- 곱셈/나눗셈 없이 덧셈, 뺼셈, Shift 연산만을 사용하여 전용 하드웨어 가속기로도 사용
- Vector Rotation을 기반으로 Sin, Cos을 계산
- 반복 횟수가 높을 수록 정확도 향상

### Vector Rotation
2차원 평면에서의 백터 회전
$X' = Xcos{\theta} - Ysin{\theta}$
$Y' = Xsin{\theta} + Ycos{\theta}$

### CORDIC 알고리즘
- 벡터 회전을 반복적으로 수행하면 근사적으로 계산 가능
- 회전 행렬을 Shift와 덧셈, 뺄셈만을 구현

회전을 작은 단계로 나누어 연속적으로 반복 계산

$tan{\theta} = 2^{-i}$ 로 근사
$X' = X - Y*d_i * 2^{-i}$
$Y' = Y + X*d_i * 2^{-i}$
$d_i = \pm 1$는 회전 방향을 결정, 목표 각도 $\theta$에 도달할 때까지 방향 조정

