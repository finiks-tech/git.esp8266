#define timer0_preload 40161290

unsigned long sec = 0;

  void inline interrupt_timer (void){
    Serial.print("secend=");
    Serial.println(sec);
    timer0_write(ESP.getCycleCount()+timer0_preload*2);
    }

void setup() {
  Serial.begin(9600);
  noInterrupts();
  timer0_isr_init();
  timer0_attachInterrupt(interrupt_timer);
  timer0_write(ESP.getCycleCount()+timer0_preload*2);
  interrupts();
}

void loop() {
  

}
