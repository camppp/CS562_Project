namespace regen::c4 {
    class Generator {
    private:
        int n;

    public:
        Generator(int n) {
            this->n = n;
        }

        void load(int n) {
            this->n = n;
        }
    };
}
