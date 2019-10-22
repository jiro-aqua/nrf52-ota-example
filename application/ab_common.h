#ifndef AB_COMMON_H__
#define AB_COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

#define DEVICE_NAME                     "AquaBlue"                                  /**< Name of device. Will be included in the advertising data. */
#define MANUFACTURER_NAME               "Aquamarine Networks."                      /**< Manufacturer. Will be passed to Device Information Service. */

// UUID for AquaBlue Service
// 8154ef7d-469b-471e-b071-2cfe62d43f3a

#define AB_BLE_UUID_BASE        {0x3a, 0x3f, 0xd4, 0x62, 0xfe, 0x2c, 0x71, 0xb0, \
                                 0x1e, 0x47, 0x96, 0x46, 0x00, 0x00, 0x54, 0x81}
#define AB_BLE_UUID_SERVICE       0xef7d
#define AB_BLE_UUID_COMMAND_CHAR  0xef70
#define AB_BLE_UUID_RESPONSE_CHAR 0xef71
#define AB_BLE_UUID_DATA_CHAR   0xef72

#ifdef __cplusplus
}
#endif

#endif // AB_COMMON_H__

