
#include "Record.h"

Record::Record()
{
}

void
Record::addWho
(Person _p)
{
  (this->who_persons).push_back(_p);
}

void
Record::addWhat
(Thing _t)
{
  (this->what_things).push_back(_t);
}

void
Record::setWho(std::vector<Person> _vp)
{
  this->who_persons = _vp;
}

void
Record::setWhat(std::vector<Thing> _vt)
{
  this->what_things = _vt;
}

void
Record::setWhere(GPS_DD _g)
{
  this->where = _g;
}

void
Record::setWhen(JvTime _jt)
{
  this->when = _jt;
}

Json::Value
Record::dump2JSON()
{
  Json::Value result;
  result["where"] = (this->where).dump2JSON();
  result["when"] = (this->when).dump2JSON();

  int i;
  for (i = 0; i < (this->who_persons).size(); i++)
    {
      result["who"][i] = ((this->who_persons)[i]).dump2JSON();
    }
  
  for (i = 0; i < (this->what_things).size(); i++)
    {
      result["what"][i] = ((this->what_things)[i]).dump2JSON();
    }

  return result;
}
