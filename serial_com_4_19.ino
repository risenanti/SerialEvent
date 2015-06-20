
byte pins[] = {
  2, 4, 6, 7, 8, 9, 10, 12};
int g=0,f=0,d=0;
int val=0;
int *p=&val, *neu=&g,*fet=&f;

byte matrix[3][3];


void setup(){

  Serial.begin(9600);
  for (int i=0;i<3;i++)
  {
    pinMode(pins[i],OUTPUT);
    digitalWrite(pins[i], LOW);
  }
  for (int k=0;k<3;k++){
    for (int j=0;j<3;j++){
	  matrix[k][j]=0;
  }}
  
}


void loop()
{
	
if (Serial.available()){    //checks for serial information
*p = Serial.read();         //pointer to val
//Serial.println(val);
if (g>=3) g=(0);f++;
if (f>=3) f=(0);
matrix[*fet][*neu]=val;          //*fet pointer to f      *neu = pointer to g
Serial.println(matrix[0][0]);
//Serial.println(matrix[f][g]); 
//Serial.println(val);
g++;}
	//Serial.println(matrix[2][2]);
    if (matrix[2][2]>0){
		for (int k=0;k<3;k++){
		for (int j=0;j<3;j++){
		displayBinary(matrix[k][j]);
		Serial.println(matrix[k][j]);
	}}}
}

       

void displayBinary(byte binary)
{
  for (int j =0;j<8;j++)
  {
    if (bitRead(binary, j)==1)
    {
      digitalWrite(pins[j], HIGH); 
    }
    else
    {
      digitalWrite(pins[j], LOW); 
    }
  }
  delay(500);
}

