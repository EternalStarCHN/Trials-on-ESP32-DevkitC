# 介绍
本仓库用于存储基于[espressif](https://www.espressif.com/zh-hans/products/socs/esp32)公司最新推出的***ESP32-WROOM-32E***制作的DevkitC开发板上进行测试的程序，开发板的PCB可参考***LiiGuang***发布在OSHWHUB上的39脚ESP32通用开发板👉[链接](https://oshwhub.com/LiiGuang/esp32-wroom-32d-typec_copy_copy)。  
开发环境使用VSCode+PlatformIO，基于Arduino的众多库函数进行开发。  
如选用Flash大小为16M的ESP32芯片，可在platformio.ini文件内增加如下三行代码更改串口监视器的波特率、上载速率和16MB的分区表。
```C++
monitor_speed = 115200
upload_speed = 961200
board_build.partitions = default_16MB.csv
```
# 测试进度
+ GPIO&Touch
+ Time&PWM
+ WiFi
+ ~~WiFi AutoConfig~~
+ Bluetooth
+ BLE
+ MultiThread
+ NTP
+ SSD1306
+ SHT30(测试SSDA与PDA两种模式)
+ DS18B20
+ AHT10
+ SGP30
+ TCS34725
+ ...  
# 许可证
Trials-on-ESP32-DevkitC is licensed under [GPL-3.0 License](https://github.com/EternalStarCHN/Trials-on-ESP32-DevkitC/blob/main/LICENSE).
