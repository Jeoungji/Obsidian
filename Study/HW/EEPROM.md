#회로 #HW

<span style="font-size: 24px;">Electronically Erasable Programmable Read-Only Memory</span>

#비휘발성_메모리 로 전원이 꺼져도 데이터 유지
전기적으로 신호로 데이터를 지우는 ROM
설정 값 저장, 로그 데이터, 펌웨어 업데이트

## 특징
- #비휘발성_메모리 (Non-Volatile)
- 재 기록 가능
- Byte 단위 쓰기 (Byte-Level Writing)
- Limited Write Cycles : 10만-100만회 Write/Erase 가능
- 속도가 느림

## 동작
- EEPROM의 내부 셀은 [트랜지스터](트랜지스터.md)의 [Floating_Gate](Floating_Gate.md)에 전자를 가둬 데이터를 저장
- 전자를 가두면 0, 방출하면 1
- 고전압을 이용하여 [Floating_Gate](Floating_Gate.md)에서 전자를 방출하거나 저장하여 데이터를 지움

#### Read
- [Floating_Gate](Floating_Gate.md)에 저장된 전자의 상태를 감지하여 0또는 1을 판별

#### Write
- 데이터를 쓰기 전 삭제 진행
- 고전압(12V)을 사용하여 [Floating_Gate](Floating_Gate.md)에 전자를 주입

#### Erase
- EEPROM의 특정 영역 또는 전체를 지울 수 있음
- 데이터를 '1'로 치기화하기 위해 [Floating_Gate](Floating_Gate.md)에서 전자를 방출하는 과정이 필요


## 종류
#### Parallel EEPROM
- Address Bus와 Data Bus를 사용하여 데이터를 송수신
- 버스와 제어 신호(`WE`, `OE`, `CE`)가 필요

#### Serial EEPROM
- [I2C](I2C.md), [SPI](SPI.md), [Microwire](Microwire.md) 등의 직렬 통신을 사용
- 소형 [MCU](MCU.md)와 쉽게 인터페이스 가능


## 12V 생성 원리
EEPROM 내부에는 [Charge_Pump](Charge_Pump.md)회로가 있음