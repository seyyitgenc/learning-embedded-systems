int lm35pin = A0;
int led = 8;
int buzzer = 10;

int time = 50;
int readed_valude = 0;
float temperature_voltage = 0;
float temperature = 0;

void setup(){
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}
void loop(){
    readed_valude = analogRead(lm35pin);
    temperature_voltage = (readed_valude / 1023.0) * 5000;
    temperature = temperature_voltage / 10.0;
    Serial.println(temperature);
    if (temperature >= 10)
    {
        digitalWrite(led, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(time);
        digitalWrite(led, LOW);
        digitalWrite(buzzer, LOW);
        delay(time);
    }
    else{
        digitalWrite(led, LOW);
        digitalWrite(buzzer, LOW);
    }
    
}