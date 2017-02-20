

int control_audio_param()
{
	int ret = -1;
	
	Aud_attr Aud_param;

	/* 获取声音记录参数 */
	app_param_GetData(_AUD_ATTR_, sizeof(Aud_param), (void *) &Aud_param);

	printf("\nAud_param.au_control = %d\t\tAud_param.au_record = %d\n\n",Aud_param.au_control, Aud_param.au_record);


}
