
#include "GPS.h"

class Bus_Stop : GPS_DD
{
 private:
  std::string name;
 protected:
 public:
  Bus_Stop(double, double, std::string);
  void setName(std::string _name);
};

