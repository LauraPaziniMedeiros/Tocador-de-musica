#include <LiquidCrystal_I2C.h>

#define caracteres 16
#define linhas     2
#define btnFrente 7
#define btnVoltar  8
#define btnTocar 6
String musica1 = "Persona";
String musica2 = "Ode a alegria";
String musica3 = "Skyrim";
String musica4 = "Marcha";
String musica5 = "Deltarune";
int qualMusica = 1;
int contador = 0;

bool btnFrentePressed = false;
bool btnVoltarPressed = false;

#define buzzer 9
#define verm 10
#define verde 11
#define azul 12

//----Direitos Autorais de André Terada--------
//Define as notas do0 até si4

/*  C = Do
	D = Re
	E = Mi
	F = Fa
	G = Sol
	A = La
	B = Si   */	

#define c0 32.703194
#define cs0 34.647823
#define d0 36.708096
#define ds0 38.890873
#define e0 41.203442
#define f0 43.653526
#define fs0 46.249302
#define g0 48.999424
#define gs0 51.91309
#define a0 55
#define as0 58.270466
#define b0 61.735416  

#define c1 65.40638
#define cs1 69.295647
#define d1 73.416199
#define ds1 77.781746
#define e1 82.406876
#define f1 87.307053
#define fs1 92.498604
#define g1 97.998848
#define gs1 103.82618
#define a1 110
#define as1 116.540947
#define b1 123.470818

#define c2 130.812775
#define cs2 138.591324
#define d2 146.832367
#define ds2 155.563492
#define e2 164.813782
#define f2 174.614105
#define fs2 184.997208
#define g2 195.997711
#define gs2 207.652344
#define a2 220
#define as2 233.081848
#define b2 246.941635

#define c3 261.625519
#define cs3 277.182648
#define d3 293.664734
#define ds3 311.126984
#define e3 329.627533
#define f3 349.228241
#define fs3 369.994385  
#define g3 391.995392
#define gs3 415.304688  
#define a3 440
#define as3 466.163788
#define b3 493.883301

#define c4 523.251099
#define cs4 554.365234
#define d4 587.329529
#define ds4 622.253906
#define e4 659.255127
#define f4 698.456482
#define fs4 739.988831
#define g4 783.990845
#define gs4 830.609375
#define a4 880
#define as4 932.327576
#define b4 987.766602

#define c5 1047
#define d5 1175

//-------------------------------------------

LiquidCrystal_I2C lcd(0X27, caracteres, linhas);

void setup()
{
  pinMode(btnFrente, INPUT_PULLUP);
  pinMode(btnVoltar, INPUT_PULLUP); // Adiciona um pinMode para 
  pinMode(btnTocar, INPUT_PULLUP); // os botões e para
  pinMode(buzzer, OUTPUT);        // o buzzer
  lcd.init();
  lcd.begin(caracteres, linhas);
  lcd.setBacklight(HIGH);
  delay(100); 
  lcd.clear();  // limpa o display
  lcd.setCursor(0,0);
  lcd.print("Musica:");
  lcd.setCursor(0,1);
  lcd.print("-> " + musica1);
  pinMode(verm, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  Inicio();
}

void loop()
{
  if (digitalRead(btnVoltar) == LOW && !btnVoltarPressed)
  {
    btnVoltarPressed = true;  
    if (qualMusica != 1)
    {
      qualMusica--;
    }
    else
    {
      qualMusica = 5;
    }
    display();
  }
  else 
    if (digitalRead(btnVoltar) == HIGH)
      btnVoltarPressed = false; 
  if (digitalRead(btnFrente) == LOW && !btnFrentePressed)
  {
    btnFrentePressed = true;
    if (qualMusica != 5)
    {
      qualMusica++;
    }
    else
    {
      qualMusica = 1;
    }
    display();
  }
  else
    if (digitalRead(btnFrente) == HIGH)
      btnFrentePressed = false;
  
  if (digitalRead(btnTocar) == LOW) // Verifica se o btnTocar
  {                 // foi apertado
    switch (qualMusica)
    {
      case 1: Persona(); break;
      case 2: Ode(); break;
      case 3: Skyrim(); break;
      case 4: Marcha(); break;
      case 5: Deltarune(); break;
    }
  }
}

void display()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Musica:");
  lcd.setCursor(0,1);
  lcd.print("-> ");
  switch (qualMusica)
  {
    case 1: lcd.print(musica1); break;
    case 2: lcd.print(musica2); break;
    case 3: lcd.print(musica3); break;
    case 4: lcd.print(musica4); break;
    case 5: lcd.print(musica5); break;
  }
}

