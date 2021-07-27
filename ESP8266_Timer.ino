#define timer0_preload 40161290

byte sec = 0, mint = 0, hour = 0;
unsigned long day = 0;

  void inline interrupt_timer (void){//timer metod of Timer :: this metod Interrupt Every second
    sec++;
    if(sec == 60){
      sec = 0;
      mint++;
      }
     if(mint == 60){
      mint = 0;
      hour++;
      }
      if(hour == 24){
        hour = 0;
        day++;
        }
    
    Serial.print("secend=");
    Serial.println(sec);
    Serial.print("mint=");
    Serial.println(mint);
    Serial.print("hour=");
    Serial.println(hour);
    Serial.print("day=");
    Serial.println(day);
    timer0_write(ESP.getCycleCount()+timer0_preload*2); //set time next Interrupt
    }

void setup() {
  Serial.begin(9600);
  noInterrupts(); 
  timer0_isr_init();  //begin timer0
  timer0_attachInterrupt(interrupt_timer); //set metod Interrupt
  timer0_write(ESP.getCycleCount()+timer0_preload*2); // set time next Interrupt
  interrupts(); 
}

void loop() {
  

}
