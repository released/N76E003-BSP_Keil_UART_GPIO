# N76E003-BSP_Keil_UART_GPIO
 N76E003-BSP_Keil_UART_GPIO

update @ 2023/09/06

1. simple timer GPIO toggle with print counting under while loop , test in N76E003 EVB

- under while loop , send TX (P06) per 100 ms

- under TIMER0 IRQ , toggle P1.1 , P1.2 per 1000 ms

2. below is LA capture with UART TX and GPIO toggle 

![image](https://github.com/released/N76E003-BSP_Keil_UART_GPIO/blob/main/LA.jpg)	


