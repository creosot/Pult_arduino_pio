#include <Arduino.h>
#include <string.h>
#include "setup.h"

uint8_t pre_cmd[] = { 0x23, 0x09, 0x23, 0x0D, 0x0A };
uint8_t menu_cmd[] = { 0x21, 0x09, 0x3F, 0x09, 0x4E, 0x0D, 0x0A };
uint8_t powr_on_after_install_door_open_cmd[] = { 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A, 0x57, 0x0D, 0x0A };
uint8_t powr_on_after_install_door_close_cmd[] = { 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A, 0x55, 0x0D, 0x0A };
uint8_t door_open_cmd[] = { 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A, 0x57, 0x0D, 0x0A };
uint8_t Menu_plus_to_UpmotorMenu_cmd[] = { 0x3F, 0x09, 0x44, 0x09, 0x52, 0x0D, 0x0A };
uint8_t UpmotorMenu_enter_to_Upmotor_cmd[] = { 0x3F, 0x0D, 0x0A, 0x44, 0x0D, 0x0A };
uint8_t HeaderUpmotor[] = { 0x44, 0x0D, 0x0A };
uint8_t Upmotor_enter_to_UpmotorMenu_cmd[] = { 0x3F, 0x0D, 0x0A, 0x44, 0x0D, 0x0A, 0x52, 0x0D, 0x0A };
uint8_t HeaderBottommotor[] = { 0x45, 0x0D, 0x0A };
uint8_t Bottommotor_enter_to_BottommotorMenu_cmd[] = { 0x3F, 0x0D, 0x0A, 0x45, 0x0D, 0x0A, 0x52, 0x0D, 0x0A };
uint8_t BottommotorMenu_enter_to_Bottommotor_cmd[] = { 0x3F, 0x0D, 0x0A, 0x45, 0x0D, 0x0A };
uint8_t UpmotorMenu_plus_to_BottommotorMenu_cmd[] = { 0x3F, 0x09, 0x45, 0x09, 0x52, 0x0D, 0x0A };
uint8_t BottommotorMenu_plus_to_BothmotorsMenu_cmd[] = { 0x3F, 0x09, 0x4B, 0x09, 0x52, 0x0D, 0x0A };
uint8_t BothmotorsMenu_enter_to_Bothmotors_cmd[] = { 0x3F, 0x0D, 0x0A, 0x4B, 0x0D, 0x0A };
uint8_t HeaderBothmotors[] = { 0x4B, 0x0D, 0x0A };
uint8_t Bothmotors_enter_to_BothmotorsMenu_cmd[] = { 0x3F, 0x0D, 0x0A, 0x4B, 0x0D, 0x0A, 0x52, 0x0D, 0x0A };
uint8_t Back_to_MainMenu_cmd[] = { 0x23, 0x09, 0x23, 0x0D, 0x0A, 0x21, 0x09, 0x3F, 0x09, 0x4E, 0x0D, 0x0A };
uint8_t BothmotorsMenu_plus_to_ScrethingMenu_cmd[] = { 0x3F, 0x09, 0x53, 0x09, 0x52, 0x0D, 0x0A };
uint8_t ScrethingMenu_plus_to_InstallMenu_cmd[] = { 0x3F, 0x09, 0x48, 0x09, 0x52, 0x0D, 0x0A };
uint8_t InstallMenu_plus_to_StoptimeMenu_cmd[] = { 0x3F, 0x09, 0x52, 0x09, 0x5A, 0x0D, 0x0A };
uint8_t Scrething_enter_cmd[] = { 0x3F, 0x09, 0x53, 0x09, 0x52, 0x0D, 0x0A };
uint8_t InstallMenu_enter_to_DoorOpen_SensorOff_cmd[] = { 0x3F, 0x09, 0x48, 0x0D, 0x0A, 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A, 0x57, 0x0D, 0x0A };
uint8_t DoorOpen_enter_3sec_to_MainMenu_cmd[] = { 0x23, 0x09, 0x23, 0x0D, 0x0A, 0x21, 0x09, 0x3F, 0x09, 0x4E, 0x0D, 0x0A };
uint8_t DoorOpen_enter_s_on_to_scrolling_cmd[] = { 0x3F, 0x09, 0x48, 0x0D, 0x0A };
uint8_t InstallMenu_enter_to_Stopped_SensorOn_cmd[] = { 0x3F, 0x09, 0x48, 0x0D, 0x0A, 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A, 0x55, 0x0D, 0x0A };
uint8_t InstallMode[] = { 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A };
uint8_t InstallMode_DoorClose[] = { 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A, 0x55, 0x0D, 0x0A };
uint8_t DoorClose[] = { 0x55, 0x0D, 0x0A };
uint8_t DoorOpen[] = { 0x57, 0x0D, 0x0A };
uint8_t HeaderInstallMenu[] = { 0x3F, 0x09, 0x48, 0x0D, 0x0A };
uint8_t InstallMenu_enter_to_Install[] = { 0x3F, 0x09, 0x48, 0x0D, 0x0A, 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A };
uint8_t Enter_Return[] = { 0x21, 0x09, 0x3F, 0x09, 0x4C, 0x0D, 0x0A };
uint8_t HeaderMotors[] = { 0x3F, 0x0D, 0x0A };

