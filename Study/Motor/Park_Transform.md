- 정지 좌표계를 회전 좌표계로 변환
- 2상 전류를 d-q 좌표계로 변환하여 직류 성분처럼 제어

정지 좌표계에서는 모터 전류가 계속 변하므로 진동하는 값을 직접 제어하기는 힘듦.

전류 벡터를 회전하는 좌표계로 변환하여 직류 성분으로 만듦

### 수식
$I_d=I_{\alpha}cos{\theta}+I_{\beta}sin{\theta}$
$I_q=-I_{\alpha}sin{\theta}+I_{\beta}cos{\theta}$


## Inverse Park Transform
$I_{\alpha}=I_dcos{\theta}-I_qsin{\theta}$
$I_{\beta}=-I_dsin{\theta}+I_qcos{\theta}$

