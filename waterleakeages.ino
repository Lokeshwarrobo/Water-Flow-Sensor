include <FlowMeter.h>  
FlowMeter Meter1 = FlowMeter(2);
FlowMeter Meter2 = FlowMeter(3);
FlowMeter Meter3 = FlowMeter(20);
const unsigned long period = 1000;
int f1,f2,f3;
void Meter1ISR() {
    Meter1.count();
}
void Meter2ISR() {
   
    Meter2.count();
}
void Meter3ISR() {
   
    Meter3.count();
}
void setup() {
    Serial.begin(9600);
    attachInterrupt(INT4, Meter1ISR, RISING);
    attachInterrupt(INT1, Meter2ISR, RISING);
    attachInterrupt(INT0, Meter3ISR, RISING);
    Meter1.reset();
    Meter2.reset();
    Meter3.reset();
    
}

void loop() {
    delay(period);
    Meter1.tick(period);
    Meter2.tick(period);
    Meter3.tick(period);
    f1 = Meter1.getCurrentFlowrate();
    f2 = Meter2.getCurrentFlowrate();
    f3 = Meter3.getCurrentFlowrate();
    if (int(f1)>int(f2) && int(f1)>int(f3))
    {
      Serial.println("there is a leakage between f1 and f2");
    }
    else if(int(f2)>int(f3))
    {
      Serial.println("there is a laeakage between f2 and f3");
    }

}
    }
    }
