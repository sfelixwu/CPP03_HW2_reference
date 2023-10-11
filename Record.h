
#ifndef _RECORD_H_
#define _RECORD_H_

// Record.h

#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"

// std::vector is part of the Standard Template Library in C++
// reference -- https://cplusplus.com/reference/vector/vector/
// std::vector<[type of the elements]> [vector variable name];

class Record
{
 private:
  // original: Person who;
  std::vector<Person> who_persons; // #1
  
  // original: Thing what; // one thing
  // how do we represent multiple things?
  // vector is C++ std template for array
  std::vector<Thing> what_things;  // #2
  // std::vector<Thing *> what_things;  // #2

  // Bus_Stop where; // location (event at one particular loaction) #3
  GPS_DD where; // location (event at one particular loaction) #3
  JvTime when;  // one particular event, one particular time point #4
  // extension -- a Record, correlating an event across multiple locations and times
  
public:
  Record();
  
  void addWho(Person _p);
  void setWho(std::vector<Person> _vp);
  void addWhat(Thing _t);
  void setWhat(std::vector<Thing> _vt);
  
  void setWhere(GPS_DD);
  void setWhen(JvTime);
  
  Json::Value dump2JSON();
};

#endif  /* _RECORD_H_ */
