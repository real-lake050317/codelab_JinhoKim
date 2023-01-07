static int uart_putchar(char u8Data, FILE *stream) {
  while (!(UCSR0A&32));
  UDR0 = u8Data;
  return 0;
}

static int uart_getchar(FILE *stream) {
  while(!Serial.available());
  return Serial.read();
}


FILE uart_output, uart_input;