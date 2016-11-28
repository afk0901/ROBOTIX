

int i;
int expression = 0;
const int maxselect = 3;//How many mixes.
int blondur1[3] = {8,9,10};
int blondur2[3] = {8,10,11};
int blondur3[4] = {8,9,10,11};
int blondur4[5] = {7,8,9,10,11};

int runloop = true;
int countbutton = 0;
int count1 = 0;

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int buttonPin_select = 2;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonStateselect = 0;
int start = 0;
int resetPin = 12;




void mix(int l,int arr[])
{
 
  for (i=0; i < l; i = i +1)
  {
    delay(1000);
    digitalWrite(arr[i], HIGH);   // opnar fyrir solinoid
    delay(1000);              // í 1 sek
    digitalWrite(arr[i], LOW);    //lokar solinoid
    delay(1000);              // í eina sek
  }
}

void mixingmsg(String msg)
{
  while(runloop)
  {
    runloop = false;
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
  

  // set up the LCD's number of columns and rows:
  // Print a message to the LCD.
  // initialize the LED pin as an output:

  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin_select, INPUT);


}


//int buttonState = 0;         // variable for reading the pushbutton status
//int buttonStateselect = 0;


void loop()
{

  //mixingmsg("Pick a mix");

  
  

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
    start++;
    expression = count1;
    Serial.print("Selected"); 
   }
 
}

  switch(expression)
  {
  
    case 1:
    Serial.print(count1);
    mix(4,  blondur3);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 2:
    Serial.print("Case 2");
    mix(3, blondur1);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 3:
    Serial.print(count1);
    mix(3, blondur2);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 4:
    mix(5, blondur4);
    pinMode(resetPin, OUTPUT);
    break;
    
    case 5:
    pinMode(resetPin, OUTPUT);
    break;
  }
}
  

