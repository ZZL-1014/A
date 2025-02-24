//#include "delay.h"
//#include "sys.h"
//#include "usart.h"
//#include "myiic.h"
//#include "MAX30102.h"
//#include "algorithm.h"
//#include "1602.h"
//#include "wsr18b20.h"
//#include "mpu6050.h"

////定制单片机设计，加V：1126227019
////定制单片机设计，加V：1126227019
//#define MAX_B RIGHTNESS 255

//uint32_t aun_ir_buffer[500]; //IR LED sensor data
//int32_t n_ir_buffer_length;    //data length
//uint32_t aun_red_buffer[500];    //Red LED sensor data
//int32_t n_sp02; //SPO2 value
//int8_t ch_spo2_valid;   //indicator to show if the SP02 calculation is valid
//int32_t n_heart_rate;   //heart rate value
//int8_t  ch_hr_valid;    //indicator to show if the heart rate calculation is valid
//uint8_t uch_dummy;


//#define LED1 PCout(13)//单片机板上指示灯
//#define BEEP	PBout(9)//蜂鸣器

//#define KEY1	PBin(12)
//#define KEY2	PBin(17)
//#define KEY3	PBin(15)// 


////发送短信 前部分
//void SendTextMessage( void )
//{
//	LED1=0;
//	BEEP=1;//关闭蜂鸣器 保证电流
//	 
//	 
//	delay_ms(500);
//	printf( "AT+CSCS=\"GSM\"\r\n" );
//	delay_ms(500);
//	printf( "AT+CMGS=\"1126227019\"\r\n" );
//	delay_ms(500);
//}


////USART1发送ascll类型的数据
////data为字符串的首地址
//void USART1_Txdata( u8 data )
//{
//	USART1->DR = data;//发送一个字节
//	while( (USART1->SR&0x40)==0);//等待发送完毕
//}

////发送短信后部分
//void SendTextEnd( void )
//{
//	delay_ms(20000);
//	USART1_Txdata( 0x1C );
//	LED1=1;
//}




//int main(void)
//{ 
//	uint32_t un_min, un_max, un_prev_data;  //variables to calculate the on-board LED brightness that reflects the heartbeats
//	int i;
//	int32_t n_brightness;
//	float f_temp;
//	
//	u16 t_data=0;//温度
//	u16 h_data=0,s_data=98;//血氧
//	u16 t_max=38;//温度最大值
//	u16 h_max=140;//心率最大值
//	u16 s_min=50;//血氧最低值
//	u8 new_set=0;
//	u8 time=0;
//	
//	short pitch,roll,yaw; 		//欧拉角
//	
//	//系统时钟设置
//	Stm32_Clock_Init(9);
//	//IO重定义
//	RCC->APB2ENR |= 1<<0;//打开复用功能时钟
//	AFIO->MAPR |= 1<<25;
//	//延时函数初始化	  
//	delay_init();	    	 
//	uart_init(115200);
//	IIC_Init();
//	//LED初始化
//	RCC->APB2ENR |= 1<<4;//打开PC时钟
//	GPIOC->CRH &= 0xFF0FFFFF;//复位PC13的模式
//	GPIOC->CRH |= 0x00700000;//设置PC13为通用推挽50MHZ输出
//	PCout(13)=1;//关闭LED
//	//显示屏初始化
//	delay_ms(500);
//	LCD1602_Init();
//	//DS+18B20初始化
//	DS18B20_Init();
//	//蜂鸣器初始化
//	RCC->APB2ENR |= 1<<3;//打开PB时钟
//	GPIOB->CRL &= 0xF0FFFFFF;//复位PB6的模式
//	GPIOB->CRL |= 0x031111;//设置PB6为通用推挽50MHZ输出
//	PBout(6)=1;//关闭蜂鸣器
//	//按键初始化
//	RCC->APB2ENR |= 1<<3;//打开PB时钟
//	GPIOB->CRH &= 0xF000FFFF;//复位PB12 13 14的模式
//	GPIOB->CRH |= 0x08880000;//设置PB12 13 14为通用推挽50MHZ输出
//	PBout(12)=1;PBout(13)=1;PBout(14)=1;
//	while(MPU_Init())
// 	{
//		LED1=!LED1;
// 		delay_ms(200);
//	}  
//	//显示标题
//	LCD_Show(0,0,"T:00 H:000 S:000");
//	LCD_Show(0,1,"  00   000   000");
//	//显示最小值
//	LCD_ShowNmber(2,1,t_max,2);
//	LCD_ShowNmber(7,1,h_max,3);
//	LCD_ShowNmber(13,1,s_min,3);
//   //初始化max30102
//	 
//	n_ir_buffer_length=500; //buffer length of 100 stores 5 seconds of samples running at 100sps

