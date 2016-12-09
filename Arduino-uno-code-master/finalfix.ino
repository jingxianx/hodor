#include <Servo.h>
#include <Wire.h>

Servo myservo;  
Servo myservo1;

int array2c[6]; 
int i2c = 0;
int i2can =2;
int unomode = 0;


int dis = 0;
int pos = 80; 
int count6 = 0;
int count6f = 0;

int maxpos = 0;
int passflag = 0;

int xs = 0;
int ys = 0;
int sflag = 0;

int leftflag = 0;
int rightflag = 0;


int overwrite = 0;
int posrap = 45;
int temprap = 0;
int posrapt = 0;


int disarray[181];
int objectarray[181];

int re = 0;

int arrayup = 0;
int arraydown = 0;
int maxobject = 0;
int i2cmaxpos = 0;

int xnumb = 0;

int turnangle = 0;
int objectcount = 0;
int tpos = 80; 

int upos = 0;
int udis = 0;

int position1 = 0;
int position2 = 0;
int position3 = 0;
int position4 = 0;
int position5 = 0;
int position6 = 0;
int position7 = 0;
int position8 = 0;

int turnflag = 0;

int countgo = 0;


int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int flag5 = 0;
int flag6 = 0;
int flag7 = 0;
int flag8 = 0;
int flag9 = 0;

//Ted edit



void setup() {
  myservo.attach(10); 
  myservo1.attach(9); 

  Wire.begin(8);               
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);  
  



   

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,INPUT);
  countgo = 1000;

  
  
}