uint8_t buttonMask[BUTTON_COUNT] = { GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3 };
uint8_t buttonOnLevel[BUTTON_COUNT] = { GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3 };
volatile uint8_t buttonCurrentState[BUTTON_COUNT] = { 0, 0, 0, 0 };
volatile uint32_t lastDebounceTime[BUTTON_COUNT] = { 0, 0, 0, 0 };
volatile uint8_t buttonStateOFF[BUTTON_COUNT] = { 0, 0, 0, 0 };
volatile uint8_t buttonStateON[BUTTON_COUNT] = { 0, 0, 0, 0 };
volatile uint8_t buttonStateChange[BUTTON_COUNT] = { 0 };
volatile uint8_t button_plus = 0;
volatile uint8_t button_minus = 0;
volatile uint8_t button_enter = 0;
volatile uint8_t button_enter_3s = 0;
volatile uint8_t button_mode_enter_reset_3s = 0;
volatile uint8_t button_mode = 0;
volatile uint8_t button_mode_fall = 0;
volatile uint8_t button_mode_5s = 0;

int incomingByte = 0;
uint8_t buf[SIZE_BUFFER];
uint8_t buf_index = 0;
bool wait_connect_pult = 0;
uint8_t power_on = 0;
uint8_t menu = 0;
uint8_t menue = 0;
uint8_t podmenu_motors = 0;
uint8_t scretching_menu = 0;
uint8_t install_door_open = 0;
uint8_t install_door_close = 0;
uint8_t podmenu_install = 0;
uint8_t door_open = 0;

void setup()  {
	CLK_Config();
	IWDG_Config();
  	GPIO_Config();
	IWDG_ReloadCounter();  
	EEPROM_Config();
	IWDG_ReloadCounter();
  	//UART2_Init();
  	Serial_begin(9600);
  	wait_connect_pult = true;
  	FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
} 

