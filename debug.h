#ifndef DEBUG_H
#define DEBUG_H
#include <string>
#include <iostream>
#define debug(args...)  (Debugger()), args
class Debugger {
public:
  Debugger(const std::string& _separator = " - ") : first(true), separator(_separator){}
  
  template<typename ObjectType> Debugger& operator,(const ObjectType& v) {
    if (!first) std::cerr << separator;
    std::cerr << v;
    first = false;
    return *this;
  }
  ~Debugger() {  std::cerr << std::endl; }
  
private:
  bool first;
  std::string separator;
};
#endif
