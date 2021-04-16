#ifndef BUMPER_INTERRUPT_H_
#define BUMPER_INTERRUPT_H_

class BumperInterrupt{
    public:
        BumperInterrupt(int _bumper_pin,int _bumper_reset_pin);
        void init();
        bool get_bumper_status();
    private:
        void init_bumper();
        void init_bumper_seset();
        static void bumper_interrupt_on();
        static void bumper_reset_interrupt_on();
        void bumper_isr_on();
        void bumper_reset_isr_on();
    private:
        bool bumper_status;
        int bumper_pin;
        int bumper_reset_pin;
};
#endif