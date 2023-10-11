
// test_GPS.cpp

#include "Person.h"
#include "Thing.h"
#include "Record.h"

int
main(int argc, char *argv[])
{
  // if (argc != 3) return -1;

  GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
  GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };

  Person Felix { "987654321", "Felix", gps_Home_Woodland };

  GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

  Thing Swedish_Meatball { Felix };
  Swedish_Meatball.model = "HUVUDROLL";
  Swedish_Meatball.sequence_num = "123456-0000";
  Swedish_Meatball.description = "frozen";
  Swedish_Meatball.location = gps_Home_Woodland;

  Felix.setLocation(gps_TLC_UCDavis, (*getNowJvTime()));

  // Felix.dump();
  // Swedish_Meatball.dump();

  Json::Value x;
  x = gps_IKEA_Sacramento.dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  Record r1;
  r1.addWho(Felix);
  r1.addWhat(Swedish_Meatball);
  r1.setWhere(gps_IKEA_Sacramento);
  r1.setWhen(*getNowJvTime());
  x = r1.dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  // HW2 event 1
  JvTime event_jv { "2023-10-04T16:00:00+0000" };

  Record hw2_r1;
  hw2_r1.addWho(Felix);

  Thing Android_Felix { Felix };
  Android_Felix.model = "Pixel 4";
  Android_Felix.sequence_num = "123456-0000";
  Android_Felix.description = "Black";
  Android_Felix.location = gps_TLC_UCDavis;

  Thing JLab_Felix { Felix };
  JLab_Felix.model = "JLab Earphone";
  JLab_Felix.sequence_num = "123456-0000";
  JLab_Felix.description = "Black";
  JLab_Felix.location = gps_TLC_UCDavis;

  hw2_r1.addWhat(Android_Felix);
  hw2_r1.addWhat(JLab_Felix);
  hw2_r1.setWhere(gps_TLC_UCDavis);
  r1.setWhen(event_jv);
  x = hw2_r1.dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  return 0;
}
