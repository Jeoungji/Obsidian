#자동차
<span style="font-size: 28px;">Electronic Control Unit</span>

- 자동차 내 다양한 기능을 제어하는 [Embbeded](Embbeded.md) 시스템으로, 센서 데이터를 수집하고 분석하여 [Actuator](Actuator.md)를 제어하는 역할
- 자동차가 전자화 됨에 따라 [ADAS](ADAS.md), [IVI](IVI.md), [BMS](BMS.md) 등 에 사용

# 기본 구조
ECU는 일반적인 [Embbeded](Embbeded.md) 시스템과 유사한  구조
### 하드웨어 구성
| 구성 요소           | 설명                                                           |
| --------------- | ------------------------------------------------------------ |
| Microcontroller | 프로그램 실행, 연산 및 [Sensor](Sensor.md)/[Actuator](Actuator.md) 제어 |
| 메모리             | 프로그램 저장, 데이터 처리, 영구 데이터 저장                                   |
| 입출력 인터페이스       | 센서 입력, 엑추에이터 출력                                              |
| 통신 모듈           | 차량 내 네트워크 통신                                                 |
| 전원 회로           | 차량 배터리에서 5V or 3.3V로 변환                                      |
| 보호 회로           | 정전기 방지, 과전압 보호                                               |
### 소프트웨어 구조
ECU 내부 소프트웨어는 기본적으로 [BSW](BSW.md), [RTE](RTE.md), [ASW](ASW.md)로 구성

# ECU 종류
### 파워트레인 관련 ECU
| ECU                               | 기능                    |
| --------------------------------- | --------------------- |
| ECM (Engine Control Module)       | 엔진 제어                 |
| TCM (Transmission Control Module) | 자동 변속기 기어 변속, 클러치 제어  |
| BMS (Battery Management System)   | 전기차 배터리 충방전 관리, 샐 밸런싱 |
| DCU (Drive Control Unit)          | 모터 및 인버터 제어           |
### 샤시 및 차량 동역학 관련 ECU
| ECU                                | 기능             |
| ---------------------------------- | -------------- |
| ABS (Anti-lock Braking System)     | 급제동 시 바퀴 잠금 방지 |
| ESC (Electronic Stability Control) | 차량 자세 안정화      |
| EPS (Electric Power Steering)      | 전자식 파워 스티어링 제어 |
| CDC (Continuous Damping Control)   | 서스펜션 댐핑 조절     |

### ADAS 및 자율주행 ECU
| ECU                               | 기능                               |
| --------------------------------- | -------------------------------- |
| ADAS ECU                          | 카메라, 레이더, LiDAR 데이터 분석 및 자율주행 제어 |
| ACC (Adaptive Cruise Control)     | 차량 속도 및 차간 거리 유지                 |
| LKA (Lane Keeping Assist)         | 차선  유지 보조 시스템                    |
| AEB (Automatic Emergency Braking) | 긴급 자동 제동                         |
### 바디 및 엔터테이먼트 관련 ECU
| ECU                                    | 기능                  |
| -------------------------------------- | ------------------- |
| BCM (Body Control Module)              | 도어, 실내등, 파워 윈도우 제어  |
| IC (Instrument Cluster)                | 계기판, 속도계, 연료 게이지 표시 |
| IVI (In-Vehicle Infotainment)          | 내비게이션, 미디어, 스마트폰 연동 |
| TPMS (Tire Pressure Monitoring System) | 타이어 공기압 모니터링        |

# 개발 과정
### 하드웨어
- MCU 선정
- Sensor 및 Actuator 연결
- 전원 설계 및 보호 회로 구성
- PCB 설계 및 프로토타이핑

### 소프트웨어
- Real-Time OS 선택
- CAN/LIN 통신 스택 적용
- 진단 소프트웨어 개발
- 기능 안전 설계

### 테스트 및 검증
- [HIL](HIL.md), [SIL](SIL.md) 테스트
- 환경 신뢰성 테스트 (고온/저온/진동/EMI)

