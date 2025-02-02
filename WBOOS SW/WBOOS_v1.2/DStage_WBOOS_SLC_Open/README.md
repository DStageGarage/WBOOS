# WBOOS v1.2 project
Here you will find the full SW project for PSoC Designer. You can also use the precompiled ready to program files from the attached set in "precompiled_hex_files" folder.

## Programming
There are a few options for programming WBOOS

1. Use PSoC MiniProg3 and PSoC Designer environment.
This is the native way for programming PSoC microcontrollers. However, PSoC MiniProg3 is not always easy to get and can be expensive.

2. Use Arduino board to program PSoC. This is probably the easiest option, you can use this project: https://github.com/zceemja/psoc1_prog/
- It is intended to use with Visual Studio Code, but you can easily open it in Arduino IDE. Just change the extension of "main.cpp" file i src folder to "main.ino" and Arduino IDE will know what to do. You should be able to compile and program it to different Arduino boards for example Arduino UNO (tested).
- Once you have the Arduino "PSoC programmer" ready you will need to install Python. Download and install Python from the official website. 
- Once you have Python ready you may have to add serial library. Open command line in Windows (type CMD in Start) and use this command: "pip install serial".
- Now connect XRES, SDA, SCL and GND lines of WBOOS with matching pins configured on your Arduino and power up both devices (you can connect 5V from Arduino to WBOOS and power it this way).
- You should now be able to program PSoC microcontroller with chosen hex file. You can directly run "programmer.py" from command line or use the provided "WBOOS_program.bat". It should make it easier to spot what's going on as well as change the file name and path if needed.

3. Use HC341 based board as a programmer. You can follow instructions on this website: https://antiradio.narod.ru/psoc/tools/programmer_341A/index.htm Be advised that it may not work with newer Windows like Win10 or Win11. It is proven to be working with Win7. If this is not a limitation for you, it may be an easier option than point 2.
