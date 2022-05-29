//
//  bifrost_dmcp_os_impl.c
//  alabang_project
//
//  Created by raoul on 28.5.2022.
//

#include "bifrost_dmcp_os_impl.h"

#include <stdio.h>
#include <string.h>
// this is what we implement
#include <dmcp.h>

// new
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

//#pragma ide diagnostic ignored "UnusedParameter"
//#pragma ide diagnostic ignored "ConstantFunctionResult"

// Declare swift bridges
// protos for function, it matches @_cdecl("swift_inc_x")
// For the rest, done before impl
intptr_t swift_inc_x(intptr_t);

// Forward declare example function, just as long as we need the artivicial example loop start
void *inc_x(void *x_void_ptr);

// This function is called from swift on init. It now simulates stuff happening.
// In the end, it has to trigger the event loop within the secret code of the dylib
// that starts listening to key events.
// I is important that the loop is stared somewhere in a thread, like here or in the
// client lib.
int c_start_client_lib_loop(void) {
    long x = 0;
    
    printf("started\n");
    
    // this variable is our reference to the thread
    pthread_t inc_x_thread;
    
    // create thread which executes inc_x(&x)
    if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    
    // wait for the thread to finish:
    if(pthread_join(inc_x_thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    return 0;
}

// Impl of demo function that itself calls swift code
void *inc_x(void *x_void_ptr) {
    long *x_ptr = (long *)x_void_ptr;
    while(*x_ptr < 10) {
        printf("C: %ld\n", *x_ptr);
        *x_ptr = swift_inc_x( *x_ptr);
        LCD_clear();
        LCD_power_on();
        LCD_power_off(42);
        usleep(2000000);
    }
    
    /* the function must return something - NULL will do */
    return NULL;
}

// actual impl that forwards up to Swift

void swift_LCD_clear(void);
void LCD_clear(void) {
    //fprintf(stderr, "Not implemented: \"%s\"\n", "LCD_clear");
    printf("LCD_clear called in c\n");
    swift_LCD_clear();
}

void swift_LCD_power_on(void);
void LCD_power_on(void) {
    //fprintf(stderr, "Not implemented: \"%s\"\n", "LCD_power_on");
    printf("LCD_power_on called in c\n");
    swift_LCD_power_on();
}

int swift_LCD_power_off(int clear);
void LCD_power_off(int clear) {
    //fprintf(stderr, "Not implemented: \"%s\"\n", "LCD_power_off");
    printf("LCD_power_off called in c\n");
    int result = swift_LCD_power_off(clear);
    printf("Got back result: %i", result);
}

void LCD_write_line(uint8_t * buf) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "LCD_write_line");
}

void bitblt24(uint32_t x, uint32_t dx, uint32_t y, uint32_t val, int blt_op, int fill) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "bitblt24");
}

uint8_t * lcd_line_addr(int y) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_line_addr");
    uint8_t * returnValue = NULL;
    return returnValue;
}

void lcd_clear_buf(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_clear_buf");
}

void lcd_refresh(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_refresh");
}

void lcd_refresh_dma(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_refresh_dma");
}

void lcd_refresh_wait(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_refresh_wait");
}

void lcd_forced_refresh(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_forced_refresh");
}

void lcd_refresh_lines(int ln, int cnt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_refresh_lines");
}

void lcd_fill_rect(uint32_t x, uint32_t y, uint32_t dx, uint32_t dy, int val) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_fill_rect");
}

void lcd_fill_ptrn(int x, int y, int dx, int dy, int ptrn1, int ptrn2) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_fill_ptrn");
}

void lcd_draw_img(const char* img, uint32_t xo, uint32_t yo, uint32_t x, uint32_t y) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_draw_img");
}

void lcd_draw_img_direct(const char* img, uint32_t xo, uint32_t yo, uint32_t x, uint32_t y) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_draw_img_direct");
}

void lcd_draw_img_part(const char* img, uint32_t xo, uint32_t yo, uint32_t x, uint32_t y, uint32_t dx) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_draw_img_part");
}