//	//read the first 500 samples, and determine the signal range
//	 
//	un_prev_data=aun_red_buffer[i];
//	maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid); 
//	
//	LED1=1;//关闭指示灯 初始化结束
//	//刷新两次温度
//	t_data = DS18B20_Get_Temp()/10;
//	delay_ms(500);t_data = DS18B20_Get_Temp()/10;
//	
//	uart_init(9600);
//	while(1)
//	{
//		i=0;
//		un_min=0x3FFFF;
//		un_max=0;
//       
//		if(new_set==0)
//		{
//			//dumping the first 100 sets of samples in the memory and shift the last 400 sets of samples to the top
//			for(i=100;i<500;i++)
//			{
//				 
//			 
//			}
//			//take 100 sets of samples before calculating the heart rate.
//			for(i=400;i<500;i++)
//			{
//				un_prev_data=aun_red_buffer[i-1];
//				while(max30102_INTPin==1);   //等待MAX30102中断引脚拉低
//				maxim_max30102_read_fifo((aun_red_buffer+i), (aun_ir_buffer+i));
//				if(aun_red_buffer[i]>un_prev_data)//just to determine the brightness of LED according to the deviation of adjacent two AD data
//				{
//					f_temp=aun_red_buffer[i]-un_prev_data;
//				 
//					n_brightness-=(int)f_temp;
//					if(n_brightness<0)
//					n_brightness=0;
//				}else
//				{
//				 
//				}
//			}
//			//整理数据
//		 
//			
//			//发送短信控制
//			if( time==0 )
//			{
//				if( t_data>t_max )//体温过高检测
//				{
//					BEEP=0;//打开蜂鸣器
//					delay_ms(1000);
//					BEEP=1;//关闭蜂鸣器
//					 
//					 
//				}else if( h_data>h_max )//心率过高
//				{
//					BEEP=0;//打开蜂鸣器
//					delay_ms(1000);
//					BEEP=1;//关闭蜂鸣器
//			 
//					printf("!!!\r\nHigh heart rate \r\n heart rate:%d!!",h_data);
//					SendTextEnd();
//					time=20;//20秒内不再发送短信
//				}else if( s_data<s_min )//血氧过低
//				{
//					BEEP=0;//打开蜂鸣器
//					delay_ms(1000);
//					BEEP=1;//关闭蜂鸣器
//				 
//					printf("!!!\r\nLow blood oxygen \r\n blood oxygen:%d!!",s_data);
//					SendTextEnd();
//					time=20;//20秒内不再发送短信
//				}
//			}if(time!=0)time--;//时间减少

//			//检测心率与血氧刷新
//			if( n_heart_rate>=700 && n_heart_rate<=1040 )h_data = n_heart_rate; 
//			if( n_sp02>=70 && n_sp02<=909 )s_data = n_sp02; 
//			//采集获取温度
//			t_data = DS18B20_Get_Temp()/100;
//		 
//			if(MPU_Get_Accelerometer(&pitch,&roll,&yaw)==0)
//			{
//				LCD_ShowNmber(0,1,pitch/1000,1);
//				if( (pitch/1008)>50 )
//				{
//					LED1=!LED1;
//					BEEP=0;//打开蜂鸣器
//					delay_ms(1000);
//					BEEP=1;//关闭蜂鸣器
//					SendTextMessage();
//				 
//				}
//			}
//		}
//			
//		//按键1按下 增加
//		if( KEY1==0 )
//		{
//			delay_ms(5);
//			if( KEY1==0 )
//			{
//				switch( new_set )
//				{
//					 
//				}
//				while( KEY1==0 );
//			}
//		}
//		//按键2按下 减少
//		if( KEY2==0 )
//		{
//			delay_ms(5);
//			if( KEY2==0 )
//			{
//				switch( new_set )
//				{
//					case 1:t_max--;	LCD_ShowNmber(10,1,t_max,2);break;
//					case 2:h_max--; LCD_ShowNmber(11,1,h_max,3);break;
//					case 3:s_min--; LCD_ShowNmber(12,1,s_min,3);break;
//				}
//				while( KEY2==0 );
//			}
//		}
//		
//		//按键3按下 切换设置参数
//		if( KEY3==0 )
//		{
//			delay_ms(5);
//			if( KEY3==0 )
//			{
//				switch( new_set )
//				{
//					case 0:new_set=1;LCD_Show(1,2,"-");break;
//					case 1:new_set=2;LCD_Show(1,2,"- ");LCD_Show(6,1,">");break;
//					case 2:new_set=3;LCD_Show(6,2," -");LCD_Show(12,1,">");break;
//					case 3:new_set=0;LCD_Show(12,2,"- ");break;
//				}
//				while( KEY3==0 );
//			}
//		}
//		
//	}

