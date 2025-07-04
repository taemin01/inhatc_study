거리가 멀어지면 비동기 직렬 방식 사용  
직렬, 병렬 통신 방식 존재  
비동기 직렬, 동기 직렬 존재  

# 시리얼 통신
    시리얼 통신에서 데이터를 이진 펄스의 형태로 전송, 이진 1을 논리 HIGH, 이진 0을 논리 LOW로 나타낸다.
    비동기식 시리얼 통신 규격 (RS-232) - 현재까지 1대1 송수신에 가장 많이 사용되는 규격이다.
    LSB - 최하위 비트  
    MOB - 최상위 비트  
    널모뎀 케이블 - 3개의 케이블만 사용
    2 = TX, 3 = RX, 5 = GND

# 차동 회로
    외부에서 잡음이 들어와도 노이즈가 잘 생기지 않는다.
    RS232는 전송 속도가 낮고 거리가 짧다. 
    RS-422 : 한 개의 마스터 장치와 슬레이브 장치 간에 데이터를 주고 받는 방식으로 통신한다. RS232의 단점을 보완하기 위해 만들어짐(슬레이브 장치는 마스터 장치가 시키는 대로 한다.)
    RS-485 : 모든 장치들이 같은 라인에서 데이터 전송 및 수신을 할 수 있다.

# 리피터
    인터넷 선은 100m 연결 가능(길어지면 신호 레벨이 낮아짐-통신 안됨) 이것을 방지하기 위해 리피터로 신호를 증폭시켜 준다. (들어온 신호를 증폭시키는 것)
    하나의 네트워크를 다른 곳으로 연결시켜준다. 새로운 신호를 만들 수는 없고 증폭만 가능

# 허브
    하나의 세그먼트 안에서 두 개 이상의 네트워크 디바이스 연결 해주는 기능을 제공하는 Physiacl Layer 장비이다.(파워만 연결하여 사용)
    신호증폭으로 거리가 멀 때 리피터 대신 사용
    스위칭 : 신호를 필요한 곳에만 보낼 수 있음(필터링 기능)
    더미 허브 : 상위에서 들어오는 신호를 모든 포트에 재전송한다.
    스타 토폴로지의 중심 역할을 한다. (멀티포트 리피터 or 콘센트레이터)
    / colision : 신호 충돌? / 토폴로지 : 망 구성 방법
    / 인터넷은 15번까지 통신 재시도 가능 /

### CSMA/CD와 CSMA/CA는 컴퓨터 네트워크에서 채널을 공유하는 방식을 나타내는 프로토콜이다.

### 스위치는 3~7 계층 별로 존재 가능

# 브리지(Bridge)
    네트워크 세그먼트 연결, 프레임을 전달 해주는 기능을 수행하는 Data Link layer(3) 장비다.
    허브보다 지능적인 동작을 하며 들어오는 프레임을 분석한다.
    세그먼트 내에서만 전송 경쟁을 한다.
    LAN과 LAN을 연결 : 리피터와 비슷한 점
    필터링 기능이 있다 : 리피터와 다른 점(데이터 보내기, 정지 가능)
    차단 가능한 점은 라우터와 비슷

# 라우터 - 비싸다(네트워크 계층 장비)
    네트워크 계층 어드레스 사용
    여러 LAN(Local Area Network)들을 연결하며 어드레스에 따라 알맞은 연결 라인을 찾아준다.
    WAN(Wide Area Network)에서 연결 다리 역할과 길찾아주는 역할을 한다.
    IP를 통해 접속 차단도 가능하다. 접근에 대한 제한, 허용을 하는 역할을 한다.

### UTP : 쉴드가 없어서 잡음이 들어감 STP 라는 쉴드 있는 트위스트 케이블이 있음

# 스위치
    브리지 기술을 기반으로 하며, 레이어 2 장비, CAM라 불리는 어드레스 테이블을 작성 및 관리한다.
    장점 : 스위치에 연결된 포트에 전용의 대역폭 제공
    처리방식 : MAC 어드레스 사용, 하드웨어로 이루어짐
    소프트웨어적으로 처리하는 브리지에 비해 고속화 가능
    브리지에 비해 쉽게 볼 수 있음
    종류 : LAN, ATM, WAN 스위치 등