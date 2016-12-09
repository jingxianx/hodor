#include <Servo.h>
#include"controller.h"
int HappyBirthday[] = { NOTE_G3,NOTE_G3,NOTE_A3,NOTE_G3,NOTE_C4,NOTE_B3,NOTE_G3,NOTE_G3,NOTE_A3,NOTE_G3,NOTE_D4,NOTE_C4,NOTE_G3,NOTE_G3,NOTE_G4,NOTE_E4,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_D4,NOTE_C4};
int HBD[]={2,2,4,4,4,8,2,2,4,4,4,8,2,2,4,4,4,4,8,2,2,4,4,4,8};

int AmazingGrace[] = { NOTE_G3,NOTE_C4,NOTE_E4,NOTE_C4,NOTE_E4,NOTE_D4,NOTE_C4,NOTE_A3,NOTE_G3,NOTE_G3,NOTE_C4,NOTE_E4,NOTE_C4,NOTE_E4,NOTE_D4,NOTE_G4,NOTE_E4,NOTE_G4,NOTE_E4,NOTE_G4,NOTE_E4,NOTE_C4,NOTE_G3,NOTE_A3,NOTE_C4,NOTE_C4,NOTE_A3,NOTE_G3,NOTE_G3, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_D4 ,NOTE_C4};
int AGD[]={4,8, 2,2,8,4,8,4,8,4,8,2,2,8,4,20,4,6,2,2,2,8,4,6,2,2,2,8,4,8,2,2,8,4,12};

int GraceThyFaithful[] = { NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4 ,NOTE_C5,NOTE_C5,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_F4,NOTE_B3,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_D4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_A4,NOTE_A4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_C5,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_F4,NOTE_B3,NOTE_C4 };
int GTD[]={4,4,4,6,2,4,4,6,2,4,8,4,4,4,6,2,4,4,4,4,12,4,4,4,6,2,4,4,4,4,4,8,4,4,4,6,2,4,4,4,4,12,4,4,4,3,1,8,4,4,4,3,1,8,4,4,4,4,4,4,4,4,4,12,4,4,4,6,2,4,4,4,4,4,8,4,4,4,6,2,4,4,4,4,12};

int small[] = { NOTE_E3,NOTE_F3,NOTE_G3,NOTE_E4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_C4,NOTE_B3,NOTE_B3,NOTE_D3,NOTE_E3,NOTE_F3,NOTE_D4,NOTE_B3,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G3,NOTE_G3,NOTE_E3,NOTE_F3,NOTE_G3,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_C4,NOTE_A3, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4 ,NOTE_G3,NOTE_F4 ,NOTE_E4 ,NOTE_D4 ,NOTE_C4 ,NOTE_C4 ,NOTE_C4 ,NOTE_E4 ,NOTE_C4 ,NOTE_D4 ,NOTE_D4 ,NOTE_D4 ,NOTE_D4 ,NOTE_D4 ,NOTE_F4 ,NOTE_D4 ,NOTE_E4 ,NOTE_E4 ,NOTE_E4 ,NOTE_E4 ,NOTE_E4 ,NOTE_G4 ,NOTE_E4 ,NOTE_F4 ,NOTE_F4 ,NOTE_F4 ,NOTE_E4 ,NOTE_D4 ,NOTE_G3 ,NOTE_B3 ,NOTE_C4};
int MFD[]={2,2,4,4,4,2,2,4,4,4,2,2,4,4,4,2,2,4,4,4,2,2,4,2,2,4,2,2,4,2,2,4,2,2,4,4,4,4,16,6,2,4,4,6,2,8,6,2,4,4,6,2,8,6,2,4,4,6,2,4,2,2,8,8,12};
int spinin = 0;
int push1f = 0;
int push1d = 0;
int push2f = 0;
int push2d = 0;
int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int pmc = 0;
int pmw = 0;
int posi = 0;  
int serflag = 0;
char Tcom = '0';
int  Ticom = 0;
int  T_dis = 0;
int  T_pos = 0;
int  countl = 0;
int  countr = 0; 
int  m_en = 1;
int  in8 = 0;
int  in9 = 0;
int in10 = 0;

