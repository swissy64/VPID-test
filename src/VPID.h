#ifndef VPID_H
#define VPID_H

class VPID{
    public:
        void Set (double LA,double I_GAIN,double MAX, double MIN );
        void paramtune(double LA, double I_GAIN);
        double Cal (double target, double process);
        double Clamp (double value, double min_value, double max_value);
    private:
        double la;
        double ig;
        double max;
        double min;
        double pP; //pP = preProcess
        double pO; // pO = preOutput
        double Output;
        double delta;

        

};

#endif