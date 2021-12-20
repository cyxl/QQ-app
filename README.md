<h1 align="center">Welcome to QQ-Apps 👋</h1>
<p>
  <img alt="Version" src="https://img.shields.io/badge/version-1.0-blue.svg?cacheSeconds=2592000" />
  <a href="https://www.hackster.io/cyxl/quiz-quest-b016cf" target="_blank">
    <img alt="Documentation" src="https://img.shields.io/badge/documentation-yes-brightgreen.svg" />
  </a>
  <a href="https://github.com/cyxl/QQ-app/blob/main/LICENSE" target="_blank">
    <img alt="License: GNU" src="https://img.shields.io/badge/License-GNU-yellow.svg" />
  </a>
</p>

> Application code for the hackster.io Reinventing Healthy Space contest

### 🏠 [Homepage](https://www.hackster.io/cyxl/quiz-quest-b016cf)

### ✨ [Demo](https://www.youtube.com/watch?v=GHmoBTd4A5o)

## 🚀 Usage

The application consists of a set of c++ and c code in a platformio project. 
Steps to recreate the application are as follows:

Make sure you have [Visual Studio Code](https://code.visualstudio.com/download) and [Platformio](https://platformio.org/install) installed.

[Generate](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/kconfig.html) an sdkconfig

Clone the Repositories:
```sh
git clone https://github.com/stantonious/mot-model
git clone https://github.com/stantonious/mot-components
git clone https://github.com/cyxl/QQ-app
```

Open Visual Code at the root of the QQ-app repository.
```sh
code QQ-app/
```

Update the sdkconfig using menuconfig
```sh
pio run -t menuconfig
# Update the following to be unique
QQ MQTT Config -> QQ Client ID 
# Update the following with your WiFi Config
WiFi Configuration -> SSID
WiFi Configuration -> WiFi Password
```

Request (or generate) QQ certificates for AWS IoT connectivity and copy to:
```sh
.../QQ-app/certs
```

Build and flash your device

## Schematics
![Schematic](https://github.com/cyxl/QQ-app/blob/main/qq-arch_UUczrIFVIy.png)

## Author

👤 **cyxl**

* Github: [@cyxl](https://github.com/cyxl)

## 🤝 Contributing

Contributions, issues and feature requests are welcome!<br />Feel free to check [issues page](https://github.com/cyxl/QQ-app/issues). 

## Show your support

Give a ⭐️ if this project helped you!

## 📝 License

Copyright © 2021 [cyxl](https://github.com/cyxl).<br />
This project is [GNU](https://github.com/cyxl/QQ-app/blob/main/LICENSE) licensed.