int interf1f = 0;
int interf1c = 0;
int interf1e = 0;

Servo myservo; 
#define lcdreg 22
#define lcdRnW 23
#define lcdclk 24
#define lcdd0 25
#define lcdd1 26
#define lcdd2 27
#define lcdd3 28
#define lcdd4 29
#define lcdd5 30
#define lcdd6 31
#define lcdd7 32




int clo = 0;
int flag = 0;
int dis = 0;


int clo2 = 0;
int flag2 = 0;
int dis2 = 0;





void setup() {
  // put your setup code here, to run once:

  pmc = 50;
  pmw = 100/pmc;
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(45, INPUT);
  pinMode(42, INPUT);
  pinMode(33, INPUT);
  pinMode(lcdreg, OUTPUT);
  pinMode(lcdRnW, OUTPUT);
  pinMode(lcdclk, OUTPUT);
  pinMode(lcdd0, OUTPUT);
  pinMode(lcdd1, OUTPUT);
  pinMode(lcdd2, OUTPUT);
  pinMode(lcdd3, OUTPUT);
  pinMode(lcdd4, OUTPUT);
  pinMode(lcdd5, OUTPUT);
  pinMode(lcdd6, OUTPUT);
  pinMode(lcdd7, OUTPUT);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
  pinMode(36,INPUT);
  pinMode(37,INPUT);
  pinMode(38,INPUT);
  pinMode(40,OUTPUT);

  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  

  
  twolinelcdinit();
  changeline(1);
  myservo.attach(12); 



}

void loop() {
    push1d = digitalRead(45);
    if(push1d == 1 && push1f == 0)
    {
      
      push1f = 1;
      if(interf1f == 3)
      {
        interf1f = 0;
      }
      else
      {
        interf1f++;
      }
      
    }
    push1f = digitalRead(45);
    push2d = digitalRead(42);
    if(push2d == 1 && push2f == 0)
    {
      
      push2f = 1;
      interf1e = 1;
     
    }
    push2f = digitalRead(42);


    
    spinin = analogRead(A1);
    //Serial.println(spinin);
    delay(20);
    digitalWrite(40,LOW);
    if(interf1f == 0)
    {
      changeline(1);
      lcdstr("1. RF Control <-   ");
      changeline(2);
      lcdstr("2. Auto-pilot      ");
      changeline(3);
      lcdstr("3. Self-Destruct   ");
      changeline(4);
      lcdstr("4. Auto Pilot(s)   ");
    }
    else if(interf1f == 1)
    {
      changeline(1);
      lcdstr("1. RF Control      ");
      changeline(2);
      lcdstr("2. Auto-pilot <-   ");
      changeline(3);
      lcdstr("3. Self-Destruct   ");
      changeline(4);
      lcdstr("4. Auto Pilot(s)   ");
    }
    else if(interf1f == 2)
    {
      changeline(1);
      lcdstr("1. RF Control      ");
      changeline(2);
      lcdstr("2. Auto-pilot      ");
      changeline(3);
      lcdstr("3. Self-Destruct <-");
      changeline(4);
      lcdstr("4. Auto Pilot(s)   ");
    }
    else if(interf1f == 3)
    {
      changeline(1);
      lcdstr("1. RF Control      ");
      changeline(2);
      lcdstr("2. Auto-pilot      ");
      changeline(3);
      lcdstr("3. Self-Destruct   ");
      changeline(4);
      lcdstr("4. Auto Pilot(s)<- ");
    }
    if(interf1e == 1)
    {
      if(interf1f ==0)
      {
        interf1e =0;
        manc();
      }else if(interf1f == 1)
      {
        interf1e = 0;
        autopilot();
      }else if(interf1f == 2)
      {
        interf1e = 0;
        selfd();
      }else if(interf1f == 3)
      {
        interf1e = 0;
        autopilots();
      }
    }
 
}

