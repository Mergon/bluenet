#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const char g_FIRMWARE_VERSION[];

extern const char g_COMPILATION_DAY[];

extern const char g_BUILD_TYPE[];

extern const char g_BEACON_UUID[];

extern const uint16_t g_BEACON_MAJOR;

extern const uint16_t g_BEACON_MINOR;

extern const uint8_t g_BEACON_RSSI;

extern uint32_t g_APPLICATION_START_ADDRESS;

extern uint32_t g_APPLICATION_LENGTH;

extern uint32_t g_RAM_R1_BASE;

extern uint32_t g_RAM_APPLICATION_AMOUNT;

extern uint32_t g_HARDWARE_BOARD_ADDRESS;

extern uint32_t g_DEFAULT_HARDWARE_BOARD;

extern uint32_t g_FLASH_MICROAPP_BASE;

extern uint8_t g_FLASH_MICROAPP_PAGES;

extern uint32_t g_RAM_MICROAPP_BASE;

extern uint32_t g_RAM_MICROAPP_AMOUNT;

extern uint8_t g_MAX_CHIP_TEMPERATURE;

extern uint16_t g_BOOT_DELAY;

extern uint16_t g_SCAN_DURATION;

extern uint16_t g_SCAN_INTERVAL;

extern uint16_t g_SCAN_WINDOW;

extern uint16_t g_SCAN_BREAK_DURATION;

extern const uint8_t g_TX_POWER;

extern const uint16_t g_CONNECTION_ALIVE_TIMEOUT;

extern const uint16_t g_MASTER_BUFFER_SIZE;

extern const bool g_CHANGE_NAME_ON_RESET;

extern const bool g_CONFIG_ENCRYPTION_ENABLED_DEFAULT;

extern const bool g_CONFIG_IBEACON_ENABLED_DEFAULT;

extern const bool g_CONFIG_MESH_ENABLED_DEFAULT;

extern const bool g_CONFIG_SCANNER_ENABLED_DEFAULT;

extern const bool g_CONFIG_INTERVAL_SCANNER_ENABLED_DEFAULT;

extern const bool g_CONFIG_TAP_TO_TOGGLE_ENABLED_DEFAULT;

extern const bool g_CONFIG_SWITCHCRAFT_ENABLED_DEFAULT;

extern const bool g_CONFIG_SWITCH_LOCK_ENABLED_DEFAULT;

extern const bool g_CONFIG_START_DIMMER_ON_ZERO_CROSSING_DEFAULT;

extern const bool g_CONFIG_PWM_ENABLED_DEFAULT;

extern const uint16_t g_CONFIG_TAP_TO_TOGGLE_RSSI_THRESHOLD_OFFSET_DEFAULT;

extern const bool g_CONFIG_SPHERE_ID_DEFAULT;

extern const bool g_CONFIG_CROWNSTONE_ID_DEFAULT;

extern const bool g_CONFIG_RELAY_HIGH_DURATION_DEFAULT;

extern const uint8_t g_CONFIG_LOW_TX_POWER_DEFAULT;

extern const float g_CONFIG_VOLTAGE_MULTIPLIER_DEFAULT;

extern const float g_CONFIG_CURRENT_MULTIPLIER_DEFAULT;

extern const uint16_t g_CONFIG_VOLTAGE_ZERO_DEFAULT;

extern const uint16_t g_CONFIG_CURRENT_ZERO_DEFAULT;

extern const uint16_t g_CONFIG_POWER_ZERO_DEFAULT;

extern const uint16_t g_CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_UP_DEFAULT;

extern const uint16_t g_CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_DOWN_DEFAULT;

extern const uint8_t g_CS_SERIAL_ENABLED;

extern const bool g_ENABLE_RSSI_FOR_CONNECTION;

#ifdef __cplusplus
}
#endif