void lcd_fillLine(int ln, uint8_t val) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_fillLine");
}

void lcd_fillLines(int ln, uint8_t val, int cnt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_fillLines");
}

void lcd_set_buf_cleared(int val) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_set_buf_cleared");
    printf("Bifrost Dummy OS was called. Got: %i\n", val);
}

int lcd_get_buf_cleared(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_get_buf_cleared");
    int returnValue = 0;
    return returnValue;
}

uint8_t reverse_byte(uint8_t x) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "reverse_byte");
    uint8_t returnValue = 0;
    return returnValue;
}

void lcd_writeNl(disp_stat_t * ds) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_writeNl");
}

void lcd_prevLn(disp_stat_t * ds) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_prevLn");
}

void lcd_writeClr(disp_stat_t * ds) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_writeClr");
}

void lcd_setLine(disp_stat_t * ds, int ln_nr) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_setLine");
}

void lcd_setXY(disp_stat_t * ds, int x, int y) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_setXY");
}

int lcd_lineHeight(disp_stat_t * ds) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_lineHeight");
    int returnValue = 0;
    return returnValue;
}

int lcd_baseHeight(disp_stat_t * ds) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_baseHeight");
    int returnValue = 0;
    return returnValue;
}

int lcd_fontWidth(disp_stat_t * ds) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_fontWidth");
    int returnValue = 0;
    return returnValue;
}

void lcd_writeText(disp_stat_t * ds, const char* text) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_writeText");
}

void lcd_textToBox(disp_stat_t * ds, int x, int width, char *text, int from_right, int align_right) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_textToBox");
}

int lcd_textWidth(disp_stat_t * ds, const char* text) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_textWidth");
    int returnValue = 0;
    return returnValue;
}

int lcd_charWidth(disp_stat_t * ds, int c) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_charWidth");
    int returnValue = 0;
    return returnValue;
}

int lcd_textToWidth(disp_stat_t * ds, const char* text, int expected_width, int * plen) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_textToWidth");
    int returnValue = 0;
    return returnValue;
}

void lcd_writeTextWidth(disp_stat_t * ds, const char* text) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_writeTextWidth");
}

int lcd_textForWidth(disp_stat_t * ds, const char* text, int expected_width, int * plen) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_textForWidth");
    int returnValue = 0;
    return returnValue;
}

int lcd_nextFontNr(int nr) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_nextFontNr");
    int returnValue = 0;
    return returnValue;
}

int lcd_prevFontNr(int nr) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_prevFontNr");
    int returnValue = 0;
    return returnValue;
}

void lcd_switchFont(disp_stat_t * ds, int nr) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_switchFont");
}

int lcd_toggleFontT(int nr) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_toggleFontT");
    int returnValue = 0;
    return returnValue;
}

int lcd_for_calc(int what) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_for_calc");
    int returnValue = 0;
    return returnValue;
}

void lcd_draw_menu_bg(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_draw_menu_bg");
}

void lcd_draw_menu_key(int n, const char *s, int highlight) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_draw_menu_key");
}

void lcd_draw_menu_keys(const char *keys[]) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_draw_menu_keys");
}

void lcd_print(disp_stat_t * ds, const char* fmt, ...) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "lcd_print");
}

const char* get_wday_shortcut(int day) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_wday_shortcut");
    const char* returnValue = NULL;
    return returnValue;
}

const char* get_month_shortcut(int month) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_month_shortcut");
    const char *returnValue = NULL;
    return returnValue;
}

int julian_day(dt_t *d) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "julian_day");
    int returnValue = 0;
    return returnValue;
}

void julian_to_date(int julian_day, dt_t *d) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "julian_to_date");
}

uint8_t get_hw_id(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_hw_id");
    uint8_t returnValue = 0;
    return returnValue;
}

void rtc_read(tm_t * tm, dt_t *dt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_read");
}

void rtc_write(tm_t * tm, dt_t *dt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_write");
}