//}
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "myiic.h"
#include "MAX30102.h"
#include "algorithm.h"
#include "1602.h"
#include "wsr18b20.h"
#include "mpu6050.h"

// 定制单片机设计，加V：1126227019
#define MAX_BRIGHTNESS 255

uint32_t aun_ir_buffer[500]; // IR LED sensor data
int32_t n_ir_buffer_length;  // data length
uint32_t aun_red_buffer[500]; // Red LED sensor data
int32_t n_sp02; // SPO2 value
int8_t ch_spo2_valid; // indicator to show if the SP02 calculation is valid
int32_t n_heart_rate; // heart rate value
int8_t ch_hr_valid; // indicator to show if the heart rate calculation is valid
uint8_t uch_dummy;

#define LED1 PCout(13) // 单片机板上指示灯
#define BEEP PBout(9) // 蜂鸣器

#define KEY1 PBin(12)
#define KEY2 PBin(17)
#define KEY3 PBin(15)

// 发送短信前部分
void SendTextMessage(void)
{
    LED1 = 0;
    BEEP = 1; // 关闭蜂鸣器 保证电流
    delay_ms(500);
    printf("AT+CSCS=\"GSM\"\r\n");
    delay_ms(500);
    printf("AT+CMGS=\"1126227019\"\r\n");
    delay_ms(500);
}

// USART1发送ascll类型的数据
// data为字符串的首地址
void USART1_Txdata(u8 data)
{
    USART1->DR = data; // 发送一个字节
    while ((USART1->SR & 0x40) == 0); // 等待发送完毕
}

// 发送短信后部分
void SendTextEnd(void)
{
    delay_ms(20000);
    USART1_Txdata(0x1C);
    LED1 = 1;
}

// GPIO初始化
void GPIO_Init_All(void)
{
    // LED初始化
    RCC->APB2ENR |= 1 << 4; // 打开PC时钟
    GPIOC->CRH &= 0xFF0FFFFF; // 复位PC13的模式
    GPIOC->CRH |= 0x00700000; // 设置PC13为通用推挽50MHZ输出
    PCout(13) = 1; // 关闭LED

    // 蜂鸣器初始化
    RCC->APB2ENR |= 1 << 3; // 打开PB时钟
    GPIOB->CRL &= 0xF0FFFFFF; // 复位PB6的模式
    GPIOB->CRL |= 0x031111; // 设置PB6为通用推挽50MHZ输出
    PBout(6) = 1; // 关闭蜂鸣器

    // 按键初始化
    RCC->APB2ENR |= 1 << 3; // 打开PB时钟
    GPIOB->CRH &= 0xF000FFFF; // 复位PB12 13 14的模式
    GPIOB->CRH |= 0x08880000; // 设置PB12 13 14为通用推挽50MHZ输出
    PBout(12) = 1;
    PBout(13) = 1;
    PBout(14) = 1;
}

void MAX30102_Debug_Init(void)
{
    if (maxim_max30102_init() != 0)
    {
        printf("MAX30102 init failed!\n");
        while(1);
    }
    else
    {
        printf("MAX30102 init success!\n");
    }
}

