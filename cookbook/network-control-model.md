# Network Control Model

## NCM 1.0 spec

* http://www.usb.org/developers/docs/devclass_docs/NCM10_012011.zip
* http://www.usb.org/developers/docs/devclass_docs/CDC1.2_WMC1.1_012011.zip
* http://www.usb.org/developers/docs/devclass_docs/CDC1.2_WMC1.1_052013.zip

### 3.6 Ethernet frame Datagram Maximum Size

* 호스트에 의해 동적 변경 가능 :  SetMaxDatagramSize (6.2.9)
* 디바이스가 지원하는 최대값은 Ethernet Networking Functional Descriptor의  wMaxSegmentSize 를 통해 확인 가능

## NCM 과 MTU 동적 변경

* https://github.com/torvalds/linux/blob/4608f064532c28c0ea3c03fe26a3a5909852811a/drivers/net/usb/cdc_ncm.c

## MTU 개념

### MTU 기본 개념

* https://www.joinc.co.kr/w/man/12/MTU
* http://ddooooki.tistory.com/15

### 이동통산사 3사 LTE망의 MTU size

* https://www.netmanias.com/ko/post/qna/5816

### MTU와 점보프레임간의 관계

* http://www.packetinside.com/2012/03/jumbo-frame.html

## Windows 환경과 MTU

### Windows 환경에서 MTU size 변경

* https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-2000-server/cc938197(v=technet.10)
* https://support.zen.co.uk/kb/Knowledgebase/Changing-the-MTU-size-in-Windows-Vista-7-or-8

### Windows 환경의 miniport driver에서 MTU size 동적 변경

* NDIS 6.5 이상에서 NDIS_STATUS_L2_MTU_SIZE_CHANGE 사용

```C
#if (NDIS_SUPPORT_NDIS650)
#define NDIS_STATUS_PD_CURRENT_CONFIG                   ((NDIS_STATUS)0x40020200L) 

#define NDIS_STATUS_GFT_OFFLOAD_CURRENT_CAPABILITIES    ((NDIS_STATUS)0x40020300L)
#define NDIS_STATUS_GFT_OFFLOAD_HARDWARE_CAPABILITIES   ((NDIS_STATUS)0x40020301L)
#define NDIS_STATUS_GFT_OFFLOAD_CURRENT_CONFIG          ((NDIS_STATUS)0x40020302L)

#define NDIS_STATUS_QOS_OFFLOAD_CURRENT_CAPABILITIES    ((NDIS_STATUS)0x40020400L)
#define NDIS_STATUS_QOS_OFFLOAD_HARDWARE_CAPABILITIES   ((NDIS_STATUS)0x40020401L)

#define NDIS_STATUS_CURRENT_MAC_ADDRESS_CHANGE          ((NDIS_STATUS)0x400200b0L)
#define NDIS_STATUS_L2_MTU_SIZE_CHANGE                  ((NDIS_STATUS)0x400200b1L)
#endif // (NDIS_SUPPORT_NDIS650)
```

### Windows 환경에서 PMTU discovery 설정

* https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-2000-server/cc957539%28v%3dtechnet.10%29