void rtc_update_time_sec(int delta_sec) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_update_time_sec");
}

uint8_t rtc_read_century(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_read_century");
    uint8_t returnValue = 0;
    return returnValue;
}

void rtc_write_century(uint8_t cent) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_write_century");
}

uint8_t rtc_read_min(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_read_min");
    uint8_t returnValue = 0;
    return returnValue;
}

uint8_t rtc_read_sec(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_read_sec");
    uint8_t returnValue = 0;
    return returnValue;
}

void rtc_wakeup_delay(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_wakeup_delay");
}

uint32_t read_power_voltage(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "read_power_voltage");
    uint32_t returnValue = 0U;
    return returnValue;
}

int get_lowbat_state(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_lowbat_state");
    int returnValue = 0;
    return returnValue;
}

int get_vbat(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_vbat");
    int returnValue = 0;
    return returnValue;
}

void start_buzzer_freq(uint32_t freq) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "start_buzzer_freq");
}

void stop_buzzer(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "stop_buzzer");
}

void set_buzzer(int pin1val, int pin2val) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "set_buzzer");
}

void beep_volume_up(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "beep_volume_up");
}

void beep_volume_down(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "beep_volume_down");
}

int get_beep_volume(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_beep_volume");
    int returnValue = 0;
    return returnValue;
}

uint32_t mark_region(uint32_t id) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "mark_region");
    uint32_t returnValue = 0U;
    return returnValue;
}

void no_region(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "no_region");
}

void set_reset_magic(uint32_t value) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "set_reset_magic");
}

int is_reset_state_file(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "is_reset_state_file");
    int returnValue = 0;
    return returnValue;
}

char * get_reset_state_file(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_reset_state_file");
    char * returnValue = NULL;
    return returnValue;
}

void set_reset_state_file(const char * str) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "set_reset_state_file");
}

int switch_usb_powered_freq(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "switch_usb_powered_freq");
    int returnValue = 0;
    return returnValue;
}

int usb_powered(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "usb_powered");
    int returnValue = 0;
    return returnValue;
}

void usb_acm_on(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "usb_acm_on");
}

int usb_is_on(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "usb_is_on");
    int returnValue = 0;
    return returnValue;
}

void usb_turn_off(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "usb_turn_off");
}

void acm_puts(const char *str) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "acm_puts");
}

char * aux_buf_ptr(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "aux_buf_ptr");
    char * returnValue = NULL;
    return returnValue;
}

void * write_buf_ptr(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "write_buf_ptr");
    char * returnValue = NULL;
    return returnValue;
}

int write_buf_size(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "write_buf_size");
    int returnValue = 0;
    return returnValue;
}

__attribute__((unused)) void program_main(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "program_main");
}

int read_key(int *k1, int *k2) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "read_key");
    int returnValue = 0;
    return returnValue;
}

void suspended_bg_key_read(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "suspended_bg_key_read");
}

void resume_bg_key_read(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "resume_bg_key_read");
}

uint32_t get_tim1_timer(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_tim1_timer");
    uint32_t returnValue = 0U;
    return returnValue;
}

void start_timer2(uint32_t div32) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "start_timer2");
}

void start_timer3(uint16_t div16) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "start_timer3");
}

void stop_timer2(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "stop_timer2");
}

void stop_timer3(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "stop_timer3");
}

uint32_t get_rtc_ticks(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "get_rtc_ticks");
    uint32_t returnValue = 0U;
    return returnValue;
}

rtc_ticks_stat_t* rtc_update_ticks(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_update_ticks");
    rtc_ticks_stat_t* returnValue = NULL;
    return returnValue;
}

void rtc_set_alarm(tm_t * tm, dt_t *dt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_set_alarm");
}

void rtc_cancel_alarm(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_cancel_alarm");
}

int qspi_user_write(uint8_t *data, int size, int offset, int erase) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "qspi_user_write");
    int returnValue = 0;
    return returnValue;
}

