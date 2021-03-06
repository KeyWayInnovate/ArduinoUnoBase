/***********************************************************************
 *       __                                                             
 *      / /        _____  __    __  _          _       __      __    __ 
 *     / /____   / _____) \ \  / / | |   __   | |     /  \     \ \  / / 
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |    / /\ \     \ \/ /  
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |   / /__\ \     \  /   
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  / /----\ \    / /    
 * /_/    \___\  \______)  /_/      \__/    \__/  /_/      \_\  / /     
 *                                                             /_/      
 *                                        
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020 
 *
 * This program is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the 
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. 
 *
 *
 * [Title]     Adjust LED Brightness by photoconductive resistance 
 * [diagram] 
 *            Arduino  pin0  ===================   photoconductive
 *      
 */
int  ADPIN  = 0  ;   
int  LEDPIN = 13 ;  
int  value = 0 ;  
float voltage = 0.0 ;
void setup()
{
    pinMode(LEDPIN,OUTPUT);   
    Serial.begin(115200);    //Serial Baud rate is 115200
}
void loop()
{
    value =  analogRead(ADPIN);      
    voltage = ( ( float )value )/1023 ;
    value = (int)voltage * 256 ;              //convert voltage to value
    analogWrite(LEDPIN,value);
    delay(1000);
}