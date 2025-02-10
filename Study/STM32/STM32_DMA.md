- [MCU](MCU.md) 내부 메모리와 [MCU](MCU/md)에 연결되는 주변 장치들 사이에 core의 간섭 없이 데이터를 전송
- DMA Controller는 독립적으로 구성 가능한 채널을 보유
- 채널 별로 우선 순위와 설정 가능한 HW가 정해져 있음
- GPIO초기화 다음으로 DMA를 초기화하여야 함. (다른 peripheral보다 우선 초기화)
##### Channel
- 각 channel은 전용 Hardware DMA Request에 연결
- software trigger 기능을 제공
##### TCB
Transfer Control Block

### 전송 모드
- Memory-to-Memory
	DMA를 사용하여 메모리간 데이터 이동
	소프트웨어로 시작
- Peripheral-to-Memory
	주변 장치에서 메모리로 데이터 전송
- Memory-to-Peripheral
	메모리에서 주변 장치로 데이터 전송
- Peripheral-to-Peripheral
	주변 장치에서  주변 장치로 데이터 전송

### 전송 과정
#### 전송 흐름

- DMA 요청 발생
	주변 장치가 DMA에  요청
	소프트웨어로 메모리 전송 요청

- DMA가 버스를 점유하여 데이터 전송
	채널  우선 순위에 따라 버스에 엑세스
	데이터  크기에 따라 주소 증가

- DMA_CNDTRx 레지스터 개수 감소
	전송할 데이터 개수가 감소

- 전송 완료시 인터럽트 발생
	인터럽트를 통해 처리 가능

### 주요 레지스터
#### DMA_CCRx
DMA 채널 설정 레지스터

![DMA_CCRx](Image/DMA_CCRx.png)
##### Bit 14 : MEM2MEM
memory to memory 설정
0 : disable
1 : enable
##### Bit 13:12 : PL[1:0]
channel의 우선 순위 설정
00 : 낮음
01 : 중간
10 : 높음
11 : 매우 높음
##### Bit 11:10 : MSIZE[1:0]
메모리 크기
00 : 8bit (Byte)
01: 16bit (Half-Word)
10 : 32bit (Word)
11 : X
##### Bit 9:8 : PSIZE[1:0]
주변 장치 크기
00 : 8bit (Byte)
01: 16bit (Half-Word)
10 : 32bit (Word)
11 : X
##### Bit 7 : MINC
메모리 증가 모드 : 전송할 때 마다 주소 자동 증가
0 : disable
1 : enable
##### Bit 6 : PINC
주변 장치 증가 모드 : 전송할 때 마다 주소 자동 증가
0 : disable
1 : enable
##### Bit 5 : CIRC
순환 모드 : 전송이 끝나면 자동으로 초기 설정값으로  재설정하여 연속 동작
0 : disable
1 : enable
##### Bit 4 : DIR
전송 방향
0 : 주변 장치 -> 메모리
1 : 메모리 -> 주변 장치
##### Bit 3 : TEIE
전송 에러 인터럽트 활성화
0 : disable
1 : enable
##### Bit 2 : HTIE
전체 데이터의 절반 전송 완료 인터럽트 활성화
0 : disable
1 : enable
##### Bit 1 : TCIE
전송 완료 인터럽트 활성화
0 : disable
1 : enable
##### Bit 0 : EN
Channel Enable
0 : disable
1 : enable


#### DMA_CNDTRx
DMA 데이터 개수 레지스터

![DMA_CNDTRx](DMA_CNDTRx.png)

##### Bit 15:0 : NDT[15:0]
전송할 데이터 수 설정
0 - 65535 사이 개수를 전송

#### DMA_CPARx
DMA 주변 장치 주소 레지스터

![DMA_CPAPx.png](DMA_CPAPx.png)
##### Bit 31:0 : PA[31:0]
주변 장치의 데이터 레지스터 주소

| PSIZE | 데이터 크기            | 무시되는 주소 비트 | 설명                     |
| ----- | ----------------- | ---------- | ---------------------- |
| 00    | 8bit (Byte)       | X          | 1바이트 정렬 가능             |
| 01    | 16bit (Half-Word) | PA 0 bit   | 2바이트 정렬 필수 (주소가 짝수)    |
| 10    | 32bit (Word)      | PA 0,1 bit | 4바이트 정렬 필수 (주소가 4의 배수) |

#### DMA_CMARx
메모리 주소 설정

![[DMA_CMARx.png]]

| PSIZE | 데이터 크기            | 무시되는 주소 비트 | 설명                     |
| ----- | ----------------- | ---------- | ---------------------- |
| 00    | 8bit (Byte)       | X          | 1바이트 정렬 가능             |
| 01    | 16bit (Half-Word) | PA 0 bit   | 2바이트 정렬 필수 (주소가 짝수)    |
| 10    | 32bit (Word)      | PA 0,1 bit | 4바이트 정렬 필수 (주소가 4의 배수) |
