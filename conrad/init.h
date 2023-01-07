// Serial.begin(9600);
  uart_output.put = uart_putchar;
  uart_output.get = NULL;
  uart_output.flags = _FDEV_SETUP_WRITE;
  uart_output.udata = 0;

  uart_input.put = NULL;
  uart_input.get = uart_getchar;
  uart_input.flags = _FDEV_SETUP_READ;
  uart_input.udata = 0;

 stdout = &uart_output;
 stdin = &uart_input;