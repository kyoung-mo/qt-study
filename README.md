# qt-study

Intel Edge AI SW Academy 9기 Qt 수업 실습 및 프로젝트 모음입니다.

---

## 주요 프로젝트

### AiotClient_tab12367
소켓 통신 기반 IoT 클라이언트 Qt 애플리케이션입니다.
서버(`iot_server`)와 TCP 소켓으로 통신하며, 탭별로 기능이 분리되어 있습니다.

| 탭 | 클래스 | 기능 |
|----|--------|------|
| Tab1 | Tab1DeviceControl | QTimer, QDial, QButtonGroup, CheckBox LED 제어 |
| Tab2 | Tab2SocketClient | TCP 소켓 연결/수신/송신, 메시지 파싱 및 라우팅 |
| Tab3 | Tab3ControlPannel | 이미지 리소스 기반 lamp/plug 원격 제어 |
| Tab6 | Tab6WebCamera | mjpg-streamer + QWebEngineView 웹캠 스트리밍 |
| Tab7 | Tab7CamOpencv | OpenCV + QThread 웹캠, HSV 색상 분류, 소켓 송신 |

- 서버 ID : `KYM_QT` / 서버 IP : `10.10.16.35:5000`
- 관련 블로그 : [velog.io/@mommers](https://velog.io/@mommers)

---

## 디렉토리 구조

```
qt-study/
├── AiotClient_tab12367/    # 메인 AiotClient 프로젝트 (Tab1,2,3,6,7)
├── AiotClient_tab1/        # Tab1 단독 실습
├── AiotClient_tab7/        # Tab7 단독 실습
├── AiotClient_practice/    # AiotClient 연습용
├── CamViewerThread/        # Qt + OpenCV 카메라 연동 예제
├── WebCamViewer/           # 웹캠 뷰어 예제
├── firstOpencv/            # OpenCV 설치 확인용 예제 (first.cpp)
├── mjpg-streamer-master/   # mjpg-streamer 소스
├── mjpg-streamer/          # mjpg-streamer 관련 실습
├── mjpg/                   # mjpg 관련 실습
├── 00_StartQtWASM/         # Qt WASM 시작 예제
├── 0_QCheckBoxUI/          # QCheckBox UI 예제
├── QCheckBox/              # QCheckBox 실습
├── QT-examples/            # Qt 예제 모음
├── plain_c/                # 순수 C 실습
├── tetrix/                 # Qt Tetrix 예제
└── build-*/                # 빌드 산출물 디렉토리
```

---

## 개발 환경

| 항목 | 내용 |
|------|------|
| OS | Ubuntu 22.04 (VirtualBox) |
| Qt | Qt Creator 6.8.3 |
| OpenCV | 4.12.0 (소스 빌드) |
| 언어 | C++ |
| 서버 | ubuntu05 (IP: 10.10.16.35) |
| 임베디드 | Raspberry Pi (IP: 10.10.16.65) |

---

## 관련 링크

- Blog : [velog.io/@mommers](https://velog.io/@mommers)
- GitHub : [github.com/kyoung-mo](https://github.com/kyoung-mo)
