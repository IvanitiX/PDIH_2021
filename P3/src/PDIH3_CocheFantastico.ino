const int PIN_INICIAL = 4;
const int NUM_PINES = 10;
int listaPines[NUM_PINES];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_PINES ; i++){
    listaPines[i] = PIN_INICIAL + i ;
    pinMode(listaPines[i],OUTPUT);
  }

}

void loop() {
  for (int i = 0; i < NUM_PINES; i++){
    for (int j = 0 ; j < NUM_PINES ; j++){
      (i == j) ? digitalWrite(listaPines[j],HIGH) : digitalWrite(listaPines[j],LOW) ;
      delay(20);
    }
  }
  for (int i = NUM_PINES - 1; i >= 0; i--){
    for (int j = NUM_PINES - 1 ; j >= 0 ; j--){
      (i == j) ? digitalWrite(listaPines[j],HIGH) : digitalWrite(listaPines[j],LOW) ;
      delay(20);
    }
  }
}