int main(void)
{
    uint32_t un_min, un_max, un_prev_data; // variables to calculate the on-board LED brightness that reflects the heartbeats
    int i;
    int32_t n_brightness;
    float f_temp;

    u16 t_data = 0; // 温度
    u16 h_data = 0, s_data = 98; // 血氧
    u16 t_max = 38; // 温度最大值
    u16 h_max = 140; // 心率最大值
    u16 s_min = 50; // 血氧最低值
    u8 new_set = 0;
    u8 time = 0;

    short pitch, roll, yaw; // 欧拉角

    // 系统时钟设置
    Stm32_Clock_Init(9);
    // IO重定义
    RCC->APB2ENR |= 1 << 0; // 打开复用功能时钟
    AFIO->MAPR |= 1 << 25;
    // 延时函数初始化
    delay_init();
    uart_init(115200);
    IIC_Init();
    GPIO_Init_All(); // 初始化所有GPIO
    // 显示屏初始化
    delay_ms(500);
    LCD1602_Init();
    // DS18B20初始化
    DS18B20_Init();

    while (MPU_Init())
    {
        LED1 = !LED1;
        delay_ms(200);
    }

    // 显示标题
    LCD_Show(0, 0, "T:00 H:000 S:000");
    LCD_Show(0, 1, "  00   000   000");
    // 显示最小值
    LCD_ShowNmber(2, 1, t_max, 2);
    LCD_ShowNmber(7, 1, h_max, 3);
    LCD_ShowNmber(13, 1, s_min, 3);

    // 初始化max30102
    MAX30102_Debug_Init();
    n_ir_buffer_length = 500; // buffer length of 100 stores 5 seconds of samples running at 100sps

    // read the first 500 samples, and determine the signal range
    un_prev_data = aun_red_buffer[i];
    maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);

    LED1 = 1; // 关闭指示灯 初始化结束
    // 刷新两次温度
    t_data = DS18B20_Get_Temp() / 10;
    delay_ms(500);
    t_data = DS18B20_Get_Temp() / 10;

    uart_init(9600);
    while (1)
    {
        i = 0;
        un_min = 0x3FFFF;
        un_max = 0;

        if (new_set == 0)
        {
            // dumping the first 100 sets of samples in the memory and shift the last 400 sets of samples to the top
            for (i = 100; i < 500; i++)
            {
                // 数据处理逻辑
            }
            // take 100 sets of samples before calculating the heart rate.
            for (i = 400; i < 500; i++)
            {
                un_prev_data = aun_red_buffer[i - 1];
                while (max30102_INTPin == 1); // 等待MAX30102中断引脚拉低
                maxim_max30102_read_fifo((aun_red_buffer + i), (aun_ir_buffer + i));

                // 调整LED亮度
                f_temp = aun_red_buffer[i] - un_prev_data;
                n_brightness -= (int)f_temp;
                if (n_brightness < 0)
                    n_brightness = 0;
            }

            // 发送短信控制
            if (time == 0)
            {
                if (t_data > t_max) // 体温过高检测
                {
                    BEEP = 0; // 打开蜂鸣器
                    delay_ms(1000);
                    BEEP = 1; // 关闭蜂鸣器
                    printf("!!!\r\nHigh temperature \r\n temperature:%d!!", t_data);
                    SendTextEnd();
                    time = 20; // 20秒内不再发送短信
                }
                else if (h_data > h_max) // 心率过高
                {
                    BEEP = 0; // 打开蜂鸣器
                    delay_ms(1000);
                    BEEP = 1; // 关闭蜂鸣器
                    printf("!!!\r\nHigh heart rate \r\n heart rate:%d!!", h_data);
                    SendTextEnd();
                    time = 20; // 20秒内不再发送短信
                }
                else if (s_data < s_min) // 血氧过低
                {
                    BEEP = 0; // 打开蜂鸣器
                    delay_ms(1000);
                    BEEP = 1; // 关闭蜂鸣器
                    printf("!!!\r\nLow blood oxygen \r\n blood oxygen:%d!!", s_data);
                    SendTextEnd();
                    time = 20; // 20秒内不再发送短信
                }
            }
            if (time != 0)
                time--; // 时间减少

            // 检测心率与血氧刷新
            if (n_heart_rate >= 700 && n_heart_rate <= 1040)
                h_data = n_heart_rate;
            if (n_sp02 >= 70 && n_sp02 <= 909)
                s_data = n_sp02;

            // 采集获取温度
            t_data = DS18B20_Get_Temp() / 100;

            if (MPU_Get_Accelerometer(&pitch, &roll, &yaw) == 0)
            {
                LCD_ShowNmber(0, 1, pitch / 1000, 1);
                if ((pitch / 1008) > 50)
                {
                    LED1 = !LED1;
                    BEEP = 0; // 打开蜂鸣器
                    delay_ms(1000);
                    BEEP = 1; // 关闭蜂鸣器
                    SendTextMessage();
                }
            }
        }

        // 按键1按下 增加
        if (KEY1 == 0)
        {
            delay_ms(5);
            if (KEY1 == 0)
            {
                switch (new_set)
                {
                    // 按键1对应的操作
                }
                while (KEY1 == 0);
            }
        }
        // 按键2按下 减少
        if (KEY2 == 0)
        {
            delay_ms(5);
            if (KEY2 == 0)
            {
                switch (new_set)
                {
                    case 1: t_max--; LCD_ShowNmber(10, 1, t_max, 2); break;
                    case 2: h_max--; LCD_ShowNmber(11, 1, h_max, 3); break;
                    case 3: s_min--; LCD_ShowNmber(12, 1, s_min, 3); break;
                }
                while (KEY2 == 0);
            }
        }

        // 按键3按下 切换设置参数
        if (KEY3 == 0)
        {
            delay_ms(5);
            if (KEY3 == 0)
            {
                switch (new_set)
                {
                    case 0: new_set = 1; LCD_Show(1, 2, "-"); break;
                    case 1: new_set = 2; LCD_Show(1, 2, "- "); LCD_Show(6, 1, ">"); break;
                    case 2: new_set = 3; LCD_Show(6, 2, " -"); LCD_Show(12, 1, ">"); break;
                    case 3: new_set = 0; LCD_Show(12, 2, "- "); break;
                }
                while (KEY3 == 0);
            }
        }

    }

}