//#include "delay.h"
//#include "sys.h"
//#include "usart.h"
//#include "myiic.h"
//#include "MAX30102.h"
//#include "algorithm.h"
//#include "1602.h"
//#include "wsr18b20.h"
//#include "mpu6050.h"

////���Ƶ�Ƭ����ƣ���V��1126227019
////���Ƶ�Ƭ����ƣ���V��1126227019
//#define MAX_B RIGHTNESS 255

//uint32_t aun_ir_buffer[500]; //IR LED sensor data
//int32_t n_ir_buffer_length;    //data length
//uint32_t aun_red_buffer[500];    //Red LED sensor data
//int32_t n_sp02; //SPO2 value
//int8_t ch_spo2_valid;   //indicator to show if the SP02 calculation is valid
//int32_t n_heart_rate;   //heart rate value
//int8_t  ch_hr_valid;    //indicator to show if the heart rate calculation is valid
//uint8_t uch_dummy;


//#define LED1 PCout(13)//��Ƭ������ָʾ��
//#define BEEP	PBout(9)//������

//#define KEY1	PBin(12)
//#define KEY2	PBin(17)
//#define KEY3	PBin(15)// 


////���Ͷ��� ǰ����
//void SendTextMessage( void )
//{
//	LED1=0;
//	BEEP=1;//�رշ����� ��֤����
//	 
//	 
//	delay_ms(500);
//	printf( "AT+CSCS=\"GSM\"\r\n" );
//	delay_ms(500);
//	printf( "AT+CMGS=\"1126227019\"\r\n" );
//	delay_ms(500);
//}


////USART1����ascll���͵�����
////dataΪ�ַ������׵�ַ
//void USART1_Txdata( u8 data )
//{
//	USART1->DR = data;//����һ���ֽ�
//	while( (USART1->SR&0x40)==0);//�ȴ��������
//}

////���Ͷ��ź󲿷�
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
//	u16 t_data=0;//�¶�
//	u16 h_data=0,s_data=98;//Ѫ��
//	u16 t_max=38;//�¶����ֵ
//	u16 h_max=140;//�������ֵ
//	u16 s_min=50;//Ѫ�����ֵ
//	u8 new_set=0;
//	u8 time=0;
//	
//	short pitch,roll,yaw; 		//ŷ����
//	
//	//ϵͳʱ������
//	Stm32_Clock_Init(9);
//	//IO�ض���
//	RCC->APB2ENR |= 1<<0;//�򿪸��ù���ʱ��
//	AFIO->MAPR |= 1<<25;
//	//��ʱ������ʼ��	  
//	delay_init();	    	 
//	uart_init(115200);
//	IIC_Init();
//	//LED��ʼ��
//	RCC->APB2ENR |= 1<<4;//��PCʱ��
//	GPIOC->CRH &= 0xFF0FFFFF;//��λPC13��ģʽ
//	GPIOC->CRH |= 0x00700000;//����PC13Ϊͨ������50MHZ���
//	PCout(13)=1;//�ر�LED
//	//��ʾ����ʼ��
//	delay_ms(500);
//	LCD1602_Init();
//	//DS+18B20��ʼ��
//	DS18B20_Init();
//	//��������ʼ��
//	RCC->APB2ENR |= 1<<3;//��PBʱ��
//	GPIOB->CRL &= 0xF0FFFFFF;//��λPB6��ģʽ
//	GPIOB->CRL |= 0x031111;//����PB6Ϊͨ������50MHZ���
//	PBout(6)=1;//�رշ�����
//	//������ʼ��
//	RCC->APB2ENR |= 1<<3;//��PBʱ��
//	GPIOB->CRH &= 0xF000FFFF;//��λPB12 13 14��ģʽ
//	GPIOB->CRH |= 0x08880000;//����PB12 13 14Ϊͨ������50MHZ���
//	PBout(12)=1;PBout(13)=1;PBout(14)=1;
//	while(MPU_Init())
// 	{
//		LED1=!LED1;
// 		delay_ms(200);
//	}  
//	//��ʾ����
//	LCD_Show(0,0,"T:00 H:000 S:000");
//	LCD_Show(0,1,"  00   000   000");
//	//��ʾ��Сֵ
//	LCD_ShowNmber(2,1,t_max,2);
//	LCD_ShowNmber(7,1,h_max,3);
//	LCD_ShowNmber(13,1,s_min,3);
//   //��ʼ��max30102
//	 
//	n_ir_buffer_length=500; //buffer length of 100 stores 5 seconds of samples running at 100sps