void loop()  
{
	uint32_t time_delay;
	uint32_t time_loop;
    uint32_t time_loop_podmenu;
	RESET_TIME_PODMENU_30m;
	time_delay = millis() + 2000;
	while (time_delay > millis())
	{
		scan_buttons();
		IWDG_ReloadCounter();
		if (button_mode)
		{
			time_delay = millis() + 2000;
		}
	}
	button_mode_fall = 0;
	Control ctrl = {MODE_NONE, MENU_MENUE, false, false, false, false};
	while (wait_connect_pult)
	{
		IWDG_ReloadCounter();
		scan_buttons();
		if (scan_change_mode(&ctrl))
		{
			flash_led(ctrl.required_mode);
			wait_connect_pult = false;
			break;
		}
		else
		{
			LEDS_OFF;
		}
	}
	START_ON_VBUT;
	time_delay = millis() + 372;
	while (time_delay > millis())
	{
		IWDG_ReloadCounter();
		flash_led(ctrl.required_mode);
	}
  	START_OFF_VBUT;
	time_delay = millis() + 120;
	while (time_delay > millis())
	{
		IWDG_ReloadCounter();
		flash_led(ctrl.required_mode);
	}
  	START_ON_VBUT;
	time_delay = millis() + 199;
	while (time_delay > millis())
	{
		IWDG_ReloadCounter();
		flash_led(ctrl.required_mode);
	}
  	START_OFF_VBUT;
	time_delay = millis() + 2128;
	while (time_delay > millis())
	{
		IWDG_ReloadCounter();
		flash_led(ctrl.required_mode);
	}
	Serial_flush();
	while (Serial_available() > 0) 
	{
		Serial_read();
	}
	Serial_write(0x23);
	Serial_write(0x0D);
	Serial_write(0x0A); 
	RESET_TIME_LOOP_15s;
	Serial_flush();
	power_on = 1;

	while (true)
	{
		while (power_on)
		{
			IWDG_ReloadCounter();
			flash_led(ctrl.required_mode);			
			if (Serial_available() > 0) 
			{
				incomingByte = Serial_read(); // get the character
				buf[buf_index++] = (uint8_t)incomingByte;
				if (incomingByte == '\n') 
				{
					if (buf_cmp(buf, buf_index, pre_cmd, sizeof pre_cmd))
					{
						buf_index = 0;
						Serial_flush();
						time_delay = millis() + 500;
						while (time_delay > millis())
						{
							IWDG_ReloadCounter();
							flash_led(ctrl.required_mode);
						}
						Serial_write(0x23);
						Serial_write(0x0D);
						Serial_write(0x0A);
						RESET_TIME_LOOP_15s;
					}
					else if (buf_cmp(buf, buf_index, menu_cmd, 7))
					{
						buf_index = 0; // Serial.println(F("MENUE PLUS NEXT"));
						Serial_flush();
						ENTER_OFF_VBUT;
						ctrl.current_menu = MENU_MENUE;
						power_on = 0;
						menu = 1;
						RESET_TIME_LOOP_15s;
						break;
					}
					else if (buf_cmp(buf, buf_index, InstallMode, 7))
					{
						buf_index = 0; // Serial.println(F("INSTALL MODE"));
						Serial_flush();
						ENTER_OFF_VBUT;
						ctrl.current_menu = MENU_INSTALL;
						//LED_UP_ON;
						//LED_DOWN_OFF;
						LEDS_OFF;
						power_on = 0;
						podmenu_install = 1;
						break;
					}
					else
					{
						buf_index = 0;
					}
				}
				if (buf_index >= SIZE_BUFFER)
				{
					iwdg_reset(); // Serial.println(F("Buffer full"));
				}
			}
			if (millis() > time_loop)
			{ 
				iwdg_reset(); // Serial.println(F("Time read end. Restart"));
			}
		}
		while (menu)
		{
			IWDG_ReloadCounter();
			flash_led(ctrl.required_mode);
			if (millis() > time_loop)
		 	{ 
				iwdg_reset(); // Serial.println(F("Time read end. Restart"));
	 		}
			if (Serial_available() > 0)
			{
				incomingByte = Serial_read(); // get the character
				buf[buf_index++] = (uint8_t)incomingByte;
				if (buf_index >= SIZE_BUFFER)
				{ 
					iwdg_reset(); //Serial.println(F("Buffer full"));
				}
				if (incomingByte == '\n') 
				{
					if (buf_cmp(buf, buf_index, menu_cmd, 7))
					{
						buf_index = 0; //Serial.println(F("MENUE PLUS NEXT"));
						Serial_flush();
						ctrl.current_menu = MENU_MENUE;
						RESET_TIME_LOOP_15s;
					}
					//UP
					else if (buf_cmp(buf, buf_index, Menu_plus_to_UpmotorMenu_cmd, 7))
					{
						buf_index = 0; //Serial.println(F("UPMOTOR WITH ENTER RETURN or PLUS NEXT"));
						Serial_flush();
						ctrl.current_menu = MENU_UP;
						RESET_TIME_LOOP_15s;
					}
					else if (ctrl.enter_podmenu && buf_cmp(buf, buf_index, UpmotorMenu_enter_to_Upmotor_cmd, 6))
					{
						buf_index = 0; //Serial.println(F("UPMOTOR"));
						Serial_flush();
						ENTER_OFF_VBUT;
                        RESET_TIME_PODMENU_30m;
						podmenu_motors = 1;
						menu = 0;
						break;
					}
					else if (ctrl.exit_podmenu && buf_cmp(buf, buf_index, Upmotor_enter_to_UpmotorMenu_cmd, 9))
					{
						buf_index = 0; //Serial.println(F("UPMOTOR WITH ENTER RETURN or PLUS NEXT"));
						Serial_flush();
						ENTER_OFF_VBUT;
						ctrl.current_menu = MENU_UP;
						ctrl.exit_podmenu = false;
						RESET_TIME_LOOP_15s;
					}
					//DOWN
					else if (buf_cmp(buf, buf_index, UpmotorMenu_plus_to_BottommotorMenu_cmd, 7))
					{
						buf_index = 0; //Serial.println(F("DOWNMOTOR WITH ENTER RETURN or PLUS NEXT"));
						Serial_flush();
						ctrl.current_menu = MENU_DOWN;
						RESET_TIME_LOOP_15s;
					}
					else if (ctrl.enter_podmenu && buf_cmp(buf, buf_index, BottommotorMenu_enter_to_Bottommotor_cmd, 6))
					{
						buf_index = 0; //Serial.println(F("DOWNMOTOR"));
						Serial_flush();
						ENTER_OFF_VBUT;
                        RESET_TIME_PODMENU_30m;
						podmenu_motors = 1;
						menu = 0;
						break;
					}
					else if (ctrl.exit_podmenu && buf_cmp(buf, buf_index, Bottommotor_enter_to_BottommotorMenu_cmd, 9))
					{
						buf_index = 0; //Serial.println(F("DOWNMOTOR WITH ENTER RETURN or PLUS NEXT"));
						Serial_flush();
						ENTER_OFF_VBUT;
						ctrl.current_menu = MENU_DOWN;
						ctrl.exit_podmenu = false;
						RESET_TIME_LOOP_15s;
					}
					//UP+DOWN
					else if (buf_cmp(buf, buf_index, BottommotorMenu_plus_to_BothmotorsMenu_cmd, 7))
					{
						buf_index = 0; //Serial.println(F("BOTHMOTOR WITH ENTER RETURN or PLUS NEXT"));
						Serial_flush();
						ctrl.current_menu = MENU_BOTH;
						RESET_TIME_LOOP_15s;
					}
					else if (ctrl.enter_podmenu && buf_cmp(buf, buf_index, BothmotorsMenu_enter_to_Bothmotors_cmd, 6))
					{
						buf_index = 0; //Serial.println(F("BOTHMOTOR"));
						Serial_flush();
						ENTER_OFF_VBUT;
                        RESET_TIME_PODMENU_30m;
						podmenu_motors = 1;
						menu = 0;
						break;
					}
					else if (ctrl.exit_podmenu && buf_cmp(buf, buf_index, Bothmotors_enter_to_BothmotorsMenu_cmd, 9))
					{
						buf_index = 0; //Serial.println(F("BOTHMOTOR WITH ENTER RETURN or PLUS NEXT"));
						Serial_flush();
						ENTER_OFF_VBUT;
						ctrl.current_menu = MENU_BOTH;
					 	ctrl.exit_podmenu = false;
					 	RESET_TIME_LOOP_15s;
					}
					//INSTALL
					else if (buf_cmp(buf, buf_index, ScrethingMenu_plus_to_InstallMenu_cmd, 7))
					{
						buf_index = 0; //Serial.println(F("INSTALL WITH ENTER RETURN or PLUS NEXT"));
						Serial_flush();
						ctrl.current_menu = MENU_INSTALL;
						RESET_TIME_LOOP_15s;
					}
					else if (buf_cmp(buf, buf_index, InstallMenu_enter_to_Install, 12))
					{
						buf_index = 0; //Serial.println(F("INSTALL"));
						Serial_flush();
						ENTER_OFF_VBUT;
						LED_INSTALL_ON;
						// uint32_t seven_sec = millis() + 70000;
						// while (seven_sec > millis())
						// {
						// 	IWDG_ReloadCounter();
						// }
						while (true)
						{
							IWDG_ReloadCounter();
						}
						//LEDS_OFF;
						podmenu_install = 1;
						menu = 0;
						break;
					}
					//HEAD MOTORDS
					else if (buf_cmp(buf, buf_index, HeaderMotors, 3))
					{
						RESET_TIME_LOOP_15s;
					}
					//HEAD UP
					else if (buf_cmp(buf, buf_index, HeaderUpmotor, 3))
					{
						RESET_TIME_LOOP_15s;
					}
					//HEAD DOWN
					else if (buf_cmp(buf, buf_index, HeaderBottommotor, 3))
					{
						RESET_TIME_LOOP_15s;
					}
					//HEAD BOTH
					else if (buf_cmp(buf, buf_index, HeaderBothmotors, 3))
					{
						RESET_TIME_LOOP_15s;
					}
					//HEAD INSTALL
					else if (buf_cmp(buf, buf_index, HeaderInstallMenu, 5))
					{
						RESET_TIME_LOOP_15s;
					}
					else
					{
						buf_index = 0;
					}
				}
			}
			switch_menu_press_plus(&ctrl);
		}
		while (podmenu_motors)
		{
			IWDG_ReloadCounter();
		 	continous_flash_led(ctrl.required_mode);
		 	scan_buttons();
            if (emulate_plus_minus_press())
            {
                RESET_TIME_PODMENU_30m;
            }
            if (millis() > time_loop_podmenu)
		 	{ 
				iwdg_reset(); // Serial.println(F("Time read end. Restart"));
	 		}
            if (button_mode_enter_reset_3s)
            {
                while (true)
                {
                    flash_reset_plus_minus_led();
                }
            }
            if (scan_change_mode(&ctrl))
            {
                Serial_flush();
                OUT_PIN_OFF;
				ctrl.enter_podmenu = false;
                ctrl.exit_podmenu = true;
                podmenu_motors = 0;
                menu = 1;
				RESET_TIME_LOOP_15s;
                break;
            }
			if (button_enter_3s)
			{
				Serial_flush();
                OUT_PIN_OFF;
				//LED_UP_ON;
				//LED_DOWN_OFF;	
				LEDS_OFF;
				ctrl.required_mode = MODE_INSTALL;
				ctrl.reset_install = false;
				ctrl.start_install = true;
				ctrl.enter_podmenu = false;
                ctrl.exit_podmenu = true;
                podmenu_motors = 0;
                menu = 1;	
				RESET_TIME_LOOP_15s;
                break;
			}
		}
		while (podmenu_install)
		{
			IWDG_ReloadCounter();
			scan_buttons();
			if (button_mode_enter_reset_3s) //button_mode_5s)
			{
				Serial_flush();
				button_mode_enter_reset_3s = 0;
				ctrl.reset_install = true;
			}
			if (ctrl.reset_install)
			{
				flash_reset_install_led();
				start_emulate_press_enter_reset();
			}
			else
			{
				if (ctrl.start_install)
				{
					start_emulate_press_enter_install_mode();
				}
				LED_INSTALL_ON;
				//flash_install_led();
			}
			if (Serial_available() > 0) 
			{
				incomingByte = Serial_read(); // get the character
				buf[buf_index++] = (uint8_t)incomingByte;
				if (incomingByte == '\n') 
				{
					//RESET NSTALL
					if (buf_cmp(buf, buf_index, menu_cmd, 7))
					{
						buf_index = 0; // Serial.println(F("MENUE PLUS NEXT"));
						Serial_flush();
						ENTER_OFF_VBUT;
						while (true)
						{
							//reset
						}
					}
					else if (buf_cmp(buf, buf_index, InstallMode_DoorClose, 10))
					{
						buf_index = 0; 
						Serial_flush();
						ENTER_OFF_VBUT;
						while (true)
						{
							//reset
						}
					}
					// else if (buf_cmp(buf, buf_index, HeaderInstallMenu, 5))
					// {
					// 	buf_index = 0; 
					// 	Serial_flush();
					// 	ENTER_OFF_VBUT;
					// 	while (true)
					// 	{
					// 		//reset
					// 	}
					// }
					else if (buf_cmp(buf, buf_index, InstallMode, 7))
					{
	
					}
					else
					{
						buf_index = 0;
					}
				}
				if (buf_index >= SIZE_BUFFER)
				{
					iwdg_reset(); // Serial.println(F("Buffer full"));
				}
			}
		}
	}
}

