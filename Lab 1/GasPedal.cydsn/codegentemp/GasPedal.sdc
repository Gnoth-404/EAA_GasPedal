# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\vboxuser\Documents\GitHub\EAA_GasPedal\Lab 1\GasPedal.cydsn\GasPedal.cyprj
# Date: Thu, 23 May 2024 17:26:13 GMT
#set_units -time ns
create_clock -name {JOYSTICK_ADC_XY_IntClock(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {TFT_SPI_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 7} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {JOYSTICK_ADC_XY_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 15 31} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {UART_LOG_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 27 53} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {CLK_LED} -source [get_pins {ClockBlock/clk_sync}] -edges {1 4801 9601} [list [get_pins {ClockBlock/dclk_glb_4}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\vboxuser\Documents\GitHub\EAA_GasPedal\Lab 1\GasPedal.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\vboxuser\Documents\GitHub\EAA_GasPedal\Lab 1\GasPedal.cydsn\GasPedal.cyprj
# Date: Thu, 23 May 2024 17:25:57 GMT