void sendint(int x)
{
  int snum = 0;
  int lo = 0;
  char se = '0';
  int smo = 0;
  int nmo = 1;
  snum = x;
  while((snum/10)>0)
  {
    snum = snum/10;
    lo ++;
  }
  snum = x;
  while(lo>=0)
  {
    smo = lo;
    while(smo>0)
    {
      nmo = nmo*10;
      smo--;
    }
    //Serial.println(nmo);
    se = (snum/nmo)%10 + 48;
    nmo = 1;
    sendchar(se);

    lo--;

  }
  
}





void twolinelcdinit(){


  
  delay(1000);  
  digitalWrite(lcdreg, LOW); 
  digitalWrite(lcdRnW, LOW); 
  digitalWrite(lcdclk, HIGH); 
  delay(1000);


  digitalWrite(lcdd0, HIGH); 
  digitalWrite(lcdd1, HIGH); 
  digitalWrite(lcdd2, HIGH); 
  digitalWrite(lcdd3, HIGH); 
  digitalWrite(lcdd4, LOW); 
  digitalWrite(lcdd5, LOW); 
  digitalWrite(lcdd6, LOW);
  digitalWrite(lcdd7, LOW); 

  digitalWrite(lcdclk, LOW);
  digitalWrite(lcdclk, HIGH);
  delay(100); 
  lcdclr();




  digitalWrite(lcdd0, LOW); 
  digitalWrite(lcdd1, LOW); 
  digitalWrite(lcdd2, LOW); 
  digitalWrite(lcdd3, HIGH); 
  digitalWrite(lcdd4, HIGH); 
  digitalWrite(lcdd5, HIGH); 
  digitalWrite(lcdd6, LOW);
  digitalWrite(lcdd7, LOW); 

  digitalWrite(lcdclk, LOW); 
  digitalWrite(lcdclk, HIGH);
  delay(100); 


  digitalWrite(lcdd0, LOW); 
  digitalWrite(lcdd1, LOW); 
  digitalWrite(lcdd2, LOW); 
  digitalWrite(lcdd3, LOW); 
  digitalWrite(lcdd4, LOW); 
  digitalWrite(lcdd5, LOW); 
  digitalWrite(lcdd6, LOW);
  digitalWrite(lcdd7, HIGH); 
  digitalWrite(lcdclk, LOW); 
  digitalWrite(lcdclk, HIGH);
  delay(100);  
}