//	//read the first 500 samples, and determine the signal range
//	 
//	un_prev_data=aun_red_buffer[i];
//	maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid); 
//	
//	LED1=1;//�ر�ָʾ�� ��ʼ������
//	//ˢ�������¶�
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
//				while(max30102_INTPin==1);   //�ȴ�MAX30102�ж���������
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
//			//��������
//		 
//			
//			//���Ͷ��ſ���
//			if( time==0 )
//			{
//				if( t_data>t_max )//���¹��߼��
//				{
//					BEEP=0;//�򿪷�����
//					delay_ms(1000);
//					BEEP=1;//�رշ�����
//					 
//					 
//				}else if( h_data>h_max )//���ʹ���
//				{
//					BEEP=0;//�򿪷�����
//					delay_ms(1000);
//					BEEP=1;//�رշ�����
//			 
//					printf("!!!\r\nHigh heart rate \r\n heart rate:%d!!",h_data);
//					SendTextEnd();
//					time=20;//20���ڲ��ٷ��Ͷ���
//				}else if( s_data<s_min )//Ѫ������
//				{
//					BEEP=0;//�򿪷�����
//					delay_ms(1000);
//					BEEP=1;//�رշ�����
//				 
//					printf("!!!\r\nLow blood oxygen \r\n blood oxygen:%d!!",s_data);
//					SendTextEnd();
//					time=20;//20���ڲ��ٷ��Ͷ���
//				}
//			}if(time!=0)time--;//ʱ�����

//			//���������Ѫ��ˢ��
//			if( n_heart_rate>=700 && n_heart_rate<=1040 )h_data = n_heart_rate; 
//			if( n_sp02>=70 && n_sp02<=909 )s_data = n_sp02; 
//			//�ɼ���ȡ�¶�
//			t_data = DS18B20_Get_Temp()/100;
//		 
//			if(MPU_Get_Accelerometer(&pitch,&roll,&yaw)==0)
//			{
//				LCD_ShowNmber(0,1,pitch/1000,1);
//				if( (pitch/1008)>50 )
//				{
//					LED1=!LED1;
//					BEEP=0;//�򿪷�����
//					delay_ms(1000);
//					BEEP=1;//�رշ�����
//					SendTextMessage();
//				 
//				}
//			}
//		}
//			
//		//����1���� ����
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
//		//����2���� ����
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
//		//����3���� �л����ò���
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

// ���Ƶ�Ƭ����ƣ���V��1126227019
#define MAX_BRIGHTNESS 255

uint32_t aun_ir_buffer[500]; // IR LED sensor data
int32_t n_ir_buffer_length;  // data length
uint32_t aun_red_buffer[500]; // Red LED sensor data
int32_t n_sp02; // SPO2 value
int8_t ch_spo2_valid; // indicator to show if the SP02 calculation is valid
int32_t n_heart_rate; // heart rate value
int8_t ch_hr_valid; // indicator to show if the heart rate calculation is valid
uint8_t uch_dummy;

#define LED1 PCout(13) // ��Ƭ������ָʾ��
#define BEEP PBout(9) // ������

#define KEY1 PBin(12)
#define KEY2 PBin(17)
#define KEY3 PBin(15)

// ���Ͷ���ǰ����
void SendTextMessage(void)
{
    LED1 = 0;
    BEEP = 1; // �رշ����� ��֤����
    delay_ms(500);
    printf("AT+CSCS=\"GSM\"\r\n");
    delay_ms(500);
    printf("AT+CMGS=\"1126227019\"\r\n");
    delay_ms(500);
}

// USART1����ascll���͵�����
// dataΪ�ַ������׵�ַ
void USART1_Txdata(u8 data)
{
    USART1->DR = data; // ����һ���ֽ�
    while ((USART1->SR & 0x40) == 0); // �ȴ��������
}

// ���Ͷ��ź󲿷�
void SendTextEnd(void)
{
    delay_ms(20000);
    USART1_Txdata(0x1C);
    LED1 = 1;
}