uint8_t * qspi_user_addr(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "qspi_user_addr");
    uint8_t * returnValue = NULL;
    return returnValue;
}

int qspi_user_size(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "qspi_user_size");
    int returnValue = 0;
    return returnValue;
}

void print_byte(uint8_t b) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "print_byte");
}

void print_buffer(uint8_t * buf, int cnt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "print_buffer");
}

int print_is_ready(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "print_is_ready");
    int returnValue = 0;
    return returnValue;
}

uint printer_get_delay(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "printer_get_delay");
    uint returnValue = 0;
    return returnValue;
}

void printer_set_delay(uint val) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "printer_set_delay");
}

void printer_advance_buf(int what) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "printer_advance_buf");
}

int printer_busy_for(int what) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "printer_busy_for");
    int returnValue = 0;
    return returnValue;
}

void rtc_check_unset(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "rtc_check_unset");
}

void run_set_time(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "run_set_time");
}

void run_set_date(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "run_set_date");
}

void disp_disk_info(const char * hdr) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "disp_disk_info");
}

int power_check_screen(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "power_check_screen");
    int returnValue = 0;
    return returnValue;
}

int handle_menu(const smenu_t * menu_id, int action, int cur_line) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "handle_menu");
    int returnValue = 0;
    return returnValue;
}

char * opt_str(char * s, char const *txt, int val) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "opt_str");
    char * returnValue = NULL;
    return returnValue;
}

char * date_str(char * s, const char * txt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "date_str");
    char * returnValue = NULL;
    return returnValue;
}

char * time_str(char * s, const char * txt) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "time_str");
    char * returnValue = NULL;
    return returnValue;
}

int file_selection_screen(const char * title, const char * base_dir, const char * ext, file_sel_fn_t sel_fn,
                          int disp_new, int overwrite_check, void * data) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "file_selection_screen");
    int returnValue = 0;
    return returnValue;
}

void item_sel_init(item_sel_state_t *st) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "item_sel_init");
}

void item_sel_reinit(item_sel_state_t *st) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "item_sel_reinit");
}

int item_sel_engine(item_sel_state_t *st, int upd) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "item_sel_engine");
    int returnValue = 0;
    return returnValue;
}

void item_sel_header(item_sel_state_t *st, int update) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "item_sel_header");
}

void msg_box(disp_stat_t * ds, const char * txt, int inv) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "msg_box");
}

int run_menu_item_sys(uint8_t line_id) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "run_menu_item_sys");
    int returnValue = 0;
    return returnValue;
}

int create_screenshot(int report_error) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "create_screenshot");
    int returnValue = 0;
    return returnValue;
}

int key_empty(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "key_empty");
    int returnValue = 0;
    return returnValue;
}

int key_push(int k1) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "key_push");
    int returnValue = 0;
    return returnValue;
}

int key_tail(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "key_tail");
    int returnValue = 0;
    return returnValue;
}

int key_pop(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "key_pop");
    int returnValue = 0;
    return returnValue;
}

int key_pop_last(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "key_pop_last");
    int returnValue = 0;
    return returnValue;
}

void key_pop_all(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "key_pop_all");
}

int key_to_nr(int key) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "key_to_nr");
    int returnValue = 0;
    return returnValue;
}

void wait_for_key_press(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "wait_for_key_press");
}

int runner_get_key(int *repeat) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "runner_get_key");
    int returnValue = 0;
    return returnValue;
}

int runner_get_key_delay(int *repeat, uint timeout, uint rep0, uint rep1, uint rep1tout) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "runner_get_key_delay");
    int returnValue = 0;
    return returnValue;
}

void wait_for_key_release(int tout) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "wait_for_key_release");
}

int runner_key_tout_value(const int first) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "runner_key_tout_value");
    int returnValue = 0;
    return returnValue;
}

void runner_key_tout_init(const int slow) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "runner_key_tout_init");
}

int toggle_slow_autorepeat(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "toggle_slow_autorepeat");
    int returnValue = 0;
    return returnValue;
}