void Inicio()
{
  tocar2(as4, 333);
  tocar2(a4, 166);
  tocar2(f4, 166);
  tocar2(g4, 166);
  tocar2(d5, 166);
  tocar2(c5, 333);
}

void Persona()
{            
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(f4, 750, 800);
  tocar(e4, 100, 150);
  tocar(c4, 100, 150);
  tocar(b3, 100, 150);
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(b3, 250, 300);
  tocar(c4, 250, 300);
  tocar(e4, 250, 300);
  tocar(f4, 750, 1000);
  tocar(e4, 1000, 1050);
  tocar(c4, 300, 350);
  tocar(e4, 300, 350);
  tocar(b3, 1000, 1050);
  tocar(b3, 150, 200);
  tocar(c4, 150, 200);
  tocar(e4, 1000, 1050);
  tocar(c4, 200, 250);
  tocar(f4, 400, 450);
  tocar(b3, 150, 200);
  tocar(g3, 900, 2000);
}
  
void Ode()
{
  tocar(a3, 500, 500);
  tocar(a3, 500, 500);
  tocar(b3, 500, 500);
  tocar(g3, 500, 500);
  tocar(a3, 500, 500);
  tocar(b3, 500, 200);
  tocar(c4, 500, 300);
  tocar(b3, 500, 500);
  tocar(g3, 500, 500);
  tocar(a3, 500, 500);
  tocar(b3, 500, 200);
  tocar(c4, 500, 300);
  tocar(b3, 500, 500);
  tocar(a3, 500, 500);
  tocar(g3, 500, 500);
  tocar(a3, 500, 500);
  tocar(g3, 500, 300);
  tocar(g3, 1000, 2000);
}

void Skyrim()
{ 
  tocar2(cs4, 750);
  tocar2(d4, 125);
  tocar2(cs4, 125);
  tocar2(d3, 500);
  tocar2(d3, 125);
  tocar2(cs3, 125);
  tocar2(d3, 500);
  tocar2(d3, 125);
  tocar2(cs3, 125);
  tocar2(e3, 250);
  tocar2(d3, 250);
  tocar2(cs3, 250);
  tocar2(b2, 500);
  tocar2(b2, 125);
  tocar2(a2, 125);
  tocar2(b2, 500);
  tocar2(b2, 125);
  tocar2(a2, 125);
  tocar2(b2, 500);
  tocar2(a2, 125);
  tocar2(b2, 125);
  tocar2(cs3, 250);
  tocar2(d3, 250);
  tocar2(a2, 250);
  tocar2(b2, 500);
  tocar2(d3, 125);
  tocar2(cs3, 125);
  tocar2(d3, 500);
  tocar2(d3, 125);
  tocar2(cs3, 125);
  tocar2(d3, 500);
  tocar2(cs3, 125);
  tocar2(d3, 125);
  tocar2(e3, 250);
  tocar2(d3, 250);
  tocar2(cs3, 250);
  tocar2(b2, 500);
  tocar2(b2, 125);
  tocar2(a2, 125);
  tocar2(b2, 500);
  tocar2(b2, 125);
  tocar2(a2, 125);
  tocar2(b2, 500);
  tocar2(a2, 125);
  tocar2(b2, 125);
  tocar2(cs3, 250);
  tocar2(d3, 250);
  tocar2(a2, 250);
  tocar2(b2, 750);
}

