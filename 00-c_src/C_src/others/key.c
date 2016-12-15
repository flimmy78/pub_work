#define REC_KEY_DOWN		0x01
#define AUDIO_KEY_DOWN		0x02
#define LOCK_KEY_DOWN		0x04
#define CAPTURE_KEY_DOWN	0x08

int KeyValueRead(void)
{
	int pmu_gpio2;
	signed char Key_value = 0;
	Read_inf readgpio;

	if(g_gpio_fd < 0)
	{
		return 0;
	}

	pmu_gpio2 = 2;
	if(ioctl(g_gpio_fd,READ_PMU_KEY,&pmu_gpio2) == -1)
}
