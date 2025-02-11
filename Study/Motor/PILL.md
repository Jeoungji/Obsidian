Park and Inverse Park Linearization

- [Park Transform](Park_Transform.md) 및 Inverse Park 변환 시 삼각함수 연산을 선형 근사화하여 연산 속도를 최적화
- MCU는 부동 소수점 연산이 느리며, 삼각함수 연산 부하가 큼
- CPU의 부하를 줄이는 것이 목적
- 빠른 연산 속도, 저전력
- 낮은 정확도

##### 선형 근사
$sin{\theta} \cong \theta$
$cos{\theta} \cong 1$

##### PILL을 적용한 Park변환
$I_d = I_\alpha * 1 + I_\beta * \theta = I_\alpha + I_\beta$
$I_q = -I_\alpha * \theta + I_\beta * 1 = I_\beta - I_\alpha$

##### PILL을 적용한 Inverse Park 변환
$I_\alpha = I_d * 1 - I_q * \theta = I_d - I_q * \theta$
$I_\beta = I_d * \theta + I_q * 1 = I_q + I_d * \theta$








