# 🛗 엘리베이터 


## 시연 영상


## 개요 
프로그래밍 역량 향상과 실제 엘리베이터를 기반하여 기본적인 엘리베이터 기능을 구현


- 개발기간 : 25. 03. 28 ~ 25. 04 .04
- 팀장 : 김현빈
- 팀원 : 이종희, 박명우

- 역할
엘리베이터 내/외부 화면 표시 구현(I2C)
엘리베이터 도어 동작 구현(SERVO MOTOR)
엘리베이터 프레임 제작

## 프로젝트 핵심 기능
- 버튼 누를 시 엘리베이터 동작
- 이동 중 버튼 누름 시 선행 동작 완료 후 이동
- 1층 -> 3층 이동 중 2층 누를 시 2층 도착 후 3층 이동


## 하드웨어
<img width="400" alt="image" src="https://github.com/user-attachments/assets/5f2b8ceb-2e90-4a8b-b76d-4aae6eb97080" />


### 보드
- STM32F411RE(ARM Cortex-M4)

### 정보표현
- I2C LCD(LCD1602) FND


### 센서 동작
- 포토인터럽트, SERVO MOTOR, Buzzer, Tact Swtich, Ezmotor, STEP MOTOR

## USECASE


## Flow Chart
<img width="1200" alt="image" src="https://github.com/user-attachments/assets/1138dcbc-625f-4175-b15f-e85f26876146" />