void switch_menu_press_plus(Control* ctrl)
{
	if (ctrl->enter_podmenu || ctrl->exit_podmenu)
	{
        PLUS_OFF_VBUT;
		start_emulate_press_enter();
        return;
	}
	static uint32_t press_on = 0;
	static uint32_t loop_press = 0;
	if (ctrl->required_mode == ctrl->current_menu)
	{
		PLUS_OFF_VBUT;
		ctrl->enter_podmenu = true;
	}
	else
	{	
		if (millis() > loop_press)
		{
			PLUS_ON_VBUT; //digitalWrite(BUT_PLUS, HIGH);
			press_on = millis() + 300;
			loop_press = millis() + 550;
		}
		if (millis() > press_on)
		{
			PLUS_OFF_VBUT; //digitalWrite(BUT_PLUS, LOW);
		}
	}
}

bool scan_change_mode(Control* ctrl)
{
	if (button_mode_fall)
	{
		uint8_t mode = (uint8_t)ctrl->required_mode;
		uint32_t time_end = millis() + 3000;
		while (true)
		{
			IWDG_ReloadCounter();
			if (button_mode_fall)
			{
				time_end = millis() + 3000;
				button_mode_fall = 0;
				mode += 1;
				if (mode >= 4)
				{
					mode = 1;
				}
			}
			if (button_enter)
			{
				button_enter = 0;
				button_mode_fall = 0;
				if (mode == ctrl->required_mode)
				{
					return false;
				}
				ctrl->required_mode = mode;
				LEDS_OFF;
				flash_led(ctrl->required_mode);
				return true;
			}
			continous_flash_led(mode);
			scan_buttons();
			if (millis() > time_end || button_plus || button_minus)
			{
				continous_flash_led(ctrl->required_mode);
				button_mode_fall = 0;
				button_plus = 0;
				button_minus = 0;
				return false;
			}
		}
	}
	return false;
}

