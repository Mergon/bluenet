/**
 * Author: Crownstone Team
 * Copyright: Crownstone (https://crownstone.rocks)
 * Date: Aug 15, 2018
 * License: LGPLv3+, Apache License 2.0, and/or MIT (triple-licensed)
 */

#include <protocol/cs_ConfigTypes.h>

char const *ConfigurationNames[] = {
	STRINGIFY_(CONFIG_NAME),
	STRINGIFY_(CONFIG_DEVICE_TYPE),
	STRINGIFY_(CONFIG_ROOM),
	STRINGIFY_(CONFIG_FLOOR),
	STRINGIFY_(CONFIG_NEARBY_TIMEOUT),
	STRINGIFY_(CONFIG_PWM_PERIOD),
	STRINGIFY_(CONFIG_IBEACON_MAJOR),
	STRINGIFY_(CONFIG_IBEACON_MINOR),
	STRINGIFY_(CONFIG_IBEACON_UUID),
	STRINGIFY_(CONFIG_IBEACON_TXPOWER),
	STRINGIFY_(CONFIG_WIFI_SETTINGS),
	STRINGIFY_(CONFIG_TX_POWER),
	STRINGIFY_(CONFIG_ADV_INTERVAL),
	STRINGIFY_(CONFIG_PASSKEY),
	STRINGIFY_(CONFIG_MIN_ENV_TEMP),
	STRINGIFY_(CONFIG_MAX_ENV_TEMP),
	STRINGIFY_(CONFIG_SCAN_DURATION),
	STRINGIFY_(CONFIG_SCAN_SEND_DELAY),
	STRINGIFY_(CONFIG_SCAN_BREAK_DURATION),
	STRINGIFY_(CONFIG_BOOT_DELAY),
	STRINGIFY_(CONFIG_MAX_CHIP_TEMP),
	STRINGIFY_(CONFIG_SCAN_FILTER),
	STRINGIFY_(CONFIG_SCAN_FILTER_SEND_FRACTION),
	STRINGIFY_(CONFIG_CURRENT_LIMIT),
	STRINGIFY_(CONFIG_MESH_ENABLED),
	STRINGIFY_(CONFIG_ENCRYPTION_ENABLED),
	STRINGIFY_(CONFIG_IBEACON_ENABLED),
	STRINGIFY_(CONFIG_SCANNER_ENABLED),
	STRINGIFY_(CONFIG_CONT_POWER_SAMPLER_ENABLED),
	STRINGIFY_(CONFIG_TRACKER_ENABLED),
	STRINGIFY_(CONFIG_ADC_BURST_SAMPLE_RATE),
	STRINGIFY_(CONFIG_POWER_SAMPLE_BURST_INTERVAL),
	STRINGIFY_(CONFIG_POWER_SAMPLE_CONT_INTERVAL),
	STRINGIFY_(CONFIG_ADC_CONT_SAMPLE_RATE),
	STRINGIFY_(CONFIG_CROWNSTONE_ID),
	STRINGIFY_(CONFIG_KEY_ADMIN),
	STRINGIFY_(CONFIG_KEY_MEMBER),
	STRINGIFY_(CONFIG_KEY_GUEST),
	STRINGIFY_(CONFIG_DEFAULT_ON),
	STRINGIFY_(CONFIG_SCAN_INTERVAL),
	STRINGIFY_(CONFIG_SCAN_WINDOW),
	STRINGIFY_(CONFIG_RELAY_HIGH_DURATION),
	STRINGIFY_(CONFIG_LOW_TX_POWER),
	STRINGIFY_(CONFIG_VOLTAGE_MULTIPLIER),
	STRINGIFY_(CONFIG_CURRENT_MULTIPLIER),
	STRINGIFY_(CONFIG_VOLTAGE_ZERO),
	STRINGIFY_(CONFIG_CURRENT_ZERO),
	STRINGIFY_(CONFIG_POWER_ZERO),
	STRINGIFY_(CONFIG_POWER_ZERO_AVG_WINDOW),
	STRINGIFY_(CONFIG_MESH_ACCESS_ADDRESS),
	STRINGIFY_(CONFIG_SOFT_FUSE_CURRENT_THRESHOLD),
	STRINGIFY_(CONFIG_SOFT_FUSE_CURRENT_THRESHOLD_PWM),
	STRINGIFY_(CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_UP),
	STRINGIFY_(CONFIG_PWM_TEMP_VOLTAGE_THRESHOLD_DOWN),
	STRINGIFY_(CONFIG_PWM_ALLOWED),
	STRINGIFY_(CONFIG_SWITCH_LOCKED),
	STRINGIFY_(CONFIG_SWITCHCRAFT_ENABLED),
	STRINGIFY_(CONFIG_SWITCHCRAFT_THRESHOLD),
	STRINGIFY_(CONFIG_MESH_CHANNEL),
	STRINGIFY_(CONFIG_UART_ENABLED)
};
