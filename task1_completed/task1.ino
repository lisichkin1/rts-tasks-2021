const int ledPin_1 = 5;
const int ledPin_2 = 6;
const int ledPin_3 = 11;
const int ledPin_4 = 10;
const int ledPin_5 = 9;

unsigned long next_time_1; // время очередного переключения первого светодиода BLUE RIGHT
unsigned long next_time_2; // ... второго светодиода GREEN
unsigned long next_time_3; //BLUE LEFT
unsigned long next_time_4; //red
unsigned long next_time_5; //yellow
unsigned long timeout_1 = 1000000; // половина периода мигания первого светодиода
unsigned long timeout_2 = 750000; // ... второго светодиода
unsigned long timeout_3 = 500000;
unsigned long timeout_4 = 250000;
int timeout_5 = 250;

int led_state_1 = 0; // начальное состояние первого светодиода - выключен
int led_state_2 = 0; // ... второго светодиода
int led_state_3 = 0;
int led_state_4 = 0;
int led_state_5 = 0;

void setup() {
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  pinMode(ledPin_4, OUTPUT);
  pinMode(ledPin_5, OUTPUT);

  digitalWrite(ledPin_1, led_state_1); // гасим первый светодиод
  digitalWrite(ledPin_2, led_state_2); // гасим второй светодиод
  digitalWrite(ledPin_3, led_state_3);
  digitalWrite(ledPin_4, led_state_4);
  digitalWrite(ledPin_5, led_state_5);

  next_time_1 = micros() + timeout_1; // вычисляем время следующего переключения первого светодиода
  next_time_2 = micros() + timeout_2; // ... второго светодиода
  next_time_3 = micros() + timeout_3;
  next_time_4 = micros() + timeout_4;
  next_time_5 = millis() + timeout_5;
}

void loop() {
  unsigned long now_time = micros(); // текущее время
  if (now_time >= next_time_1) { // если текущее время превысило намеченное время, то
    next_time_1 = now_time + timeout_1; // вычисляем время следующего переключения
    led_state_1 = !led_state_1; // меняем состояние на противоположное
    digitalWrite(ledPin_1, led_state_1); // зажигаем или гасим светодиод
  }

  now_time = micros();
  if (now_time >= next_time_2) {
    next_time_2 = now_time + timeout_2;
    led_state_2 = !led_state_2;
    digitalWrite(ledPin_2, led_state_2);
  }

  now_time = micros();
  if (now_time >= next_time_3) {
    next_time_3 = now_time + timeout_3;
    led_state_3 = !led_state_3;
    digitalWrite(ledPin_3, led_state_3);
  }

  now_time = micros();
  if (now_time >= next_time_4) {
    next_time_4 = now_time + timeout_4;
    led_state_4 = !led_state_4;
    digitalWrite(ledPin_4, led_state_4);
  }

  now_time = millis();
  if (now_time >= next_time_5) {
    next_time_5 = now_time + timeout_5;
    led_state_5 = !led_state_5;
    digitalWrite(ledPin_5, led_state_5);
  }

}
