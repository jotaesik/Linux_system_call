# 📂 **Linux System Call Project**

## 📋 **프로젝트 설명 (Project Description)**

이 프로젝트는 **리눅스 시스템 콜**을 활용하여 텍스트 파일의 내용을 읽어 들이고, 다양한 옵션을 적용하여 출력 형식을 지정할 수 있는 C 언어 기반 프로그램입니다.  
해당 프로젝트는 `cat` 명령어를 기반으로 하여, 파일의 내용을 줄 단위로 읽어오는 기능과 줄 번호, 줄 끝 표시 등의 다양한 옵션을 제공합니다.

## 🛠️ **주요 기능 (Features)**

1. **텍스트 파일의 내용을 한 줄씩 읽어 출력**  
   - 프로그램은 주어진 텍스트 파일을 읽고, 내용을 한 줄씩 출력합니다.
   
2. **다양한 출력 옵션 제공**  
   - **`-E` 옵션**: 각 줄 끝에 `$` 기호를 추가하여 줄 끝을 표시합니다.  
   - **`-n` 또는 `-N` 옵션**: 각 줄의 앞에 줄 번호를 추가하여 출력합니다.  
   - 두 옵션을 함께 사용할 수 있으며, 줄 번호와 줄 끝을 모두 표시합니다.

3. **시스템 콜 활용**  
   - `fopen`, `fgetc`, `fread` 등의 시스템 콜을 사용하여 파일의 내용을 처리하고, 메모리를 동적으로 할당하여 텍스트 파일의 줄을 읽어 들입니다.

## 📂 **폴더 구조 (Folder Structure)**
```
Linux_system_call/
├── README.md # 프로젝트 설명 파일
├── first.c # 메인 소스 코드 파일
├── first.o # 컴파일된 오브젝트 파일
└── makefile # 컴파일 및 빌드를 위한 Makefile
```