bool buf_cmp(uint8_t* buf, uint8_t buflen, uint8_t* target, uint8_t tlen)
{
    if (!tlen)
    {
        return false;
    }
    if (buflen < tlen)
    {
        return false;
    }
    uint8_t* tstart = target;
    uint8_t* bufstart = buf + (buflen - tlen);
    while (tlen--)
    {
        if (*bufstart++ != *tstart++)
        {
            return false;
        }
    }
    return true;
}

bool emulate_plus_minus_press()
{	
    bool ret = false;
	if (button_plus)
	{
        ret = true;
		GPIO_WriteLow(OUT_GPIO_PORT, OUT_PLUS_PIN); //digitalWrite(BUT_PLUS, HIGH);
	}
	else
	{
		GPIO_WriteHigh(OUT_GPIO_PORT, OUT_PLUS_PIN); //digitalWrite(BUT_PLUS, LOW);
	}
	if (button_minus)
	{
        ret = true;
		GPIO_WriteLow(OUT_GPIO_PORT, OUT_MINUS_PIN); //digitalWrite(BUT_MINUS, HIGH);
	}
	else
	{
		GPIO_WriteHigh(OUT_GPIO_PORT, OUT_MINUS_PIN); //digitalWrite(BUT_MINUS, LOW);
	}
    return ret;
}

