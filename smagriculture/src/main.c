#include <zephyr.h>
#include <drivers/adc.h>

const enum adc_gain ADC_GAIN = ADC_GAIN_1;
const enum adc_reference ADC_REFENCE = ADC_REF_INTERNAL;
const uint16_t ADC_ACQUISITION_TIME = ADC_ACQ_TIME_DEFAULT;
const uint8_t ADC_CHANNEL_ID = ;

struct adc_channel_cfg adc_config = {
        .gain = ADC_GAIN,
        .reference = ADC_REFENCE,
        .acquisition_time = ADC_ACQUISITION_TIME,
        .channel_id = ADC_CHANNEL_ID,
        .differential = 0,
};



int main (){
    char DEVICE_NAME =  DT_LABEL(DT_NODELABEL("st,stm32-adc"));

    struct device *adc1 = device_get_binding(DEVICE_NAME);
    if (adc1) {
        LOG_ERR("GPIO device " DEVICE_NAME " not found!");
        return -EIO;
    }

    int ch = adc_channel_setup(adc1, &adc_config);

    int value = adc_read(adc1, &adc_config);
}