class EmbeddedSwig {
public:
    EmbeddedSwig(int init_param_I8259) {
        // Set up the PIC's control words
        pic_control_word = init_param_I8259;

        // Set up the PIC's interrupt masks
        pic_interrupt_mask = 0x00;

        // Set up any other necessary configurations
        // ...
    }

private:
    int pic_control_word;
    int pic_interrupt_mask;
};
