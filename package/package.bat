REM set your sdk path
set SDK=C:\Nordic\nRF5_SDK_15.3.0_59ac345

REM NRF52840
set FAMILY=NRF52840
set HWVERSION=52
set SDVERSION=0xb6
set SOFTDEVICE=%SDK%\components\softdevice\s140\hex\s140_nrf52_6.1.1_softdevice.hex

REM nRF52832
REM set FAMILY=NRF52
REM set HWVERSION=52
REM set SDVERSION=0xb7
REM set SOFTDEVICE=%SDK%\components\softdevice\s132\hex\s132_nrf52_6.1.1_softdevice.hex

REM set your app/bl path (nRF52840)
set APP=..\application\pca10056\s140\ses\Output\Release\Exe\ble_app_buttonless_dfu_pca10056_s140.hex
set BOOTLOADER=..\bootloader\pca10056_ble\ses\Output\Release\Exe\secure_bootloader_ble_s140_pca10056.hex

REM set your app/bl path (nRF52832)
REM set APP=..\application\pca10040\s132\ses\Output\Release\Exe\ble_app_buttonless_dfu_pca10040_s132.hex
REM set BOOTLOADER=..\bootloader\pca10040_ble\ses\Output\Release\Exe\secure_bootloader_ble_s132_pca10040.hex

REM set your private key path
set PRIVATEKEY=..\..\dfu\private.key


REM make image for ROM FLASHING
mkdir Output
nrfutil settings generate --family %FAMILY% --application %APP% --application-version 1 --bootloader-version 1 --bl-settings-version 1 Output\settings.hex
mergehex --merge %SOFTDEVICE% %BOOTLOADER% --output Output\SD_BL.hex
mergehex --merge Output\SD_BL.hex %APP% --output Output\SD_BL_APP.hex
mergehex --merge Output\SD_BL_APP.hex Output\settings.hex --output Output\all.hex

del Output\SD_BL.hex
del Output\SD_BL_APP.hex
del Output\settings.hex

REM make image for OTA
nrfutil pkg generate --hw-version %HWVERSION% --application-version 1 --application %APP% --sd-req %SDVERSION% --key-file %PRIVATEKEY% Output\ota_app.zip
nrfutil pkg generate --hw-version %HWVERSION% --bootloader-version 1 --bootloader %BOOTLOADER% --application-version 1 --application %APP% --softdevice %SOFTDEVICE% --sd-id %SDVERSION% --sd-req %SDVERSION% --key-file %PRIVATEKEY% Output\ota_all.zip

