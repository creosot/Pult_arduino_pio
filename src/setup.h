
#define BUTTON_GPIO_PORT  (GPIOB)
#define BUTTON_GPIO_PINS  (GPIO_PIN_3 | GPIO_PIN_2 | GPIO_PIN_1 | GPIO_PIN_0)
#define LED_GPIO_PORT  (GPIOC)
#define LED_GPIO_PINS  (GPIO_PIN_2 | GPIO_PIN_1)

#define OUT_GPIO_PORT  (GPIOD)
#define OUT_GPIO_PINS  (GPIO_PIN_7 | GPIO_PIN_4 | GPIO_PIN_3 | GPIO_PIN_2 | GPIO_PIN_0)
#define OUT_START_PIN (GPIO_PIN_0)
#define OUT_NUSE_PIN (GPIO_PIN_2)
#define OUT_PLUS_PIN (GPIO_PIN_3)
#define OUT_MINUS_PIN (GPIO_PIN_4)
#define OUT_ENTER_PIN (GPIO_PIN_7)

#define BUTTON_COUNT	4
#define DEBOUNCE_ms 50
#define GERKON_GPIO_PORT (GPIOC)
#define GERKON_PIN (GPIO_PIN_4)
#define LED_UP_PIN (GPIO_PIN_1)
#define LED_DOWN_PIN (GPIO_PIN_2)
#define BUT_MODE 0
#define BUT_MINUS 1
#define BUT_PLUS 2
#define BUT_ENTER 3
#define SIZE_BUFFER 100
#define LEDS_OFF (GPIO_WriteHigh(LED_GPIO_PORT, LED_GPIO_PINS))
#define LEDS_ON (GPIO_WriteLow(LED_GPIO_PORT, LED_GPIO_PINS))
#define LED_UP_ON (GPIO_WriteLow(LED_GPIO_PORT, LED_UP_PIN))
#define LED_UP_OFF (GPIO_WriteHigh(LED_GPIO_PORT, LED_UP_PIN))
#define LED_DOWN_ON (GPIO_WriteLow(LED_GPIO_PORT, LED_DOWN_PIN))
#define LED_DOWN_OFF (GPIO_WriteHigh(LED_GPIO_PORT, LED_DOWN_PIN))
#define START_ON_VBUT (GPIO_WriteLow(OUT_GPIO_PORT, OUT_START_PIN))
#define START_OFF_VBUT (GPIO_WriteHigh(OUT_GPIO_PORT, OUT_START_PIN))
#define PLUS_ON_VBUT (GPIO_WriteLow(OUT_GPIO_PORT, OUT_PLUS_PIN))
#define PLUS_OFF_VBUT (GPIO_WriteHigh(OUT_GPIO_PORT, OUT_PLUS_PIN))
#define ENTER_ON_VBUT (GPIO_WriteLow(OUT_GPIO_PORT, OUT_ENTER_PIN))
#define ENTER_OFF_VBUT (GPIO_WriteHigh(OUT_GPIO_PORT, OUT_ENTER_PIN))
#define OUT_PIN_OFF (GPIO_WriteHigh(OUT_GPIO_PORT, OUT_GPIO_PINS))
#define RESET_TIME_LOOP_10s (time_loop = millis() + 10000)
#define RESET_TIME_LOOP_15s (time_loop = millis() + 15000)
#define RESET_TIME_PODMENU_30m (time_loop_podmenu = millis() + 1800000UL)
#define DELAY_PRESS 3000

typedef enum FLASH_MODE{
	FLASH_UP = 1,
	FLASH_DOWN,
	FLASH_BOTH,
	FLASH_NONE,
	FLASH_INSTALL,
} Flash_mode;

typedef enum MODE{
	MODE_UP = 1,
	MODE_DOWN,
	MODE_BOTH,
	MODE_NONE,
	MODE_INSTALL,
} Mode;

typedef enum MENU{
	MENU_MENUE = 0,
	MENU_UP,
	MENU_DOWN,
	MENU_BOTH,
	MENU_STRETCHING,
	MENU_INSTALL,
} Menu;

typedef enum PODMENU{
    UNKNOwN = 0,
	POD_MENU_UP = 1,
	POD_MENU_DOWN,
	POD_MENU_BOTH,
} Podmenu;

typedef struct CONTROL{
	Mode required_mode;
	Menu current_menu;
    bool enter_podmenu;
	bool exit_podmenu;
	bool reset_install;
	bool start_install;
} Control;

static void CLK_Config(void);
static void GPIO_Config();
static void IWDG_Config();  //1.02s
static void EEPROM_Config();
void getButtonState(uint8_t but);
void scan_buttons();
bool scan_change_mode(Control* ctrl);
void flash_led(Flash_mode flash);
void flash_install_led();
void flash_reset_led();
void continous_flash_led(Flash_mode flash);
void iwdg_reset();
void check_reset_flag();
void switch_menu_press_plus(Control* ctrl);
void start_emulate_press_enter();
void start_emulate_press_enter_reset();
void start_emulate_press_enter_install_mode();
bool emulate_plus_minus_press();
bool buf_cmp(uint8_t* buf, uint8_t buflen, uint8_t* target, uint8_t tlen);