void start_emulate_press_enter()
{
	static uint32_t press_on_enter = 0;
	static uint32_t loop_press_enter = 0;
	if (millis() > loop_press_enter)
	{
		ENTER_ON_VBUT; 
		press_on_enter = millis() + 300;
		loop_press_enter = millis() + 550;
	}
	if (millis() > press_on_enter)
	{
		ENTER_OFF_VBUT; //digitalWrite(BUT_PLUS, LOW);
	}
}

void start_emulate_press_enter_install_mode()
{
	static uint32_t press_off = 0;
	static uint32_t press_enter = 0;
	if (millis() > press_enter)
	{
		ENTER_ON_VBUT; 
		press_off = millis() + 300;
		press_enter = millis() + 5500;
	}
	if (millis() > press_off)
	{
		ENTER_OFF_VBUT; //digitalWrite(BUT_PLUS, LOW);
	}
}

void start_emulate_press_enter_reset()
{
	static uint32_t on_enter_reset = 0;
	static uint32_t enter_reset = 0;
	if (millis() > enter_reset)
	{
		ENTER_ON_VBUT; 
		on_enter_reset = millis() + 3000;
		enter_reset = millis() + 5500;
	}
	if (millis() > on_enter_reset)
	{
		ENTER_OFF_VBUT; //digitalWrite(BUT_PLUS, LOW);
	}
}

void continous_flash_led(Flash_mode flash)
{
	switch (flash)
	{
	case FLASH_UP:
		LED_UP_ON;
		LED_DOWN_OFF;
		return;
	case FLASH_DOWN:
		LED_DOWN_ON;
		LED_UP_OFF;
		return;
	case FLASH_PLUS_MINUS:
		LED_PLUS_MINUS_ON;
		return;
	case FLASH_NONE:
		LEDS_OFF;
		return;
	default:
		return;
	}
}

void check_reset_flag()
{
	if (RST_GetFlagStatus (RST_FLAG_IWDGF))
  	{
		uint32_t t = millis() + 1000;
		uint32_t time_on = 0;
		while (millis() < t)
		{
			IWDG_ReloadCounter();
			if (millis() > time_on)
			{
				GPIO_WriteReverse(LED_GPIO_PORT, LED_GPIO_PINS);
				time_on = millis() + 60;
			}
		}
		RST_ClearFlag (RST_FLAG_IWDGF);
  	}
}

void iwdg_reset()
{
	uint32_t time_on = 0;
	GPIO_WriteHigh(LED_GPIO_PORT, LED_GPIO_PINS);
	while (true)
	{
		if (millis() > time_on)
		{
			GPIO_WriteReverse(LED_GPIO_PORT, LED_GPIO_PINS);
			time_on = millis() + 60;
		}
	}
}

void flash_reset_plus_minus_led()
{
	static uint32_t time_on = 0;
	if (millis() > time_on)
	{
		GPIO_WriteReverse(LED_GPIO_PORT, LED_DOWN_PIN);
		GPIO_WriteReverse(LED_GPIO_PORT, LED_UP_PIN);
		time_on = millis() + 100;
	}
}

void flash_reset_install_led()
{
	static uint32_t time_on = 0;
	if (millis() > time_on)
	{
		GPIO_WriteReverse(LED_GPIO_PORT, LED_INSTALL_PIN);
		//GPIO_WriteReverse(LED_GPIO_PORT, LED_UP_PIN);
		time_on = millis() + 100;
	}
}

void flash_install_led()
{
	static uint32_t time_off = 0;
	static uint32_t start_loop = 0;
	if (millis() > start_loop)
	{
		GPIO_WriteLow(LED_GPIO_PORT, LED_INSTALL_PIN);
		start_loop = millis() + 1200;
		time_off = millis() + 50;
	}
	if (millis() > time_off)
	{
		GPIO_WriteHigh(LED_GPIO_PORT, LED_INSTALL_PIN);
	}
}