void lcdclr(){

  digitalWrite(lcdd0, HIGH); 
  digitalWrite(lcdd1, LOW); 
  digitalWrite(lcdd2, LOW); 
  digitalWrite(lcdd3, LOW); 
  digitalWrite(lcdd4, LOW); 
  digitalWrite(lcdd5, LOW); 
  digitalWrite(lcdd6, LOW);
  digitalWrite(lcdd7, LOW); 
  delay(1);  
  digitalWrite(lcdclk, LOW);
  digitalWrite(lcdclk, HIGH);
  delay(1);   
}
void changeline(int x){
    digitalWrite(lcdd0, LOW); 
  digitalWrite(lcdd1, LOW); 
  digitalWrite(lcdd2, LOW); 
  digitalWrite(lcdd3, HIGH); 
  digitalWrite(lcdd4, HIGH); 
  digitalWrite(lcdd5, HIGH); 
  digitalWrite(lcdd6, LOW);
  digitalWrite(lcdd7, LOW); 

  digitalWrite(lcdclk, LOW); 
  digitalWrite(lcdclk, HIGH);
  delay(1); 

  if(x==1)
  {
      digitalWrite(lcdd0, LOW); 
      digitalWrite(lcdd1, LOW); 
      digitalWrite(lcdd2, LOW); 
      digitalWrite(lcdd3, LOW); 
      digitalWrite(lcdd4, LOW); 
      digitalWrite(lcdd5, LOW); 
      digitalWrite(lcdd6, LOW);
      digitalWrite(lcdd7, HIGH); 
      digitalWrite(lcdclk, LOW); 
      digitalWrite(lcdclk, HIGH);
      delay(1); 
    
  }
  if(x==2)
  {
      digitalWrite(lcdd0, LOW); 
      digitalWrite(lcdd1, LOW); 
      digitalWrite(lcdd2, LOW); 
      digitalWrite(lcdd3, LOW); 
      digitalWrite(lcdd4, LOW); 
      digitalWrite(lcdd5, LOW); 
      digitalWrite(lcdd6, HIGH);
      digitalWrite(lcdd7, HIGH); 
      digitalWrite(lcdclk, LOW); 
      digitalWrite(lcdclk, HIGH);
      delay(1); 
    
  }
  if(x==3)
  {
      digitalWrite(lcdd0, LOW); 
      digitalWrite(lcdd1, LOW); 
      digitalWrite(lcdd2, HIGH); 
      digitalWrite(lcdd3, LOW); 
      digitalWrite(lcdd4, HIGH); 
      digitalWrite(lcdd5, LOW); 
      digitalWrite(lcdd6, LOW);
      digitalWrite(lcdd7, HIGH); 
      digitalWrite(lcdclk, LOW); 
      digitalWrite(lcdclk, HIGH);
      delay(1); 
    
  }
  if(x==4)
  {
      digitalWrite(lcdd0, LOW); 
      digitalWrite(lcdd1, LOW); 
      digitalWrite(lcdd2, HIGH); 
      digitalWrite(lcdd3, LOW); 
      digitalWrite(lcdd4, HIGH); 
      digitalWrite(lcdd5, LOW); 
      digitalWrite(lcdd6, HIGH);
      digitalWrite(lcdd7, HIGH); 
      digitalWrite(lcdclk, LOW); 
      digitalWrite(lcdclk, HIGH);
      delay(1); 
    
  }

}


void sendchar(char x){
  int now=0;
  digitalWrite(lcdreg, HIGH);
  digitalWrite(lcdd0, LOW); 
  digitalWrite(lcdd1, LOW); 
  digitalWrite(lcdd2, LOW); 
  digitalWrite(lcdd3, LOW); 
  digitalWrite(lcdd4, LOW); 
  digitalWrite(lcdd5, LOW); 
  digitalWrite(lcdd6, LOW);
  digitalWrite(lcdd7, LOW); 
  now = x;
  if((now%2) == 1)
  {
    digitalWrite(lcdd0, HIGH);
  }
  now = now/2;
    if((now%2) == 1)
  {
    digitalWrite(lcdd1, HIGH);
  }
  now = now/2;
    if((now%2) == 1)
  {
    digitalWrite(lcdd2, HIGH);
  }
  now = now/2;
    if((now%2) == 1)
  {
    digitalWrite(lcdd3, HIGH);
  }
  now = now/2;
    if((now%2) == 1)
  {
    digitalWrite(lcdd4, HIGH);
  }
  now = now/2;
    if((now%2) == 1)
  {
    digitalWrite(lcdd5, HIGH);
  }
  now = now/2;
    if((now%2) == 1)
  {
    digitalWrite(lcdd6, HIGH);
  }
  now = now/2;
  if((now%2) == 1)
  {
    digitalWrite(lcdd7, HIGH);
  }
  digitalWrite(lcdclk, LOW); 
  digitalWrite(lcdclk, HIGH);
  delay(1);
  digitalWrite(lcdreg, LOW);
  
}

