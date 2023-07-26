

using namespace std;
class MotorMoviment{
    public:
    void linear(float x, float y,float z,float f,float oldX,float oldY,float oldZ,float oldF) {
        cout<<"Linear Moviment"<<endl;
        
    };
    void ciruclarClock(float x, float y,float z,float f,float oldX,float oldY,float oldZ,float oldF) {
        float R = 0;
        R = 0.7 * sqrt(pow((oldX-x),2) + pow((oldY-y),2));
        cout<<"Circular Clock Whise Moviment"<<": Sphere with radius = "<<R<<endl;

        vector<float>P;
        P.push_back((oldX+x)/2);
        P.push_back((oldY+y)/2);
        
    };
    void spinClock() {
        cout<<"Motor Now Spinning Clock Whise"<<endl;
    };
    void stopSpin() {
        cout<<"Motor Stopped Spinning!"<<endl;
    };
    void stopAll() {
        cout<<"Motor Stopped! Program Ended!"<<endl;
    }

};