void flash_led(Flash_mode flash)
{
	static uint32_t time_on = 0;
	if (millis() > time_on)
	{
		switch (flash)
		{
		case FLASH_UP:
			GPIO_WriteReverse(LED_GPIO_PORT, LED_UP_PIN);
			GPIO_WriteHigh(LED_GPIO_PORT, LED_DOWN_PIN);
			break;
		case FLASH_DOWN:
			GPIO_WriteReverse(LED_GPIO_PORT, LED_DOWN_PIN);
			GPIO_WriteHigh(LED_GPIO_PORT, LED_UP_PIN);
			break;
		case FLASH_PLUS_MINUS:
			GPIO_WriteReverse(LED_GPIO_PORT, LED_PLUS_MINUS_GPIO_PINS);
			break;
		case FLASH_NONE:
			GPIO_WriteHigh(LED_GPIO_PORT, LED_GPIO_PINS);
			break;
		case FLASH_INSTALL:
			GPIO_WriteReverse(LED_GPIO_PORT, LED_INSTALL_PIN);
			break;
		default:
			break;
		}
		time_on = millis() + 250;
	}
}

void scan_buttons()
{
    static unsigned long mode_enter_delay_3sec = 0xFFFF;
	static unsigned long enter_delay_3sec = 0xFFFF;
	//static unsigned long mode_delay_3sec = 0xFFFF;
	for (uint8_t i = 0; i < BUTTON_COUNT; i++)
	{
		getButtonState(i); 
	}
	//plus
	if (buttonStateChange[BUT_PLUS])
	{
		buttonStateChange[BUT_PLUS] = 0;
		if (buttonStateON[BUT_PLUS])
		{
			// Serial.println(F("PLUS ON"));
			button_plus = 1;
		}
		if (buttonStateOFF[BUT_PLUS])
		{
			// Serial.println(F("PLUS OFF"));
			button_plus = 0;
		}
	}
	//minus
	if (buttonStateChange[BUT_MINUS])
	{
		buttonStateChange[BUT_MINUS] = 0;
		if (buttonStateON[BUT_MINUS])
		{
			// Serial.println(F("MINUS ON"));
			button_minus = 1;
		}
		if (buttonStateOFF[BUT_MINUS])
		{
			// Serial.println(F("MINUS OFF"));
			button_minus = 0;
		}
	}
  //mode
	if (buttonStateChange[BUT_MODE])
	{
		buttonStateChange[BUT_MODE] = 0;
		if (buttonStateON[BUT_MODE])
		{
			// Serial.println(F("MINUS ON"));
			button_mode = 1;
		}
		if (buttonStateOFF[BUT_MODE])
		{
			// Serial.println(F("MINUS OFF"));
			button_mode = 0;
			button_mode_fall = 1;
		}
	}
	//press mode 3sec
	// if (!button_mode || button_plus || button_minus || button_enter)
	// {
	// 	button_mode_5s = 0;
	// 	mode_delay_3sec = millis() + DELAY_PRESS;
	// }
	// if (button_mode)
	// {
	// 	if (millis() > mode_delay_3sec)
	// 	{
	// 		button_mode_5s = 1;
	// 	}
	// }
	//enter
	if (buttonStateChange[BUT_ENTER])
	{
		buttonStateChange[BUT_ENTER] = 0;
		if (buttonStateON[BUT_ENTER])
		{
			// Serial.println(F("ENTER ON"));
			button_enter = 1;
		}
		if (buttonStateOFF[BUT_ENTER])
		{
			// Serial.println(F("ENTER OFF"));
			button_enter = 0;
		}
	}
    //mode+enter
    if (button_enter && button_mode)
    {
        button_mode_enter_reset_3s = 1;
    }
    else
    {
        button_mode_enter_reset_3s = 0;
        mode_enter_delay_3sec = millis() + DELAY_PRESS;
    }
    
	//press enter 3sec
	if (!button_enter || button_plus || button_minus || button_mode)
	{
		button_enter_3s = 0;
		enter_delay_3sec = millis() + DELAY_PRESS;
	}
	if (button_enter)
	{
		if (millis() > enter_delay_3sec)
		{
			button_enter_3s = 1;
		}
	}
}

void getButtonState(uint8_t but) {
	uint8_t state = GPIO_ReadInputData(GPIOB) & buttonMask[but];
	if (state ^ buttonCurrentState[but]) {
		//0^1 button press state=0;  1^0 button release state=1
		lastDebounceTime[but] = millis();
		buttonCurrentState[but] = state;
		return;
	}
	if ((millis() - lastDebounceTime[but] > DEBOUNCE_ms)) {
		if (buttonCurrentState[but] == buttonOnLevel[but]) {
			//1-button press or button release
			if (!buttonStateON[but]) 
			{
				buttonStateChange[but] = 1;
			}
			buttonStateON[but] = 1;
			buttonStateOFF[but] = 0;
		}
		else {
			if (buttonStateON[but])
			{
				buttonStateChange[but] = 1;
			}
			buttonStateON[but] = 0;
			buttonStateOFF[but] = 1;
		}
	}
}

