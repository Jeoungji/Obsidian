#자동차 #소프트웨어
<span style="font-size: 28px;">Basic Software</span>

- AUTOSAR 기반 차량 소프트웨어 구조에서 가장 기초적인  계층
- 차량 [ECU](ECU.md)의 어플레케이션이 하드웨어 제어를 위해 표준화된 인터페이스를 사용할 수 있드록 지원

# 역할
- 하드웨어 추상화
	MCU, 센서, 엑추에이터 등 하드웨어를  직접 제어하는 기능을 추상화
- 표준화된 인터페이스 제공
	차량 내 다양한 [ECU](ECU.md)가 동일한 소프트웨어 환경에서 동작하도록 표준 API 제공
- 운영 체제 및 서비스 관리
	[RTOS](RTOS.md) 기반으로 Task 관리, Memory관리, 통신 스택 등을 지원
- 통신 및 네트워크 관리
	[CAN](CAN.md), [LIN](LIN.md), [FlexRay](FlexRay.md), [Ethernet](Ethernet.md) 과 같은 차량 네트워크 [Protocol](Protocol.md)를 관리
- 진단 및 오류 관리
	차량 내 진단 기능 ([OBD-II](OBD-II.md), [UDS](UDS.md)) 및 오류 로깅 기능을 제공하여 차량의 유지 보수 및 원격 진단 지원

# 구성
### MCAL
Microcontroller Abstraction Layer
- [MCU](MCU.md) 및 하드웨어 주변 장치를 제어
- 주요 모듈
	- [GPIO](GPIO.md) Driver
	- [ADC](ADC.md) Driver
	- [PWM](PWM.md) Driver : 모터 및 조명 제어를 위한 PWM 신호 생성
	- [SPI](SPI.md)/[I2C](I2C.md)/[UART](UART.md) Driver : 보드 내의 외부 장치와의 통신
	- [CAN](CAN.md)/[LIN](LIN.md)/[FlexRay](FlexRay.md) Driver : 차량 내 [Network](Network.md) 통신 지원

### EAL
[ECU](ECU.md) Abstraction Layer
- [ECU](ECU.md)의 하드웨어를 추상화하여 상위 계층이 직접 하드웨어를 다루지 않도록 함.
- 주요 기능
	- 메모리 인터페이스 관리
	- 센서 및 엑추에이터 인터페이스 관리
	- 디바이스 드라이버를 표준화하여 상위 계층에서 일관되게 접근할 수 있도록 지원

### Service Layer
- [OS](OS.md), 통신 관리, 진단 서비스, 전력 관리 등 핵심 기능 제공
- 주요 모듈
	- [OS](OS.md) ([RTOS](RTOS.md)) : Task 스케줄링, 리소스 관리
	- Com Stack : 네트워크 관리
	- Diagnostic (진단 서비스) : [DTC](DTC.md) 로깅, [UDS](UDS.md) 프로토콜 지원
	- Memory Service : 메모리 관리
	- Watchdog Manager : 감시 타이머 관리


# 고려 사항
- [AUTOSAR](AUTOSAR.md)표준 준수
- 실시간 성능 최적화
- 안전성 ([ISO-26262](ISO-26262.md) 준수)
	[ASIL](ASIL.md) 등급을 고려해서 설계
- [ECU](ECU.md) 호환성
	사용하는 하드웨어 플랫폼에 맞는 BSW 개발


# BSW 개발을 위한 툴 및 환경
- Vector MICROSAR
- EB tresos Studio
- DaVinci Configurator
- CANoe/CANalyzer