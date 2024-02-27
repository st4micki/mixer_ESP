#include<math.h>
#define POT_COUNT 4
#define PERCENTAGE_ACCURACY 5
int adc[POT_COUNT] = {4, 34, 15, 2};
float percents[POT_COUNT] = {0};

float pots[POT_COUNT] = {0};
char buf[100];

typedef struct{
  float alpha;
  float outputs[4];
} EMA;

EMA filter = {0.25, {0}};


float filter_read(EMA *filter, float input, int index){
  filter->outputs[index] = filter->alpha * input + (1.0 - filter->alpha) * filter->outputs[index];
  return filter->outputs[index];
}


float format_read(float read) {
  float read_percent = (read/4095)*100;
  int read_mod = int(read_percent) % PERCENTAGE_ACCURACY;
  read_percent = floor(read_percent - read_mod)/100;
  return read_percent;
}




void setup() {
  Serial.begin(9600);
  
}

void loop() {
 strcpy(buf, "");
 for (int i = 0; i < POT_COUNT; i++){
   pots[i] = (float)analogRead(adc[i]);
   pots[i] = filter_read(&filter, pots[i], i);
   percents[i] = format_read(pots[i]);
 }

 sprintf(buf, "%.2f|%.2f|%.2f|%.2f", percents[0], percents[1], percents[2], percents[3]);
 Serial.println(buf);
 delay(50);
}