// GPIO��ʼ��
void GPIO_Init_All(void)
{
    // LED��ʼ��
    RCC->APB2ENR |= 1 << 4; // ��PCʱ��
    GPIOC->CRH &= 0xFF0FFFFF; // ��λPC13��ģʽ
    GPIOC->CRH |= 0x00700000; // ����PC13Ϊͨ������50MHZ���
    PCout(13) = 1; // �ر�LED

    // ��������ʼ��
    RCC->APB2ENR |= 1 << 3; // ��PBʱ��
    GPIOB->CRL &= 0xF0FFFFFF; // ��λPB6��ģʽ
    GPIOB->CRL |= 0x031111; // ����PB6Ϊͨ������50MHZ���
    PBout(6) = 1; // �رշ�����

    // ������ʼ��
    RCC->APB2ENR |= 1 << 3; // ��PBʱ��
    GPIOB->CRH &= 0xF000FFFF; // ��λPB12 13 14��ģʽ
    GPIOB->CRH |= 0x08880000; // ����PB12 13 14Ϊͨ������50MHZ���
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

    u16 t_data = 0; // �¶�
    u16 h_data = 0, s_data = 98; // Ѫ��
    u16 t_max = 38; // �¶����ֵ
    u16 h_max = 140; // �������ֵ
    u16 s_min = 50; // Ѫ�����ֵ
    u8 new_set = 0;
    u8 time = 0;

    short pitch, roll, yaw; // ŷ����

    // ϵͳʱ������
    Stm32_Clock_Init(9);
    // IO�ض���
    RCC->APB2ENR |= 1 << 0; // �򿪸��ù���ʱ��
    AFIO->MAPR |= 1 << 25;
    // ��ʱ������ʼ��
    delay_init();
    uart_init(115200);
    IIC_Init();
    GPIO_Init_All(); // ��ʼ������GPIO
    // ��ʾ����ʼ��
    delay_ms(500);
    LCD1602_Init();
    // DS18B20��ʼ��
    DS18B20_Init();

    while (MPU_Init())
    {
        LED1 = !LED1;
        delay_ms(200);
    }

    // ��ʾ����
    LCD_Show(0, 0, "T:00 H:000 S:000");
    LCD_Show(0, 1, "  00   000   000");
    // ��ʾ��Сֵ
    LCD_ShowNmber(2, 1, t_max, 2);
    LCD_ShowNmber(7, 1, h_max, 3);
    LCD_ShowNmber(13, 1, s_min, 3);

    // ��ʼ��max30102
    MAX30102_Debug_Init();
    n_ir_buffer_length = 500; // buffer length of 100 stores 5 seconds of samples running at 100sps

    // read the first 500 samples, and determine the signal range
    un_prev_data = aun_red_buffer[i];
    maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);

    LED1 = 1; // �ر�ָʾ�� ��ʼ������
    // ˢ�������¶�
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
                // ���ݴ����߼�
            }
            // take 100 sets of samples before calculating the heart rate.
            for (i = 400; i < 500; i++)
            {
                un_prev_data = aun_red_buffer[i - 1];
                while (max30102_INTPin == 1); // �ȴ�MAX30102�ж���������
                maxim_max30102_read_fifo((aun_red_buffer + i), (aun_ir_buffer + i));

                // ����LED����
                f_temp = aun_red_buffer[i] - un_prev_data;
                n_brightness -= (int)f_temp;
                if (n_brightness < 0)
                    n_brightness = 0;
            }

            // ���Ͷ��ſ���
            if (time == 0)
            {
                if (t_data > t_max) // ���¹��߼��
                {
                    BEEP = 0; // �򿪷�����
                    delay_ms(1000);
                    BEEP = 1; // �رշ�����
                    printf("!!!\r\nHigh temperature \r\n temperature:%d!!", t_data);
                    SendTextEnd();
                    time = 20; // 20���ڲ��ٷ��Ͷ���
                }
                else if (h_data > h_max) // ���ʹ���
                {
                    BEEP = 0; // �򿪷�����
                    delay_ms(1000);
                    BEEP = 1; // �رշ�����
                    printf("!!!\r\nHigh heart rate \r\n heart rate:%d!!", h_data);
                    SendTextEnd();
                    time = 20; // 20���ڲ��ٷ��Ͷ���
                }
                else if (s_data < s_min) // Ѫ������
                {
                    BEEP = 0; // �򿪷�����
                    delay_ms(1000);
                    BEEP = 1; // �رշ�����
                    printf("!!!\r\nLow blood oxygen \r\n blood oxygen:%d!!", s_data);
                    SendTextEnd();
                    time = 20; // 20���ڲ��ٷ��Ͷ���
                }
            }
            if (time != 0)
                time--; // ʱ�����

            // ���������Ѫ��ˢ��
            if (n_heart_rate >= 700 && n_heart_rate <= 1040)
                h_data = n_heart_rate;
            if (n_sp02 >= 70 && n_sp02 <= 909)
                s_data = n_sp02;

            // �ɼ���ȡ�¶�
            t_data = DS18B20_Get_Temp() / 100;

            if (MPU_Get_Accelerometer(&pitch, &roll, &yaw) == 0)
            {
                LCD_ShowNmber(0, 1, pitch / 1000, 1);
                if ((pitch / 1008) > 50)
                {
                    LED1 = !LED1;
                    BEEP = 0; // �򿪷�����
                    delay_ms(1000);
                    BEEP = 1; // �رշ�����
                    SendTextMessage();
                }
            }
        }

        // ����1���� ����
        if (KEY1 == 0)
        {
            delay_ms(5);
            if (KEY1 == 0)
            {
                switch (new_set)
                {
                    // ����1��Ӧ�Ĳ���
                }
                while (KEY1 == 0);
            }
        }
        // ����2���� ����
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

        // ����3���� �л����ò���
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