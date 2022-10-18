#include <cmath>

class VoltageEncoder {

    public:

        unsigned int bits;
        
        int voltageToBinary(double voltage);
        double binaryToVoltage(int voltBinary);

};