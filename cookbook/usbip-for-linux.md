# 리눅스를 위한 USBIP UTILS 설치 및 사용 가이드

## Server 설치 및 설정

1. linux-tools 설치
    ```bash
    sudo apt-get install linux-tools-`uname -r`
    ```
2. 커널모듈 올리기
    ```bash
    sudo modprobe usbip_host
    ```
3. 데몬 실행
    ```bash
    sudo /usr/lib/linux-tools/`uname -r`/usbipd -D
    ```
4. usbip를 통해 바인드할 USB 장치 리스트 보기
    ```bash
    sudo /usr/lib/linux-tools/`uname -r`/usbip list -l
    ```
5. usbip를 통해 바인드할 USB 장치 선택하기
    ```bash
    sudo /usr/lib/linux-tools/`uname -r`/usbip bind --busid={busid}
    ```

## Client 설치 및 설정

1. linux-tools 와 데몬 실행\
    Server와 동일하게 설치 및 실행
2. 커널모듈 올리기
    ```bash
    sudo modprobe vhci_hcd
    ```
3. Server의 USB 장치 리스트 보기
    ```bash
    sudo /usr/lib/linux-tools/`uname -r`/usbip list --remote={ip addr}
    ```
4. Server의 USB 장치 연결하기
    ```bash
    sudo /usr/lib/linux-tools/`uname -r`/usbip attach --remote={ip addr} --busid={busid}
    ```
5. 연결된 Usb 장치 목록보기
    ```bash
    sudo /usr/lib/linux-tools/`uname -r`/usbip port
    ```

## 부록: USB 메모리 원격 연결시 속도 측정

### Server 측정 (physically connected)

``` bash
test@ubuntu:/media/test/44B6-9D8E$ dd if=/dev/zero of=./largefile bs=8k count=10000
10000+0 records in
10000+0 records out
81920000 bytes (82 MB, 78 MiB) copied, 9.47435 s, 8.6 MB/s

test@ubuntu:/media/test/44B6-9D8E$ sudo sh -c "sync && echo 3 > /proc/sys/vm/drop_caches"
test@ubuntu:/media/test/44B6-9D8E$ dd if=./largefile of=/dev/null bs=8k
10000+0 records in
10000+0 records out
81920000 bytes (82 MB, 78 MiB) copied, 8.26258 s, 9.9 MB/s

```

### Client 측정 (connected over ip network)

``` bash
test@test:/media/test/BE72-5066$ dd if=/dev/zero of=./largefile bs=8k count=10000
10000+0 records in
10000+0 records out
81920000 bytes (82 MB, 78 MiB) copied, 36.7054 s, 2.2 MB/s

test@test:/media/test/BE72-5066$ sudo sh -c "sync && echo 3 > /proc/sys/vm/drop_caches"
[sudo] password for test: 

test@test:/media/test/BE72-5066$ dd if=./largefile of=/dev/null bs=8k
10000+0 records in
10000+0 records out
81920000 bytes (82 MB, 78 MiB) copied, 91.0599 s, 900 kB/s
```
