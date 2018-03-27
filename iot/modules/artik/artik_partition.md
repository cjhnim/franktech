# Aritk 05X 에 대한 파티션 정보

## ARTIK05X 파티션 정보

artik05x에 대한 파티션 정보는 SamsungARTIK github에서 찾을 수 있었습니다.

* <https://github.com/SamsungARTIK/TizenRT/blob/artik/build/configs/artik05x/scripts/partition_map.cfg>

각 영역에 대하여 바이너리를 다운로드하면 펌웨어 다운이 가능할 것으로 예상됩니다.

```javascript
#
# Partition Map
#
#   Name      Description       Start address   Size        RO
set partition_list {
    bl1     { "BL1"             0x04000000      0x00004000  0 }
    sssro   { "SSS R/O Key"     0x04004000      0x0000C000  1 }
    bl2     { "BL2"             0x04010000      0x00030000  0 }
    sssfw   { "SSS F/W"         0x04040000      0x00008000  0 }
    wlanfw  { "WLAN F/W"        0x04048000      0x00080000  0 }
    os      { "OS"              0x040C8000      0x00258000  0 }
    factory { "Factory Reset"   0x04320000      0x00180000  0 }
    ota     { "OTA download"    0x044A0000      0x00180000  0 }
    user    { "USER R/W"        0x04620000      0x0015E000  0 }
    nvram   { "WiFi NVRAM"      0x0477E000      0x00002000  1 }
    sssrw   { "SSS R/W Key"     0x04780000      0x00080000  1 }
```

## ARTIK053 의 PIT 파일

이번엔 ARTIK05X가 아닌 ARTIK053에 대한 PIT 파일을 찾았습니다. 파티션 정보를 json 형태로 기술해놓고 있었습니다..\
모든 파티션을 기술한 것이 아니라 BL1, BL2, SSS, WLAN, OS 등 몇개의 파티션만 기술이 되어 있는 상태입니다.

* <https://github.com/SamsungARTIK/TizenRT/blob/artik/build/configs/artik053/scripts/artik053.pit>

```javascript
{
   "model": "ARTIK053"
   "binaries": [
      {
         "name" : "BL1",
         "binaryPath" : "053/bl1.bin",
         "baseAddr" : "0x04000000",
         "size" : "0x00004000"
      },
      {
         "name" : "BL2",
         "binaryPath" : "053/bl2.bin",
         "baseAddr" : "0x04010000",
         "size" : "0x00030000"
      },
      {
         "name" : "SSS",
         "binaryPath" : "053/sssfw.bin",
         "baseAddr" : "0x04040000",
         "size" : "0x00008000"
      },
      {
         "name" : "WLAN",
         "binaryPath" : "053/wlanfw.bin",
         "baseAddr" : "0x04048000",
         "size" : "0x00080000"
      },
      {
         "name" : "OS",
         "binaryPath" : "053/tinyara_head.bin",
         "baseAddr" : "0x040C8000",
         "size" : "0x00258000"
      }
   ]
}
```

## 결론(???)

ARTIK05X의 파티션 정보와 파티션 정보를 기록하고 있는 PIT 파일을 SamsungARTIK github에서 찾을 수 있었습니다. 아직 이 정보를 가지고 무엇을 할 수 있는 것은 아니지만, 누군가에게는 도움이 될 수도 있을 것이라는 생각에 정보를 정리해두었습니다. 추후에 좀더 의미있는 정보를 알아내면 문서를 갱신하도록 하겠습니다.