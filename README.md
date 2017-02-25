# AnalogTx

## Wat?

An experiment with nRF52 and Arduino environment to send the value of all the
analog inputs over BLE.


## How?


### Hardware

We use the [nRF52 DK board](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.nrf52%2Fdita%2Fnrf52%2Fdevelopment%2Fnrf52_dev_kit%2Fhw_drawings_v1.0.html&cp=2_2_2_5_0)
(but it's flexible).


### Firmware

Starting from this repo:

https://github.com/sandeepmistry/arduino-nRF5

But a fork was needed to allow using the 8 analog input as by default there
are only 6 usable (a firmware limitation to stick to Arduino conventions).
This fork is available here:

https://github.com/honnet/arduino-nRF5

The added analog input are AIN0 and AIN3 - see [pin assignments](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.nrf52832.ps.v1.1%2Fpin.html&cp=2_2_0_3&anchor=pin_assign).


### Software

To test the reception, we used the BLE UART app by Nordic Semi for Android:

https://play.google.com/store/apps/details?id=com.nordicsemi.nrfUARTv2

But a custom app can be made starting from this repo:

https://github.com/NordicSemiconductor/Android-nRF-UART

