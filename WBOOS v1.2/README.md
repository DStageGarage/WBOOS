# WBOOS v1.2
The v1.2 HW of WBOOS project has a few mainly cosmetic changes over v1.1:
- C7 removed from BOM as it shouldn't be populated, having it can result in reference voltage instabilities.
- R16 for the LCD backlight moved to the TOP (main component side) for automated assembly. Solder pad on the BOTTOM provided if user wished to control backlight externally (marked "BL").
- R7 moved to the TOP (main component side) for automated assembly - only LSU4.9 is supported anyway so there'sno need to acces that resistor from the BOTTOM.
- propper BOM abd CPL file (Pick'n'place) for JLCPCB added to allow for automated assembly.
- cosmetic changes on the schematic.

> [!TIP]
> There is usually a short of inventory in JLCPCB for the main chip U1 CY8C24423-24. You can purchase it in online electronic stores such as Farnell or Mouser and solder it malually.