static void IWDG_Config()
{
	IWDG_Enable(); //IWDG->KR =0xCC; // старт IWDG
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_256); //1.02s
	IWDG_SetReload(0xFF); //1.02s
	//IWDG_WriteAccessCmd(IWDG_WriteAccess_Disable);
	IWDG_ReloadCounter();
}

static void GPIO_Config()
{
  	// pinMode(led1,OUTPUT);
  	// pinMode(led2,OUTPUT);
  	//button
  	GPIO_DeInit(GPIOB);
  	GPIO_Init(BUTTON_GPIO_PORT, (GPIO_Pin_TypeDef)BUTTON_GPIO_PINS, GPIO_MODE_IN_FL_NO_IT);
  	//led
  	GPIO_DeInit(GPIOC);
  	GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
  	GPIO_WriteHigh(LED_GPIO_PORT, LED_GPIO_PINS);
  	//gerkon in
  	//GPIO_Init(GERKON_GPIO_PORT, (GPIO_Pin_TypeDef)GERKON_PIN, GPIO_MODE_IN_FL_NO_IT);
  	//out to block stiboard
  	GPIO_DeInit(GPIOD);
  	GPIO_Init(OUT_GPIO_PORT, (GPIO_Pin_TypeDef)OUT_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
  	GPIO_WriteHigh(OUT_GPIO_PORT, OUT_GPIO_PINS);
}

static void CLK_Config(void)
{
	CLK_LSICmd(ENABLE);
  	CLK_HSECmd(ENABLE);
  	while(CLK_GetFlagStatus(CLK_FLAG_HSERDY) == FALSE);
  	CLK_HSICmd(DISABLE);
  	CLK_ClockSwitchCmd(ENABLE);
  	CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);                             
  	CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}

static void EEPROM_Config()
{
	FLASH_DeInit();
	FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
	FLASH_Unlock(FLASH_MEMTYPE_DATA);
	while (FLASH_GetFlagStatus(FLASH_FLAG_DUL) == RESET); // Wait for unlock success
}

// void EEPROM_Write_byte(uint32_t Address, uint8_t Data)
// {
// 	assert_param(IS_FLASH_DATA_ADDRESS_OK(Address));  
// 	 //Unlock
// 	FLASH_Unlock(FLASH_MEMTYPE_DATA);
// 	FLASH_ProgramByte(Address, Data);
// 	// for( ; Len > 0; Len--)
// 	// {
// 	// 		 Refresh_WWDG_Window(); //feed the dog
// 	// 		*p++ = *pData++;
// 	// 		 / / Wait for the write to complete
// 	// 		while(!(FLASH_GetFlagStatus(FLASH_FLAG_EOP))); 
// 	// } 
// 	 //Lock
// 	FLASH_Lock(FLASH_MEMTYPE_DATA);
// }


// void Derive_EPWrite(u16 Adr, u8 *pData, u16 Len)
// {
// 	u8 *p;
// 	 //p pointer points to the corresponding unit of the EEPROM
// 	p = (u8*)0x4000 + Adr;   
// 	 //Unlock
// 	FLASH_Unlock(FLASH_MEMTYPE_DATA);
// 	 / / Write data
// 	for( ; Len > 0; Len--)
// 	{
// 			 Refresh_WWDG_Window(); //feed the dog
// 			*p++ = *pData++;
// 			 / / Wait for the write to complete
// 			while(!(FLASH_GetFlagStatus(FLASH_FLAG_EOP))); 
// 	} 
// 	 //Lock
// 	FLASH_Lock(FLASH_MEMTYPE_DATA);
// }
 
// /****************************************************************************************
// *  Function: Derive_EPRead                                                                         
//  * Object: Read EEPROM
//  * Input: Head address (0~2048) Data storage pointer Data length
//  * Output: None                                         
//  * Remarks: 2K EEPROM
// ****************************************************************************************/
// void Derive_EPRead(u16 Adr, u8 *pData, u16 Len)
// {
// 	u8 *p;
// 	 //p pointer points to the corresponding unit of the EEPROM
// 	p = (u8*)0x4000 + Adr; 
// 	 //Unlock
// 	FLASH_Unlock(FLASH_MEMTYPE_DATA);
// 	 / / Read data
// 	for( ; Len > 0; Len--)
// 	{
// 		*pData++ = *p++;
// 		 Refresh_WWDG_Window(); //feed the dog
// 	}
// 	 //Lock EEPROM
// 	FLASH_Lock(FLASH_MEMTYPE_DATA);