int i;
int expression = 0;
int blondur1[3] = {11,9,10};
int blondur2[3] = {8,10,11};
int blondur3[4] = {8,9,10,11};
int blondur4[5] = {4,8,9,10,11};
int blondur5[4] = {4,9,11,10};
int countbutton = 0;
int count1 = 0;
const int buttonPin = 3;    
const int buttonPin_select = 2;
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
  
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin_select, INPUT);

Serial.print("PICK A MIX!");
//We use a while loop to wait for the user to press the button. Teh button state is LOW when it's pressed.
while(start == 0)
{
  buttonState = digitalRead(buttonPin);
  buttonStateselect = digitalRead(buttonPin_select);
  
  if (buttonState == LOW)
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

  
  if (buttonStateselect == LOW)
   {
    
    expression = count1;
    Serial.print("Selected"); 
    break;
   }
 
}
  switch(expression)
  {
  
    case 1:
     Serial.print("Mixing mix number 1...");
    mix(3,blondur1);
    pinMode(resetPin, OUTPUT);
    Serial.print("DONE");
    break;
    
    case 2:
    Serial.print("Mixing mix number 2...");
    mix(3, blondur1);
    pinMode(resetPin, OUTPUT);
     Serial.print("DONE");
    break;
    
    case 3:
    Serial.print("Mixing mix number 3...");
    mix(3, blondur2);
    pinMode(resetPin, OUTPUT);
    Serial.print("DONE");
    break;
    
    case 4:
     Serial.print("Mixing mix number 4...");
    mix(5, blondur4);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 5:
     Serial.print("Mixing mix number 5...");
    mix(4, blondur5);
    pinMode(resetPin, OUTPUT);
    Serial.print("DONE");
    break;
  }
  
}


void loop()
{
}

