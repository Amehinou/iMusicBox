// iM project is a DIY musicbox Power By R3
#include <SoftwareSerial.h>
#include "mp3TF.h"
#include <stdlib.h>


int volume = 12;
int button_left = 2;
int button_right = 3;
int button_M = 4;
int songNumber = 1;
int songList[6];
bool checkStop = false;


mp3TF iM = mp3TF ();

void unitSongList(int maxNumber, int minNumber){

	
	for (int i = 1; i <= 6; i++){
		randomSeed(analogRead(0));
		songList[i] = random(maxNumber, minNumber);
	}

}

void setup(){

	

	
	iM.init (&Serial);
	Serial.begin (9600);
	pinMode(2, INPUT);  //left +
	pinMode(3, INPUT);  //right _
	pinMode(4, INPUT);  //on M

	 
  	iM.setVolume (volume);
  	delay(500);
  	//mp3_folder(1);
  	iM.play(9);
  	
  	//iM.loopAllon ();

}


void loop(){
	if(digitalRead(button_left) == LOW && digitalRead(button_right) == LOW && digitalRead(button_M) == LOW){  // left right M | 
		//iM.playWithSakura(2);
		//iM.play(9063);
		//iM.loopAllon();
		//iM.play(10);
		delay(1000);
		if(digitalRead(button_left) == LOW && digitalRead(button_right) == LOW && digitalRead(button_M) == LOW){  //into sleep model
			iM.playWithSakura(2);
			delay(5000);	    
		}else{
			if (checkStop){
				iM.play();
				checkStop = false;
				}else{
					iM.pause();
					checkStop = true;
				}
		}
		//mp3_next();
	}else if(digitalRead(button_left) == LOW && digitalRead(button_right) == HIGH && digitalRead(button_M) == HIGH){
		delay(200);
		if(digitalRead(2) == LOW && digitalRead(3) == HIGH){
			volume = volume + 1;
			if(volume >= 20){
				volume = 20;   
			    }
			iM.setVolume(volume); 
		}   
	}else if(digitalRead(button_left) == HIGH && digitalRead(button_right) == LOW && digitalRead(button_M) == HIGH){
		delay(200);
		if(digitalRead(2) == HIGH && digitalRead(3) == LOW){
			volume = volume - 1;
			if(volume <= 1){
				volume = 1;   
			    }
			iM.setVolume(volume);
		}    
	}else if(digitalRead(button_left) == HIGH && digitalRead(button_right) == LOW && digitalRead(button_M) == LOW){			// right M | next
		//songNumber 
		//iM.next();
		iM.next();
		delay(100);   
	}


}