int is_slow_autorepeat(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "is_slow_autorepeat");
    int returnValue = 0;
    return returnValue;
}

void reset_auto_off(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "reset_auto_off");
}

int is_auto_off(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "is_auto_off");
    int returnValue = 0;
    return returnValue;
}

int is_menu_auto_off(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "is_menu_auto_off");
    int returnValue = 0;
    return returnValue;
}

int sys_auto_off_cnt(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_auto_off_cnt");
    int returnValue = 0;
    return returnValue;
}

void print_dmy_date(char * s, int const sz, dt_t *dt, const char * append, int shortmon, char sep_arg) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "print_dmy_date");
}

void print_clk24_time(char * t, int const sz, tm_t *tm, int disp_sec, int disp_dow) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "print_clk24_time");
}

int check_create_dir(const char * dir) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "check_create_dir");
    int returnValue = 0;
    return returnValue;
}

void set_fat_label(const char * label) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "set_fat_label");
}

int file_exists(const char * fn) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "file_exists");
    int returnValue = 0;
    return returnValue;
}

int file_size(const char * fn) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "file_size");
    int returnValue = 0;
    return returnValue;
}

int sys_disk_ok(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_disk_ok");
    int returnValue = 0;
    return returnValue;
}

int sys_disk_write_enable(int val) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_disk_write_enable");
    int returnValue = 0;
    return returnValue;
}

void sys_disk_check_valid(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_disk_check_valid");
}

int sys_is_disk_write_enable(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_is_disk_write_enable");
    int returnValue = 0;
    return returnValue;
}

void sys_clear_write_buf_used(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_clear_write_buf_used");
}

int sys_write_buf_used(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_write_buf_used");
    int returnValue = 0;
    return returnValue;
}

void sys_timer_disable(int timer_ix) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_timer_disable");
}

void sys_timer_start(int timer_ix, uint32_t ms_value) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_timer_start");
}

int sys_timer_active(int timer_ix) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_timer_active");
    int returnValue = 0;
    return returnValue;
}

int sys_timer_timeout(int timer_ix) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_timer_timeout");
    int returnValue = 0;
    return returnValue;
}

void sys_delay(uint32_t ms_delay) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_delay");
}

uint32_t sys_tick_count(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_tick_count");
    uint32_t returnValue = 0U;
    return returnValue;
}

uint32_t sys_current_ms(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_current_ms");
    uint32_t returnValue = 0U;
    return returnValue;
}

void sys_critical_start(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_critical_start");
}

void sys_critical_end(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_critical_end");
}

void sys_sleep(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_sleep");
}

int sys_free_mem(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_free_mem");
    int returnValue = 0;
    return returnValue;
}

void sys_reset(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_reset");
}

int sys_last_key(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_last_key");
    int returnValue = 0;
    return returnValue;
}

void make_date_filename(char * str, const char * dir, const char * ext) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "make_date_filename");
}

void sys_flashing_init(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_flashing_init");
}

void sys_flashing_finish(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_flashing_finish");
}

int sys_flash_erase_block(void* start_addr, uint32_t size) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_flash_erase_block");
    int returnValue = 0;
    return returnValue;
}

int sys_flash_write_block(void* dst_addr, uint8_t * src_buf, uint32_t size) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "sys_flash_write_block");
    int returnValue = 0;
    return returnValue;
}

void run_help(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "run_help");
}

void run_help_file(const char * help_file) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "run_help_file");
}

void run_help_file_style(const char * help_file, user_style_fn_t *user_style_fn) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "run_help_file_style");
}

void draw_power_off_image(int allow_errors) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "draw_power_off_image");
}

void reset_off_image_cycle(void) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "reset_off_image_cycle");
}

int update_bmp_file_header(FIL* fp, int width, int height, uint32_t bg_color) {
    fprintf(stderr, "Not implemented: \"%s\"\n", "update_bmp_file_header");
    int returnValue = 0;
    return returnValue;
}