void Marcha()
{
  tocar2(g1/4, 500);
  tocar2(g1/4, 500);
  tocar2(g1/4, 500);
  tocar2(f3/4, 350);
  tocar2(c4/4, 150);
  tocar2(g1/4, 500);
  tocar2(f3/4, 350);
  tocar2(c4/4, 150);
  tocar2(g1/4, 650);
   
  delay(500);
   
  tocar2(e4/4, 500);
  tocar2(e4/4, 500);
  tocar2(e4/4, 500);
  tocar2(f4/4, 350);
  tocar2(f4/4, 150);
  tocar2(gs3/4, 500);
  tocar2(f3/4, 350);
  tocar2(c4/4, 150);
  tocar2(g1/4, 650);

  delay(500);
}

void Deltarune()
{
  tocar2(a3, 100);
  tocar2(gs3, 100);
  tocar2(a3, 100);
  tocar2(c4, 100);
  tocar2(a3, 100);
  tocar2(gs3, 100);
  tocar2(a3, 100);
  tocar2(e4, 800);
  tocar2(d4, 100);
  tocar2(c4, 100);
  tocar2(b3, 100);
  tocar2(c4, 100);
  tocar2(d4, 100);
  tocar2(g4, 100);
  tocar2(f4, 100);
  tocar2(e4, 800);
  tocar2(d4, 100);
  tocar2(c4, 100);
  tocar2(b3, 100);
  tocar2(c4, 100);
  tocar2(d4, 100);
  tocar2(g4, 100);
  tocar2(f4, 100);
  tocar2(e4, 400);
  tocar2(d4, 400);
  tocar2(e4, 600);
  tocar2(d4, 100);
  tocar2(c4, 100);
  tocar2(b3, 400);
  tocar2(d4, 400);
  tocar2(e4, 200);
  tocar2(d4, 100);
  tocar2(e4, 500);
  tocar2(d4, 200);
  tocar2(c4, 100);
  tocar2(d4, 200);
  tocar2(g3, 100);
  tocar2(a3, 100);
  tocar2(b3, 100);
  tocar2(c4, 200);
  tocar2(b3, 100);
  tocar2(c4, 300);
  tocar2(a3, 200);
  tocar2(b3, 200);
  tocar2(a3, 100);
  tocar2(gs3, 300);
  tocar2(b3, 200);
  tocar2(c4, 300);
  tocar2(b3, 300);
  tocar2(a3, 1000);
  tocar2(a3, 800);
  tocar2(gs3, 800);
}
void tocar(float nota, int duracao, int delays)
{
  contarIteracao();
  tone(buzzer, nota, duracao);
  delay(delays);
  apagarLeds();
}

void tocar2(float nota, int delays)
{
  contarIteracao();
  tone(buzzer, nota);
  delay(delays);
  noTone(buzzer);
  apagarLeds();
}

void cor1()
{
  digitalWrite(verm, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);
}

void cor2()
{
  digitalWrite(verm, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(azul, LOW);
}

void cor3()
{
  digitalWrite(verm, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, HIGH);
}

void cor4()
{
  digitalWrite(verm, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(azul, LOW);
}

void cor5()
{
  digitalWrite(verm, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(azul, HIGH);
}

void cor6()
{
  digitalWrite(verm, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(azul, HIGH);
}

void cor7()
{
  digitalWrite(verm, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(azul, HIGH);
}

void apagarLeds()
{
  digitalWrite(verm, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);
}

void contarIteracao()
{
  if (contador >= 8)
  {
    contador = 1;
  }
  switch (contador)
  {
    case 1: cor1(); break;
    case 2: cor2(); break;
    case 3: cor3(); break;
    case 4: cor4(); break;
    case 5: cor5(); break;
    case 6: cor6(); break;
    case 7: cor7(); break;
  }
  contador++;
}