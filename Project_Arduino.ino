void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode leds
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  //pinMode botões
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  //pinMode buzzers
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int botao_apertado2 = digitalRead(2);
  int botao_apertado3 = digitalRead(3);
  int botao_apertado4 = digitalRead(4);

  int musica = 1;
  int musica_selecionada = 0;
  int apertou = false;
  int selecao = false;

  Serial.print("Bem vindo ao Project Arduino!");
  delay(2000);
  Serial.print("\nAperte o botão do meio para iniciar");

  while(botao_apertado3 == LOW){
    botao_apertado3 = digitalRead(3);
  }

  Serial.print("\n \nAperte os botões da esquerda e da direita para trocar de música");
  delay(1000);

  while(selecao != true){
    if(musica > 5){
      musica = 1;
    }
    else if(musica < 1){
      musica = 5;
    }

    if(musica == 1){
      Serial.print("\nInochi no Tabekata - Eve");
    }

    if(musica == 2){
      Serial.print("\nThrough the fires and flames - Dragonforce");
    }
    
    if(musica == 3){
      Serial.print("\nRadioactive - Imagine Dragons");
    }

    if(musica == 4){
      Serial.print("\n\"Forbidden\" - D'espairsRays");
    }

    if(musica == 5){
      Serial.print("Musica da Sarah");
    }

    apertou = false;
    while(apertou != true){
      if(botao_apertado2 == HIGH){
        musica--;
        apertou = true;
      }
      if(botao_apertado3 == HIGH){
        musica_selecionada = musica;
        selecao = true;
        apertou = true;
      }
      if(botao_apertado4 == HIGH){
        musica++;
        apertou = true;
      }
    }
  }
}