void loop() {

  overwrite = 0 ;

  unomode  = digitalRead(12);
  if(unomode ==1)
  {
    Serial.println("it is 1");
  }else
  {
    Serial.println("it is 2");
  }
  turnflag = 0;
  flag1 = 0;
  flag2 = 0;
  flag3 = 0;
  position1 = 0;
  position2 = 0;
  position3 = 0;
  objectcount = 0;
  posrap = 90;
//
if(unomode == 1)
{
  while(count6!= 5)
  {
    myservo1.write(count6 * 36); 
    unomode  = digitalRead(12);
     if(unomode ==0)
     {
      count6 = 0;
       break;
     }
  }
  myservo1.write(count6 * 36); 
  while(passflag != 1){
    unomode  = digitalRead(12);
     if(unomode ==0)
     {
      count6 = 0;
       break;
     }
     }
  passflag = 0;

  delay(100);
 // i2can = 2;
  Serial.println("hi");
  Serial.println(i2can*36);
}




  
  for (pos = 0; pos <= 180; pos += 1) { 
    dis = analogRead(A0);
    disarray[pos] = dis;
    if(dis>300)
    {
      objectarray[pos] = 1;
    }
    if(dis<300)
    {
      objectarray[pos] = 0;
    }


    myservo.write(pos);           
    //myservo1.write(pos);   
    delay(10);      
                     
  }

  
  arrayup = 0;
  objectcount = 0;
  maxobject = 0;
  maxpos = 0;
  overwrite = 0;
  Serial.print("1 Overwrite is: ");
  Serial.println(overwrite);
  temprap = i2can*36 - 15;
  while(temprap <= (i2can*36 + 15))
  {
    if(objectarray[temprap] == 1)
    {
      overwrite = 1;
    }
    temprap ++;
  }
  Serial.print("2 Overwrite is: ");
  Serial.println(overwrite);
  while(arrayup < 180)
  {
    
    xnumb = objectarray[arrayup];
   // Serial.println(arrayup);
   // Serial.println(" A: ");
  //  Serial.println(xnumb);
    if(xnumb == 0)
    {
      objectcount ++; 
    }
    if(xnumb == 1)
    {
      if(objectcount > maxobject)
      {
        maxobject = objectcount;
        maxpos = arrayup;
      }
      objectcount = 0;
    }

    
    arrayup ++;
  }

  
  if(arrayup >= 180 && objectcount > 0)
  {
       if(objectcount > maxobject)
      {
        maxobject = objectcount;
        maxpos = arrayup;
      }
      objectcount = 0;


    
  }
  turnangle = maxpos - maxobject/2;
//  Serial.print(" turn aaa: ");
 // Serial.println(turnangle);
  //Serial.println(90 - turnangle);
  if(maxobject<10)
  {
    re = 1;
    digitalWrite(8,HIGH);
    delay(800);
    digitalWrite(8,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    delay(500);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
   // Serial.print("MaxC: ");
   // Serial.println(maxobject);
  }
  if(unomode == 0)
  {
    overwrite = 1;
  }
  if(overwrite == 1)
  {
    if(((90-turnangle) < -15)&& (re == 0))
    {
      if(rightflag != 3)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(6*(turnangle-90));
        Serial.print("1 Left: ");
        Serial.println(turnangle - 90);
        rightflag++;
      }
      else if(rightflag == 3 && leftflag == 2)
      {
        digitalWrite(8,HIGH);
        delay(800);
        digitalWrite(8,LOW);
        rightflag = 0;
        leftflag = 0;
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(5*100);
        Serial.print("1 BL: ");
        Serial.println(5*45);
      }else if(rightflag == 3 && leftflag != 2)
      {


        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(6*(turnangle-90));
        Serial.print("1 LLeft: ");
        Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }else if(rightflag !=2 && leftflag == 3)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(6*(turnangle-90));
        Serial.print("1 l2left: ");
        Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }
     
    }
    else if(((90-turnangle) > 15) && (re == 0))
    {
     if(leftflag!=3)
     {
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(8*(90-turnangle));
        Serial.print("Right: ");
        Serial.println(turnangle - 90);
        leftflag++;
     }
     else if(leftflag == 3 && rightflag ==2 )
     {
        digitalWrite(8,HIGH);
        delay(800);
        digitalWrite(8,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(5*100);
        Serial.print("right: ");
        Serial.println(turnangle - 90);
        leftflag = 0;
        rightflag = 0;
     }else if(rightflag == 3 && leftflag != 2)
      {
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(8*(90-turnangle));
        Serial.print("right: ");
        Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }else if(rightflag !=2 && leftflag == 3)
      {
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(8*(90-turnangle));
        Serial.print("right: ");
        Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }


     
    }
    else if(re == 0)
    {
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(150);
     digitalWrite(6,LOW);
     digitalWrite(7,HIGH);
     delay(10);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(150);
     Serial.println("GO ");
     leftflag = 0;
     rightflag = 0;

    }
  }
   if(overwrite == 0)
   {
    if((90-i2can*36)<0)
    {
       digitalWrite(6,HIGH);
       digitalWrite(7,LOW);
       delay(7*(i2can*36-90));
       Serial.print("Go i left  : ");
       Serial.println(7*(i2can*36-90));
       
       
    }else if((90-i2can*36)>0)
    {
       digitalWrite(6,LOW);
       digitalWrite(7,HIGH);
       delay(7*(90-i2can*36));
       Serial.print("Go i right  : ");
       Serial.println(7*(90-i2can*36));
    }
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(250);
     digitalWrite(6,LOW);
     digitalWrite(7,HIGH);
     delay(10);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(250);
   }
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   re = 0;
  



  overwrite = 0; 
  posrap = 90;
  //i2can = 4;
  if(unomode == 1)
  {
    
  
  while(count6!= 0)
  {
    myservo1.write(count6 * 36); 
    unomode  = digitalRead(12);
     if(unomode ==0)
     {
      count6 = 0;
       break;
     }
  }
  myservo1.write(count6 * 36); 
  while(passflag != 1){
    unomode  = digitalRead(12);
     if(unomode ==0)
     {
      count6 = 0;
       break;
     }
     }
  passflag = 0;

  delay(100);
  }
  




  
  for (pos = 180; pos >= 0; pos -= 1) { 
      
    dis = analogRead(A0);
    disarray[pos] = dis;
    if(dis>300)
    {
      objectarray[pos] = 1;
    }
    if(dis<300)
    {
      objectarray[pos] = 0;
    }   
    myservo.write(pos);   
    delay(10);                      
  }
  arrayup = 0;
  objectcount = 0;
  maxobject = 0;
  maxpos = 0;

  temprap = i2can*36 - 15;
  while(temprap <= (i2can*36 + 15))
  {
    if(objectarray[temprap] == 1)
    {
      overwrite = 1;
    }
    temprap ++;
  }
  while(arrayup < 180)
  {
    xnumb = objectarray[arrayup];
   // Serial.println(arrayup);
  //  Serial.println(" B: ");
   // Serial.println(xnumb);
    if(xnumb == 0)
    {
      objectcount ++; 
    }
    if(xnumb == 1)
    {
      if(objectcount > maxobject)
      {
        maxobject = objectcount;
        maxpos = arrayup;
      }
      objectcount = 0;
    }
    arrayup ++;
  }
  if(arrayup >= 180 && objectcount > 0)
  {
       if(objectcount > maxobject)
      {
        maxobject = objectcount;
        maxpos = arrayup;
      }
      objectcount = 0;
  }
  //Serial.print("2. ");

  turnangle = maxpos - maxobject/2;
  //Serial.print("B a: ");
  //Serial.println(turnangle);
   
  //Serial.println(90-turnangle);
  if(maxobject<10)
  {
    re = 1;
    digitalWrite(8,HIGH);
    delay(800);
    digitalWrite(8,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    delay(500);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  //  Serial.print("MaxC: ");
   // Serial.println(maxobject);
    
  }
  if(unomode == 0)
  {
    overwrite = 1;
  }
  if(overwrite == 1)
  {
    Serial.println("i am here");
    if(((90-turnangle) < -20)&& (re == 0))
    {
      if(rightflag != 3)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(6*(turnangle-90));
        Serial.print("2 left: ");
        Serial.println(turnangle - 90);
        rightflag++;
      }
      else if(rightflag ==3 && leftflag ==2)
      {
        rightflag = 0;
        leftflag = 0;
        digitalWrite(8,HIGH);
        delay(800);
        digitalWrite(8,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(5*100);
        Serial.print("left: ");
        Serial.println(5*120);
      }else if(rightflag == 3 && leftflag != 2)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(6*(turnangle-90));
        //Serial.print("left: ");
        //Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }else if(rightflag !=2 && leftflag == 3)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        delay(6*(turnangle-90));
        Serial.print("left: ");
        Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }
     
    }
    else if(((90-turnangle) > 20) && (re == 0))
    {
     if(leftflag!=3)
     {
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(6*(90-turnangle));
        Serial.print("2 right: ");
        Serial.println(turnangle - 90);
        leftflag++;
     }
     else if(leftflag ==3 && rightflag == 2)
     {
        digitalWrite(8,HIGH);
        delay(800);
        digitalWrite(8,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(5*100);
        Serial.print("right: ");
        Serial.println(5*45);
        leftflag = 0;
        rightflag = 0;
     }else if(rightflag == 3 && leftflag != 2)
      {
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(6*(90-turnangle));
        Serial.print("right: ");
        Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }else if(rightflag !=2 && leftflag == 3)
      {
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        delay(6*(90-turnangle));
        Serial.print("right: ");
        Serial.println(turnangle - 90);
        rightflag = 0;
        leftflag = 0;
      }
    }
    else if(re == 0)
    {
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(150);
     digitalWrite(6,LOW);
     digitalWrite(7,HIGH);
     delay(10);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(150);
     Serial.println("GO ");
     leftflag = 0;
     rightflag = 0;

    }
  }
   if(overwrite == 0)
   {
    if((90-i2can*36)<0)
    {
       digitalWrite(6,HIGH);
       digitalWrite(7,LOW);
       delay(7*(i2can*36-90));
       Serial.print("Go i 2 left  : ");
       Serial.println(7*(i2can*36-90));
    }else if((90-i2can*36)>0)
    {
       digitalWrite(6,LOW);
       digitalWrite(7,HIGH);
       delay(10*(90-i2can*36));
       Serial.print("Go i 2 right  : ");
       Serial.println(5*(90 - i2can*36));
    }
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(250);
     digitalWrite(6,LOW);
     digitalWrite(7,HIGH);
     delay(10);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(250);
   }
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   re = 0;
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  posrap = Wire.read();    // receive byte as an integer
  Serial.print (count6 * 36);
  Serial.print (": ");
  Serial.println(posrap);
  
  // print the integer
  array2c[count6] = posrap;
  if(posrap!=0){
   if(count6 == 5 || count6 == 0)
    {
      i2cmaxpos = 300;
      i2c = 0;
      while(i2c<6)
      {
        if(i2cmaxpos>array2c[i2c])
        {
          i2cmaxpos = array2c[i2c];
          i2can = i2c;
        }
        
        i2c++;
      }
       Serial.println("Target is at ");
       Serial.println(i2can*36);
       passflag = 1;
    }
  
    if(count6f == 0)
  {
    if(count6 == 4)
    {
      count6f = 1;
    }
    count6 ++;
    if(count6 == 7)
    {
      i2cmaxpos = 300;
      i2c = 0;
      while(i2c<6)
      {
        if(i2cmaxpos>array2c[i2c])
        {
          i2cmaxpos = array2c[i2c];
          i2can = i2c;
        }
        
        i2c++;
      }
      Serial.println("Target is at ");
       Serial.println(i2can*36);
       
    }
 
 
  }else if(count6f == 1)
  {
    if(count6 == 1)
    {
      count6f = 0;
    }
    count6 --;
    if(count6 == 8)
    {
      i2cmaxpos = 300;
      i2c = 0;
      while(i2c<6)
      {
        if(i2cmaxpos>array2c[i2c])
        {
          i2cmaxpos = array2c[i2c];
          i2can = i2c;
        }
        i2c++;
      }
      Serial.println("Target is at ");
      Serial.println(i2can*36);
    }


  }
}
}






