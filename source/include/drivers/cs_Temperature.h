/**
 * Author: Crownstone Team
 * Copyright: Crownstone (https://crownstone.rocks)
 * Date: Oct 23, 2014
 * License: LGPLv3+, Apache License 2.0, and/or MIT (triple-licensed)
 */
#pragma once

//#include "nrf_soc.h"

#include <ble/cs_Nordic.h>
#include "util/cs_BleError.h"
#include <drivers/cs_twisupport.h>

/** Get temperature reading from the softdevice
 *
 * The received value from the softdevice is in
 * 0.25°C steps, so in order to get it in °C, the
 * value is divided by 4
 */
inline int32_t getTemperature() {
	int32_t temperature;
	uint32_t err_code;

	err_code = sd_temp_get(&temperature);
	APP_ERROR_CHECK(err_code);

//	LOGd("raw temp: %d", temperature);
//	LOGi("temp: %d", temperature / 4);

	temperature = (temperature / 4);


	//temperature = possiblyGetTemperature();

	return temperature;
}