void selfd (void)
{
  lcdclr(); 
  int ii = 0;
  changeline(1);
  delay(1000);
  lcdstr("Self-destruct: STP");
  changeline(1);
  delay(2000);
  delay(1000);
  lcdstr("Self-destruct: ACT");
  tone(44, NOTE_E4, 1000);
  delay(1000);
  noTone(44);
  changeline(2);
  while(ii<=100)
  {
    delay(20);
    changeline(2);
    lcdstr("Short-Cir: ");
    sendint(ii);
    sendchar('%');
    lcdstr("  ");
    ii++;
  }
  tone(44, NOTE_E4, 1000);
  delay(1000);
  noTone(44);
  changeline(3);
  ii = 0;
  while(ii<=100)
  {
    delay(20);
    changeline(3);
    lcdstr("Batery-Overload:");
    sendint(ii);
    sendchar('%');
    ii++;
  }
  tone(44, NOTE_E4, 1000);
  delay(1000);
  noTone(44);
  changeline(4);
  ii = 10;
  while(ii>=0)
  {
    tone(44, NOTE_E2, 500);
    delay(1000);
    noTone(44);
    changeline(4);
    lcdstr("Destruction in: ");
    sendint(ii);
    lcdstr("  ");
    ii--;
  }
  tone(44, NOTE_E3, 2000);
  delay(3000);
  noTone(44);
  lcdclr();
  changeline(1);
  lcdstr("Just Kidding");
  changeline(2);
  lcdstr("Have a nice day");
  changeline(3);
  lcdstr("(_/-.-)_/");

  delay(5000);
  
  
}

void lcdstr(char x[])
{
  int i = 0;
  while( x[i] != '\0')
  {
    sendchar(x[i]);
    i++;
  }
}

void autopilot(void)
{
  lcdclr();
  changeline(1);
  lcdstr("Auto Pilot mode");
  push1d = 0;
  push1f = 0;
  delay(2000);
  while(1){
   a1 = digitalRead(34);
  a2 = digitalRead(35);
  a3 = digitalRead(36);
  a4 = digitalRead(37);
  clo = digitalRead(33);
  clo2 = digitalRead(38);
  in8 = digitalRead(8);
  in9 = digitalRead(9);
  in10 = digitalRead(10);

  m_en == 0;
  if(in8 == 1 && in9 == 1 && in10 == 0)
  {
    digitalWrite(49,HIGH);
    digitalWrite(52,HIGH);
    delay(1);
    digitalWrite(49,LOW);
    digitalWrite(52,LOW);
    delay(pmw);
    

    digitalWrite(53,LOW);
    digitalWrite(48,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW); 
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
  }
  else if(in8 == 1 && in9 == 0 && in10 == 0)
  {
    digitalWrite(48,HIGH);
    digitalWrite(52,HIGH);
    delay(1);

    digitalWrite(48,LOW);
    digitalWrite(52,LOW);
    delay(pmw);
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);

    digitalWrite(53,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW); 
  }
  else if(in8 == 0 && in9 == 1 && in10 == 0)
  {

    digitalWrite(53,HIGH);
    digitalWrite(49,HIGH);
    delay(1);
    digitalWrite(53,LOW);
    digitalWrite(49,LOW);
    delay(pmw);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
    digitalWrite(48,LOW);
    
  }
  else if(in8 == 0 && in9 == 0 && in10 == 0)
  {
    digitalWrite(48,LOW);
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);

    digitalWrite(53,LOW);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);

    
  }
  else if(in10 == 1)
  {
    digitalWrite(48,HIGH);
    digitalWrite(53,HIGH);
    delay(1);

    digitalWrite(48,LOW);
    digitalWrite(53,LOW);
    delay(pmw); 
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);
  }

  clo = digitalRead(33);
  clo2 = digitalRead(38);
  if((clo == 0) && (flag == 1) )
  {
    dis ++;
  }  
  flag = clo;
 
  if((clo2 == 0) && (flag2 == 1) )
  {
    dis2 ++;
  }
  flag2 = clo2;

  if(a1 == 1)
  {
    return;
  }
  }

}

