// ENG MOSTAFA
// startup.c
void Reset_Handler ();
extern int main ();
void Default_Handler()
{
	Reset_Handler () ;
}
void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));

static unsigned long _stack_top[256];

void (*const g_p_fn_vectors[])() __attribute__((section(".vectors")))=
{
	(void (*)()) (&_stack_top[0]+sizeof(_stack_top)),
	 &Reset_Handler,
	 &NMI_Handler,
	 &H_Fault_Handler
};

extern unsigned int _END_text ;
extern unsigned int _Start_data;
extern unsigned int _END_data;
extern unsigned int _Start_bss;
extern unsigned int _END_bss;


void Reset_Handler()
{
	unsigned int data_size= (unsigned char*)& _END_data - (unsigned char*)&_Start_data;
    unsigned char* P_scr = (unsigned char*)&_END_text;
    unsigned char* P_dst = (unsigned char*)&_Start_data;	
	for(int i=0;i<data_size;i++ )
	{
	   *((unsigned char*)P_dst++)=*((unsigned char*)P_scr++);	
	}	
	unsigned int bss_size= (unsigned char*)&_END_bss - (unsigned char*)&_Start_bss;
	P_dst=(unsigned char*)&_Start_bss;
	for(int j=0;j<bss_size;j++ )
	{
	   *((unsigned char*)P_dst++) = (unsigned char)0;	
	}	
	
	main();
}