#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>


/*  Control a WS2811 or WS2812b Led strip with an IR remote

    This sketch is designed to control a WS2811 or WS2812 Led strip using a RGB IR Remote:
    RGB Remote: https://images-na.ssl-images-amazon.com/images/I/71%2BXEYNSplL._SL1500_.jpg

    Functions:  OFF, ON, Increase/Decrease Brightness, Rainbow colors, Flash colors

    External libraries used for custom colors:
      - MyGRBcolor for WS2811 strip:  http://bluenik.com/14971557/my-grb-color-library
      - MyRGBcolor for WS2812b strip: http://bluenik.com/14971557/my-rgb-color-library

    Note: THIS SKETCH IS DIVIDED IN DIFFERENT TABS

    CIRCUIT:

    WS2812b Led Strip:
      - 5V   Pin  to  5V  Pin  of the Arduino
      - GND  Pin  to  GND Pin  of the Arduino
      - Data Pin  to  Pin 10   of the Arduino

    IR Receiver:
      - 5V   Pin  to  5V  Pin  of the Arduino
      - GND  Pin  to  GND Pin  of the Arduino
      - Data Pin  to  Pin 11   of the Arduino

    Status Led [Optional]:
      - Positive  Pin  to  Pin 13 of the Arduino
      - Negative  Pin  to  GND through a 220 Ohm Resistor

*/
