#include <TaskManagerIO.h>
#define pin1 3
#define pin2 5
#define pin3 6
#define pin4 9
#define pin5 10
#define pin6 11


const long interval1 = 1000;
const long interval2 = 2000;
const long interval3 = 3000;
const long interval4 = 7000;
const long interval5 = 10000;
const long interval6 = 15000;

int pin1State=LOW;//прерывание будет срабатывать всякий раз, когда на выводе присутствует низкий уровень сигнала
int pin2State=LOW;
int pin3State=LOW;
int pin4State=LOW;
int pin5State=LOW;
int pin6State=LOW;


void setup() {
  pinMode(pin1,OUTPUT);// устанавливает режим работы - выход
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  
  taskid_t task1 = taskManager.scheduleFixedRate(interval1, [] {
    if(pin1State==LOW){
      pin1State=HIGH;  // прерывание будет срабатывать всякий раз, когда на выводе присутствует высокий уровень сигнала . scheduleFixedRate - Планирует задачу для повторного выполнения с указанной частотой.
    }else{
      pin1State=LOW;
      }    
    digitalWrite(pin1,pin1State);
  }, TIME_MICROS);
  
  taskid_t task2 = taskManager.scheduleFixedRate(interval2, [] {
    if(pin2State==LOW){
      pin2State=HIGH;  
    }else{
      pin2State=LOW;
      }    
    digitalWrite(pin2,pin2State);
  }, TIME_MICROS);
  
  taskid_t task3 = taskManager.scheduleFixedRate(interval3, [] {
    if(pin3State==LOW){
      pin3State=HIGH;  
    }else{
      pin3State=LOW;
      }    
    digitalWrite(pin3,pin3State);
  }, TIME_MICROS);
  
  taskid_t task4 = taskManager.scheduleFixedRate(interval4, [] {
    if(pin4State==LOW){
      pin4State=HIGH;  
    }else{
      pin4State=LOW;
      }    
    digitalWrite(pin4,pin4State);
  }, TIME_MICROS);
  
  taskid_t task5 = taskManager.scheduleFixedRate(interval5, [] {
    if(pin5State==LOW){
      pin5State=HIGH;  
    }else{
      pin5State=LOW;
      }    
    digitalWrite(pin5,pin5State);
  }, TIME_MICROS);
  
  taskid_t task6 = taskManager.scheduleFixedRate(interval6, [] {
    if(pin6State==LOW){
      pin6State=HIGH;  
    }else{
      pin6State=LOW;
      }    
    digitalWrite(pin6,pin6State);
  }, TIME_MICROS);
}

void loop() {
   taskManager.runLoop();
}
