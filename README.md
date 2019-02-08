# node-pifacecad

* This module for control pifacecad with nodejs.

* This module can be used in an environment equipped with the pifacecad raspberry pi

> const pifacecad = require('node-pifacecad');
> pifacecad.open();
> pifacecad.lcd_backlight_on();
> pifacecad.lcd_write('Hello world!');
> pifacecad.close();


* High level functions

  open()
    Opens and initialises a PiFace Control and Display.
    Returns a file descriptor for making raw SPI transactions to the
    MCP23S17 (for advanced users only).

  close()
   Closes a PiFace Control and Display (turns off interrupts, closes file
   descriptor).

  read_switches()
    Reads the entire switch port.

  read_switch(number)
    Reads a single switch.

  lcd_write
    Writes a message to the LCD screen starting from the current cursor
    position. Accepts '\\n'. Returns the current cursor address.

  lcd_set_cursor(col, row)
    Sets the cursor position on the screen (col , row).

  lcd_set_cursor_address(address)
    Sets the cursor position on the screen (address = col + row*40).

  lcd_get_cursor_address()
    Returns the cursor position (address).

  lcd_clear()
    Clears the screen and returns the cursor to home (0, 0).

  lcd_home()
    Returns the cursor to home (0, 0).

  lcd_display_on()
    Turns the display on.

  lcd_display_off()
    Turns the display off.

  lcd_blink_on()
    Turns the blinking cursor on.

  lcd_blink_off()
    Turns the blinking cursor off.

  lcd_cursor_on()
    Turns the underline cursor on.

  lcd_cursor_off()
    Turns the underline cursor off.

  lcd_backlight_on()
    Turns the backlight on.

  lcd_backlight_off()
    Turns the backlight off.

  lcd_move_left
    Moves the display left.

  lcd_move_right()
    Moves the display right.

  lcd_left_to_right()
    The cursor will move to the right after printing causing text to read
    left to right.

  lcd_right_to_left()
    The cursor will move to the left after printing causing text to read
    right to left.

  lcd_autoscroll_on()
    The screen will follow text if it moves out of view.

  lcd_autoscroll_off()
    The screen will not follow text if it moves out of view.

  lcd_store_custom_bitmap(array)
    Stores a custom bitmap to the location specified (up to 8: 0-7).

    Example:
      uint8_t bitmap[] = {0x15, 0xa, 0x15, 0xa, 0x15, 0xa, 0x15, 0xa};
      pifacecad_lcd_store_custom_bitmap(0, bitmap); // store
      pifacecad_lcd_write_custom_bitmap(0); // write

  lcd_write_custom_bitmap(number)
    Writes the custom bitmap stored at the specified bank location to the
    display.

  colrow2address(col, row)
    Returns an address calculated from a column and a row.

  address2col(address)
   Returns a row calculated from an address.

* Low level functions

  open_noinit
    Opens a PiFace Control and Display without initialising it.
    Returns a file descriptor for making raw SPI transactions to the
    MCP23S17 (for advanced users only).

  lcd_init()
   Initialised the LCD. You will not need to call this if you have called
   pifacecad_open.

  lcd_send_command(byte)
    Send a command to the HD44780.

  lcd_send_data(byte)
    Send data to the HD44780.

  lcd_send_byte(byte)
    Send a byte to the HD44780.

  lcd_set_rs(value)
    Set the RS pin on the HD44780.

  lcd_set_rw(value)
    Set the RW pin on the HD44780.

  lcd_set_enable(value)
    Set the enable pin on the HD44780.

  lcd_set_backlight(value)
    Set the backlight pin on the HD44780.

  lcd_pulse_enable
    Pulse the enable pin on the HD44780.

