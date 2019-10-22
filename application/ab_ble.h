#ifndef AB_BLE_H__
#define AB_BLE_H__

#ifdef __cplusplus
extern "C" {
#endif


#define AB_BLE_MAX_DATA_LEN    (NRF_SDH_BLE_GATT_MAX_MTU_SIZE - 1 - 2)

#define AB_BLE_OBSERVER_PRIO 2

#define AB_BLE_SERVICE_DEF(_name)                                                                 \
static ab_ble_t _name;                                                                            \
NRF_SDH_BLE_OBSERVER(_name ## _obs,                                                               \
                     AB_BLE_OBSERVER_PRIO,                                                    \
                     ble_on_ble_evt, &_name)

typedef void (*ab_ble_command_write_handler_t) (const uint8_t *commands, uint8_t length);
typedef void (*ab_ble_tx_complete_handler_t)(void);

typedef struct ab_ble_s
{
    uint16_t                    service_handle;
    ble_gatts_char_handles_t    command_char_handles;
    ble_gatts_char_handles_t    response_char_handles;
    ble_gatts_char_handles_t    data_char_handles;
    uint8_t                     uuid_type;
    ab_ble_command_write_handler_t command_write_handler;
    ab_ble_tx_complete_handler_t tx_complete_handler;
} ab_ble_t; 


void advertising_start(bool erase_bonds);
void ab_ble_init(void);

#ifdef __cplusplus
}
#endif

#endif // AB_BLE_H__

