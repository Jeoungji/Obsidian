Permanent Magnet Synchronous Motor
영구 자석 동기 모터

- Vector Control
- AC 전류 입력
- Sin 상전류 파형
- Sin 역기전력 파형
- 토크 및 효율 높음
- 토크 리플 작음
- 평행한 착자 방향


|        | SMPMSM                                           | IPMSM                                                                 |
| ------ | ------------------------------------------------ | --------------------------------------------------------------------- |
| 영구 자석  | 회전자 표면 부착                                        | 회전자 내부에 매립                                                            |
| 제어     | $i_d = 0$                                        | 단위 전류 당 최대 토크 제어 ([MTPA](MTPA.md))                                    |
| 토크 방정식 | $T_e=\frac{P}{2}\frac{3}{2}\phi_fi_q$            | $T_e=\frac{P}{2}\frac{3}{2}[\phi_fi_q+(L_d-L_q)i_di_q]$               |
| 토크     | Magnet Torque                                    | Magnet Torque + Reluctance Torque                                     |
| 최대 토크  | 전류각 $90\degree$에서 최대<br>($L_d=L_q$ -> 리럭턴스 토크 X) | 전류각 $90\degree\pm\alpha$<br>($L_d\neq L_q$ -> 최대 토크를 발생하는 전류각을 찾아야 함) |
| 회전 속도  | 상대적으로 낮은 회전 속도                                   | 고속 회전에 유리 (통상 10000[RPM] 이상)                                          |
| 효율     | 희토류 자석을 사용하여 효율 증대                               | Magnet Torque와 Reluctance                                             |
| 적용 분야  | 고응답 고정밀의 산업기계                                    | 압축기, 스핀들, 전기 자동차의 모터                                                  |
