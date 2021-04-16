#include "BumperInterrupt.h"
#include "Arduino.h"
static BumperInterrupt *isr_flag;

BumperInterrupt::BumperInterrupt(int _bumper_pin, int _bumper_reset_pin):bumper_pin(_bumper_pin),bumper_reset_pin(_bumper_reset_pin)
{
    bumper_status = false;
}

void BumperInterrupt::init(){
    init_bumper();
    init_bumper_seset();    
}

bool BumperInterrupt::get_bumper_status(){
    if(bumper_status == 0){
        return false;
    }else if(bumper_status == 1){
        return true;
    }
}

void BumperInterrupt::init_bumper(){
    isr_flag = this;
    pinMode(bumper_pin,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(bumper_pin),&BumperInterrupt::bumper_interrupt_on,CHANGE);
}

void BumperInterrupt::init_bumper_seset(){
    isr_flag = this;
    pinMode(bumper_reset_pin,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(bumper_reset_pin),&BumperInterrupt::bumper_reset_interrupt_on,CHANGE);
}

void BumperInterrupt::bumper_interrupt_on(){
    isr_flag->bumper_isr_on();
}

void BumperInterrupt::bumper_reset_interrupt_on(){
    isr_flag->bumper_reset_isr_on();
}

void BumperInterrupt::bumper_isr_on(){
    bumper_status = true;
}

void BumperInterrupt::bumper_reset_isr_on(){
    bumper_status = false;
}