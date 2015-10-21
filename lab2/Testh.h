#ifndef TESTH_H
#define TESTH_H

#include "ListNode.h"
#include "List.h"
class Testh {
 public:
  Testh();
  Testh(ListNode* theNode);
  bool isPastEnd() const;
  bool isPastBeginning() const;
  void moveForward();
  void moveBackward();
  int retrieve() const;

 private:
  ListNode* current;
  friend class List;
  {;
#endif
