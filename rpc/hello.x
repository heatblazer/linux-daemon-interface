

struct input_data {
    double input_data<200>;
};

typedef struct input_data input_data;

program HELLOPROG {
    version HELLOVERS {
        double hello(input_data) = 1;
    } = 1;
} = 22855;
