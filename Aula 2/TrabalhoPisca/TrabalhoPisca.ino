//Trabalho 1: Pisca

#define BUT1_PIN 7
#define BUT2_PIN 8
#define LED_PIN 13

int estado;
unsigned long tpisca = 1000;
unsigned long t;
unsigned long t1;
bool pressionadob1;
bool pressionadob2;

void estado1(unsigned long atual) {
  digitalWrite (LED_PIN,HIGH);
  t= atual;
  estado=1;
}

void estado2(unsigned long atual) {
  digitalWrite (LED_PIN,LOW);
  t= atual;
  estado=2;
}

void estado3(unsigned long atual) {
  digitalWrite (LED_PIN,HIGH);
  t= atual;
  t1= atual;
  estado=3;
}

void estado4(unsigned long atual){
  digitalWrite (LED_PIN,LOW);
  t= atual;
  t1= atual;
  estado=4;
}

void estado5(unsigned long atual) {
  digitalWrite (LED_PIN,HIGH);
  t= atual;
  t1= atual;
  estado=5;
}

void estado6(unsigned long atual) {
  digitalWrite (LED_PIN,LOW);
  t= atual;
  t1= atual;
  estado=6;
}

void estado7 (void) {
  digitalWrite (LED_PIN,HIGH);
  estado=7;
}

void estado8 (void){
  digitalWrite (LED_PIN,LOW);
  estado=8;
}

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_PIN,OUTPUT);     // Enable pin 13 for digital output
  pinMode(BUT1_PIN,INPUT);      // Enable pin 6 for digital input
  pinMode(BUT2_PIN,INPUT);       // Enable pin 7 for digital input
  estado1(millis());
  //tpisca=1000;
  t = 0;
  t1 = 0;
  pressionadob1 = false;
  pressionadob2 = false;
}

void loop() {
  int but1 = digitalRead(BUT1_PIN); //Le o estado do botao 1
  int but2 = digitalRead(BUT2_PIN); //Le o estado do botao 2
  unsigned long atual = millis();
  
  Serial.print(but1);
  Serial.print("   ");
  Serial.print(but2);
  Serial.print("   ");
  Serial.print(estado);
  Serial.print("   ");
  Serial.println(tpisca);
  
  switch (estado)
  {
    case 1:
    if ((atual-t) >= tpisca)
    {
      estado2(atual);
    }
    else if (but1 && pressionadob1 == false)
    {
      pressionadob1 = true;
      estado3(atual);
    }
    else if (but2 && pressionadob2 == false)
    {
      pressionadob2 = true;
      estado5(atual);
    }   
    else if (!but1 && pressionadob1 == true)
    { 
      pressionadob1 = false; 
    }
    else if (!but2 && pressionadob2 == true)
    {
      pressionadob2 = false;
    }
    break;

    case 2:
    if ((atual-t)>=tpisca)
    {
      estado1(atual);
    }
    else if (but1 && pressionadob1==false)
    {
      pressionadob1 = true;
      estado4(atual);
    }
    else if (but2 && pressionadob2==false)
    {
      pressionadob2 = true;
      estado6(atual);
    }
    else if (!but1 && pressionadob1==true)
    { 
      pressionadob1 = false; 
    }
    else if (!but2 && pressionadob2==true)
    {
      pressionadob2 = false;
    }
    break;

    case 3:
    if ((atual-t) >= tpisca)
    {
      estado4(atual);
    }
    else if((atual-t1) >= 500)
    {
      estado1(atual);
    }
    else if (!but1)
    {
      tpisca += 200;
      pressionadob1 = false;
      estado1(atual);
    }
    else if (but2)
    {
      estado7();
    }
    break;

    case 4: 
    if ((atual-t) >= tpisca)
    {
      estado3(atual);
    }
    else if ((atual-t1) >= 500)
    {
      estado2(atual);
    }
    else if (!but1)
    {
      tpisca += 200;
      pressionadob1 = false;
      estado2(atual);
    }
    else if(but2)
    {
      estado8();
    }
    break;

    case 5:
    if ((atual-t) >= tpisca)
    {
      estado6(atual);
    }
    else if ((atual-t1) >= 500)
    {
      estado1(atual);
    }
    else if (!but2)
    {
      if(tpisca >=400)
        tpisca -= 200;
      pressionadob2 = false;
      estado1(atual);
    }
    else if(but1)
    {
      estado7();
    }
    break;

    case 6:
    if ((atual-t) >= tpisca)
    {
      estado5(atual);
    }
    else if ((atual-t1) >= 500)
    {
      estado2(atual);
    }
    else if (!but2)
    {
      if(tpisca >=400)
        tpisca -= 200;
      pressionadob2 = false;
      estado2(atual);
    }
    else if(but1)
    {
      estado8();
    }
    break;
    
  }

}
