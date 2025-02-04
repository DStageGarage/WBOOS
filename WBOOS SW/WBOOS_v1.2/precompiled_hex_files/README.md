# WBOOS v1.2 precompiled files
You can use the precompiled hex file to program your WBOOS board without a need for installing PSoC Designer and compilation. There are a few most frequently used configuration options tyo chose from:

| HEX file | Configuration |
| :---: | :--- |
| DStage_WBOOS_LCD_AFR.hex | standard 2x16 LCD display, top row shows AFR and temperature as a digital value, bottom row shows Lambda/AFR as bargraph |
| DStage_WBOOS_LCD_Lambda.hex | standard 2x16 LCD display, top row shows Lambda and temperature as a digital value, bottom row shows Lambda/AFR as bargraph |
| DStage_WBOOS_LCD_AFR_Lambda.hex | standard 2x16 LCD display, top row shows AFR and temperature as a digital value, bottom row shows Lambda as a digital value |
| DStage_WBOOS_LED_AFR.hex | TM1637 based LED 7-segment display module, shows AFR as a digital value |
| DStage_WBOOS_LED_Lambda.hex | TM1637 based LED 7-segment display module, shows Lambda as a digital value |
| DStage_WBOOS_LED_AFR_Lambda.hex | TM1637 based LED 7-segment display module, shows AFR or Lambda as a digital value switched witha a pin state |
| DStage_WBOOS_XXXX_slow.hex | a variant of the XXXX equivalent descibed above but with a slower display refresh rate of about 4 times per second instead of 10 times per second in a standard variant |

You can use the WBOOS_program.bat to program those by changing the path and file name. Just edit WBOOS_program.bat with a notepad.