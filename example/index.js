
const pifacecad = require('node-pifacecad');

function sleep(ms)
  {
    return new Promise((resolve, reject) => setTimeout( resolve, ms ));
  }

class TextScroll
  {
    constructor(width, text)
      {
        this.width = width,
        this.text = text;
        this.current = new Array(width);
        this.current.fill(' ');
        this.idx = -1;
      };
    get()
      {
        this.idx = (this.idx + 1 ) % this.text.length;
        this.current.shift();
        this.current.push( this.text.charAt( this.idx ));
        return this.current.join('');
      }
    
  }

function shutdown()
  {
    pifacecad.lcd_backlight_off();
    pifacecad.lcd_blink_off();
    pifacecad.lcd_cursor_off();
    pifacecad.lcd_clear();
    process.exit();
  }

async function main()
  {
    pifacecad.open();
    pifacecad.lcd_backlight_on();
    pifacecad.lcd_blink_off();
    pifacecad.lcd_cursor_off();
    pifacecad.lcd_write('Hello World! ');


    await sleep(500);
    pifacecad.lcd_display(0);
    await sleep(500);
    pifacecad.lcd_display(1);
    await sleep(500);


    //await sleep(5000);

    pifacecad.lcd_set_cursor(0,1);
    pifacecad.lcd_write_custom_bitmap(0);


    const text = new TextScroll(
      16,
      [
        "Hello World! ",
        "Press the switches! ",
        "There are five switches at the bottom and ",
        "a left/select/right-switch at the top.  "
      ].join('')
    );

    const cg =
      [
        [ 0b00000, 0b00000, 0b00000, 0b00100, 0b00000, 0b00000, 0b00000, 0b00000 ],
        [ 0b00000, 0b00000, 0b00100, 0b01010, 0b00100, 0b00000, 0b00000, 0b00000 ],
        [ 0b00000, 0b00100, 0b00000, 0b10001, 0b00000, 0b00100, 0b00000, 0b00000 ],
        [ 0b00000, 0b00000, 0b00100, 0b01010, 0b00100, 0b00000, 0b00000, 0b00000 ],
        [ 0b00000, 0b00000, 0b00000, 0b00100, 0b00000, 0b00000, 0b00000, 0b00000 ],
      ]

    let cgidx = 0;
    while (true) {
      pifacecad.lcd_store_custom_bitmap( 0, cg[cgidx] );
      cgidx = (cgidx + 1) % cg.length;

      const sw = pifacecad.read_switches();
      pifacecad.lcd_set_cursor(2,1);
      pifacecad.lcd_write(
        [
          sw & 0b00000001 ? ' ' : '1',
          sw & 0b00000010 ? ' ' : '2',
          sw & 0b00000100 ? ' ' : '3',
          sw & 0b00001000 ? ' ' : '4',
          sw & 0b00010000 ? ' ' : '5',
          sw & 0b01000000 ? ' ' : 'L',
          sw & 0b00100000 ? ' ' : 'S',
          sw & 0b10000000 ? ' ' : 'R'
        ].join('')
      );

      pifacecad.lcd_set_cursor(0,0);
      pifacecad.lcd_write(text.get());

      await sleep(250);
    }

    pifacecad.close();
  }
process.on('SIGINT', shutdown );
main();
