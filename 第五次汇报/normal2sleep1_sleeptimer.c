void Normal2Sleep1_sleeptimer(int i)
{
	U32 j;
	PMU_MaskWakeUp = 0x02;  //屏蔽GPIO唤醒；
	PMU_CRYCFG = 0x1f;      //
	PMU_RCCFG = 0x3f;       //enable rc osc,if you want the chip to work into Stop mode ,you must open the RC clock source 
	PMU_SleepTimerSetValue = 0xff;    //configure sleeptimer value
	if(i)                          // i=1 enable pll , elae disable pll
	{
	    PMU_BPLLCFG2 = 0x1c022; // 50
	    //PMU_XPLLCFG2 = 0x24018; // 32
	    PMU_PMCR = 0x3; // 5 times clk
        delay(2);
	    PMU_PMCR = 0x6; // 5 times clk
        for(j=1;j<1000;j++);
	}
	else
	{
	    PMU_PMCR = 0x00; // disable pll
        for(j=1;j<200;j++);
	}
	PMU_SleepTimerCfg = 0x05;    //enable sleeptimer osc
	PMU_PWROFFCFG = 0xff;       //set the waiting time of power off
	PMU_PWRONCFG = 0xff;        //set power on waiting time

	GPIO_PORTA_SEL = 0xff;
	GPIO_PORTA_PULLUP = 0xff;
	GPIO_PORTA_DIR = 0xff;
	GPIO_PORTB_SEL = 0xfff;
	GPIO_PORTB_PULLUP = 0xfff;
	GPIO_PORTB_DIR = 0xfff;

    PMU_PMDR = 0x0a;   //into sleep mode
// 	wfi();
 	delay(10);

};