void manc (void)
{
  lcdclr();
  changeline(1);
  lcdstr("RF Control Mod");
  push1d = 0;
  push1f = 0;
  delay(2000);
  while(1){
  a1 = digitalRead(34);
  a2 = digitalRead(35);
  a3 = digitalRead(36);
  a4 = digitalRead(37);
  if(a1 == 1 )
  {
    digitalWrite(53,HIGH);
    digitalWrite(49,HIGH);
    delay(1);
    digitalWrite(53,LOW);
    digitalWrite(49,LOW);
    delay(pmw);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
    digitalWrite(48,LOW);
  }else if(a2 == 1 )
  {
    digitalWrite(48,HIGH);
    digitalWrite(53,HIGH);
    delay(1);

    digitalWrite(48,LOW);
    digitalWrite(53,LOW);
    delay(pmw); 
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);    
  }else if(a3==1 )
  {
    digitalWrite(48,HIGH);
    digitalWrite(52,HIGH);
    delay(1);

    digitalWrite(48,LOW);
    digitalWrite(52,LOW);
    delay(pmw);
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);

    digitalWrite(53,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW); 
  }
  else if(a4==1 )
  {


     
  
    digitalWrite(49,HIGH);
    digitalWrite(52,HIGH);
    delay(1);
    digitalWrite(49,LOW);
    digitalWrite(52,LOW);
    delay(pmw);
    

    digitalWrite(53,LOW);
    digitalWrite(48,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW); 
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
  }
  else
  {
    digitalWrite(48,LOW);
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);

    digitalWrite(53,LOW);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);
  }

  push1d = digitalRead(45);
    if(push1d == 1 && push1f == 0)
    {
      
      push1f = 0;
      push1d = 0;
      return;
      
    }
    push1f = digitalRead(45);

  }
}
void autopilots(void)
{
  lcdclr();
  changeline(1);
  lcdstr("Auto Pilot(s) mode");
  push1d = 0;
  push1f = 0;
  delay(2000);
  digitalWrite(40,HIGH);
  while(1){
   a1 = digitalRead(34);
  a2 = digitalRead(35);
  a3 = digitalRead(36);
  a4 = digitalRead(37);
  clo = digitalRead(33);
  clo2 = digitalRead(38);
  in8 = digitalRead(8);
  in9 = digitalRead(9);
  in10 = digitalRead(10);

  m_en == 0;
  if(in8 == 1 && in9 == 1 && in10 == 0)
  {
    digitalWrite(49,HIGH);
    digitalWrite(52,HIGH);
    delay(1);
    digitalWrite(49,LOW);
    digitalWrite(52,LOW);
    delay(pmw);
    

    digitalWrite(53,LOW);
    digitalWrite(48,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW); 
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
  }
  else if(in8 == 1 && in9 == 0 && in10 == 0)
  {
    digitalWrite(48,HIGH);
    digitalWrite(52,HIGH);
    delay(1);

    digitalWrite(48,LOW);
    digitalWrite(52,LOW);
    delay(pmw);
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);

    digitalWrite(53,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW); 
  }
  else if(in8 == 0 && in9 == 1 && in10 == 0)
  {

    digitalWrite(53,HIGH);
    digitalWrite(49,HIGH);
    delay(1);
    digitalWrite(53,LOW);
    digitalWrite(49,LOW);
    delay(pmw);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
    digitalWrite(48,LOW);
    
  }
  else if(in8 == 0 && in9 == 0 && in10 == 0)
  {
    digitalWrite(48,LOW);
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);

    digitalWrite(53,LOW);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);

    
  }
  else if(in10 == 1)
  {
    digitalWrite(48,HIGH);
    digitalWrite(53,HIGH);
    delay(1);

    digitalWrite(48,LOW);
    digitalWrite(53,LOW);
    delay(pmw); 
    digitalWrite(49,LOW);
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
    digitalWrite(52,LOW);
    digitalWrite(51,LOW);
    digitalWrite(50,LOW);
  }

  clo = digitalRead(33);
  clo2 = digitalRead(38);
  if((clo == 0) && (flag == 1) )
  {
    dis ++;
  }  
  flag = clo;
 
  if((clo2 == 0) && (flag2 == 1) )
  {
    dis2 ++;
  }
  flag2 = clo2;

  if(a1 == 1)
  {
    return;
  }
  }

}





