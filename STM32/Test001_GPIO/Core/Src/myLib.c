char s[200]; // output buffer
char b[100]; // input buffer
int __io_putchar(int ch) // 1char output to termial 1문자 단위로 포트로 출력
{
	HAL_UART_Transmit(&huart2, &ch, 1, 10);
	return ch;
}

int __io_getchar(void) // 1문자 단위로 포트로 출력
{
	int ch;
	while(HAL_UART_Receive(&huart2, &ch, 1, 10) != HAL_OK);
	HAL_UART_Transmit(&huart2, &ch, 1, 10);
	if(ch == '\r') HAL_UART_Transmit(&huart2, "\n", 1, 10);  // \r : CR carriage return
	return ch;
}
void ProgramStart()
{
	  printf("\033[2J\033[1;1H\n"); // [y;xH : move cur to (x,y)
	  printf("Program Ready... Press Blue Butoon to start\n ");
	  while(HAL_GPIO_ReadPin(GPIOC, GPIO_13) != 0) //  2J : clear screen , GPIOC_13 : B1 B1 for start
}

//int __io_getchar(void) //___ 가 많은 경우 system function, output console : monitor , input console : keybord
