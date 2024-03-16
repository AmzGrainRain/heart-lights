#include "UART.h"

void UART_init()
{
    EA  = 1; // �����ж�
    ES  = 1; // �������ж�
    ET1 = 0; // ��ֹ��ʱ��1�ж�

    TMOD &= 0x0F; // �����ʱ��1ģʽλ
    TMOD |= 0x20; // �趨��ʱ��1Ϊ8λ�Զ���װ��ʽ

    PCON &= 0x7F; // �����ʲ�����
    SCON = 0x40;  // 8λ����,�ɱ䲨����

    TL1 = 0xFD; // �趨��ʱ��ֵ
    TH1 = 0xFD; // �趨��ʱ����װֵ
    TR1 = 1;    // ������ʱ��1

    UART_send_string("Init UART protocol done.\n");
}

void UART_send_char(unsigned char com_data)
{
    SBUF = com_data;
    while (TI == 0);
    TI = 0;
}

void UART_send_string(char* str)
{
    char* p = str;
    while (*p != '\0')
    {
        UART_send_char(*p);
        ++p;
    }
}
