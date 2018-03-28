### 리눅스 개발 환경을 갖출 때 필요한 팁 위주로 정리합니다.

## cmake 최신 버전 설치하기

Ubuntu 16.04 버전에서 apt-get 으로 설치하면 최신 버전이 설치되지 않습니다.
제 PC 환경에서는 아래 보는 바와 같이 3.5.1 이 설치됩니다.

```console
test@ubuntu:~$ cmake --version
cmake version 3.5.1
```

이럴 땐 웹사이트에서 직접 다운받아 경로에 복사해주는 작업을 해야 합니다.
그전에 먼저 이미 설치된 cmake를 지워줍니다.

```console
sudo apt-get purge cmake
```

그리고 cmake.org에서 최신 설치스크립트를 다운 받습니다.

```console
wget https://cmake.org/files/v3.10/cmake-3.10.3-Linux-x86_64.sh
```

다운 받은 설치 스크립트를 실행합니다. 그리고나면 압축해제된 bin, doc, man, share 폴더를 확인할 수 있습니다.

```console
sudo ./cmake-3.10.3-Linux-x86_64.sh --skip-license
```

bin, doc, man, share를 기본 경로상으로 복사해줍니다.

```console
test@ubuntu:~/tmp$ sudo cp -r bin /usr/
test@ubuntu:~/tmp$ sudo cp -r doc /usr/share/
test@ubuntu:~/tmp$ sudo cp -r man /usr/share/
test@ubuntu:~/tmp$ sudo cp -r share /usr/
```

다운 버전의 cmake가 잘 실행되는지 확인해 봅시다.

```console
test@ubuntu:~$ cmake --version
cmake version 3.10.3
```