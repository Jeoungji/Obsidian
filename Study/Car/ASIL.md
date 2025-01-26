#자동차 #프로세스
<span style="font-size: 24px;">Automotive Saftey Integrity Level</span>

시스템이나 구성 요소의 안정 중요도를 정의하는 척도
[HARA](HARA.md)를 통해 결정

### 요소
- <span style="font-size: 24px;">S</span>everity : 시스템 고장이 발생했을 때 탑승자, 보행자에게 미치는 심각도 #Severity
	- S0 : 무해
	- S1: 경상
	- S2 : 중상해
	- S3 : 사망
- <span style="font-size: 24px;">E</span>xposure : 위험 상황에 노출될 가능성 #Exposure
	- E0 : 거의 발생 X
	- E1 : 매우 낮음
	- E2 : 낮음
	- E3 : 중간
	- E4 : 높음
- <span style="font-size: 24px;">C</span>ontrollability : 운전자나 시스템이 위험을 제어할 수 있는 정도 #Controllability
	- C0 : 쉽게 제어 가능
	- C1 : 일반적인 운전자가 제어 가능
	- C2 : 몇몇 운전자만 제어  가능
	- C3 : 대부분 불가능

### 분류
- QM (Quality Management)
	추가적인 안전 요구 사항 필요X
- ASIL A
	낮은 안전 중요도
- ASIL B
	중간 안전 중요도
- ASIL C
	높은 안전 중요도
- ASIL D
	가장 높은 안전 중요도

### ASIL 결정 매트릭스
| Severity | Esposure   | Controllability | ASIL     |
| -------- | ---------- | --------------- | -------- |
| S0       | All        | All             | QM       |
| S1       | E1, E2     | C0, C1, C2, C3  | QM       |
| S1       | E3, E4     | C3              | ASIL A   |
| S2       | E2, E3, E4 | C2              | ASIL B   |
| S2, S3   | E3, E4     | C3              | ASIL C/D |
| S3       | E4         | C3              | ASIL D   |