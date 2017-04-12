/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
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
 * [Title]     stepper motor  .
 * [Diagram]
 *         Arduino PIN 8   ===================  Stepper motor A
 *         Arduino PIN 9   ===================  Stepper motor B
 *         Arduino PIN 10  ===================  Stepper motor C
 *         Arduino PIN 11  ===================  Stepper motor D
 */
#define  STEPPER_MOTOR_A   8
#define  STEPPER_MOTOR_B   9
#define  STEPPER_MOTOR_C   10
#define  STEPPER_MOTOR_D   11

#define  STEPPER_MODE_4    4
#define  STEPPER_MODE_8    8
boolean StepperDir = 0;

int stepperSpeed = 3 ,CurrentStep = 0 ;  //set Stepper motor speed  delayms
int stepsum = 0 ;
void setup()
{
    pinMode(STEPPER_MOTOR_A, OUTPUT);
    pinMode(STEPPER_MOTOR_B, OUTPUT);
    pinMode(STEPPER_MOTOR_C, OUTPUT);
    pinMode(STEPPER_MOTOR_D, OUTPUT);
    Serial.begin(115200);
    Serial.println("Stepper Motor And Start :");
}

void loop()
{
    switch( CurrentStep )
    {
        case 0:
          digitalWrite(STEPPER_MOTOR_A, LOW);
          digitalWrite(STEPPER_MOTOR_B, HIGH);
          digitalWrite(STEPPER_MOTOR_C, HIGH);
          digitalWrite(STEPPER_MOTOR_D, HIGH);
        break;
        case 1:
          digitalWrite(STEPPER_MOTOR_A, LOW);
          digitalWrite(STEPPER_MOTOR_B, LOW);
          digitalWrite(STEPPER_MOTOR_C, HIGH);
          digitalWrite(STEPPER_MOTOR_D, HIGH);
        break;
        case 2:
          digitalWrite(STEPPER_MOTOR_A, HIGH);
          digitalWrite(STEPPER_MOTOR_B, LOW);
          digitalWrite(STEPPER_MOTOR_C, HIGH);
          digitalWrite(STEPPER_MOTOR_D, HIGH);
        break;
        case 3:
          digitalWrite(STEPPER_MOTOR_A, HIGH);
          digitalWrite(STEPPER_MOTOR_B, LOW);
          digitalWrite(STEPPER_MOTOR_C, LOW);
          digitalWrite(STEPPER_MOTOR_D, HIGH);
        break;
                case 4:
          digitalWrite(STEPPER_MOTOR_A, HIGH);
          digitalWrite(STEPPER_MOTOR_B, HIGH);
          digitalWrite(STEPPER_MOTOR_C, LOW);
          digitalWrite(STEPPER_MOTOR_D, HIGH);
        break;
        case 5:
          digitalWrite(STEPPER_MOTOR_A, HIGH);
          digitalWrite(STEPPER_MOTOR_B, HIGH);
          digitalWrite(STEPPER_MOTOR_C, LOW);
          digitalWrite(STEPPER_MOTOR_D, LOW);
          break;
          case 6:
          digitalWrite(STEPPER_MOTOR_A, HIGH);
          digitalWrite(STEPPER_MOTOR_B, HIGH);
          digitalWrite(STEPPER_MOTOR_C, HIGH);
          digitalWrite(STEPPER_MOTOR_D, LOW);
        break;
        case 7:
          digitalWrite(STEPPER_MOTOR_A, LOW);
          digitalWrite(STEPPER_MOTOR_B, HIGH);
          digitalWrite(STEPPER_MOTOR_C, HIGH);
          digitalWrite(STEPPER_MOTOR_D, LOW);
        default:
          digitalWrite(STEPPER_MOTOR_A, LOW);
          digitalWrite(STEPPER_MOTOR_B, LOW);
          digitalWrite(STEPPER_MOTOR_C, LOW);
          digitalWrite(STEPPER_MOTOR_D, LOW);
        break;
    }
    if( StepperDir )
    {
        CurrentStep++;
    }else{
        CurrentStep--;
    }
    if( CurrentStep >= STEPPER_MODE_8 ){
        CurrentStep = 0;
    }
    if( CurrentStep < 0 ){
        CurrentStep = STEPPER_MODE_8-1 ;
    }
    delay(stepperSpeed);
    stepsum++ ;
    if( stepsum == 4096 )
    {
        Serial.println(stepsum);
        stepsum = 0 ;
        delay(5000);
    }
}
