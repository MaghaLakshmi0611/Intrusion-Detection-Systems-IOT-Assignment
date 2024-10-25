int trigger = 12;
int echo = 13;
int led = 8;
long duration =0;
int cm = 0;
int inch = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(trigger, OUTPUT);
    pinMode(echo, OUTPUT);
    pinMode(led, OUTPUT);
}

void loop()
{
    digitalWrite(trigger, LOW);
    digitalWrite(trigger, HIGH);
    digitalWrite(trigger, LOW);
    
    duration = pulseIn(echo, HIGH);
    cm = duration*0.034/2;
    inch = duration*0.0133/2;
    
    if(inch < 50);{
        digitalWrite(led, HIGH);
        tone(9,500,100);
    }
    if(inch < 100){
        Serial.print("Inches: ");
        Serial.println(inch);
        Serial.print("Cm: ");
        Serial.print(cm);
    }
//Temp-36
int reading = analogRead(A0);
float voltage = reading*5.0;
        voltage /= 1024.0;
        Serial.println();
        Serial.print(voltage);
        Serial.print(" volts ");
float temperatureC = (voltage - 0.5)*100;
        Serial.print(temperatureC);
        Serial.print(" degree F ");
float temperatureF = (temperatureC * 9.0/5.0) + 32.0;
        Serial.print(temperatureF);
        Serial.println("temperature F ");
    if(temperatureC > 37.5){
            tone(6,500,100);
    }
    delay(500);
}