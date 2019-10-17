# nrf52-ota-example
This is a example project for nRF52 OTA.

# Qiita
このリポジトリは、Qiitaの記事「nRF52でBLEデバイスを開発する（２）OTAアップデート Buttonless DFUとSecure DFU」( https://qiita.com/jiro-aqua/items/97c8ec6910d584281b7a )のためのリポジトリです。

# to use this example

- copy your private key file to ../dfu/private.key
- copy your public key file to ../dfu/dfu_public_key.c
- open application's emProject file by Segger Embedded Studio and build it.
- open bootloader's emProject file by Segger Embedded Studio and build it.
- open command prompt at ./package/
- execute package.bat to build ROM image and OTA image.

# ROM flashing

- connect nRF52840 target via J-Link Debugger.
- execute program.bat

# OTA

- copy Output/ota_app.zip (application only) or ota_all.zip (app/bl/sd) to your Android or iPhone.
- nRF-Connect (on Google Play or AppStore) or nRF-Toolbox(https://github.com/NordicSemiconductor) can be use as OTA Central.



