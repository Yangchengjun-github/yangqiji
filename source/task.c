#include "task.h"

unsigned char cnt_1ms = 0;
unsigned char cnt_10ms = 0;
struct 
{
    unsigned char preiod;
    unsigned char pulse;
    unsigned char counter;
}output_CB = {10,9,0};
void timebase_init(void)
{
    //分频器使能
    _pscen = 1;
    //时钟
    _clksel1 = 0;
    _clksel0 = 0;
    //周期2^9
    _tb02 = 1;
    _tb01 = 0;
    _tb00 = 1;
    

    //中断使能
    _tb0e =  1;
    //总中断
    _emi = 1;
    // 使能
    _tb0on = 1;
}
void task_debug(void);
void task_run(void)
{
    if (sys_clk.period_10ms)
    {
        sys_clk.period_10ms = 0;
        #if (DEBUG == 1)
        task_debug();
        #endif
        task_ntc_voltage();
        task_key();
        task_app();
        task_buzzer();
        task_led();
    }
    if (sys_clk.period_1s)
    {
        sys_clk.period_1s = 0;
        
    }
}

void task_debug(void)
{
    static unsigned int a;
    a++;
    if(a>=100)
    {
        a = 0;
       // my_printf_int(123);
        // UART_SoftWareSendByte(0xaa);
        // UART_SoftWareSendByte(0x55);
        UART_SoftWareSendByte(sys_arg.timer_autoShutdown >> 8);
        UART_SoftWareSendByte(sys_arg.timer_autoShutdown);
    }
    
        
   
}
void __attribute((interrupt(0x10))) TB0_ISR(void)
{
    GCC_NOP();
    cnt_1ms++;
    if (cnt_1ms >= 10)
    {
        cnt_1ms = 0;
        cnt_10ms++;
        sys_clk.period_10ms = 1;
        if (cnt_10ms >= 100)
        {
            cnt_10ms = 0;
            sys_clk.period_1s = 1;
            sys_arg.timer_autoShutdown++;
            sys_arg.limit_timer++;
            if(sys_arg.timer_disable)
            {
                sys_arg.timer_disable--;
            }
        }
    }
      
}
