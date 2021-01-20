#include <stdio.h>
#include "boards.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "nrf_drv_twi.h"
#include "nrf_delay.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"


#define TWI_INSTANCE_ID 0

#define AL_I2C_VDD 2
#define AL_I2C_SCL 25
#define AL_I2C_SDA 24
#define AL_I2C_ALERT 23
#define AL_I2C_A0 22
#define AL_I2C_A1 21
#define AL_I2C_A2 20

#define AL_I2C_ADDR (0x18U >> 1)
#define AL_I2C_REG_TEMP 0x05


static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

static uint16_t m_sample;

static uint16_t al_i2c_last;

static bool down = true;
static bool ready = false;


uint16_t possiblyGetTemperature() {
   ret_code_t err_code;

   if (down) {
      down = false;
      
      const nrf_drv_twi_config_t twi_ali2c_config = {
         .scl = AL_I2C_SCL,
         .sda = AL_I2C_SDA,
         .frequency = NRF_DRV_TWI_FREQ_100K,
         .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
         .clear_bus_init = false
      };
      
      err_code = nrf_drv_twi_init(&m_twi, &twi_ali2c_config, twi_handler, NULL);
      APP_ERROR_CHECK(err_code);
      
      nrf_drv_twi_enable(&m_twi);
      
      uint8_t reg = AL_I2C_REG_TEMP;
      err_code = nrf_drv_twi_tx(&m_twi, AL_I2C_ADDR, reg, sizeof(reg), false);
      APP_ERROR_CHECK(err_code);
      
      return 0;
   } else if (ready) {
      err_code = nrf_drv_twi_rx(&m_twi, AL_I2C_ADDR, &m_sample, sizeof(m_sample));
      APP_ERROR_CHECK(err_code);
      
      return al_i2c_last;
   }
}

void twi_handler(nrf_drv_twi_evt_t const * p_event, void * p_context) {
   switch (p_event->type) {
      case NRF_DRV_TWI_EVT_DONE:
         ready = true;
         if (p_event->xfer_desc.type == NRF_DRV_TWI_XFER_RX) {
            al_i2c_last = m_sample;
         }
         break;
      default:
         break;
   }
}
