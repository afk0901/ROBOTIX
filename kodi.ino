int i;
int expression = 0;
int blondur1[3] = {11,9,10};
int blondur2[3] = {8,10,11};
int blondur3[4] = {8,9,10,11};
int blondur4[5] = {7,8,9,10,11};
int blondur5[4] = {7,9,11,10};
int countbutton = 0;
int count1 = 0;
const int buttonPin = 5;    
const int buttonPin_select = 6;
int buttonState = 0;         
int buttonStateselect = 0;
int start = 0;
int resetPin = 12;

//uses a for loop to loop through the selenoids. It's equal liquid flowing through each one. 
void mix(int l,int arr[])
{
 
  for (i=0; i < l; i = i +1)
  {
    delay(1000);
    digitalWrite(arr[i], HIGH);   
    delay(1000);              
    digitalWrite(arr[i], LOW);    
    start++;              
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin_select, INPUT);

  
}


void loop()
{
    while(start == 0)
  {
    buttonState = digitalRead(buttonPin);
    buttonStateselect = digitalRead(buttonPin_select);


    switch(count1)
    {
      case 0:
      digitalWrite(A0, HIGH);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      break;
      
      case 1:
      digitalWrite(A0, HIGH);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      break;
      
      case 2:
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      break;
      
      case 3:
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      break;
      
      case 4:
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      break;
      
      case 5:
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      digitalWrite(A4, HIGH);
      break;
      
    }
    
    if (buttonState == 0)
    {
      
      if(count1 >= 5)
      {
        count1 =  1;
        Serial.print(count1);
        Serial.print("ButtonState");
        delay(1000);
      }
        
      else
      {
        count1++; 
        Serial.print(count1);
        Serial.print("ButtonState");
        delay(1000);
      }
    }
  
    
     if (buttonStateselect == 0)
     {

      if (count1 == 0)
      {
        expression = 1;
      }

      else
      {
        expression = count1;  
      }
      
      Serial.print("Selected"); 
      break;
     }
 
  }
  switch(expression)
  {
  
    case 1:
    Serial.print("Mixing mix number 1...");
    mix(3,blondur1);
    Serial.print("DONE");
    delay(100);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 2:
    Serial.print("Mixing mix number 2...");
    mix(3, blondur1);
    Serial.print("DONE");
    delay(100);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 3:
    Serial.print("Mixing mix number 3...");
    mix(3, blondur3);
    Serial.print("DONE");
    delay(100);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 4:
    Serial.print("Mixing mix number 4...");
    mix(5, blondur4);
    Serial.print("DONE");
    delay(100);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 5:
    Serial.print("Mixing mix number 5...");
    mix(4, blondur5);
    Serial.print("DONE");
    delay(100);
    pinMode(resetPin, OUTPUT);
    break;
  }

}
